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
    int n, S;
    cin >> n >> S;
    vector<int> p(n); for(aur x : p) cin >> x;
    unordered_map<int, vector<int>> H, L;
    int h = n/2, l = n-h;
    rep(A, bit(h)){
        int s = 0;
        rep(i, h) if(A>>i&1) s += p[i];
        H[s].emplace_back(A);
    }
    rep(A, bit(l)){
        int s = 0;
        rep(i, l) if(A>>i&1) s += p[i+h];
        L[s].emplace_back(A<<h);
    }
    vector<vector<int>> res;
    for(aur x : H) for(aur a : x.snd) for(aur b : L[S - x.fst]){
        vector<int> v;
        rep(i, n) if((a|b)>>i&1) v.emplace_back(i+1);
        res.emplace_back(v);
    }
    sort(all(res));
    for(aur x : res) repsz(i, x) cout << x[i] << (i == x.size()-1 ? "\n" : " ");
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
