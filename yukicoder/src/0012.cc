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

constexpr int N = 5 * 1000 * 1000 + 1;
constexpr int D = 10;

array<int, N> sieve(){ //{{{
    static array<int, N> f;
    rep(i, f.size()) f[i] = i;
    f[0] = f[1] = 0;
    for(int i = 2; i < N; ++i) if(f[i] == i)
        for(int j = i + i; j < N; j += i) f[j] = 0;
    return f;
} //}}}

bool solve(){
    static auto is_prime = sieve();
    static array<int, N> t = {};
    rep(n, N) if(is_prime[n]) for(int m = n; m; m /= D) t[n] |= 1<<(m%D);

    int a = 0;
    {
        int n; cin >> n;
        rep(i, n){ int x; cin >> x; a |= 1<<x; }
    }

    int res = -1;
    for(int l = 1, r = 1; true; ){
        while(l < N and (t[l] & ~a)) ++l;
        if(l >= N) break;
        r = l;
        while(r < N-1 and (t[r+1] & ~a) == 0) ++r;
        int c = 0;
        REP(i, l, r+1) c |= t[i];
        if(c == a) chmax(res, r-l);
        l = r+1;
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
