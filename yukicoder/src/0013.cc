// こういうのは UnionFind 使うとやりやすい.
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
struct UnionFind2D{//{{{
    const int h, w;
    UnionFind uf;
    UnionFind2D(const int &h, const int &w) : h(h), w(w), uf(h*w){}
    inline int find(const int &x, const int &y){ return uf.find(x*w+y); }
    inline bool same(const int &x, const int &y, const int &xx, const int &yy){
        return find(x, y) == find(xx, yy); }
    inline bool unite(const int &x, const int &y, const int &xx, const int &yy){
        return uf.unite(x*w+y, xx*w+yy); }
    inline int count(){ return uf.count(); }
    inline int count(const int &x, const int &y){ return uf.count(x*w+y); }
};//}}}

bool solve(){
    int w, h; cin >> w >> h;
    UnionFind2D uf(h, w);
    vector<vector<int>> in(h, vector<int>(w));
    rep(i, h) rep(j, w) cin >> in[i][j];
    constexpr int dxy[2] = {0, 1};
    rep(i, h) rep(j, w) rep(dir, 2){
        int x = i + dxy[dir], y = j + dxy[1-dir];
        if(x < 0 or x >= h) continue;
        if(y < 0 or y >= w) continue;
        if(in[i][j] != in[x][y]) continue;
        if(!uf.unite(i, j, x, y)){ cout << "possible" << endl; return true; }
    }
    cout << "impossible" << endl;
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
