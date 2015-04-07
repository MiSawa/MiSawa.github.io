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

vector<int> ps;
vector<int> memo;
bool dfs(int n){
    int &res = memo[n];
    if(res >= 0) return res;
    if(n == 0 or n == 1) return res = true;
    for(aur p : ps){
        if(p > n) break;
        if(!dfs(n-p)) return res = true;
    }
    return res = false;
}

bool solve(){
    int n;
    cin >> n;
    memo.assign(n+10, -1);
    ps = sieve(n);
    cout << (dfs(n) ? "Win" : "Lose") << endl;
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
