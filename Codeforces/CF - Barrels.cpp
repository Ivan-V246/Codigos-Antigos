#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f3f3f3f3f
#define ll long long
#define  int ll
#define op cin.tie(0); ios::sync_with_stdio(0);

signed main() { op
    int n, k; cin >> n >> k;
    vector <int> sla;
    for(int i = 0; i < n; i++) {
        int a; cin >> a;
        sla.emplace_back(a);
    }
    sort(sla.begin(), sla.end());
    int ans = 0;
    for(int i = n-1, j = k; j >= 0; i--,j--) {
        ans += sla[i];
    }
    cout << ans << endl;
}