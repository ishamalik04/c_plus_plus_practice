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
node* minvalue(node*root)
{
    node*temp=root;
    while(temp->left!=NULL)
    {
        temp=temp->left;
    }
    return temp;
}
node* maxvalue(node*root)
{
    node*temp=root;
    while(temp->right!=NULL)
    {
        temp=temp->right;
    }
    return temp;
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
bool searchinbst(node*root,int x)
{
    if(root==NULL)
    {
        return false;
    }
    if(root->data==x)
    {
        return true;
    }
    if(root->data>x)
    {
        return searchinbst(root->left,x);
    }
    else
    {
        return searchinbst(root->right,x);
    }
}
node* deletefrombst(node*root,int val)
{
    if(root==NULL)
    {
        return root;
    }
    if(root->data==val)
    {
        //0 child
        if(root->left==NULL && root->right==NULL)
        {
            delete root;
            return NULL;
        }
        //1 child(left)
        if(root->left!=NULL && root->right==NULL)
        {
            node*temp=root->left;
            delete root;
            return temp;
        }
        //1 child(right)
        {
            if(root->left==NULL && root->right!=NULL)
            {
                node*temp=root->right;
                delete root;
                return temp;
            }
        }
        //2 child
        if(root->left!=NULL &&  root->right!=NULL)
        {
            int mini=minvalue(root->right)->data;
            root->data=mini;
            root->right=deletefrombst(root->right,mini);
            return root;
        }
    }
    else if(root->data>val)
    {
        root->left=deletefrombst(root->left,val);
        return root;
    }
    else
    {
        root->right=deletefrombst(root->right,val);
        return root;
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
    int x;
    cout<<"enter node to search: ";
    cin>>x;
    bool y;
    y=searchinbst(root,x);
    if(y==0)
    {
        cout<<"node not present"<<endl;
    }
    else
    {
        cout<<"node present";
    }
    node*min,*max;
    min=minvalue(root);
    max=maxvalue(root);
    int a;
    cout<<"enter node to delete: ";
    cin>>a;
    cout<<endl;
    cout<<"minimum value in bst is: "<<min->data<<endl;
    cout<<"maximum value in bst is: "<<max->data<<endl;
    root=deletefrombst(root,a);
    cout<<"printing the bst after deletion: "<<endl;
    levelordertraversal(root);
}























