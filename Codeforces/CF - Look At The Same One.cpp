#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f3f3f3f3f
#define ll long long
#define  int ll
#define op cin.tie(0); ios::sync_with_stdio(0);

signed main() { op
    int n; cin >> n;
    string sol; cin >> sol;
    int r = 0;
    vector <int> contar(n), contal(n);
    for(int i = n-1; i >= 0; i--) {
        contar[i] = r;
        if(sol[i] == 'R') r++;
    }
    int l = 0;
    for(int i = 0; i < n; i++) {
        contal[i] = l;
        if(sol[i] == 'L') l++;
    }
    int ans = INF;
    for(int i = 0; i < n; i++) {
        ans = min(ans, contar[i]+contal[i]);
    }
    cout << ans << endl;
}