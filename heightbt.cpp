// height of binary tree
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
void preorder(node*root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(node*root)
{
    if(root==NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
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
    cout<<"inorder order traversal of tree is: "<<endl;
    inorder(root);
    cout<<endl;
    cout<<"preorder traversal of tree is: "<<endl;
    preorder(root);
    cout<<endl;
    cout<<"postorder traversal of tree is: "<<endl;
    postorder(root);
}






















