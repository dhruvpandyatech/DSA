/* Structrue of Binary Tree Node
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
    int heightOfBt(Node* root)
    {
          if(root == NULL) return 0;
        int lh = heightOfBt(root->left);
        int rh = heightOfBt(root->right);
        return 1 + max(lh,rh);
    }
    int height(Node* root) {
        // code here
      return heightOfBt(root)-1;
    }
};
