class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    vector<bool> use;

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        path=vector<int>(n);
        use=vector<bool>(n);
        dfs(nums,0);
        return ans;
    }

    void dfs(vector<int>& nums,int u){
        if(u==nums.size()){
            ans.push_back(path);
            return;
        }

        for(int i=0;i<nums.size();i++){
            //��ֹ�����ظ����� �ظ�Ԫ��Ӧ�ñ���һ�����˳��
            if(i&&nums[i]==nums[i-1]&&!use[i-1]) continue;
            if(!use[i]){
                path[u]=nums[i];
                use[i]=true;
                dfs(nums,u+1);
                use[i]=false;
            }
        }
    }
};
