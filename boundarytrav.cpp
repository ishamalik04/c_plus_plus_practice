//sum tree...for every node in tree, other than leaves,its value should be equal to the sum of its left subtree and right subtree
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
class boundarytrav
{
    public:
    void traverseleft(node*root,vector<int>&ans)
    {
        if(root==NULL||(root->left==NULL&&root->right==NULL))
        {
            return;
        }
        //ans.push_back(root->data);
        cout<<root->data<<" ";
        if(root->left)
        {
            traverseleft(root->left,ans);
        }
        else
        {
            traverseleft(root->right,ans);
        }
    }
    void traverseleaf(node*root,vector<int>&ans)
    {
        if(root==NULL)
        {
            return;
        }
        if(root->left==NULL && root->right==NULL)
        {
            cout<<root->data<<" ";
            //ans.push_back(root->data);
            return;
        }
        traverseleaf(root->left,ans);
        traverseleaf(root->right,ans);
    }
    void traverseright(node*root,vector<int>&ans)
    {
        if(root==NULL||(root->left==NULL&&root->right==NULL))
        {
            return;
        }
        if(root->right)
        {
            traverseright(root->right,ans);
        }
        else
        {
            traverseright(root->left,ans);
        }
        cout<<root->data<<" ";
        //ans.push_back(root->data);
    }
    void boundary(node*root)
    {
        vector<int>ans;
        if(root==NULL)
        {
            return ;
        }
        cout<<root->data<<" ";
        ans.push_back(root->data);
        traverseleft(root->left,ans);
        traverseleaf(root->left,ans);
        traverseleaf(root->right,ans);
        traverseright(root->right,ans);
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
void inorder(node*root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main()
{
    node*root=NULL;
    root=buildtree(root);
    cout<<"level order traversal of tree is: "<<endl;
    levelordertraversal(root);
    cout<<endl;
    cout<<"inorder order traversal of tree is: "<<endl;
    inorder(root);
    cout<<endl;
    boundarytrav obj;
    obj.boundary(root);

}
