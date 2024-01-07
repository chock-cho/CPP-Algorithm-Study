/* Lowest Common Ancestor of a Binary Search Tree - BST의 특성을 활용하여 재귀적으로 호출해주는 함수로 풀이하였습니다.*/
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root->val < p->val && root->val < q->val) 
            return lowestCommonAncestor(root->right, p, q);
        else if(root->val > p->val && root->val > q->val)
            return lowestCommonAncestor(root->left, p, q);
        else 
            return root;
    }
};
