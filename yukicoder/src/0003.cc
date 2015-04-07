// bfs するだけ.
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
    int n;
    cin >> n;
    vector<int> d(n+1, bit(30));
    queue<int> q;
    q.emplace(1); d[1] = 1;
    while(!q.empty()){
        int u = q.front(); q.pop();
        int t = __builtin_popcount(u);
        if(u-t >  0) if(chmin(d[u-t], d[u]+1)) q.emplace(u-t);
        if(u+t <= n) if(chmin(d[u+t], d[u]+1)) q.emplace(u+t);
    }
    if(d[n] == bit(30)) d[n] = -1;
    cout << d[n] << endl;
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
