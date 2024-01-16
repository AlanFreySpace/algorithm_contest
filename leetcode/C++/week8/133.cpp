/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> hash;

    Node* cloneGraph(Node* node) {
        if (node == NULL) {
            return NULL;
        }

        dfs(node);// 复制点

        for (auto [node, newNode] : hash) { //复制邻边
            for (Node* neighbor : node->neighbors) {
                newNode->neighbors.push_back(hash[neighbor]);
            }
        }

        return hash[node];
    }

    void dfs(Node* node) {
        hash[node] = new Node(node->val);

        for (Node* neighbor : node->neighbors) {
            if (hash.count(neighbor) == 0) {
                dfs(neighbor);
            }
        }
    }
};