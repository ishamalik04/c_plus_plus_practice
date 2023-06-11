//detect cycle in a directed graph using BFS
#include<bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    vector<int> topoSort(int V,vector<int>adj[])
    {
        int indegree[V];
        for(int i=0;i<V;i++)
        {
            indegree[i]=0;
        }
        for(int i=0;i<V;i++)
        {
           for(auto it: adj[i])
           {
               indegree[it]++;
           }
        }
        queue<int>q;
        for(int i=0;i<V;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        vector<int>topo;
        while(!q.empty())
        {
           int node=q.front();
           q.pop();
           topo.push_back(node);
           for(auto it:adj[node])
           {
               indegree[it]--;
               if(indegree[it]==0)
               {
                   q.push(it);
               }
           }
        }
        return topo;
    }
    bool isCyclic(int V,vector<int>adj[])
    {
        vector<int>ans=topoSort(V,adj);
        if(ans.size()==V)
        {
            return false;
        }
        else
        {
            return true;
        }
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
