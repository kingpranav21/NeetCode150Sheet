
//for root, the max of left height + right height is diameter because you have leftH and rightH for every node
//TC->O(N), SC->O(height of tree)
//SC best case : balanced tree->(Ologn) ,degenerate tree->O(n)
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        height(root, diameter);
        return diameter;
    }
    int height(TreeNode* root, int &diameter){
        if(!root) return 0;
        int leftH = height(root->left, diameter);
        int rightH = height(root->right, diameter);
        diameter = max(diameter, leftH + rightH);
        return 1 + max(leftH, rightH);
    }
};
