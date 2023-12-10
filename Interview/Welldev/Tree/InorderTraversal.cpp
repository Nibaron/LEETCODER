#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // Function to perform iterative inorder traversal
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;  // Result vector to store inorder traversal values
        if(root == NULL) return ans;  // If the tree is empty, return an empty vector

        stack<TreeNode*> st;  // Stack to keep track of nodes during traversal
        TreeNode* node = root;  // Start from the root of the tree

        while(true)
        {
            // Traverse left subtree and push nodes onto the stack
            if(node != NULL)
            {
                st.push(node);
                node = node->left;
            }

            // If the left subtree is exhausted, pop a node from the stack, process it, and move to its right subtree
            else
            {
                if(st.empty()) break;  // Break the loop if the stack is empty
                node= st.top();  // Pop a node from the stack
                st.pop();
                ans.push_back(node->val);  // Process the node by adding its value to the result vector
                node= node->right;  // Move to the right subtree
            }
        }

        return ans;  // Return the result vector containing inorder traversal elements
    }
};

int main() {
    // Example usage
    Solution solution;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    vector<int> result = solution.inorderTraversal(root);

    cout << "Inorder Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
