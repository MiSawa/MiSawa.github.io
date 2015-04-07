// DAG なのでトポロジカル順序で DP.
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

struct E{
    int to, cost, time;
    E(int to, int cost, int time) : to(to), cost(cost), time(time){}
};
using G = vector<vector<E>>;

bool solve(){
    int n, c, e;
    cin >> n >> c >> e;
    G g(n);
    vector<int> s(e), t(e), y(e), m(e);
    for(auto &x : s) cin >> x;
    for(auto &x : t) cin >> x;
    for(auto &x : y) cin >> x;
    for(auto &x : m) cin >> x;
    rep(i, e) g[--s[i]].eb(--t[i], y[i], m[i]);

    vector<vector<int>> dp(n, vector<int>(c*3, 1<<30));
    dp[0][0] = 0;
    rep(u, n) rep(i, c+1) for(auto &e : g[u])
        chmin(dp[e.to][i+e.cost], dp[u][i] + e.time);
    int res = *min_element(begin(dp[n-1]), begin(dp[n-1])+c+1);
    if(res == (1<<30)) res = -1;
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
