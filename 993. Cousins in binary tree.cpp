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
    int solve(TreeNode*root,int x,int d,int &p1,int p)
    {
        if(root==NULL)return 0;
        if(root->val==x)
        {
            p1=p;
            return d;
        }
        int k1=solve(root->left,x,d+1,p1,root->val);
        if(k1!=0)return k1;
        int k2=solve(root->right,x,d+1,p1,root->val);
        if(k2!=0)return k2;
        return 0;
    }
    bool isCousins(TreeNode* root, int x, int y) {
        int d1=0,d2=0,p1=-1,p2=-1;
        d1=solve(root,x,0,p1,0);
        d2=solve(root,y,0,p2,0);
        //cout<<d1<<" "<<d2<<" "<<p1<<" "<<p2<<endl;
        if(d1==d2&&p1!=p2)return true;
        return false;
    }
};