#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt,tune=native")

using namespace std;
using ll = long long;

const ll N = 2e5;
set<ll> adj[N];
char r[N];
ll sz[N]; // rooted subtree size

void sz_dfs(ll v, ll p){
    sz[v]=1;
    for(ll u: adj[v]){
        if(u==p) continue;
        sz_dfs(u, v);
        sz[v] += sz[u];
    }
}

ll c_dfs(ll v, ll p, ll r) {
    ll up = sz[r]-sz[v];
    assert(up<=(sz[r]/2));
    for(ll u: adj[v]){
        if(u==p) continue;
        if(sz[u]<=(sz[r]/2)) continue;
        return c_dfs(u,v,r);
    }
    return v;
}

ll centroid(ll v) {
    // root tree at v, determine subtree sizes
    sz_dfs(v,v);

    return c_dfs(v,v,v);
}

// divide & conquer
void dc(ll v, char rank){
    ll c = centroid(v);
    // cout<<"dc: "<<v<<endl;
    // cout<<"centroid: "<<c<<endl;
    r[c] = rank;
    set<ll> tmp = adj[c];
    for(ll u: tmp){
        adj[u].erase(c);
        adj[c].erase(u);
        dc(u, rank-1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin>>n;
    for(ll i=0;i<n-1;i++){
        ll a, b;
        cin>>a>>b;
        a--, b--;
        adj[a].insert(b);
        adj[b].insert(a);
    }
    dc(0,'Z');
    for(ll i=0;i<n;i++){
        cout<<(char)('Z'-r[i]+'A')<<" ";
    }
}