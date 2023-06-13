//DFS traversal of graph
#include<bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    void dfs(int node,vector<int>adj[],int vis[],vector<int>&ls)
    {
        vis[node]=1;
        ls.push_back(node);
        //traverse all its neighbours
        for(auto it: adj[node])
        {
            if(!vis[it])
            {
                dfs(it,adj,vis,ls);
            }
        }
    }
};
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>adj[n+1];
    int vis[n+1]={0};
    int start=3;
    vector<int>ls;
    for(int i=1;i<m+1;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=0;i<n+1;i++)
    {

        for(int j=0;j<adj[i].size();j++)
        {
            cout<<adj[i][j]<<" ";
        }
        cout<<"\n";
    }
    vector<int>ans;
    Solution obj;
    obj.dfs(start,adj,vis,ls);
    for(int i=0;i<ls.size();i++)
    {
        cout<<ls[i]<<" ";
    }
}
