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

vector<int> as;
vector<vector<int>> dp;
int ok(int i, int now, const int &total){
    if(now > total) return 0;
    int &res = dp[i][now];
    if(res >= 0) return res;
    if(i == as.size()) return res = total == now;
    return res = ok(i+1, now+as[i], total) or ok(i+1, now*as[i], total);
}
string dfs(int i, int now, const int &total){
    if(i == as.size()) return "";
    if(ok(i+1, now+as[i], total)) return "+" + dfs(i+1, now+as[i], total);
    else                          return "*" + dfs(i+1, now*as[i], total);
}

bool solve(){
    int n; cin >> n;
    int total; cin >> total;
    as.resize(n);
    for(aur a : as) cin >> a;
    dp.assign(n+1, vector<int>(total+1, -1));
    cout << dfs(1, as[0], total) << endl;
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
