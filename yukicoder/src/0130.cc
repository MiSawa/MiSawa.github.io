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

template<typename It>
int dfs(It b, It e, int d = 30, int offset = 0){
    if(next(b) == e) return 0;
    It m = lower_bound(b, e, offset | bit(d));
    if(e == m) return dfs(b, m, d-1, offset);
    if(b == m) return dfs(m, e, d-1, offset | bit(d));
    return min(dfs(b, m, d-1, offset), dfs(m, e, d-1, offset | bit(d))) + bit(d);
}

bool solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(aur x : a) cin >> x;
    sort(all(a)); a.erase(unique(all(a)), end(a));
    cout << dfs(all(a)) << endl;
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
