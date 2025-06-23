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
    // DFS TC->O(N), SC->O(height of tree)

    // best case-> O(log(n)) in case of balanced BT
    // worst case-> O(n) in case of degenrate tree/ skew tree

    // int maxDepth(TreeNode* root) {
    //     if(!root) return 0;
    //     int left = maxDepth(root->left);
    //     int right = maxDepth(root->right);

    //     return max(left,right) + 1; 
    // }

    //BFS
    //TC->O(N), SC->O(N)
    int maxDepth(TreeNode* root){
        if(!root) return 0;
        queue<TreeNode*>q;
        q.push(root);

        int level = 0;

        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                TreeNode* front = q.front();
                q.pop();

                if(front->left){
                    q.push(front->left);
                }

                if(front->right){
                    q.push(front->right);
                }
            }
            level++;
        }
        return level;
    }
};