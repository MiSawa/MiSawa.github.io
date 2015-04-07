// 素因数分解して Nim.
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

vector<int> factorization(int n){
    vector<int> res;
    for(int p = 2; p * p <= n; ++p) if(n % p == 0){
        int e = 0;
        for(; n % p == 0; ++e, n /= p);
        res.emplace_back(e);
    }
    if(n != 1) res.emplace_back(1);
    return res;
}

bool solve(){
    int n;
    cin >> n;
    int nim = 0;
    for(auto &x : factorization(n)) nim ^= x;
    cout << (nim ? "Alice" : "Bob") << endl;
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
