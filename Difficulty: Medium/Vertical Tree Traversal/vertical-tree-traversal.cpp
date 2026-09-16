/* Structure of binary tree node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/
class Solution {
public:
    vector<vector<int>> verticalOrder(Node *root) {

        if (root == nullptr)
            return {};

        map<int, vector<int>> nodes;
        queue<pair<Node*, int>> todo;

        todo.push({root, 0});

        while (!todo.empty()) {

            auto p = todo.front();
            todo.pop();

            Node* node = p.first;
            int x = p.second;

            nodes[x].push_back(node->data);

            if (node->left) {
                todo.push({node->left, x - 1});
            }

            if (node->right) {
                todo.push({node->right, x + 1});
            }
        }

        vector<vector<int>> ans;

        for (auto p : nodes) {
            ans.push_back(p.second);
        }

        return ans;
    }
};