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


signed main() { 
    int n; cin >> n;
    double ans = 0;
    for(int i = 2; i <= n; i++) {
        double a = i;
        double b = i-1;
        double pro = a*b;
        ans += pro/n;
    }
    cout << fixed << setprecision(10) << ans << endl;
}
