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

const int N = 2e5 + 10;
ll p2[N];
const ll MOD = (ll)1e9+7;

void solve()
{
    int n; cin >> n;
    vec<vec<int>> g(n);
    vec<int> depth(n), par(n, - 1);
    L(i, 1, n ){
        int u, v; cin >> u >> v;
        u --; v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    auto go = [&](auto && dfs, int u) -> void {
        for (int v: g[u]) if (v != par[u]) {
            par[v] = u;
            depth[v] = depth[u] + 1;
            dfs(dfs, v);
        }
    };
    auto lca = [&](auto && dfs, int u, int v) -> int {
        if (u == v) return u;
        if (depth[u] > depth[v]) {
            return dfs(dfs, par[u], v);
        } else return dfs(dfs, u, par[v]);
    };
    depth[0] = 1;
    go(go, 0);
    vec<int> leaf;
    L(i,1,n) if (SZ(g[i]) == 1) leaf.pb(i);
    if (SZ(leaf) > 2){
        cout << "0\n";
        return;
    }
    if (SZ(leaf) == 1) {
        cout << p2[depth[leaf[0]]] << "\n";
        return;
    }
    int x = leaf[0];
    int y = leaf[1];
    int ca = lca(lca, x, y);
    if (depth[x] > depth[y]) swap(x, y);
    if (depth[x] == depth[y]) {
        cout << ((2ll * p2[depth[ca]]) % MOD) <<"\n";
        return; 
    }
    ll base = p2[depth[ca]];
    base *= (p2[depth[y] - depth[x]] + p2[depth[y] - depth[x] - 1]) % MOD;
    base %= MOD;
    cout << base << "\n";
}


int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int TT = 1;
    p2[0] = 1;
    L(i, 1, N){
        p2[i] = (p2[i - 1] * 2ll) % MOD;
    }
    cin >> TT;
    while (TT--)
    {
        solve();
    }
}