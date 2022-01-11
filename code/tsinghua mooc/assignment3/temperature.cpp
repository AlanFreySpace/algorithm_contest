#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include "temperature.h"

const long long inf = 0x3f3f3f3f3f3f;//一个远大于2^32的数,用于二分查找当哨兵用
typedef long long ll;
const int maxn = 1e5;

int cmp(const void* a, const void* b);

struct yav;

template<typename TtT>
class Vector {//向量模板
private:
    TtT* Data;//该向量的数据域
    int Len, Size;//Len:向量长度 Size:向量中元素个数
public:
    inline Vector() {
        Data = NULL;
        Len = Size = 0;
    }

    inline Vector(const Vector& other) {//向量复制
        if (this == &other || !Len)return;
        Data = (TtT*)malloc(sizeof(TtT) * other.Len);//为数据域分配内存
        for (int i = 0; i < other.Size; i++)Data[i] = other.Data[i];//数据复制
        Len = other.Len, Size = other.Size;
    }

    inline TtT& operator[](const int x) {//运算符重载
        return Data[x];
    }

    const Vector& push_back(const TtT x) {//追加元素x到向量中
        if (Size >= Len) {//向量扩容
            Len = (Len == 0 ? 1 : Len << 1);
            TtT* newData = (TtT*)malloc(sizeof(TtT) * Len);//新分配内存
            memcpy(newData, Data, Size * sizeof(TtT));//将Data中的数据复制到newData中
            free(Data);//释放Data的内存空间
            Data = newData;//Data指向newData
        }
        Data[Size++] = x;//追加元素
        return *this;//返回向量
    }

    const Vector& pop_back() {//删除向量末尾元素
        Size--;
        if (Size == (Len >> 2)) {//向量中元素过少，则
            Len = Len >> 1; //向量长度减半
            TtT* newData = (TtT*)malloc(sizeof(TtT) * Len);
            memcpy(newData, Data, Size * sizeof(TtT));
            free(Data);
            Data = newData;
        }
        return *this;
    }

    inline unsigned int size() {//返回向量中元素个数
        return Size;
    }

    inline unsigned int len() {//返回向量长度
        return Len;
    }

    inline void sort() {//用这个sort就会出错不知道为什么
        qsort(Data, Size, sizeof(TtT), cmp);
    }


};

ll answer, count;

struct yav {//y and val
    int y, val;
} bbb[maxn];

int cmp(const void* a, const void* b) {
    return (*(yav*)a).y - (*(yav*)b).y;
}


typedef struct Node {
    int BF;//节点的平衡因子，balance factor
    ll x, y, temperature;
    ll maxx, minx;//以该Node为根节点的树中x的取值范围

    Node() {
        maxx = -inf;
        minx = inf;
    }

    /*
    ysorted:按照从小到大的顺序,存放以当前节点为根的树中所有的y值,以加速查找,可见这将增加空间
    复杂度为O(nlogn),但却减小了时间复杂度
    temp:按ysorted的顺序存放对应的温度值
    d:前缀温度和,即d[i]=temp[1]+...+temp[i],可加速对区间温度和的计算
    */
    Vector<long long> ysorted, temp, d;
    Vector<yav> xtemp;//存放当前节点对应横坐标x的所有y值
    struct Node* lc, * rc;
} Node, * Tree;//注意声明中的*，如* Tree,Tree* p和程序主体中的*，如
//(*p)->rc含义是不同的 Node, * Tree表明Tree是指向Node的指针 声明Tree* p表示:
//p是指向Tree的指针，即指向指针的指针 而程序主体中，*p表示褪去一层指针，即*p表示
//Tree，即指针
void LR(Tree* p) { //左旋,参考教材193页，相当于zag操作(LeftRotate)
    Tree R;
    R = (*p)->rc;//*p褪去一层指针，则就代表指向Node的指针
    (*p)->rc = R->lc;
    R->lc = (*p);
    *p = R;
}

void RR(Tree* p) { //右旋，参考教材193页，即zig操作(RightRotate)
    Tree L;
    L = (*p)->lc;
    (*p)->lc = L->rc;
    L->rc = (*p);
    *p = L;
}

