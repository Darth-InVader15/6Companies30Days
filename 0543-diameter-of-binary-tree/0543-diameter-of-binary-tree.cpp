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
private:
    int ans = 0;
    int solve(TreeNode* node)
    {
        if(!node)   return 0;

        int lt = 0, rt = 0;

        if(node->left) lt = 1 + solve(node->left);
        if(node->right) rt = 1 + solve(node->right);

        ans = max(ans, (lt+rt));
        return max(lt,rt);

    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        solve(root);
        return ans;
    }
};