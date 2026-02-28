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
    int n; cin >> n;
    string ini, tar; cin >> ini >> tar;
    bool certo[n];
    for(int i = 0; i < n; i++) {
        certo[i] = (ini[i] == tar[i]);
    }
    int l = 0, r = n-1;
    bool flag = 0;
    int ans = 0;
    while(l <= r) {
        if(flag) {
            if(certo[l] and certo[r]) {
                ans++;
                l++;
                r--;
                flag = 0;
            } else if(!certo[l]) {
                l++;
            } else if(!certo[r]) {
                r--;
            }
        } else {
            if(!certo[l] and !certo[r]) {
                ans++;
                l++;
                r--;
                flag = 1;
            } else if(certo[l]) {
                l++;
            } else if(certo[r]) {
                r--;
            }
        }
    }
    cout << ans << endl;
}