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
    void totalPath(TreeNode* node,int sum,int targetSum,vector<vector<int>> &ans,vector<int> &arr)
    {
        if(node == NULL)return ;
        sum += node->val;
        arr.push_back(node->val);
        if(node->left == NULL && node->right == NULL)
        {
            if(sum == targetSum){
            ans.push_back(arr);
             sum -= node->val;
             arr.pop_back();
             return;
            }
        }
        totalPath(node->left,sum,targetSum,ans,arr);
        totalPath(node->right,sum,targetSum,ans,arr);
        arr.pop_back();

    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        if(root == NULL)return ans;
        vector<int> arr;
        totalPath(root,0,targetSum,ans,arr);
        return ans;
    }
};