#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ll t;
    cin>>t;
    while(t--){
        ll n, k, z;
        cin>>n>>k>>z;
        ll a[n]; for(ll i=0;i<n;i++) cin>>a[i];
        ll ans=0;
        for(ll i=0;i<=z;i++){
            ll sum=0;
            for(ll j=0;j<=k-i-i;j++) sum+=a[j];
            // find the max pair sum till k-i-i
            ll mx=0;
            for(ll j=0;j<=k-i-i;j++)
                mx=max(mx, a[j]+a[j+1]);
            ans=max(ans, sum+mx*i);
        }
        cout<<ans<<endl;
    }
}