class Solution {
public:
    /*
    1.���� dividend �� divisor �ķ����ж����մ𰸵ķ��š�
    2.��� dividend �� divisor Ϊ���������Ϊ��������Ϊ����������������� 1��
    3.���ñ����ķ�ʽ������ͨ���Լ�Ԥ����һ����Ԫ�鱶�����飺(divisor, -1),
    (2 * divisor, -2), (4 * divisor, -4)�������� ֱ�� 2^k * divisor С���� dividend������;ע���ж�Խ�硣
    4.�����������������飬��� dividend С�ڵ�ǰ����� dividend ��ȥ��ǰ��ۼƸ��𰸣��Դ����ơ�
    */
    int divide(int dividend, int divisor) {
        const int HALF_INT_MIN=-1073741824;//-2^30
        int x=dividend,y=divisor;
        bool sign=(x>0)^(y>0);
        if(x>0) x=-x;
        if(y>0) y=-y;

        vector<pair<int,int> > vec;
        for(int t1=y,t2=-1;t1>=x;t1+=t1,t2+=t2){
            vec.emplace_back(t1,t2);
            if(t1<HALF_INT_MIN) break;
        }

        int ans=0;
        for(int i=vec.size()-1;i>=0;i--){
            if(x<=vec[i].first){
                x-=vec[i].first;
                ans+=vec[i].second;
            }
        }

        if(!sign){
            if(ans==INT_MIN)
                return INT_MAX;
            ans=-ans;
        }
        return ans;
    }
};
