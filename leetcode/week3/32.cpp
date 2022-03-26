class Solution {
public:
    int longestValidParentheses(string s) {
        int res=0;
        stack<int> stk;

        //start ��ʾ��һ�ε�һ�γ��ֲ��Ϸ����������е������ŵ�λ��
        for(int i=0,start=-1;i<s.size();i++){
            //����������ţ��������±���ջ
            if(s[i]=='(') stk.push(i);
            else{//������
                if(stk.size()){//ջ��Ϊ�գ�����ǰ������ƥ���
                    stk.pop();//������֮ƥ���������
                    /*
                    �����ǰջ�л��������ţ�˵����ջ������λ�õ���һ��λ�õ����������֮��
                    ��һ���Ϸ����������У����Ը��³��ȣ�������"(()()"��
                    ��������͵�ǰ������ƥ������󣬵�ǰջΪ�գ���ô�� start λ�ÿ�ʼ����һ��
                    λ�ã�����һ�εĿ�ʼλ�ã�����ǰ������֮����һ���Ϸ����������У�������start
                    ���³��ȣ�������"()()"��
                    */
                    if(stk.size()){
                        res=max(res,i-stk.top());
                    }else{
                        res=max(res,i-start);
                    }
                }else{//�����ǰ�����Ų���ƥ��ɹ��������λ�þ�����һ�ε�һ�γ��ֲ��Ϸ����������е�λ�ã�����start
                    start=i;
                }
            }
        }
        return res;
    }
};