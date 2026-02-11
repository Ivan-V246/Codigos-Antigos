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
        int a, b, c; cin >> a >> b >> c;
        int menor = min({a, b, c});
        if(menor == a) {
            cout << "First" << endl;
        }
        if(menor == b) {
            cout << "Second" << endl;
        }
        if(menor == c) {
            cout << "Third" << endl;
        }
    }
}
