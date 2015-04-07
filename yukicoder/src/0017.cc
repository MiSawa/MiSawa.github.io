#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define rall(x) (x).rbegin(),(x).rend()
#define REP(i,b,n) for(int i=(int)(b);i<(int)(n);++i)
#define rep(i,n) REP(i,0,n)
#define repsz(i,v) rep(i,(v).size())
#define aur auto&
#define bit(n) (1LL<<(n))
#define eb emplace_back
#define mt make_tuple
#define fst first
#define snd second
using namespace std;
typedef long long ll;
//#define int long long
template<class C>int size(const C &c){ return c.size(); }
template<class T>bool chmin(T&a,const T&b){if(a<=b)return false;a=b;return true;}
template<class T>bool chmax(T&a,const T&b){if(a>=b)return false;a=b;return true;}

bool solve(){
    int n; cin >> n;
    vector<int> s(n); for(aur x : s) cin >> x;
    vector<vector<int>> g(n, vector<int>(n, numeric_limits<int>::max()/4));
    rep(u, n) g[u][u] = 0;
    {
        int m; cin >> m;
        rep(_, m){
            int a, b, c; cin >> a >> b >> c;
            g[a][b] = g[b][a] = min(g[a][b], c);
        }
    }
    rep(k, n) rep(i, n) rep(j, n) chmin(g[i][j], g[i][k] + g[k][j]);
    int res = numeric_limits<int>::max();
    rep(i, n) if(i != 0 and i != n-1) rep(j, n) if(j != 0 and j != n-1 and i != j)
        chmin(res, s[0] + g[0][i] + s[i] + g[i][j] + s[j] + g[j][n-1] + s[n-1]);
    cout << res << endl;
    return true;
}
signed main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << std::fixed << std::setprecision(10);
    solve();
    return 0;
}
// vim:set foldmethod=marker commentstring=//%s:
