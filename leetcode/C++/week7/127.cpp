class Solution {
public:
    unordered_set<string> set;
    unordered_map<string, int> dist;
    queue<string> q;

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        for (auto word : wordList) {
            set.push(word);
        }

        if (!set.count(endWord)) {
            return 0;
        }

        dist[endWord] = 0;
        q.push(beginWord);
        bool endFlag = false;

        while (!q.empty() && !endFlag) {
            string s = q.front();
            q.pop();

            string t = s;
            for (int i = 0; i < t.size(); t++) {
                t = s;
                for (char j = 'a'; j <= 'z'; j++) {
                    t[i] = j;
                    if (set.count(t) && !dist.count(t)) {

                    }
                }
            }
        }
    }
};