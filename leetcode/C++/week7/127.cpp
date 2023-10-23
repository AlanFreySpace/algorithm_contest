class Solution {
public:
    unordered_set<string> set;
    unordered_map<string, int> dist;
    queue<string> q;
    //本题是126题的简化版
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        for (auto word : wordList) {
            set.insert(word);
        }

        if (!set.count(endWord)) {
            return 0;
        }

        dist[beginWord] = 0;
        q.push(beginWord);
        bool endFlag = false;

        while (!q.empty() && !endFlag) {
            string s = q.front();
            q.pop();

            string t = s;
            for (int i = 0; i < t.size() && !endFlag; i++) {
                t = s;
                for (char j = 'a'; j <= 'z'; j++) {
                    t[i] = j;
                    if (set.count(t) && !dist.count(t)) {
                        dist[t] = dist[s] + 1;
                        q.push(t);
                        if (t == endWord) {
                            endFlag = true;
                            break;
                        }
                    }
                }
            }
        }

        if (!dist.count(endWord)) {
            return 0;
        }
        return dist[endWord] + 1;
    }
};