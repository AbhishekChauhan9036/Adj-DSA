#include<bits/stdc++.h>

using namespace std;

queue<pair<int,int> > q;
int x[]={1,0,-1,0};
int y[]={0,-1,0,1};

int main()
{
     int vis[3][5];
     for(int i=0;i<3;i++)
     {
         for(int j=0;j<5;j++)
         {
             cin>>vis[i][j];
             if(vis[i][j]==2)
                q.push(make_pair(i,j));
         }
     }
     q.push(make_pair(-1,-1));
     int ans=0;
     while(!q.empty())
     {
         int curx,cury,destx,desty;
         while(q.front().first!=-1 && q.front().second!=-1)
         {
             curx=q.front().first;
             cury=q.front().second;
             cout<<curx<<" "<<cury<<" here "<<'\n';
             for(int i=0;i<4;i++)
             {
                 destx=curx+x[i];
                 desty=cury+y[i];
                 if(destx>=0 && destx<3 && desty>=0 && desty<5 && vis[destx][desty]==1)
                 {
                     vis[destx][desty]=2;
                     q.push(make_pair(destx,desty));
                 }
             }
             q.pop();
         }
         ans++;
         cout<<"here\n";
         q.pop();
         if(!q.empty())
            q.push(make_pair(-1,-1));
     }
     cout<<ans-1;



    return 0;
}
