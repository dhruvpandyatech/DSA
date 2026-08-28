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
        void inOrderTraversal(Node* root,vector<int> &eles)
        {
            if(root==NULL) return;
            inOrderTraversal(root->left,eles);
            eles.push_back(root->data);
            inOrderTraversal(root->right,eles);
        }
    vector<int> inOrder(Node* root) {
        // code here
        vector<int> eles;
        inOrderTraversal(root,eles);
        return eles;
    }
};