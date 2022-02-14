#include <stdio.h>
#include <deque>
#include <algorithm>
using namespace std;

#define eps 1.e-8

pair<double, double> g[505];//加油站<到杭州距离,一升汽油的价格>

int main() {
    double cmax, d, davg;
    int n;
    while (scanf("%lf%lf%lf%d", &cmax, &d, &davg, &n) != EOF) {
        for (int i = 0; i < n; i++)
            scanf("%lf%lf", &g[i].second, &g[i].first);
        g[n++] = make_pair(d, 0.);//终点也看作一个加油站,便于编码
        sort(g, g + n);

        deque<pair<double, double> > q;//模拟油箱<一升汽油的价格,该油的油量>
        /*
        sumDis:记录行驶路程
        oil:记录油箱中剩多少油
        cost:记录花费
        */
        double sumDis = 0., oil = 0., cost = 0.;
        if (g[0].first > eps) printf("The maximum travel distance = 0.00\n");
        else {
            q.push_back(make_pair(g[0].second, cmax));//在第一个加油站加满油
            oil = cmax;

            for (int i = 1; i < n; i++) {//从加油站i-1到i的过程
                double gDis = g[i].first - g[i - 1].first;
                double need = gDis / davg;
                if (need > cmax + eps) {//油箱中的油不够
                    sumDis += (cmax * davg);
                    printf("%s%.2lf", "The maximum travel distance = ", sumDis);
                    printf("\n");
                    break;
                }
                else {
                    sumDis += gDis;
                    while (need >= eps) {//使用油箱中的油
                        double tmp = q.front().second;
                        if (tmp > need + eps) {
                            oil -= need;
                            cost += (need * q.front().first);
                            q.front().second -= need;
                            need = 0.;
                        }
                        else {
                            oil -= tmp;
                            cost += (tmp * q.front().first);
                            need -= tmp;
                            q.pop_front();
                        }
                    }
                    //给油箱加满油
                    if (q.empty()||q.back().first <= g[i].second - eps)
                        q.push_back(make_pair(g[i].second, cmax - oil));
                    else {
                        while (!q.empty()&&q.back().first > g[i].second + eps) {
                            oil -= q.back().second;
                            q.pop_back();
                        }
                        q.push_back(make_pair(g[i].second, cmax - oil));
                    }
                    oil = cmax;
                    if (i == n-1) printf("%.2lf\n", cost);
                }
            }
        }
    }
    return 0;
}
