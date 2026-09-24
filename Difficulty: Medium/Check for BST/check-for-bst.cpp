/* Structure of a Binary Search Tree node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
    bool fn(Node* node, long long min,long long max)
    {
        if(node == NULL)return true;
        if(node->data >= max || node->data <= min) return false;
        return fn(node->left,min,node->data) && fn(node->right,node->data,max);
    }
    bool isBST(Node* root) {
        // code here
        if(root == NULL)return true;
        return fn(root,LLONG_MIN,LLONG_MAX);
        
    }
};