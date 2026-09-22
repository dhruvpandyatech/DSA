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
    void paths(TreeNode*node,vector<string> &ans,string str)
        { 
        if(node == NULL)return;
      
        
        str+=(to_string(node->val));
        if(node->left == NULL && node->right == NULL){
            ans.push_back(str);
            return;
        }
        str+="->";

        paths(node->left,ans,str);
        paths(node->right,ans,str);
        }
public:
    vector<string> binaryTreePaths(TreeNode* node) {
        vector<string> ans;
        if(node ==NULL)return ans;
        paths(node,ans,"");
        return ans;
    }
};