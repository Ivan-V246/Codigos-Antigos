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
    int n, k; cin >> n >> k;
    int a; cin >> a;
    double fel = max(0LL, a-k+1);
    double tri = a-fel;
    for(int i = 1; i < n; i++) {
        cin >> a;
        double f = max(0LL, a-k+1);
        double t = a-f;
        double temp = t*fel;
        fel = (fel+tri)*f + temp;
        tri = tri*t;
    }
    double tot = fel+tri;
    double ans = fel / tot;
    cout << fixed << setprecision(10) << ans << endl;
}
