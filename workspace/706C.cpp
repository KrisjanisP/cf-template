#include <bits/stdc++.h>

using ll = long long;
using namespace std;

const ll INF=1e18;

string rev(string s){
    reverse(s.begin(), s.end());
    return s;
}

int main() {
    ll n;
    cin>>n;
    ll c[n];
    for(ll& x: c) cin>>x;
    string a[n];
    for(string& x: a) cin>>x;
    string a_rev[n];
    for(ll i=0;i<n;i++) a_rev[i]=rev(a[i]);
    
    // price for previous not reversed, price for previous reversed
    vector<ll> dp[2]={{0,c[0]},{0,0}};
    for(ll i=1;i<n;i++){
        dp[i%2]={INF,INF};
        if(dp[(i+1)%2][0]!=INF){
            if(a[i]>=a[i-1]) dp[i%2][0]=min(dp[i%2][0], dp[(i+1)%2][0]);
            if(a_rev[i]>=a[i-1]) dp[i%2][1]=min(dp[i%2][1], dp[(i+1)%2][0]+c[i]);
        }
        if(dp[(i+1)%2][1]!=INF){
            if(a[i]>=a_rev[i-1]) dp[i%2][0]=min(dp[i%2][0], dp[(i+1)%2][1]);
            if(a_rev[i]>=a_rev[i-1]) dp[i%2][1]=min(dp[i%2][1], dp[(i+1)%2][1]+c[i]);
        }
    }
    
    ll res = min(dp[(n-1)%2][0],dp[(n-1)%2][1]);
    if(res==INF) cout<<-1<<endl;
    else cout<<res<<endl;
}