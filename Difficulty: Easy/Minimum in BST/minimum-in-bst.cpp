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
    void mmin(Node* node,int &ans)
    {
        if(node == NULL)return;
        ans = min(ans,node->data);
        mmin(node->left,ans);
    }
    int minValue(Node* root) {
        // code here
        if(root == NULL)return -1;
        int ans = INT_MAX;
        mmin(root,ans);
        return ans;
    }
};