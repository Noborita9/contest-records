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

void solve()
{
    int n; cin >> n;
    vec<int> a(n), b(n);
    L(i,0,n) cin >> a[i];
    L(i,0,n) cin >> b[i];
    int ans = -1;
    L(i,0,n){
        if (a[i] == b[i]){
            ans = i;
        }
    }
    set<int> u, d; // 
    for (int i = n - 2; i >= 0; i --) {
        if (u.find(a[i]) != u.end() || (d.find(b[i]) != d.end()) || (u.find(b[i]) != u.end()) || (d.find(a[i]) != d.end()) || (d.find(b[i]) != d.end()) || (u.find(a[i]) != u.end()) || a[i] == a[i + 1] || b[i] == b[i + 1]){//(u.find(b[i]) != u.end()) || (d.find(a[i]) != d.end()) || (d.find(b[i]) != d.end()) || (u.find(a[i]) != u.end())){
            // cout << "A: " << a[i] << " B: " << b[i] << 
            ans = max(i, ans);
            break;
        }
        u.insert(a[i + 1]);
        d.insert(b[i + 1]);
        a.swap(b);
    }

    cout << ans + 1 << "\n";
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