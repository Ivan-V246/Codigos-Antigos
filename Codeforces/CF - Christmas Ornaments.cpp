#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f3f3f3f3f
#define ll long long
#define  int ll
#define op cin.tie(0); ios::sync_with_stdio(0);

signed main() {
    int n, a, b, c; cin >> n;
    vector <int> sla(3);
    for(auto &x: sla) cin >> x;

    sort(sla.begin(), sla.end());
    int mi = sla[0];
    int smi = sla[1];
    int tot = sla[0]+sla[1]+sla[2];
    int val = tot*(n/tot);
    int ans = (n/tot)*3;
    n-= val;
    if(n >= mi) {
        ans++;
        n -= mi;
    }
    if(n >= smi) {
        ans++;
    }
    cout << ans << endl;
}