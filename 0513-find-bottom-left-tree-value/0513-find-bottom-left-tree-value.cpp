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
    int maxx = -1;
    void trav(TreeNode* node,unordered_map<int,int> &mpp, int ty)
    {
        if(!node)   return;
        maxx = max(maxx,ty);

        trav(node->right,mpp,ty+1);
        mpp[ty] = node->val;
        trav(node->left,mpp,ty+1);

    }
    int findBottomLeftValue(TreeNode* root) {
        unordered_map<int,int> mpp;
        trav(root,mpp,0);
        return mpp[maxx];        
    }
};