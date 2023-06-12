//detect cycle in a directed graph using dfs
#include<bits/stdc++.h>
using namespace std;
class Solution
{
    private:
    bool dfscheck(int node,vector<int>adj[],int vis[],int pathVis[])
    {
        vis[node]=1;
        pathVis[node]=1;
        //traverse for adjacent nodes
        for(auto it: adj[node])
        {
            //when node is not visited
            if(!vis[it])
            {
                if(dfscheck(it,adj,vis,pathVis)==true)
                {
                    return true;
                }
            }
            //if node has previously visited but it has to be visited on same path
            else if(pathVis[it])
            {
                return true;
            }
        }
        pathVis[node]=0;
        return false;
    }
    public:
    bool isCyclic(int V,vector<int>adj[])
    {
        int vis[V];
        for(int i=0;i<V;i++)
        {
            vis[i]=0;
        }
        int pathVis[V];
        for(int i=0;i<V;i++)
        {
            pathVis[i]=0;
        }
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                if(dfscheck(i,adj,vis,pathVis)==true)
                {
                    return true;
                }
            }
        }
        return false;
    }
};
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>adj[n+1];
    for(int i=1;i<m+1;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        //adj[v].push_back(u);
    }
    for(int i=0;i<n+1;i++)
    {

        for(int j=0;j<adj[i].size();j++)
        {
            cout<<adj[i][j]<<" ";
        }
        cout<<"\n";
    }
    Solution obj;
    bool ans=obj.isCyclic(n,adj);
    if(ans)
    cout<<"YES CYCLE PRESENT";
    else
    cout<<"NO,CYCLE NOT PRESENT";
    return 0;
}
