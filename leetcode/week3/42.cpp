class Solution {
public:
    /*
    �ⷨһ:����ɨ��
    1.�۲�����ͼ�Σ����Ƕ�ˮ��������н��в��
    2.ע�⵽��ÿ���������Ϸ����ܽ��ܵ�ˮ�ĸ߶ȣ������������ߵľ��Σ�
    ���ұ���ߵľ��ξ����ġ�����أ������i���������ĸ߶�Ϊheight[i]��
    �Ҿ����������ߵľ������ĸ߶�Ϊleft_max[i]���ұ���ߵľ������߶�Ϊ
    right_max[i]����þ������Ϸ��ܽ���ˮ�ĸ߶�Ϊ
    min(left_max[i], right_max[i]) - height[i]��
    3.��Ҫ�ֱ��������ɨ����left_max������������right_max�����ͳ�ƴ𰸼��ɡ�
    */
    int trap(vector<int>& height) {
        int ans=0;
        int n=height.size();
        vector<int> left_max(n),right_max(n);

        left_max[0]=height[0];
        for(int i=1;i<n;i++)
            left_max[i]=max(left_max[i-1],height[i]);

        right_max[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--)
            right_max[i]=max(right_max[i+1],height[i]);

        for(int i=0;i<n;i++)
            ans+=(min(left_max[i],right_max[i])-height[i]);

        return ans;
    }
};

class Solution {
public:
    /*
    �ⷨ��:����ջ
    1.��һ��˼·������ÿ��λ����ߺ��ұߵ�һ���������͵ľ�������
    �Լ��������������ɵ�U�ͣ��൱�ڶ�ˮ��������н��в�⡣
    2.ά���ϸ񵥵��ݼ��ĵ���ջ����ÿ�μ��ջ��Ҫ��ջʱ��iΪ�ұߵ�һ��
    ��st.top()���͵ľ��Σ�st.top()����ջ�����������Ϊtop��
    3.�����ʱջ����Ȼ���ھ��Σ�����st.top()����ջ���ջ������top��i
    ����λ�ù���һ��U�ͣ�����topλ�ô���U�͵ĵײ�����ʱ���Լ������U��
    ���ܽ��ܵ�ˮ�����Ϊ
    (i - st.top() - 1) * (min(height[st.top()], height[i]) - height[top])��
    4.���ǰ���ν�ջ��
    */
    int trap(vector<int>& height) {
        int n=height.size(),ans=0;
        stack<int> stk;

        for(int i=0;i<n;i++){
            while(!stk.empty()&&height[stk.top()]<=height[i]){
                int top=stk.top();
                stk.pop();
                if(stk.empty()) break;
                ans+=(min(height[i],height[stk.top()])-height[top])*(i-stk.top()-1);
            }
            stk.push(i);
        }
        return ans;
    }
};
