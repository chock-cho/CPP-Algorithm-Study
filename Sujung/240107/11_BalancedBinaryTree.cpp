/* Balanced Binary Tree - dfs로 풀이하였습니다. */
// 높이를 구하는 함수를 세운 후, dfs를 이용하여 균형인지 체크해주었습니다.
class Solution {
public:
    int calcHeight(TreeNode *node){
        if(node == NULL) return 0;
        return max(calcHeight(node->left), calcHeight(node->right))+1;
    }
    bool DFS(TreeNode *node){
        if(node == NULL) return true;

        int left_height= calcHeight(node->left);
        int right_height= calcHeight(node->right);
        if(abs(left_height-right_height) > 1 || !DFS(node->left) || !DFS(node->right)) return false;
        return true;
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        return DFS(root);
    }
};
