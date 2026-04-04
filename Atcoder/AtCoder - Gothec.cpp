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
    int m, d; cin >> m >> d;
    if((m == 1 and d == 7) or (m == 3 and d == 3) or (m == 5 and d == 5) or (m == 7 and d == 7) or (m == 9 and d == 9)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}   