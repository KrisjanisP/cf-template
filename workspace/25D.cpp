#include <bits/stdc++.h>
#define pb push_back

using namespace std;
using ll = long long;
using ii = pair<ll,ll>;

const ll N = 1000;

ll r[N];
ll root(ll v){
    if(r[v]==v) return v;
    return r[v]=root(r[v]);
}

void unite(ll a, ll b){
    a = root(a);
    b = root(b);
    r[b]=a;
}

int main() {
    ll n;
    cin>>n;
    for(ll i=0;i<n;i++) r[i]=i;

    vector<ii> remove, add;
    for(ll i=0;i<n-1;i++){
        ll a, b;
        cin>>a>>b;
        a--, b--;
        if(root(a)==root(b)) remove.pb({a+1, b+1});
        else unite(a,b);
    }


    set<ll> s;
    for (ll i = 0; i < n; i++) s.insert(root(i));

    auto it = s.begin();
    ll first = *it;
    it++;
    while (it != s.end()) {
        add.pb({first + 1, *it + 1}); // Connect distinct roots
        it++;
    }

    cout << remove.size() << endl;
    for (size_t i = 0; i < remove.size(); i++) {
        cout << remove[i].first << " " << remove[i].second << " " << add[i].first << " " << add[i].second << endl;
    }
    
}