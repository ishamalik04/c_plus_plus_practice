//create binary search tree
//search in bst
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
node* insertinbst (node* &root,int d)
{
    if(root==NULL)
    {
        root=new node(d);
        return root;
    }
    if(d>root->data)
    {
        root->right=insertinbst(root->right,d);
    }
    else
    {
        root->left=insertinbst(root->left,d);
    }
    return root;
}
void takeinput(node* &root)
{
    int data;
    cin>>data;
    while(data!=-1)
    {
        insertinbst(root,data);
        cin>>data;
    }
}
node* find(node*& root,int& p,int& q)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(root->data<p && root->data<q)
    {
        return find(root->right,p,q);
    }
    if(root->data>p && root->data>q)
    {
        return find(root->left,p,q);
    }
    return root;
}

void lowestcommancesbst(node*root)
{
    node*ans;
    int p,q;
    cout<<"enter node1 , node2"<<endl;
    cin>>p>>q;
    ans=find(root,p,q);
    cout<<"ans: "<<ans->data;
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

int main()
{
    node*root=NULL;
    cout<<"enter data to insert in bst: ";
    takeinput(root);
    cout<<endl;
    cout<<"printing the bst: "<<endl;
    levelordertraversal(root);
    lowestcommancesbst(root);

}