void LB(Tree* T) {//参考下面的RB函数，是对称的操作
    Tree L, Lr;
    L = (*T)->lc;
    switch (L->BF) {
    case 1://新节点插入在T的左孩子的左子树上，做单右旋处理
        (*T)->BF = L->BF = 0;
        RR(T);
        break;
    case -1://新插入节点在T的左孩子的右子树上，做双旋处理
        Lr = L->rc;
        switch (Lr->BF) {
        case 1:
            (*T)->BF = -1;
            L->BF = 0;
            break;
        case 0:
            (*T)->BF = L->BF = 0;
            break;
        case -1:
            (*T)->BF = 0;
            L->BF = 1;
            break;
        }
        Lr->BF = 0;
        LR(&(*T)->lc);
        RR(T);
    }
}

void RB(Tree* T) {//即右侧重平衡(RightBalance)
    Tree R, Rl;
    R = (*T)->rc;
    switch (R->BF) {
    case -1://新节点插在T的右孩子的右子树上，要做单左旋处理,就是教材196页所示情况
        (*T)->BF = R->BF = 0;
        LR(T);
        break;
    case 1://新节点插在T的右孩子的左子树上，要做双旋处理
        Rl = R->lc;//做的旋转处理和教材197页是相同的，需要注意的是此时要分情况来处理平衡因子
        switch (Rl->BF) {//的变化
        case 1:
            (*T)->BF = 0;
            R->BF = -1;
            break;
        case 0:
            (*T)->BF = R->BF = 0;
            break;
        case -1:
            (*T)->BF = 1;
            R->BF = 0;
            break;
        }
        Rl->BF = 0;
        RR(&(*T)->rc);
        LR(T);
    }
}
//将横坐标为x,纵坐标为y,气温为val的数据插入以T为根节点的AVL树中
bool insert(Tree* T, int x, int y, int val, bool* taller) { //变量taller反映AVL树T长高与否
    if (!*T) {//AVL树初始为空的情况，增加新Node
        *T = new Node;
        (*T)->x = x;
        (*T)->y = y;
        (*T)->temperature = val;
        (*T)->lc = (*T)->rc = NULL;
        (*T)->BF = 0;
        (*T)->xtemp.push_back({ y, val });

        *taller = true;
    }
    else {
        if (x == (*T)->x) { //不插入新的Node,只将y和val加入xtemp向量
            *taller = false;
            (*T)->xtemp.push_back({ y, val });
            return false;
        }
        if (x < (*T)->x) {//x作为T的左子树插入，递归进行
            if (!insert(&(*T)->lc, x, y, val, taller))//未插入，即在递归中退化至x == (*T)->x的情形
                return false;
            if (*taller) {  //插入左子树，且左子树深度增加
                switch ((*T)->BF) {
                case 1://即插入前T的平衡因子为1，则插入左子树后平衡因子变为2失衡，则应开始调整
                    LB(T);
                    *taller = false;
                    break;
                case 0://插入前T的左右子树等深，插入后T的左子树变深
                    (*T)->BF = 1;
                    *taller = true;
                    break;
                case -1://插入前T的右子树比左子树深，插入后T的左右子树等深
                    (*T)->BF = 0;
                    *taller = false;
                    break;
                }
            }
        }
        else {
            //以下为右子树插入，和上面左子树的情况是对称的
            if (!insert(&(*T)->rc, x, y, val, taller))
                return false;
            if (*taller) { //插入右子树，且右子树深度增加
                switch ((*T)->BF) {
                case 1://插入前T的左子树比右子树深，插入后T的左右子树等深
                    (*T)->BF = 0;
                    *taller = false;
                    break;
                case 0://插入前T的左右子树等深，插入后T的右子树变深
                    (*T)->BF = -1;
                    *taller = true;
                    break;
                case -1://即插入前T的平衡因子为-1，则插入右子树后平衡因子变为-2失衡,则应开始调整
                    RB(T);
                    *taller = false;
                    break;
                }
            }
        }
    }
    return true;
}

inline ll Max(ll a, ll b) {
    if (a > b) return a;
    else return b;
}

