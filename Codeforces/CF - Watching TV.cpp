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
        map <int, int> freq;
        for(int i = 0; i < n; i++) {
            string s; int a; cin >> s >> a;
            freq[a]++;
        }
        int ans = 0;
        int resp = 0;
        for(auto x: freq) {
            if(x.s > ans) {
                ans = x.s;
                resp = x.f;
            }
        }
        cout << resp << endl;
    }
}
