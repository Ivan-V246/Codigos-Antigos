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
const int MAXN = 2e5+5;

signed main() { op
    int t; cin >> t;
    while(t--) {
        int n, k, x; cin >> n >> k >> x;
        int superior = n;
        int inferior = n-k;
        inferior++;
        int total = 0;
        if((superior - inferior) % 2 == 0) {
            total += inferior;
            inferior++;
        }
        total += (superior+inferior) * ((superior-inferior)+1)/2;

        int menores = 0;
        superior = k;
        inferior = 1;
        if((superior - inferior) % 2 == 0) {
            menores += inferior;
            inferior++;
        }
        menores += (superior+inferior) * ((superior-inferior)+1)/2;

        if(total >= x and x >= menores) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}
