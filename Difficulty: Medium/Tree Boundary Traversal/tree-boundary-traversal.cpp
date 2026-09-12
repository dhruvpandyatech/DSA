/* Node Structure
class Node {
  public:
    int data;
    Node* left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
    
    bool isLeaf(Node*root)
    {
        if(root == NULL) return false;
        return (root->right == NULL && root->left == NULL);
    }
    
    void addLeft(Node* root,vector<int> &res)
    {
        Node* curr = root->left;
        while(curr)
        {
            if(!isLeaf(curr)) res.push_back(curr->data);
            if(curr->left) curr = curr->left;
            else
            curr = curr->right;
        }
    }
    
    
    void addLeaf(Node* root,vector<int>&res)
    {
        if(isLeaf(root))
        {
            res.push_back(root->data);
        }
        if(root->left) addLeaf(root->left,res);
        if(root->right) addLeaf(root->right,res);
    }
    
    
    void addRight(Node*root,vector<int> &res)
    {
        Node* curr = root->right;
        vector<int> tmp;
        while(curr){
        if(!isLeaf(curr)) tmp.push_back(curr->data);
        if(curr->right) curr = curr->right;
        else
        curr = curr->left;
        }
        
        int size = tmp.size()-1;
        for(int i = size;i>=0;i--)
        {
            res.push_back(tmp[i]);
        }
    }
  
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int> res;
        if(root == NULL)
        {
            return res;
        }
        if(!isLeaf(root))
        {
            res.push_back(root->data);
        }
        addLeft(root,res);
        addLeaf(root,res);
        addRight(root,res);
        return res;
    }
};