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
    void bottom(TreeNode* node,int level,vector<int> &ans)
    {
        if(node == NULL) return;
        if(level == ans.size()){
            ans.push_back(node->val);
        }
        bottom(node->left,level+1,ans);
        bottom(node->right,level+1,ans);
    }
    int findBottomLeftValue(TreeNode* root) {

        if(root == NULL) return 0;
        vector<int> ans;
        bottom(root,0,ans);
        return ans[ans.size()-1];
    }
};