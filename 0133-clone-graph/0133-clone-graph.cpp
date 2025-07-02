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
    Node* dfs(Node* currNode, unordered_map<Node*, Node*>& cloneMap) {
        if (cloneMap.find(currNode) != cloneMap.end())
            return cloneMap[currNode];

        Node* clone = new Node(currNode->val);
        cloneMap[currNode] = clone;

        for (auto neighbor : currNode->neighbors) {
            clone->neighbors.push_back(dfs(neighbor, cloneMap));
        }

        return clone;
    }

    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        unordered_map<Node*, Node*> cloneMap;
        return dfs(node, cloneMap);
    }
};