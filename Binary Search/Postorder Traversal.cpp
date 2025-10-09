/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
   void postorderHelper(Node* root, vector<int>& result) {
        if (root == nullptr) return;
        postorderHelper(root->left, result);
        postorderHelper(root->right, result);
        result.push_back(root->data);
    }
    
    vector<int> postOrder(Node* root) {
        vector<int> result;
        postorderHelper(root, result);
        return result;
    }
    
    // Helper to build tree from level order input (vector with N for null)
    Node* buildTree(const vector<string>& nodes) {
        if (nodes.empty() || nodes[0] == "N") return nullptr;
    
        Node* root = new Node(stoi(nodes[0]));
        queue<Node*> q;
        q.push(root);
        int i = 1;
        while (!q.empty() && i < nodes.size()) {
            Node* curr = q.front();
            q.pop();
    
            // Left child
            if (nodes[i] != "N") {
                curr->left = new Node(stoi(nodes[i]));
                q.push(curr->left);
            }
            i++;
            if (i >= nodes.size()) break;
    
            // Right child
            if (nodes[i] != "N") {
                curr->right = new Node(stoi(nodes[i]));
                q.push(curr->right);
            }
            i++;
        }
        return root;
    }    
    
};
