#include<bits/stdc++.h>
#define ll long long
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define MAX 2000

using namespace std;
int n,m;
bool vis[52][52];
char arr[52][52];
int x[]={1,0,-1,0};
int y[]={0,-1,0,1};
bool flag=0;
void dfs(int row,int col, int fromr, int fromc, char color)
{
    vis[row][col]=1;
    for(int i=0;i<4;i++)
    {
        int destx=row+x[i];
        int desty=col+y[i];
        if(destx==fromr && desty==fromc)
        {

        }
        else
        {
            ///cout<<destx<<" "<<desty<<" "<<arr[destx][desty]<<'\n';
            if(destx>=0 && destx<n && desty>=0 && desty<m && arr[destx][desty]==color)
            {
                ///cout<<destx<<" "<<desty<<" "<<vis[destx][desty]<<'\n';
                if(vis[destx][desty]==1)
                    {flag=1;break;}
                else
                    dfs(destx,desty,row,col,color);
            }
            else
                continue;

        }
    }


}

int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    for(int i=0;i<1;i++)
    {
        char ch='A'+i;

        for(int j=0;j<n;j++)
        {
            for(int k=0;k<m;k++)
            {
                memset(vis,0,sizeof vis);
                ///cout<<"here\n";
                if(arr[j][k]==ch)
                    dfs(j,k,-2,-2,ch);
                if(flag==1)
                    break;
            }
            if(flag==1)
                break;
        }
        if(flag==1)
            break;

    }
    if(flag==1)
        cout<<"Yes\n";
    else
        cout<<"No\n";
    return 0;
}
