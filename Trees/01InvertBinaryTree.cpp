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

//Apporach :
//Iterate each node , swap its left and right node
//if they have left or right, do same for them 

class Solution {
public:
    //DFS~recursion TC->O(N), SC->O(N)
    // TreeNode* invertTree(TreeNode* root) {
    //     //base case
    //     if(root==NULL) return NULL;
    //     swap(root->left, root->right);
    //     invertTree(root->left);
    //     invertTree(root->right);

    //     return root;
    // }

    //BFS TC->O(N), SC->O(N)
    TreeNode* invertTree(TreeNode* root){
        if(root==NULL)return NULL;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* front = q.front();
            q.pop();
            swap(root->left, root->right);
            if(root->left){
                q.push(root->left);
            }
            if(root->right){
                q.push(root->right);
            }
        }
        return root;
    }
};