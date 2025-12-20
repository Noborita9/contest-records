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
        vec<int> a(n);
        map<int, int> M;
        L(i,0,n) {
            cin >> a[i];
            M[a[i]] ++;
        }
        map<int, int> last;
        vec<int> next(n, n);
        for (int i = n - 1; i >= 0; i --) {
            if (last[a[i]]){
                next[i] = last[a[i]];
            }
            last[a[i]] = i;
            // cout << a[i] << " -> " << i << 
        }
        // L(i,0,n) cout << next[i] << " "; cout << "\n";
        set<int> MUST;
        int from = 0;
        int until = 0;
        int groups = 0;
        map<int, int> occ;
        
        while (1) {
            if (until == n || from == n) break;
            // cout << until << " - " << n << "\n";
            occ.clear();
            int nx = until;
            int hv = 0;
            for (int j = from; j <= until && nx != n; j ++) {
                occ[a[j]] ++;
                if (occ[a[j]] == 1 && MUST.find(a[j]) != MUST.end()){
                    hv ++;
                }
                nx = max(nx, next[j]);
                // cout << until - from << endl;
            }
            for (int j = from; j <= until && nx != n; j ++) {
                MUST.insert(a[j]);
            }
            occ.clear();
            while (hv < SZ(MUST) && from < n && nx != n) {
                // cout << hv << " - " << " from: " << from << " until " << until << " - " << SZ(MUST)<< "\n";
                
                occ[a[from]] ++;
                if (occ[a[from]] == 1){
                    hv ++;
                    MUST.insert(a[from]);
                }
                nx = max(nx, next[from]);
                from ++;
            }
            // cout << hv << " - " << until << " sz " << SZ(MUST) << "\n";
            from = max(until, from);
            until = nx;
            // cout << from << " - " << until << " nx " << nx << endl;
            if (hv == SZ(MUST) || nx == n){
                groups ++;
            }
        }

        cout << groups << "\n";
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