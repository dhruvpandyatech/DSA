/* Binary Tree Node Structure
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
    vector<int> preOrder(Node* root) {
        // code here
        vector<int> ans;
        if(root==NULL) return ans;
        stack<Node*> st;
        
        st.push(root);
        
        while(!st.empty())
        {
            int size = st.size();
            for(int i = 0;i<size;i++)
            {
            Node* node = st.top();
            st.pop();
            if(node->right!=NULL) st.push(node->right);
            if(node->left!=NULL) st.push(node->left);
            ans.push_back(node->data);
            }
        }
        return ans;
    }
};