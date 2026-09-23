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
    void findCeilHelp(Node* root,int x,int& ans){
        if(root == NULL)return;
        if(root->data >= x){
            if(root->data == x)
            {
            ans = root->data;
            return;
            }
            ans = root->data;
        }
        if(root->data > x)findCeilHelp(root->left,x,ans);
        else
        findCeilHelp(root->right,x,ans);
    }
    int findCeil(Node* root, int x) {
        // code here
        int ans = -1;
        if(root == NULL)return ans;
        findCeilHelp(root,x,ans);
        return ans;}
};
