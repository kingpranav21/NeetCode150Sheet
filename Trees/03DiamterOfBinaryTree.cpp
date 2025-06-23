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
    //DFS
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int left = findMaxDepth(root->left);
        int right = findMaxDepth(root->right);

        return left+right;
    }
    int findMaxDepth(TreeNode* root){
        if(!root) return 0;
        int left = findMaxDepth(root->left);
        int right = findMaxDepth(root->right);

        return max(left, right)+1;
    }
};