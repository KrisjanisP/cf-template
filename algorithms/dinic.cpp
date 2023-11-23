#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<ll,ll>;

namespace dinic {
    const ll N=1e5+5, INF=1e9;
    struct edge{ll v, c, f;};

    ll src, snk, h[N], ptr[N];
    vector<edge> edgs;

    vector<ll> g[N];

    void add_edge(ll u, ll v, ll c) {
        ll k=edgs.size();
        edgs.push_back({v,c,0});
        edgs.push_back({u,0,0});
        g[u].push_back(k);
        g[v].push_back(k+1);
    }

    void clear() {
        memset(h, 0, sizeof(h));
        memset(ptr,0,sizeof(ptr));
        edgs.clear();
        for(ll i=0;i<N;i++) g[i].clear();
        src=0;
        snk=N-1;
    }

    bool bfs() {
        memset(h, 0, sizeof(h));
        queue<ll> q;
        h[src]=1;
        q.push(src);
        while(!q.empty()){
            ll u=q.front();q.pop();
            for(ll i:g[u]){
                ll v=edgs[i].v;
                if(!h[v]&&edgs[i].f<edgs[i].c)
                    q.push(v),h[v]=h[u]+1;
            }
        }
        return h[snk];
    }

    ll dfs(ll u, ll flow){
        if(!flow or u==snk) return flow;
        for(ll &i=ptr[u];i<g[u].size();i++){
            edge &dir=edgs[g[u][i]],&rev=edgs[g[u][i]^1];
            ll v=dir.v;
            if(h[v]!=h[u]+1) continue;
            ll inc=min(flow,dir.c-dir.f);
            inc=dfs(v,inc);
            if(inc){
                dir.f+=inc,rev.f-=inc;
                return inc;
            }
        }
        return 0;
    }

    ll dinic(){
        ll flow=0;
        while(bfs()){
            memset(ptr,0,sizeof(ptr));
            while(ll inc=dfs(src,INF))
                flow += inc;
        }
        return flow;
    }

    vector<pair<ii,ll>> recover() {
        vector<pair<ii,ll>> res;
        for(ll i=0;i<edgs.size();i+=2){
            if(edgs[i].f>0){
                ll v=edgs[i].v;
                ll u=edgs[i^1].v;
                res.push_back({{u,v},edgs[i].f});
            }
        }
        return res;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    dinic::clear();

}