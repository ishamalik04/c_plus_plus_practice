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
class ksumpath
{
    public:
    void sumk(node*root,int k)
    {
        vector<int>path;
        int count=0;
        solve(root,k,count,path);
        cout<<"no. of path whose sum is equal to "<<k<<"is: "<<count<<endl;
    }
    void solve(node*root,int k,int &count,vector<int>path)
    {
        if(root==NULL)
        {
            return;
        }
        path.push_back(root->data);
        solve(root->left,k,count,path);
        solve(root->right,k,count,path);
        int size=path.size();
        int sum=0;
        for(int i=size-1;i>=0;i--)
        {
            sum+=path[i];
            if(sum==k)
            {
                count++;
            }
        }
        path.pop_back();
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
    ksumpath obj;
    cout<<"enter sum: ";
    int k;
    cin>>k;
    obj.sumk(root,k);

}
