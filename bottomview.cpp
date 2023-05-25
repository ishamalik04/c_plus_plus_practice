#include<iostream>
#include<queue>
#include<map>
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
class bottomview
{
    public:
    void bottomv(node*root)
    {
        vector<int>ans;
        if(root==NULL)
        {
            return;
        }
        map<int,int>topnode;
        queue<pair<node*,int>>q;
        q.push(make_pair(root,0));
        while(!q.empty())
        {
            pair<node*,int>temp=q.front();
            q.pop();
            node*frontnode=temp.first;
            int hd=temp.second;
            topnode[hd]=frontnode->data;
            if(frontnode->left)
            {
                q.push(make_pair(frontnode->left,hd-1));
            }
            if(frontnode->right)
            {
                q.push(make_pair(frontnode->right,hd+1));
            }
        }
        for(auto i: topnode)
        {
            ans.push_back(i.second);
        }
        for(int j=0;j<ans.size();j++)
        {
            cout<<ans[j]<<" ";
        }
        return ;
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
    bottomview obj;
    obj.bottomv(root);

}
