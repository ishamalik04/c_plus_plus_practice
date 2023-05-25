class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        int postorderindex=n-1;
        map<int,int>nodetoindex;
        createmapping(inorder,nodetoindex,n);
        TreeNode*ans=solve( inorder,postorder,postorderindex,0,n-1,n,nodetoindex);
        return ans;

    }
    TreeNode* solve(vector<int>& inorder,vector<int>& postorder, int& index, int inorderstart,int inorderend,int n,map<int,int>&nodetoindex)
    {
        if(index<0||inorderstart>inorderend)
        {
            return NULL;
        }
        int element=postorder[index--];
        TreeNode* root=new TreeNode(element);
        int position=nodetoindex[element];
        root->right=solve(inorder,postorder,index,position+1,inorderend,n,nodetoindex);
        root->left=solve(inorder,postorder,index,inorderstart,position-1,n,nodetoindex);
        return root;
    }
    void createmapping(vector<int>&inorder,map<int,int>&nodetoindex,int n)
    {
        for(int i=0;i<n;i++)
        {
            nodetoindex[inorder[i]]=i;
        }
    }

};
