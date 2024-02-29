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
    int maxx = 0;
private:
    void trav(TreeNode* node, int lvl, unordered_map<int,vector<int>> &mpp)
    {
        if(!node)   return;

        maxx = max(maxx,lvl);

        trav(node->left,lvl+1,mpp);
        mpp[lvl].push_back(node->val);
        trav(node->right,lvl+1,mpp);

    }

public:
    bool isEvenOddTree(TreeNode* root) {
        unordered_map<int,vector<int>> mpp;
        trav(root,0,mpp);

        if(root->val % 2 == 0)  return 0;

        for(int i=0;i<=maxx;i++)
        {
            auto arr = mpp[i];
            int n = arr.size();
            // cout<<i<<" ";
            if(i&1)
            {
                if(arr[0] % 2 != 0) return 0;
                for(int j=1;j<n;j++)
                {
                    if(arr[j] % 2 != 0 || arr[j-1] % 2 != 0)    return 0;
                    if(arr[j] >= arr[j-1])    return 0;
                }
            }
            else
            {
                if(arr[0] % 2 == 0) return 0;
                for(int j=1;j<n;j++)
                {
                    if(arr[j] % 2 == 0 || arr[j-1] % 2 == 0)    return 0;
                    if(arr[j] <= arr[j-1])    return 0;
                }
            }
        }
        return 1;
        
    }
};