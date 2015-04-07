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

inline ll powMod(ll b, ll e, ll m){
    ll res = 1;
    for(; e; e >>= 1, b = b * b % m) if(e&1) res = res * b % m;
    return res;
}

bool solve(){
    int x, n; cin >> x >> n;
    constexpr int mod = 1000 * 1000 + 3;
    ll res = 0;
    rep(_, n){
        int a; cin >> a;
        (res += powMod(x, a, mod)) %= mod;
    }
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
