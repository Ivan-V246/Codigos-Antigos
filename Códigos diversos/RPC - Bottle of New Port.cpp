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
#define vi vector<int>
#define dbg(x) cout << #x << " " << x << endl;
const int MAXN = 1e3+5;

signed main() {
    int n, a, b, c, d; cin >> n >> a >> b >> c >> d;
    double tot = 0;
    double vinho = 0;
    if(a > c*n) {
        vinho = a -(c*n);
        tot += a-(c*n);
    }
    if(b > d*n) {
        tot += b-(d*n);
    }
    cout << fixed << setprecision(14) << ((vinho * 100)/tot) << endl;
}