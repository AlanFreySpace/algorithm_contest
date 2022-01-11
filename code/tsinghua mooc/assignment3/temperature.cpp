#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include "temperature.h"

const long long inf = 0x3f3f3f3f3f3f;//һ��Զ����2^32����,���ڶ��ֲ��ҵ��ڱ���
typedef long long ll;
const int maxn = 1e5;

int cmp(const void* a, const void* b);

struct yav;

template<typename TtT>
class Vector {//����ģ��
private:
    TtT* Data;//��������������
    int Len, Size;//Len:�������� Size:������Ԫ�ظ���
public:
    inline Vector() {
        Data = NULL;
        Len = Size = 0;
    }

    inline Vector(const Vector& other) {//��������
        if (this == &other || !Len)return;
        Data = (TtT*)malloc(sizeof(TtT) * other.Len);//Ϊ����������ڴ�
        for (int i = 0; i < other.Size; i++)Data[i] = other.Data[i];//���ݸ���
        Len = other.Len, Size = other.Size;
    }

    inline TtT& operator[](const int x) {//���������
        return Data[x];
    }

    const Vector& push_back(const TtT x) {//׷��Ԫ��x��������
        if (Size >= Len) {//��������
            Len = (Len == 0 ? 1 : Len << 1);
            TtT* newData = (TtT*)malloc(sizeof(TtT) * Len);//�·����ڴ�
            memcpy(newData, Data, Size * sizeof(TtT));//��Data�е����ݸ��Ƶ�newData��
            free(Data);//�ͷ�Data���ڴ�ռ�
            Data = newData;//Dataָ��newData
        }
        Data[Size++] = x;//׷��Ԫ��
        return *this;//��������
    }

    const Vector& pop_back() {//ɾ������ĩβԪ��
        Size--;
        if (Size == (Len >> 2)) {//������Ԫ�ع��٣���
            Len = Len >> 1; //�������ȼ���
            TtT* newData = (TtT*)malloc(sizeof(TtT) * Len);
            memcpy(newData, Data, Size * sizeof(TtT));
            free(Data);
            Data = newData;
        }
        return *this;
    }

    inline unsigned int size() {//����������Ԫ�ظ���
        return Size;
    }

    inline unsigned int len() {//������������
        return Len;
    }

