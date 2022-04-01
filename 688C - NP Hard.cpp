#include<bits/stdc++.h>
#define ll long long
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define MAX 2000

using namespace std;
vector<int> adj[100005];
int mark[100005];
vector<int> vc[2];

bool flag=0;
void dfs(int src, bool color)
{
    mark[src]=color;
    vc[color].push_back(src);

    for(int i=0;i<adj[src].size();i++)
    {
        int dest = adj[src][i];
        if(mark[dest]==-1)
            dfs(dest,1-color);
        else if(mark[dest]==color)
            {flag=1;}
        else
        {

        }


    }
}

int main()
{
    int n,m,u,v;
    cin>>n>>m;
    memset(mark,-1,sizeof mark);
    for(int i=0;i<m;i++)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1;i<=n;i++)
    {
        if(mark[i]==-1 && adj[i].size()>0)
            dfs(i,0);
    }


    /*cout<<"MARK"<<'\n';
    for(int i=1;i<=n;i++)
    {
        cout<<mark[i]<<" ";
    }
    cout<<'\n';*/
    if(flag==1)
        {cout<<-1<<'\n';return 0;}
    for(int i=0;i<2;i++)
    {
        cout<<vc[i].size()<<'\n';
        for(int j=0;j<vc[i].size();j++)
            cout<<vc[i][j]<<" ";
        cout<<'\n';
    }
    return 0;
}
