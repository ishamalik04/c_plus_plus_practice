// create  binary tree from level order
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
void buildfromlevelorder(node*&root)
{
    queue<node*> q;
    cout<<"enter data: "<<endl;
    int data;
    cin>>data;
    root=new node(data);
    q.push(root);
    while(!q.empty())
    {
        node* temp=q.front();
        q.pop();
        cout<<"enter left data  "<<endl;
        int leftdata;
        cin>>leftdata;
        if(leftdata!=-1)
        {
            temp->left=new node(leftdata);
            q.push(temp->left);
        }
        cout<<"enter right data "<<endl;
        int righttdata;
        cin>>righttdata;
        if(righttdata!=-1)
        {
            temp->right=new node(righttdata);
            q.push(temp->right);
        }
    }
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
int main()
{
    node*root=NULL;
    buildfromlevelorder(root);
    cout<<"level order traversal of tree is: "<<endl;
    levelordertraversal(root);
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






















