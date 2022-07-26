#include<bits/stdc++.h>
using namespace std;
vector<int>graph[10005];
int visit[10005],in[10005],low[10005];
int timer=0;
set<int>s;
void dfs_art_point(int node,int parent)
{
    visit[node]=1;
    low[node]=in[node]=timer;
    timer++;
    int children=0;
    for(int child:graph[node])
    {
        if(child==parent)continue;
        if(visit[child]==1)
        {
            low[node]=min(low[node],in[child]);
        }
        else
        {
            dfs_art_point(child,node);
            low[node]=min(low[node],low[child]);
            if(low[child]>=in[node]&&parent!=-1)s.insert(node);
            children++;
        }
    }
    if(children>1&&parent==-1)s.insert(node);
}
int main()
{
    int t;cin>>t;
    for(int k=1;k<=t;k++)
    {
        for(int i=0;i<10005;i++)
        {
            visit[i]=0;
            low[i]=0;
            in[i]=0;
            graph[i].clear();
        }
        timer=0;
        s.clear();
        int n,m;cin>>n>>m;
        for(int i=1;i<=m;i++)
        {
            int a,b;cin>>a>>b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        dfs_art_point(1,-1);
        printf("Case %d: %d\n",k,s.size());

    }
}
