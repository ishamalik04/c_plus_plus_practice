//bellman ford algorithm
#include<bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    vector<int> dijkstra(int V,vector<vector<int>>&edges,int S)
    {
        vector<int>dist(V,1e9);
        dist[S]=0;
        for(int i=0;i<V-1;i++)
        {
            for(auto it:edges)
            {
                int u=it[0];
                int v=it[1];
                int wt=it[2];
                if(dist[u]!=1e9 && dist[u]+wt<dist[v])
                {
                    dist[v]=dist[u]+wt;
                }
            }
        }
        for(auto it:edges)
        {
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            if(dist[u]!=1e9 && dist[u]+wt<dist[v])
            {
                return{-1};
            }
        }
        return dist;
    }
};
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
       int V,E;
       cin>>V>>E;
       vector<vector<int>>edges;
       for(int i=0;i<E;i++)
       {
           vector<int>temp;
           for(int j=0;j<3;j++)
           {
               int x;
               cin>>x;
               temp.push_back(x);
           }
           edges.push_back(temp);
       }
       int S;
       cin>>S;
       Solution obj;
       vector<int>ans=obj.dijkstra(V,edges,S);
       for(int i=0;i<V;i++)
       {
           cout<<ans[i]<<" ";
       }
       cout<<endl;
    }
    return 0;
}






