inline ll Min(ll a, ll b) {
    if (a < b) return a;
    else return b;
}
//归并排序:按y的大小对节点T中的xtemp[l,r]进行排序
void merge1(Tree* T, int l, int mid, int r) {
    if (l == r) return;
    merge1(&(*T), l, (l + mid) >> 1, mid);
    merge1(&(*T), mid + 1, (mid + 1 + r) >> 1, r);
    int i = l, j = mid + 1;//对有序的T[l,mid]和T[mid+1,r]进行合并
    for (int k = l; k <= r; k++) {
        //T[mid+1,r]中元素处理完毕或者T[l,mid]元素较小
        if (j > r || (i <= mid && (*T)->xtemp[i].y < (*T)->xtemp[j].y)) bbb[k] = (*T)->xtemp[i++];
        else bbb[k] = (*T)->xtemp[j++];//其他情况
    }
    for (int k = l; k <= r; k++)//将有序的yav转移到节点T中的xtemp[l,r]
        (*T)->xtemp[k] = bbb[k];
}

void build(Tree* T) {
    if ((*T) == NULL) return;

    build(&((*T)->lc));
    build(&((*T)->rc));

    //类似于构造x方向的线段树:得到以T为根的树的x的取值范围
    (*T)->maxx = (*T)->x;
    (*T)->minx = (*T)->x;
    if ((*T)->lc != NULL) {
        (*T)->maxx = Max((*T)->maxx, (*T)->lc->maxx);
        (*T)->minx = Min((*T)->minx, (*T)->lc->minx);
    }
    if ((*T)->rc != NULL) {
        (*T)->maxx = Max((*T)->maxx, (*T)->rc->maxx);
        (*T)->minx = Min((*T)->minx, (*T)->rc->minx);
    }
    //调用这个sort排序就会出问题，所以后来手写了个归并
   // (*T)->xtemp.sort();
    int too = (*T)->xtemp.size() - 1;
    merge1(&(*T), 0, too / 2, too);
    Vector<long long> ytemp, valtemp;
    int lsize = 0, rsize = 0, tsize = 0;
    if ((*T)->lc != NULL)
        lsize = (*T)->lc->ysorted.size() - 1;
    if ((*T)->rc != NULL)
        rsize = (*T)->rc->ysorted.size() - 1;
    tsize = (*T)->xtemp.size();
    int nowt, nowl, nowr;
    nowt = 0, nowl = 1;//注意节点T的成员ysorted中有一哨兵:下面代码的(*T)->ysorted.push_back(-inf)，所以从1开始
    //将T的左子树和节点T的y值按从小到大的顺序存入ytemp临时变量中,对应的
    //温度存入valtemp临时变量中
    while (nowt < tsize && nowl < lsize) {
        if ((*T)->lc->ysorted[nowl] < (*T)->xtemp[nowt].y) {
            ytemp.push_back((*T)->lc->ysorted[nowl]);
            valtemp.push_back((*T)->lc->temp[nowl++]);
        }
        else {
            ytemp.push_back((*T)->xtemp[nowt].y);
            valtemp.push_back((*T)->xtemp[nowt++].val);
        }
    }
    while (nowt < tsize) {
        ytemp.push_back((*T)->xtemp[nowt].y);
        valtemp.push_back((*T)->xtemp[nowt++].val);
    }
    while (nowl < lsize) {
        ytemp.push_back((*T)->lc->ysorted[nowl]);
        valtemp.push_back((*T)->lc->temp[nowl++]);
    }

    //将以T节点为根的树的y值按照从小到大的顺序存放到节点T的成员变量ytemp中，
    //对应的温度存入成员变量temp中
    int to = ytemp.size();
    nowr = 1, nowt = 0;
    (*T)->ysorted.push_back(-inf);//注意成员变量ysorted的头部有一哨兵
    (*T)->temp.push_back(0);//成员变量temp头部也有一哨兵
    while (nowr < rsize && nowt < to) {
        if ((*T)->rc->ysorted[nowr] < ytemp[nowt]) {
            (*T)->ysorted.push_back((*T)->rc->ysorted[nowr]);
            (*T)->temp.push_back((*T)->rc->temp[nowr++]);
        }
        else {
            (*T)->ysorted.push_back(ytemp[nowt]);
            (*T)->temp.push_back(valtemp[nowt++]);
        }
    }
    while (nowr < rsize) {
        (*T)->ysorted.push_back((*T)->rc->ysorted[nowr]);
        (*T)->temp.push_back((*T)->rc->temp[nowr++]);
    }
    while (nowt < to) {
        (*T)->ysorted.push_back(ytemp[nowt]);
        (*T)->temp.push_back(valtemp[nowt++]);
    }


    to = (*T)->ysorted.size();
    (*T)->ysorted.push_back(inf);//注意成员变量ysorted的尾部有一哨兵
    (*T)->temp.push_back(0);//成员变量temp的尾部也有一哨兵
    (*T)->d.push_back(0);
    //d[i]=d[i-1]+temp[i],即d[i]代表温度之和,这样可加速对区间温度和的计算
    for (int i = 1; i < to; i++) {
        (*T)->d.push_back((*T)->d[i - 1] + (*T)->temp[i]);
    }
}

