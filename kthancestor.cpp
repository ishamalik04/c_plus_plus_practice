#include<iostream>
#include<queue>
#include<map>
#include<climits>
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
class kthancestor
{
    public:
    node*rv,*ans;
    node* solve(node*root,int& k,int& node)
    {
        if(!root)
        {
            return NULL;
        }
        if(root->data==node||(rv=solve(root->left,k,node))||(rv=solve(root->right,k,node)))
        {
            if(k==0)
            {
                cout<<"ans: "<<root->data<<endl;
                return NULL;
            }
            k--;
            return rv? rv:root;
        }
        return NULL;
    }
    void get(node*root,int k, int node)
    {
        ans=solve(root,k,node);
        if(ans)
        {
            cout<<"-1"<<endl;
        }
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

int main()
{
    node*root=NULL;
    root=buildtree(root);
    cout<<"level order traversal of tree is: "<<endl;
    levelordertraversal(root);
    cout<<endl;
    kthancestor obj;
    cout<<"enter k: ";
    int k,node;
    cin>>k;
    cout<<endl;
    cout<<"enter node: ";
    cin>>node;
    obj.get(root,k,node);

}
