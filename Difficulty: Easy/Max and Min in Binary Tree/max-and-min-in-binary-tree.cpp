/* Structure of Binary Tree Node
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};*/

class Solution {
  public:
    void findMaxHelp(Node* root,int &maxAns)
    {
        if(root == NULL)return;
        maxAns = max(maxAns,root->data);
        findMaxHelp(root->left,maxAns);
        findMaxHelp(root->right,maxAns);
    }
    void findMinHelp(Node* root,int &minAns){
        if(root == NULL)return;
        minAns = min(minAns,root->data);
        findMinHelp(root->left,minAns);
        findMinHelp(root->right,minAns);
    }
  
    int findMax(Node *root) {
        // code here
        if(root == NULL)return -1;
        int maxAns = INT_MIN;
        findMaxHelp(root,maxAns);
        return maxAns;
}

    int findMin(Node *root) {
        // code here
        if(root == NULL)return -1;
        int minAns = INT_MAX;

        findMinHelp(root,minAns);
        
        return minAns;
    }
};