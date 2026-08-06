#include <bits/stdc++.h>
using namespace std;
#define op ios::sync_with_stdio(false); cin.tie(NULL);
#define INF 0x3f3f3f3f
#define pii pair<int,int>
#define ll long long
#define mkp make_pair
#define endl '\n'
#define f first
#define s second
#define int long long
#define dbg(x) cout << #x << " " << x << endl;
const int MAXN = 1e6+5;

// map <int, bool> dp;
// vector <int> pot;
//
// bool solve(int atual) {
//     if(dp.count(atual) > 0) return dp[atual];
//
//     bool ans = 1;
//     for(auto x : pot) {
//         if (atual >= x) {
//             ans &= solve(atual - x);
//         }
//     }
//     ans = !ans;
//     return dp[atual] = ans;
// }


signed main() {
    int n; cin >> n;
    cout << (n%3 == 0 ? "PERDE" : "GANHA") << endl;
    // int v = 1;
    // dp[1] = 1;
    // pot.emplace_back(1);
    // for(int i = 0; ; i++) {
    //     v *= 2;
    //     dp[v] = 1;
    //     pot.emplace_back(v);
    //     if(v >= 1e18) break;
    // }
    // for(int i = 1; i <= 300; i++) {
    //     cout << i << " -> " << solve(i) << endl;
    // }
}
