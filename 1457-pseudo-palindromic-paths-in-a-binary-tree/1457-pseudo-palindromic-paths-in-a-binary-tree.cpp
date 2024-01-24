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
    // set<vector<int>> ans;
    int cnt = 0;
    void inord(TreeNode* node, vector<int> anss)
    {
        if(!node)   return;

        anss[node->val - 1]++;

        if(!node->left && !node->right) //this means we have reached a leaf node
        {
            if(chk(anss))
            {
                // ans.insert(anss);
                cnt++;
            }
        }
        inord(node->left,anss);
        inord(node->right,anss);
    }

    bool chk(vector<int> &arr)
    {
        int cntOdd = 0;
        for(auto x:arr)
        {
            if(x&1) cntOdd++;
        }
        if(cntOdd > 1)  return 0;
        return 1;
    }
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        //so a basic thought process is that wehave to trave from the root to leaf\
        // so we can store every path from root to leaf in a arr
        // then we can check our condition on each of this arr
        // another interesting thught, as the data is from 1-9, we can store them in a arr of size 9
        // this way our chk fn will check if there are more than 1 ele whose tot occurence is odd
        // if not, it can be arranged to form a pallindrome, else it can not be done
        // store the arr matching our conditions in a set, return the size of the set in the end

        vector<int> anss(9,0);
        inord(root,anss);

        // return ans.size();
        return cnt;


        
    }
};