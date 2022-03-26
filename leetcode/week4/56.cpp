class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& a) {
        vector<vector<int>> ans;
        /*
        ���ڶ�ά����,sort��������ÿһ����Ԫ������,����
        ���а���Ԫ������
        */
        sort(a.begin(),a.end());
        int l=a[0][0],r=a[0][1];

        for(int i=1;i<a.size();i++){
            if(r<a[i][0]){//���䲻�ص� ���´�
                ans.push_back({l,r});
                l=a[i][0],r=a[i][1];
            }else r=max(r,a[i][1]);//�����ص� �����Ҳ�˵�
        }
        ans.push_back({l,r});//���һ������
        return ans;
    }
};
