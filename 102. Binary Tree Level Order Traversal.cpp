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
    void solve(TreeNode* root,vector<vector<int>>&v1,int d)
    {
        if(root==NULL)return;
        if(d==v1.size())v1.push_back(vector<int>());
        v1[d].push_back(root->val);
        solve(root->left,v1,d+1);
        solve(root->right,v1,d+1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> v1;
        solve(root,v1,0);
        return v1;
    }
};