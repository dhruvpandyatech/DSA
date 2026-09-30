
class Codec {
public:
    string serialize(TreeNode* root) {
        if (root == NULL) return "";

        string s = "";
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* curNode = q.front();
            q.pop();

            if (curNode == NULL) {
                s.append("#,");
            } else {
                s.append(to_string(curNode->val) + ',');
                q.push(curNode->left);
                q.push(curNode->right);
            }
        }

        return s;
    }

    TreeNode* deserialize(string data) {
        if (data.empty()) return NULL;

        stringstream ss(data);
        string str;

        if (!getline(ss, str, ',')) return NULL;

        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            // Left child
            if (!getline(ss, str, ',')) break;

            if (str == "#") {
                node->left = NULL;
            } else {
                node->left = new TreeNode(stoi(str));
                q.push(node->left);
            }

            // Right child
            if (!getline(ss, str, ',')) break;

            if (str == "#") {
                node->right = NULL;
            } else {
                node->right = new TreeNode(stoi(str));
                q.push(node->right);
            }
        }

        return root;
    }
};