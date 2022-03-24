class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    vector<bool> use;

    vector<vector<int>> permute(vector<int>& nums) {//dfs��Ӧ��
        int n=nums.size();
        use=vector<bool>(n);//ע��������������
        path=vector<int>(n);
        dfs(nums,0);
        return ans;
    }

    void dfs(vector<int>& nums,int u){
        if(u==nums.size()){
            ans.push_back(path);
            return;
        }

        for(int i=0;i<nums.size();i++){
            if(!use[i]){
                path[u]=nums[i];
                use[i]=true;
                dfs(nums,u+1);
                use[i]=false;
            }
        }
    }
};
