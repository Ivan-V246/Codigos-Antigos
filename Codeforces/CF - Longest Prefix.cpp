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
        string a, b; cin >> a >> b;
        map <char, int> n2;
        for(auto x : b) {
            n2[x]++;
        }
        int ans = 0;
        for(auto x : a) {
            if(n2[x] > 0) {
                ans++;
                n2[x]--;
            } else{
                break;
            }
        }
        cout << ans << endl;
    }
}
