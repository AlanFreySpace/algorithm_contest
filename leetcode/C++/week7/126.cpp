class Solution {
public:
    unordered_set<string> s;
    unordered_map<string, int> dist;// beginWord到各节点的最短距离
    queue<string> q;
    vector<string> path;
    vector<vector<string>> ans;
    string firstWord;

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        for (auto word : wordList) {
            s.insert(word);
        }
        // 剪枝:若wordList中没有endWord,则直接返回
        if (!s.count(endWord)) {
            return ans;
        }
        dist[beginWord] = 0;
        q.push(beginWord);

        bool endFlag = false;// 表示是否已经找到一条到endWord的路径

        while (!q.empty() && !endFlag) {
            string t = q.front(); // 返回栈顶元素
            q.pop();

            string r = t;
            // bfs,构建单词之间的关系图,得到beginWord到endWord的最短距离
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

        // 剪枝:如果没有到endWord的路径,直接返回
        if (!dist.count(endWord)) {
            return ans;
        }

        firstWord = beginWord;
        path.push_back(endWord);
        dfs(endWord);
        return ans;
    }

    // 构造从beginWord到endWord的最短路径
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