//Approach : base case if both are null, return true
//if one of them is null , return false
//check for left and right
//if there is left && right && same value then return true else false

class Solution {
public:
    // DFS
    // TC - O(N), SC - O(N)
    // Best Case Space : Balanced Tree - O(logN), Skew Tree - O(N)

    // bool isSameTree(TreeNode* p, TreeNode* q) {
    //     if(p == NULL && q == NULL){
    //         return true;
    //     }
    //     if((p != NULL && q == NULL) || (p == NULL && q != NULL)){
    //         return false;
    //     }

    //     bool left = isSameTree(p->left, q->left);
    //     bool right = isSameTree(p->right, q->right);

    //     if((p->val == q->val) && left && right){
    //         return true;
    //     } 
    //     return false;
    // }

    bool isSameTree(TreeNode* p, TreeNode* q){
        queue<TreeNode*>p1;
        queue<TreeNode*>q1;
        
        p1.push(p);
        q1.push(q);

        while(!p1.empty() && !q1.empty()){
            TreeNode* frontp = p1.front();
            TreeNode* frontq = q1.front();

            p1.pop();
            q1.pop();

            if(frontp == NULL && frontq == NULL) continue;
            if(!frontp || !frontq || frontp->val!=frontq->val){
                return false;
            }
            p1.push(frontp->left);
            p1.push(frontp->right);
            q1.push(frontq->left);
            q1.push(frontq->right);
        }
        return true;
    }
};
