class Solution {
public:
    /*
    ע����C++��-4%10=-4
    */
    int reverse(int x) {//�ؾ����㷨
        int r=0;
        /*
        ���䷽��:��r*10+x%10>INT_MAX�����
        ���ǿ��ǵ���ȡ�������� ʵ���Ƶ������Ϊ����(����дһ�¿ɿ�����)
        */
        while(x){
            if(x>0&&r>(INT_MAX-x%10)/10) return 0;//�ж��Ƿ����
            if(x<0&&r<(INT_MIN-x%10)/10) return 0;
            r=r*10+x%10;
            x/=10;
        }
        return r;
    }
};
