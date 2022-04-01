#include<bits/stdc++.h>
#define ll long long
#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

///to be done using struct and in java as well

int main()
{
    vector<pair<int,pair<int,int> > > v;
    int n,k,tod,after,diff,ans=0;
    cin>>n>>k;
    int today[n+5];
    for(int i=0;i<n;i++)
    {
        cin>>today[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>after;
        v.pb(mp(today[i]-after,mp(today[i],after)));
    }
    sort(v.begin(),v.end());
    int kitty=0;
    for(int i=0;i<v.size();i++)
    {
        diff=v[i].f;
        tod=v[i].s.f;
        after=v[i].s.s;
        if(diff<=0||kitty<k)
            {ans+=tod;kitty++;}
        else
            ans+=after;
    }
    cout<<ans<<'\n';

    return 0;
}
