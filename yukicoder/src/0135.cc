#include <bits/stdc++.h>
using namespace std;

bool solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &x : a) cin >> x;
    sort(begin(a), end(a));
    a.erase(unique(begin(a), end(a)), end(a));
    adjacent_difference(begin(a), end(a), begin(a));
    cout << (a.size() == 1 ? 0 : *min_element(next(begin(a)), end(a))) << endl;
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
