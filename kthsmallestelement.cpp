class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int i=0;
        int ans=solve(root,k,i);
        return ans;
    }
    int solve(TreeNode*root,int k,int &i)
    {

        if(root==NULL)
        {
            return -1;
        }
        int left=solve(root->left,k,i);
        if(left!=-1)
        {
            return left;
        }
        i++;
        if(i==k)
        {
            return root->val;
        }
        return solve(root->right,k,i);
    }
};
