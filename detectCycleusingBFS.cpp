// detect cycle in undirected graph using BFS
#include<bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    bool detect(int src,vector<int>adj[],int vis[])
    {
        vis[src]=1;
        queue<pair<int,int>>q;
        q.push({src,-1});
        while(!q.empty())
        {
            int node=q.front().first;
            int parent=q.front().second;
            q.pop();
            for(auto adjNode: adj[node])
            {
                if(!vis[adjNode])
                {
                    vis[adjNode]=1;
                    q.push({adjNode,node});
                }
                else if (parent!=adjNode)
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
    Solution obj;
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            if(obj.detect(i,adj,vis))
            {
                cout<<"CYCLE IS PReSENT ";
                return 0;
            }
        }
    }
    cout<<"CYCLE NOT PRESENT";
    return 0;
}
