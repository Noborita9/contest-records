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
    vec<ll> A(n); L(i,0,n) cin >> A[i];
    ll a = A[0];
    ll b = A[1];
    ll y = - ((b - (2 * a)) / (n + 1));
    ll x = (a - (n * y));
    // cout << x << " " << y << "\n";
    if (x < 0 || y < 0) {
        cout << "NO\n";
        return;
    }
    L(i,0,n){
        int I = i + 1;
        int CI = n - i;
        if (I * x + CI * y != A[i]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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