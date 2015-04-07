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

struct UnionFind{ //{{{
    vector<int> par;
    int n, cnt;
    UnionFind(const int &x=0){init(x);}
    void init(const int &x){par.assign(cnt = n = x, -1);}
    inline int find(const int &x){ return par[x]<0 ? x : par[x] = find(par[x]); }
    inline bool same(const int &x, const int &y){ return find(x) == find(y); }
    inline bool unite(int x, int y){
        if((x = find(x)) == (y = find(y))) return false;
        --cnt;
        if(par[x] > par[y]) swap(x, y);
        par[x] += par[y];
        par[y] = x;
        return true;
    }
    inline int count() const { return cnt; }
    inline int count(int x){ return -par[find(x)]; }
};
//}}}

bool solve(){
    int n;
    cin >> n;
    vector<int> l(n), s(n);
    rep(i, n) cin >> l[i] >> s[i];
    rep(i, n) --s[i];

    vector<vector<int>> g(n, vector<int>(n, numeric_limits<int>::max()/3));
    rep(u, n) g[u][u] = 0;
    rep(u, n) g[u][s[u]] = -1;
    rep(k, n) rep(i, n) rep(j, n) chmin(g[i][j], g[i][k] + g[k][j]);

    UnionFind uf(n);
    rep(u, n) if(g[u][u] < 0) rep(v, n) if(g[u][v] < 0) uf.unite(u, v);

    vector<int> mn(n, numeric_limits<int>::max()/2);
    rep(u, n) if(g[u][u] < 0) chmin(mn[uf.find(u)], l[u]);

    int res = accumulate(all(l), 0);
    rep(u, n) if(g[u][u] < 0 and uf.find(u) == u) res += mn[u];
    cout << res / 2.0 << endl;
    return true;
}
signed main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << std::fixed << std::setprecision(1);
    solve();
    return 0;
}
// vim:set foldmethod=marker commentstring=//%s:
