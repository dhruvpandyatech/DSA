/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void insert(TreeNode* node,TreeNode* newNode,TreeNode* preNode,int flag)
    {
        if(node == NULL)
        {
            if(flag == 0)
            preNode->left = newNode;
            else preNode->right = newNode;
            return;
        } 
        if(node->val < newNode->val)
        {
            insert(node->right,newNode,node,1);
        }
        else
        {
            insert(node->left,newNode,node,0);
        }
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* newNode = new TreeNode(val);
        if(root == NULL)return newNode;
        insert(root,newNode,root,0);
        return root;
    }
};