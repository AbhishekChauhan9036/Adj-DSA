#include<bits/stdc++.h>

using namespace std;

bool visited[6]={0};
//memset(visited,0,sizeof(visited));
vector<int> adj[6];

dfs(int u)
{
    cout<<u<<" ";
    visited[u]=true;
    for(int j=0;j<adj[u].size();j++)
    {
        if(visited[adj[u][j]]==false)
            {dfs(adj[u][j]);}
    }
}

int main()
{

  adj[1].push_back(0);
  adj[0].push_back(4);
  adj[1].push_back(2);
  adj[1].push_back(3);
  adj[1].push_back(4);
  adj[2].push_back(3);
  adj[3].push_back(4);

  for(int i=0;i<6;i++)
  {
      if(visited[i]==false)
        {dfs(i);}
  }





  return 0;
}
