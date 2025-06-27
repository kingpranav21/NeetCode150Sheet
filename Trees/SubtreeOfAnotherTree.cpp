//firstly if there is no subroot return true nothing to match
//if there is no root then return false
//check for full same tree , if it is return true
//check for left tree matches the subtree
//check for rigth tree matches the subtree


class Solution {
public:
    //Approach - 1 DFS TC - O(m*n), SC - O(m+n)
    bool isSameTree(TreeNode* p, TreeNode* q){
        if(p == NULL && q == NULL) return true;
        if((p!=NULL && q==NULL) || (p==NULL && q!=NULL)) return false;
        if((p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right)){
            return true;
        }
        return false;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!subRoot) return true; //no subroot present so no comparison
        if(!root) return false;
        if(isSameTree(root, subRoot)) return true;
        if(isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot)){
            return true;
        }
        return false;
    }
};
