#include <bits/stdc++.h>
#define pb push_back

using namespace std;
using ll = long long;
using ii = pair<ll,ll>;
using vi = vector<ll>;
using ld = long double;

int main() {
    ios_base::sync_with_stdio(false);
    
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin>>n;
        ll a[n];
        for(ll i=0;i<n;i++){
            cin>>a[i];
        }
        sort(a,a+n);
        ll res=0;
        for(ll i=0;i<n;i++){
            for(ll j=i+1;j<n;j++){
                res += __gcd(a[i],a[j])*(n-j-1);
            }
            cout<<res<<endl;
        }
        cout<<res<<"\n";
    }
}