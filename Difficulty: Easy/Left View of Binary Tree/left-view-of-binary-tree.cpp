/* Structure of Binary Tree Node
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
    void leftSideView(Node* node,int level,vector<int> &ans)
    {
        if(node == NULL)return;
        if(level == ans.size())
        {
            ans.push_back(node->data);
        }
        
        leftSideView(node->left,level+1,ans);
        leftSideView(node->right,level+1,ans);
    }
    vector<int> leftView(Node *root) {
        // code here
        vector<int> ans;
        if(root == NULL) return ans;
        leftSideView(root,0,ans);
        return ans;
    }
};