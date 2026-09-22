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
    int sumOfLeft(TreeNode* node,int &sum, int flag)
    {
        if(node == NULL) return 0;
        if(node->left == NULL && node->right == NULL && flag == 1)sum += node->val;
        int left = sumOfLeft(node->left,sum,1);
        int right = sumOfLeft(node->right,sum,0);
        return sum;
    }
    int sumOfLeftLeaves(TreeNode* node) {
        int sum =0;
        return sumOfLeft(node,sum,0);
    }
};