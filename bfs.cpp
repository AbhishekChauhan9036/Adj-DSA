#include<bits/stdc++.h>

using namespace std;
bool vis[6];

vector<int> adj[6];

void bfs(int u)
{
    queue<int> q;
    q.push(u);
    vis[u]=true;
    cout<<u<<" ";
    while(!q.empty())
    {
        int s=q.front();
        q.pop();
        for(int i=0;i<adj[s].size();i++)
        {
            if(adj[s][i]==false)
                {cout<<i<<" ";vis[i]=true;q.push(i);}

        }


    }

}



int main()
{
  memset(vis, 0 , sizeof(vis));
  adj[5].push_back(1);
  adj[0].push_back(2);
  adj[3].push_back(2);
  adj[4].push_back(5);
  adj[5].push_back(2);

  for(int i=0;i<6;i++)
  {
      if(vis[i]==false)
        bfs(i);
  }

  return 0;
}
