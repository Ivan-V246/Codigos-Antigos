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
        int n; cin >> n;
        int a; cin >> a;
        bool flag = 0;
        int ant = a;
        for(int i = 1; i < n; i++) {
            cin >> a;
            if(ant > a) flag = 1;
            ant = a;
        }
        if(flag) {
            cout << 1 << endl;
        } else {
            cout << n << endl;
        }
    }
}