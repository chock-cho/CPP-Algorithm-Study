/* Invert Binary Tree - 레벨 순회 방식으로 풀이하였습니다. */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL) return NULL;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode *cur = q.front();
            q.pop();

            swap(cur->left, cur->right);

            if(cur->left) q.push(cur->left);
            if(cur->right) q.push(cur->right);
        }
        return root;
    }
};