    inline void sort() {//�����sort�ͻ����֪��Ϊʲô
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
    int BF;//�ڵ��ƽ�����ӣ�balance factor
    ll x, y, temperature;
    ll maxx, minx;//�Ը�NodeΪ���ڵ������x��ȡֵ��Χ

    Node() {
        maxx = -inf;
        minx = inf;
    }

    /*
    ysorted:���մ�С�����˳��,����Ե�ǰ�ڵ�Ϊ�����������е�yֵ,�Լ��ٲ���,�ɼ��⽫���ӿռ�
    ���Ӷ�ΪO(nlogn),��ȴ��С��ʱ�临�Ӷ�
    temp:��ysorted��˳���Ŷ�Ӧ���¶�ֵ
    d:ǰ׺�¶Ⱥ�,��d[i]=temp[1]+...+temp[i],�ɼ��ٶ������¶Ⱥ͵ļ���
    */
    Vector<long long> ysorted, temp, d;
    Vector<yav> xtemp;//��ŵ�ǰ�ڵ��Ӧ������x������yֵ
    struct Node* lc, * rc;
} Node, * Tree;//ע�������е�*����* Tree,Tree* p�ͳ��������е�*����
//(*p)->rc�����ǲ�ͬ�� Node, * Tree����Tree��ָ��Node��ָ�� ����Tree* p��ʾ:
//p��ָ��Tree��ָ�룬��ָ��ָ���ָ�� �����������У�*p��ʾ��ȥһ��ָ�룬��*p��ʾ
//Tree����ָ��
void LR(Tree* p) { //����,�ο��̲�193ҳ���൱��zag����(LeftRotate)
    Tree R;
    R = (*p)->rc;//*p��ȥһ��ָ�룬��ʹ���ָ��Node��ָ��
    (*p)->rc = R->lc;
    R->lc = (*p);
    *p = R;
}

void RR(Tree* p) { //�������ο��̲�193ҳ����zig����(RightRotate)
    Tree L;
    L = (*p)->lc;
    (*p)->lc = L->rc;
    L->rc = (*p);
    *p = L;
}

void LB(Tree* T) {//�ο������RB�������ǶԳƵĲ���
    Tree L, Lr;
    L = (*T)->lc;
    switch (L->BF) {
    case 1://�½ڵ������T�����ӵ��������ϣ�������������
        (*T)->BF = L->BF = 0;
        RR(T);
        break;
    case -1://�²���ڵ���T�����ӵ��������ϣ���˫������
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

void RB(Tree* T) {//���Ҳ���ƽ��(RightBalance)
    Tree R, Rl;
    R = (*T)->rc;
    switch (R->BF) {
    case -1://�½ڵ����T���Һ��ӵ��������ϣ�Ҫ������������,���ǽ̲�196ҳ��ʾ���
        (*T)->BF = R->BF = 0;
        LR(T);
        break;
    case 1://�½ڵ����T���Һ��ӵ��������ϣ�Ҫ��˫������
        Rl = R->lc;//������ת����ͽ̲�197ҳ����ͬ�ģ���Ҫע����Ǵ�ʱҪ�����������ƽ������
        switch (Rl->BF) {//�ı仯
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
//��������Ϊx,������Ϊy,����Ϊval�����ݲ�����TΪ���ڵ��AVL����
bool insert(Tree* T, int x, int y, int val, bool* taller) { //����taller��ӳAVL��T�������
    if (!*T) {//AVL����ʼΪ�յ������������Node
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
        if (x == (*T)->x) { //�������µ�Node,ֻ��y��val����xtemp����
            *taller = false;
            (*T)->xtemp.push_back({ y, val });
            return false;
        }
        if (x < (*T)->x) {//x��ΪT�����������룬�ݹ����
            if (!insert(&(*T)->lc, x, y, val, taller))//δ���룬���ڵݹ����˻���x == (*T)->x������
                return false;
            if (*taller) {  //���������������������������
                switch ((*T)->BF) {
                case 1://������ǰT��ƽ������Ϊ1���������������ƽ�����ӱ�Ϊ2ʧ�⣬��Ӧ��ʼ����
                    LB(T);
                    *taller = false;
                    break;
                case 0://����ǰT������������������T������������
                    (*T)->BF = 1;
                    *taller = true;
                    break;
                case -1://����ǰT����������������������T��������������
                    (*T)->BF = 0;
                    *taller = false;
                    break;
                }
            }
        }
        else {
            //����Ϊ���������룬������������������ǶԳƵ�
            if (!insert(&(*T)->rc, x, y, val, taller))
                return false;
            if (*taller) { //���������������������������
                switch ((*T)->BF) {
                case 1://����ǰT����������������������T��������������
                    (*T)->BF = 0;
                    *taller = false;
                    break;
                case 0://����ǰT������������������T������������
                    (*T)->BF = -1;
                    *taller = true;
                    break;
                case -1://������ǰT��ƽ������Ϊ-1���������������ƽ�����ӱ�Ϊ-2ʧ��,��Ӧ��ʼ����
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
//�鲢����:��y�Ĵ�С�Խڵ�T�е�xtemp[l,r]��������
void merge1(Tree* T, int l, int mid, int r) {
    if (l == r) return;
    merge1(&(*T), l, (l + mid) >> 1, mid);
    merge1(&(*T), mid + 1, (mid + 1 + r) >> 1, r);
    int i = l, j = mid + 1;//�������T[l,mid]��T[mid+1,r]���кϲ�
    for (int k = l; k <= r; k++) {
        //T[mid+1,r]��Ԫ�ش�����ϻ���T[l,mid]Ԫ�ؽ�С
        if (j > r || (i <= mid && (*T)->xtemp[i].y < (*T)->xtemp[j].y)) bbb[k] = (*T)->xtemp[i++];
        else bbb[k] = (*T)->xtemp[j++];//�������
    }
    for (int k = l; k <= r; k++)//�������yavת�Ƶ��ڵ�T�е�xtemp[l,r]
        (*T)->xtemp[k] = bbb[k];
}

void build(Tree* T) {
    if ((*T) == NULL) return;

    build(&((*T)->lc));
    build(&((*T)->rc));

    //�����ڹ���x������߶���:�õ���TΪ��������x��ȡֵ��Χ
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
    //�������sort����ͻ�����⣬���Ժ�����д�˸��鲢
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
    nowt = 0, nowl = 1;//ע��ڵ�T�ĳ�Աysorted����һ�ڱ�:��������(*T)->ysorted.push_back(-inf)�����Դ�1��ʼ
    //��T���������ͽڵ�T��yֵ����С�����˳�����ytemp��ʱ������,��Ӧ��
    //�¶ȴ���valtemp��ʱ������
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

    //����T�ڵ�Ϊ��������yֵ���մ�С�����˳���ŵ��ڵ�T�ĳ�Ա����ytemp�У�
    //��Ӧ���¶ȴ����Ա����temp��
    int to = ytemp.size();
    nowr = 1, nowt = 0;
    (*T)->ysorted.push_back(-inf);//ע���Ա����ysorted��ͷ����һ�ڱ�
    (*T)->temp.push_back(0);//��Ա����tempͷ��Ҳ��һ�ڱ�
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
    (*T)->ysorted.push_back(inf);//ע���Ա����ysorted��β����һ�ڱ�
    (*T)->temp.push_back(0);//��Ա����temp��β��Ҳ��һ�ڱ�
    (*T)->d.push_back(0);
    //d[i]=d[i-1]+temp[i],��d[i]�����¶�֮��,�����ɼ��ٶ������¶Ⱥ͵ļ���
    for (int i = 1; i < to; i++) {
        (*T)->d.push_back((*T)->d[i - 1] + (*T)->temp[i]);
    }
}

void slove(Tree* T, int y1, int y2) {//���ֲ���ysorted
    int l = 0, r = (*T)->ysorted.size() - 1;
    if ((*T)->ysorted[1] > y2 || (*T)->ysorted[r - 1] < y1) return;//����ʧ��

    int mid;
    int from, to;
    while (l < r) {
        mid = (l + r + 1) >> 1;
        if ((*T)->ysorted[mid] >= y1) r = mid - 1;
        else l = mid;
    }
    from = l;//����[l,r]������С��y1������ߵ���

    l = 0, r = (*T)->ysorted.size() - 1;
    while (l < r) {
        mid = (l + r) >> 1;
        if ((*T)->ysorted[mid] <= y2) l = mid + 1;
        else r = mid;
    }
    to = l;//����[l,r]�����д���y2����С�ߵ���
    count = count + to - from - 1;
    answer = answer + (*T)->d[to - 1] - (*T)->d[from];
}

void slove2(Tree* T, int y1, int y2) {//˳����Ҽ���
    for (int i = 0; i < (*T)->xtemp.size(); i++) {
        if ((*T)->xtemp[i].y >= y1 && (*T)->xtemp[i].y <= y2) {
            answer += (*T)->xtemp[i].val;
            count++;
        }
    }
}
//��ѯ��TΪ���ڵ����
void query(Tree* T, int x1, int y1, int x2, int y2) {//�൱���������
    if ((*T) == NULL) return;
    if ((*T)->minx >= x1 && (*T)->maxx <= x2) {//[minx,maxx]��ȫ������[x1,x2]��
        slove(&(*T), y1, y2);//����������ýڵ�T�е�ysorted���ٲ���
        return;
    }
    if ((*T)->maxx < x1 || (*T)->minx > x2) return;//[minx,maxx]��ȫ��������[x1,x2]��,��TΪ�����������ٲ���
    if ((*T)->x >= x1 && (*T)->x <= x2) {//[minx,maxx]���ְ�����[x1,x2]�У���ʱ��
        slove2(&(*T), y1, y2);//���ҽڵ�T
    }
    //����T����������������
    query(&(*T)->lc, x1, y1, x2, y2);
    query(&(*T)->rc, x1, y1, x2, y2);
}


int main() {
    int n, q;
    n = GetNumOfStation();//�۲�վ����
    int x, y, val;
    Tree T = NULL;
    bool taller;
    for (int i = 0; i < n; i++) {
        GetStationInfo(i, &x, &y, &val);//�õ��۲�վ��λ�úͲ�õ��¶�
        insert(&T, x, y, val, &taller);//��������x��AVL��,��x��ͬ���Ƚ���Ӧy������ֵ���浽��x�ڵ��xtemp������
    }
    build(&T);//����range���Լ��ٲ���
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
