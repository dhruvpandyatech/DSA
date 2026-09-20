/*
Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    void rightSideView(Node* node, int level,vector<int> &ans)
    {
        if(node == NULL) return;
        if(ans.size() == level)
        {
            ans.push_back(node->data);
        }
        rightSideView(node->right,level+1,ans);
        rightSideView(node->left,level+1,ans);
    }
  
    vector<int> rightView(Node *root) {
        //  code here
        vector<int> ans;
        if(root == NULL) return ans;
        
        rightSideView(root,0,ans);
        return ans;
    }
};