/* Structure of binary tree node
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  public:
    int maxPath(Node* root,int& maxi)
    {
        if(root == NULL) return 0;
        int leftSum = max(0,maxPath(root->left,maxi));
        int rightSum = max(0,maxPath(root->right,maxi));
        maxi = max(maxi,leftSum+rightSum+root->data);
        return root->data + max(leftSum,rightSum);
    }
    int findMaxSum(Node *root) {
        // code here
        int maxi = INT_MIN;
        maxPath(root,maxi);
        return maxi;
    }
};