#include <stdio.h>
#include <deque>
#include <algorithm>
using namespace std;

#define eps 1.e-8

pair<double, double> g[505];//╪ссму╬

int main() {
    double cmax, d, davg;
    int n;
    while (scanf("%lf%lf%lf%d", &cmax, &d, &davg, &n) != EOF) {
        for (int i = 0; i < n; i++)
            scanf("%lf%lf", &g[i].second, &g[i].first);
        g[n++] = make_pair(d, 0.);
        sort(g, g + n);

        deque<pair<double, double> > q;
        double sumDis = 0., oil = 0., cost = 0.;
        if (g[0].first > eps) printf("The maximum travel distance = 0.00\n");
        else {
            q.push_back(make_pair(g[0].second, cmax));
            oil = cmax;

            for (int i = 1; i < n; i++) {
                double gDis = g[i].first - g[i - 1].first;
                double need = gDis / davg;
                if (need > cmax + eps) {
                    sumDis += (cmax * davg);
                    printf("%s%.2lf", "The maximum travel distance = ", sumDis);
                    printf("\n");
                    break;
                }
                else {
                    sumDis += gDis;
                    while (need >= eps) {
                        double tmp = q.front().second;
                        if (tmp > need + eps) {
                            oil -= need;
                            cost += (need * q.front().first);
                            q.front().second -= need;
                            need = 0.;
                            //printf("%lf\n", cost);
                        }
                        else {
                            oil -= tmp;
                            cost += (tmp * q.front().first);
                            need -= tmp;
                            q.pop_front();
                            //printf("%lf\n", cost);
                        }
                    }

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
            //printf("%lf\n", cost);
            //printf("%lf\n", sumDis);
        }
    }
    return 0;
}
