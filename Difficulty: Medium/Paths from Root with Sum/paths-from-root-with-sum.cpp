/* A Tree node
class Node {
public:
    int data;
    Node *left, *right;
    Node(int x) {
        left = right = nullptr;
        data = x;
    }
};*/

class Solution {
  public:
    void totalPath(Node* node, int sum,int target,vector<int> &arr,vector<vector<int>> &ans)
    {
        if(node == NULL)return;
        sum += node->data;
        arr.push_back(node->data);
        if(target == sum)
        {
            ans.push_back(arr);
        }
        totalPath(node->left,sum,target,arr,ans);
        totalPath(node->right,sum,target,arr,ans);
        arr.pop_back();
    }
    vector<vector<int>> printPaths(Node *root, int sum) {
        // code here
        vector<vector<int>> ans;
        if(root == NULL)return ans;
        vector<int> arr;
        totalPath(root,0,sum,arr,ans);
        return ans;
    }
};