void slove(Tree* T, int y1, int y2) {//二分查找ysorted
    int l = 0, r = (*T)->ysorted.size() - 1;
    if ((*T)->ysorted[1] > y2 || (*T)->ysorted[r - 1] < y1) return;//查找失败

    int mid;
    int from, to;
    while (l < r) {
        mid = (l + r + 1) >> 1;
        if ((*T)->ysorted[mid] >= y1) r = mid - 1;
        else l = mid;
    }
    from = l;//查找[l,r]区间中小于y1的最大者的秩

    l = 0, r = (*T)->ysorted.size() - 1;
    while (l < r) {
        mid = (l + r) >> 1;
        if ((*T)->ysorted[mid] <= y2) l = mid + 1;
        else r = mid;
    }
    to = l;//查找[l,r]区间中大于y2的最小者的秩
    count = count + to - from - 1;
    answer = answer + (*T)->d[to - 1] - (*T)->d[from];
}

void slove2(Tree* T, int y1, int y2) {//顺序查找即可
    for (int i = 0; i < (*T)->xtemp.size(); i++) {
        if ((*T)->xtemp[i].y >= y1 && (*T)->xtemp[i].y <= y2) {
            answer += (*T)->xtemp[i].val;
            count++;
        }
    }
}
//查询以T为根节点的树
void query(Tree* T, int x1, int y1, int x2, int y2) {//相当于先序遍历
    if ((*T) == NULL) return;
    if ((*T)->minx >= x1 && (*T)->maxx <= x2) {//[minx,maxx]完全包含在[x1,x2]中
        slove(&(*T), y1, y2);//此情况可利用节点T中的ysorted加速查找
        return;
    }
    if ((*T)->maxx < x1 || (*T)->minx > x2) return;//[minx,maxx]完全不包含在[x1,x2]中,以T为根的树无需再查找
    if ((*T)->x >= x1 && (*T)->x <= x2) {//[minx,maxx]部分包含在[x1,x2]中，此时先
        slove2(&(*T), y1, y2);//查找节点T
    }
    //查找T的左子树和右子树
    query(&(*T)->lc, x1, y1, x2, y2);
    query(&(*T)->rc, x1, y1, x2, y2);
}


int main() {
    int n, q;
    n = GetNumOfStation();//观察站总数
    int x, y, val;
    Tree T = NULL;
    bool taller;
    for (int i = 0; i < n; i++) {
        GetStationInfo(i, &x, &y, &val);//得到观察站的位置和测得的温度
        insert(&T, x, y, val, &taller);//创建关于x的AVL树,若x相同则先将相应y和气温值保存到该x节点的xtemp向量中
    }
    build(&T);//建立range树以加速查找
    int x1, y1, x2, y2;
    while (GetQuery(&x1, &y1, &x2, &y2)) {
        answer = 0, count = 0;
        query(&T, x1, y1, x2, y2);
        if (count == 0) {
            Response(0);
        }
        else {
            Response(answer / count);
        }
    }
    return 0;
}
