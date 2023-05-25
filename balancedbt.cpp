// check balanced binary tree
#include<iostream>
#include<queue>
using namespace std;
class node
{
    public:
    int data;
    node*left;
    node*right;
    node(int d)
    {
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};
node* buildtree(node*root)
{
    cout<<"enter data: "<<endl;
    int data;
    cin>>data;
    root=new node(data);
    if (data==-1)
    {
        return NULL;
    }
    cout<<"enter data for left of:  "<<data<<endl;
    root->left=buildtree(root->left);
    cout<<"enter data for right of:  "<<data<<endl;
    root->right=buildtree(root->right);
    return root;
}
class Solution {
public:
    bool isBalanced(node* root) {
        return isbalancedfast(root).first;
    }
    pair<bool,int> isbalancedfast(node*root)
    {
        if(root==NULL)
        {
            pair<bool,int>p=make_pair(true,0);
            return p;
        }
        pair<bool,int>left=isbalancedfast(root->left);
        pair<bool,int>right=isbalancedfast(root->right);
        bool leftans=left.first;
        bool rightans=right.first;
        bool diff = abs(left.second-right.second)<=1;
        pair<bool,int>ans;
        ans.second=max(left.second,right.second)+1;
        if(leftans && rightans && diff)
        {
            ans.first=true;
        }
        else
        {
            ans.first=false;
        }
        return ans;
    }
};

void levelordertraversal(node*root)
{
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        node*temp=q.front();
        q.pop();
        if(temp==NULL)
        {
            cout<<endl;
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout<<temp->data<<" ";
            if(temp->left)
            {
                q.push(temp->left);
            }
            if(temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

int height(node*root)
{
    if(root==NULL)
    {
        return 0;
    }
    int left=height(root->left);
    int right=height(root->right);
    int ans= max(left,right)+1;
    return ans;
}
int main()
{
    node*root=NULL;
    root=buildtree(root);
    cout<<"level order traversal of tree is: "<<endl;
    levelordertraversal(root);
    int h=height(root);
    cout<<"height of tree is : "<<h<<endl;
    cout<<endl;

    Solution obj;
    bool b=obj.isBalanced(root);
    cout<<"balanced or not: "<<b<<endl;
}






















