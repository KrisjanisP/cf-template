#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll f(ll l, ll r){
    return l*r;
}

int main() {
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll a[n];
        ll ans=0;
        for(ll& x: a) cin>>x;
        for(ll i=0;i<n;i++){
            ll left[n+1], right[n+1];
            memset(left, 0, sizeof(left));
            memset(right, 0, sizeof(right));
            for(ll j=i+2;j<n;j++) right[a[j]]++;
            ll cur=0;
            for(ll j=i+2;j<n-1;j++){
                cur-=f(left[a[j]],right[a[j]]);
                right[a[j]]--;
                cur+=f(left[a[j]],right[a[j]]);

                cur-=f(left[a[j-1]],right[a[j-1]]);
                left[a[j-1]]++;
                cur+=f(left[a[j-1]],right[a[j-1]]);

                if(a[i]==a[j]){
                    ans += cur;
                }
            }
        }
        cout<<ans<<endl;
    }
}