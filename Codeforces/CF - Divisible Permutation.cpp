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
        int ans[n];
        ans[n-1] = n;
        bool flag = 1;
        for(int i = n-1; i >= 1; i--) {
            if(flag) {
                ans[i-1] = ans[i]-i; 
            } else {
                ans[i-1] = ans[i]+i;
            }
            flag = !flag;
        }
        for(auto x : ans) {
            cout << x <<  " ";
        }
        cout << endl;
    }
}
