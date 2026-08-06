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
    string str; cin >> str;
    vector <int> ps(m);
    int c = 0;
    for(int i = 0; i < m; i++) {
        if(str[i] == 'G') {
            if(i-d >= 0) {
                ps[i-d] += 1;
            } else {
                c++;
            }
            if(i+d+1 <= m-1) {
                ps[i+d+1] -= 1;
            }
        }
    }
    int ans = 0;
    for(auto x : ps) {
        c += x;
        ans += (c == 0);
    }
    cout << ans << endl;
}
