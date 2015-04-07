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

template<typename T> std::vector<T> get_vec(size_t n){//{{{
    std::vector<T> res; res.reserve(n);
    for(size_t i = 0; i < n; ++i){ T x; std::cin >> x; res.emplace_back(x); }
    return res;
}//}}}

bool solve(){
    int n; cin >> n;
    auto a = get_vec<int>(n), b = get_vec<int>(n);
    b.insert(end(b), all(b));
    int res = numeric_limits<int>::max();
    rep(p, n){
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(aur x : a) pq.emplace(x, 0);
        int top = 0;
        rep(i, n){
            int level, battle;
            tie(level, battle) = pq.top(); pq.pop();
            pq.emplace(level + b[p+i]/2, ++battle);
            chmax(top, battle);
        }
        chmin(res, top);
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
