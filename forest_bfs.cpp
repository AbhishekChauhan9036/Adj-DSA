#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> adj[n+5];
        vector<int> roots;
        int x,par;
        for(int i=0;i<n;i++)
        {
            cin>>par;
            if(par!=-1)
            {
                adj[par].push_back(i);
            }
            else
            {
                roots.push_back(i);
            }
        }
        queue< pair<int,int> > q;
        for(int i=0;i<roots.size();i++)
        {
            x=roots[i];
            q.push(make_pair(x,0));
        }
        int maxi=0;
        vector<int> out[n+5];
        vector<int>::iterator it;
        while(!q.empty())
        {
            int cur=q.front().first;
            int lev=q.front().second;
            out[lev].push_back(cur);
            maxi=lev;
            for(int j=0;j<adj[cur].size();j++)
            {
                int dest = adj[cur][j];
                q.push(make_pair(dest,lev+1));
            }
            q.pop();
        }
        for(int p=0;p<=maxi;p++)
        {
            sort(out[p].begin(),out[p].end());
            for(int c=0;c<out[p].size();c++)
                cout<<out[p][c]<<" ";
            cout<<'\n';
        }
        cout<<'\n';

    }
    return 0;
}
