class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;

    vector<vector<int>> combinationSum(vector<int>& c, int target) {
        dfs(c,0,target);
        return ans;
    }

    void dfs(vector<int>& c,int u,int target){
        if(target==0){
            ans.push_back(path);
            return;
        }
        if(u==c.size()) return;

        for(int i=0;i*c[u]<=target;i++){//i����ǰ�������м���c[u]
            dfs(c,u+1,target-i*c[u]);
            path.push_back(c[u]);//ע��Ԫ��ѹ��ʱ��
        }

        for(int i=0;i*c[u]<=target;i++){//�ָ��ֳ�
            path.pop_back();
        }
    }
};
