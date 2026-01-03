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
        string s; cin >> s;
        int ans = 0;
        if(s[0] == 'u') {
            ans++;
            s[0] = 's';
        }
        if(s[s.size()-1] == 'u') {
            ans++;
            s[s.size()-1] = 's';
        }
        for(int i = 1; i < s.size()-1; i++) {
            if(s[i] == 'u') {
                if(s[i-1] != 's') {
                    ans++;
                    s[i-1] = 's';
                }
                if(s[i+1] != 's') {
                    ans++;
                    s[i+1] = 's';
                }
            }
        }
        cout << ans << endl;
    }
}
