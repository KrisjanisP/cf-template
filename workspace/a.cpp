#include <bits/stdc++.h>
#define pb push_back
#define in insert

using namespace std;
using ll = long long;
using ii = pair<ll,ll>;
using vi = vector<ll>;

const ll N=2e5;

ll n, m;
vi adj[N];
bool vis[N];
vector<ii> edges;
vi ord;
ll pos[N];

void dfs(ll u){
    vis[u]=true;
    for(ll v:adj[u]) if(!vis[v]) dfs(v);
    ord.pb(u);
}

int main() {
    ios_base::sync_with_stdio(false);

    ll t; cin>>t;
    while(t--){
        cin>>n>>m;
        edges.clear();
        for(ll i=0;i<n;i++) adj[i].clear();
        for(ll i=0;i<m;i++){
            ll t, a, b;
            cin>>t>>a>>b;
            a--, b--;
            if(t==1) adj[a].pb(b);
            else edges.pb({a,b});
        }
        ord.clear();
        memset(vis, 0, sizeof(vis));
        for(ll i=0;i<n;i++) if(!vis[i]) dfs(i);
        reverse(ord.begin(), ord.end());
        for(ll i=0;i<n;i++) pos[ord[i]]=i;
        bool bad = false;
        for(ll i=0;i<n;i++){
            for(ll v:adj[i]){
                if(pos[v]<pos[i]) bad=true;
            }
        }
        if(bad) cout<<"NO\n";
        else{
            cout<<"YES\n";
            for(ii e:edges){
                if(pos[e.first]<pos[e.second]) cout<<e.first+1<<" "<<e.second+1<<"\n";
                else cout<<e.second+1<<" "<<e.first+1<<"\n";
            }
            for(ll i=0;i<n;i++)
                for(ll v:adj[i])
                    cout<<i+1<<" "<<v+1<<"\n";
        }

    }
}