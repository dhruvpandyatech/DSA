/* A binary tree node
class Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    bool hasPathSum(Node *root, int target) {
        // code here
        if(root == NULL) return false;
        if(root->left == NULL && root->right == NULL){
            return target == root->data;
        }
       return hasPathSum(root->left,target-root->data)||hasPathSum(root->right,target-root->data);
    }
};