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

vector<int> factors(const int &n){//{{{
    vector<int> res;
    for(int i = 1; i * i <= n; ++i) if(n % i == 0){
        res.emplace_back(i);
        if(i * i != n) res.emplace_back(n / i);
    }
    return res;
}//}}}
int lcm(const int &a, const int &b){ return a / __gcd(a,b) * b; }

constexpr int N = 11000;
bool solve(){
    int n; cin >> n;
    vector<int> a(n); for(aur x : a) cin >> x;
    array<int, N> c = {};
    for(aur x : a) ++c[x];
    int last = a[0]; --c[last];

    array<vector<int>, N> fac;
    array<vector<int>, N> rev;
    for(aur x : a) if(fac[x].empty()){
        fac[x] = factors(x);
        for(auto &f : fac[x]) rev[f].emplace_back(x);
    }
    for(aur x : rev) sort(rall(x));

    vector<int> res;
    res.eb(last);
    rep(_, n-1){
        pair<int, int> nex = make_pair(numeric_limits<int>::max(), 0);
        for(aur f : fac[last]){
            while(!rev[f].empty() and !c[rev[f].back()]) rev[f].pop_back();
            if(rev[f].empty()) continue;
            chmin(nex, make_pair(lcm(last, rev[f].back()), rev[f].back()));
        }
        last = nex.snd;
        --c[last];
        res.eb(last);
    }
    rep(i, n) cout << res[i] << (i == n-1 ? "\n" : " ");
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
