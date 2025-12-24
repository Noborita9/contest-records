#include <bits/stdc++.h>
using namespace std;

#define L(i, j, n) for (int i = (j); i < (int)n; i ++)
#define SZ(x) int((x).size())
#define ALL(x) begin(x),end(x)
#define vec vector
#define pb push_back
#define eb emplace_back

using ll = long long;
using ld = long double;
const ll oo = (ll)1e18;

struct DSU {
    vec<int> par, sz;
    vec<ll> cheap;
    DSU(int n): par(n), sz(n, 1), cheap(n, oo) {iota(ALL(par),0);}
    int find(int a){return a == par[a] ? a: par[a] = find(par[a]);}
    void join(int a, int b, ll w){
        a=find(a);b=find(b);
        if(a==b){
            cheap[a]=min(cheap[a],w);
            return;
        }
        if(sz[b]>sz[a])swap(a,b);
        par[b]=a;
        sz[a]+=sz[b];
        cheap[a]=min(cheap[a],min(cheap[b],w));

    }
};


void solve()
{
    int n, m; cin >> n >> m;
    DSU ds(n);
    vec<tuple<ll,int,int>> E;
    E.reserve(m);
    L(i,0,m){
        int u, v; ll w; cin >> u >> v >> w;
        E.eb(w,u-1,v-1);
    }
    sort(ALL(E));
    ll ans = oo;
    for (const auto &[w, u, v]: E){
        if (ds.find(u)==ds.find(v)){
            ds.join(u,v,w);
            if (ds.find(u)==ds.find(0)&&ds.find(0)==ds.find(n-1)){
                ans=min(ans,ds.cheap[ds.find(0)]+w);
            }
            continue;
        }
        ds.join(u,v,w);
        if (ds.find(u)==ds.find(0)&&ds.find(0)==ds.find(n-1)){
            ans=min(ans,ds.cheap[ds.find(0)]+w);
        }
    } 
    cout << ans << "\n";
}


int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int TT = 1;
    cin >> TT;
    while (TT--)
    {
        solve();
    }
}