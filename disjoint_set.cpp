//Disjoint Set
//if two components belong to same graph or not in constant time
#include<bits/stdc++.h>
using namespace std;
class DisjointSet
{
    vector<int>rank,parent;
    public:
    DisjointSet(int n)
    {
        rank.resize(n+1,0);
        parent.resize(n);
        for(int i=0;i<=n;i++)
        {
            parent[i]=i;
        }
    }
    int findUpar(int node)
    {
        if(node==parent[node])
        {
            return node;
        }
        return parent[node]=findUpar(parent[node]);
    }
    void unionByRank(int u,int v)
    {
        int ulp_u=findUpar(u);
        int ulp_v=findUpar(v);
        if(ulp_u==ulp_v)
        return;
        if(rank[ulp_u]<rank[ulp_v])
        {
            parent[ulp_u]=ulp_v;
        }
        else if(rank[ulp_v]<rank[ulp_u])
        {
            parent[ulp_v]=ulp_u;
        }
        else
        {
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }
    }
};
int main()
{
    DisjointSet ds(7);
    ds.unionByRank(1,2);
    ds.unionByRank(2,3);
    ds.unionByRank(4,5);
    ds.unionByRank(6,7);
    ds.unionByRank(5,6);
    if(ds.findUpar(3)==ds.findUpar(7))
    {
        cout<<"same\n";
    }
    else
    {
        cout<<"not same\n";
    }
    ds.unionByRank(3,7);
    if(ds.findUpar(3)==ds.findUpar(7))
    {
        cout<<"same\n";
    }
    else
    {
        cout<<"not same\n";
    }
    return 0;
}

















