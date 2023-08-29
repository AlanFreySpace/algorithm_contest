class Solution {
public:
    unordered_set<string> s;
    unordered_map<string, int> dist;// beginWord�����ڵ����̾���
    queue<string> q;
    vector<string> path;
    vector<vector<string>> ans;
    string firstWord;

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        for (auto word : wordList) {
            s.insert(word);
        }
        // ��֦:��wordList��û��endWord,��ֱ�ӷ���
        if (!s.count(endWord)) {
            return ans;
        }
        dist[beginWord] = 0;
        q.push(beginWord);

        bool endFlag = false;// ��ʾ�Ƿ��Ѿ��ҵ�һ����endWord��·��

        while (!q.empty() && !endFlag) {
            string t = q.front(); // ����ջ��Ԫ��
            q.pop();

            string r = t;
            // bfs,��������֮��Ĺ�ϵͼ,�õ�beginWord��endWord����̾���
            for (int i = 0; i < t.size() && !endFlag; i++) {
                t = r;
                for (char j = 'a'; j <= 'z'; j++) {
                    t[i] = j;
                    if (s.count(t) && !dist.count(t)) {
                        dist[t] = dist[r] + 1;
                        if (t == endWord) {
                            endFlag = true;
                            break;
                        }
                        q.push(t);
                    }
                }
            }
        }

        // ��֦:���û�е�endWord��·��,ֱ�ӷ���
        if (!dist.count(endWord)) {
            return ans;
        }

        firstWord = beginWord;
        path.push_back(endWord);
        dfs(endWord);
        return ans;
    }

    // �����beginWord��endWord�����·��
    void dfs(string t) {
        if (firstWord == t) {
            reverse(path.begin(), path.end());
            ans.push_back(path);
            reverse(path.begin(), path.end());
        }
        else {
            string r = t;
            for (int i = 0; i < t.size(); i++) {
                string t = r;
                for (char j = 'a'; j <= 'z'; j++) {
                    t[i] = j;
                    if (dist.count(t) && dist[r] == dist[t] + 1) {
                        path.push_back(t);
                        dfs(t);
                        path.pop_back();
                    }
                }
            }
        }
    }
};