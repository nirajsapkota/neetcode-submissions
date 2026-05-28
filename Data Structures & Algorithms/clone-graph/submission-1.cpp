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
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;

        auto clones = std::unordered_map<Node*, Node*>();
        auto s = std::stack<Node*>();
        
        clones[node] = new Node(node->val);
        s.push(node);

        while (!s.empty()) {
            auto current = s.top();
            s.pop();

            for (auto neighbor : current->neighbors) {
                if (!clones.contains(neighbor)) {
                    clones[neighbor] = new Node(neighbor->val);
                    s.push(neighbor);
                }
                clones[current]->neighbors.push_back(clones[neighbor]);
            }
        }

        return clones[node];
    }
};
