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
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        if(n%2 == 0) {
            cout << n << " ";
        } else {
            cout << n-1 << " ";
        }
        for(int i = 2; i <= n-1; i++) {
            if(i%2 == 0) {
                cout << i+1 << " ";
            } else {
                cout << i-1 << " ";
            }
        }
        cout << 1 << endl;
    }
}   