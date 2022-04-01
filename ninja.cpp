#include<bits/stdc++.h>

using namespace std;

int main()
{
   int n,t;
   cin>>t;
   while(t--)
   {
       cin>>n;
       int p,wt;
       cin>>p>>wt;
       vector< pair<int,int> > v[n+5];
       int floor[n+5];
       int dest[105]={0};int wgt[105]={0};
       for(int i=1;i<n;i++)
       {
           cin>>floor[i];

       }
       for(int i=1;i<n;i++)
       {

           for(int j=1;j<=floor[i];j++)
           {
                 cin>>dest[j];
           }
           for(int j=1;j<=floor[i];j++)
           {
                 cin>>wgt[j];
           }
           for(int j=1;j<=floor[i];j++)
           {
                 v[i].push_back(make_pair(dest[j],wgt[j]));
                 v[dest[j]].push_back(make_pair(i,wgt[j]));
           }
       }
       int pob=0,cur_wt=0;///people on board
       int ff,ss,ans;
       bool flag=0;
       for(int i=1;i<n;i++)
       {
           sort(v[i].begin(),v[i].end());
           for(int j=0;j<v[i].size();j++)
           {


               ff=v[i][j].first;
               ss=v[i][j].second;
               if(ff<i) ///get lost
               {
                   cur_wt = max(0,cur_wt-ss);
                   pob--;
               }
               else if(ff==i) {}
               else
               {
                   cur_wt+=ss;
                   pob++;
               }
               ///cout<<i<<" "<<j<<" "<<pob<<" "<<cur_wt<<'\n';
                if(pob>p||cur_wt>wt)
                  {flag=1;break;}


           }
           if((pob>p||cur_wt>wt) || flag==1)
                  {ans=i;break;}
       }
       if(flag==1)
            cout<<ans<<'\n';
       else
            cout<<n<<'\n';

   }


  return 0;
}
