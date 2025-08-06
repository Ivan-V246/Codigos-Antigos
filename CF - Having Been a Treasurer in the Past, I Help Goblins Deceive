#include <bits/stdc++.h>
 
#define ALL(x) x.begin(), x.end()
#define endl '\n'
 
#define F first
#define S second
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
 
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
#define int ll
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
const int MAXN = 5e3+5;
const int MOD = 1e9 +7;


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--) {
        int n; string b; cin >> n >> b;
        int n1 = 0, n2 = 0;
        for(int i = 0; i < n; i++) {
            if(b[i] == '-') {
                n1++;
            } else {
                n2++;
            }
        }
        int ans = 0;
        int mid = n1/2;
        ans = mid;
        if(n1%2 != 0) mid++;
        ans*= mid;
        cout << ans*n2 << endl;
    }
}
