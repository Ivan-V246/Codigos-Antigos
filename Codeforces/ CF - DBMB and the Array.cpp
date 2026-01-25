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


signed main() { op
    int t; cin >> t;
    while(t--) {
        int n, b, c; cin >> n >> b >> c;
        int sum = 0;
        for(int i = 0; i < n; i++) {
            int a; cin >> a;
            sum += a;
        }
        if(sum > b) {
            cout << "NO" << endl;
            continue;
        }

        int resto = b - sum;
        if(resto == 0 or resto%c == 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}
