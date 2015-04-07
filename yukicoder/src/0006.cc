// どうせ 10 個以内に衝突するので, 尺取りするまでもない.
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

// returns prime list <= mx
vector<int> sieve(int mx){ //{{{
    vector<int> f(mx+1);
    rep(i, f.size()) f[i] = i;
    vector<int> res;
    for(int i = 2; i <= mx; ++i){
        if(f[i] == i){
            res.eb(i);
            for(int j = i + i; j <= mx; j += i){
                f[j] = 0;
            }
        }
    }
    return res;
} //}}}
// return primes l <= p < r
vector<ll> segsieve(ll L, ll R){ //{{{
    vector<int> ps = sieve(sqrt(R)+1);
    vector<ll> f(R-L+1);
    vector<ll> res;
    REP(i, L, R+1) f[i-L] = i;
    rep(i, ps.size()){
        int p = ps[i];
        ll j = L + (p-L%p)%p;
        if(j == p) j += p;
        while(j < R){
            f[j-L] = 0;
            j += p;
        }
    }
    REP(i, max(L, 2LL), R) if(f[i-L]) res.eb(i);
    return res;
} //}}}

bool solve(){
    int k, n;
    cin >> k >> n;
    vector<ll> ps = segsieve(k, n+1);
    pair<int, ll> res(0, 0);
    repsz(i, ps){
        array<int, 9> cnt = {};
        int j;
        for(j = 0; i+j < size(ps); ++j) if(cnt[ps[i+j]%9]++) break;
        chmax(res, make_pair(j, ps[i]));
    }
    cout << res.snd << endl;
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
