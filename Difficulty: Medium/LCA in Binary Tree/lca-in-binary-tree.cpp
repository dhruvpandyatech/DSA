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
    Node* lca(Node* node, int n1, int n2) {
        //  code here
        if(node == NULL || node->data == n1 || node->data == n2)
        return node;
        
        Node* left = lca(node->left,n1,n2);
        Node* right = lca(node->right,n1,n2);
        if(left == NULL)return right;
        if(right == NULL)return left;
        else
        return node;
    }
};