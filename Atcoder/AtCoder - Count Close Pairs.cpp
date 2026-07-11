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
    int l = 1, r = 2;
    int ans = 0;
    string a;
    while(r < n) {
        cout << "? " << l << " " << r << endl;
        cout.flush();
        cin >> a;
        if(a == "Yes") {
            ans += r-l;
            r++;
        } else {
            l++;
            if(l == r) r++;
        }
    }
    cout << "? " << l << " " << n << endl;
    cout.flush();
    cin >> a;
    if(a == "Yes") ans += n-l;
    while(a == "No") {
        l++;
        if(l == n) break;
        cout << "? " << l << " " << n << endl;
        cout.flush();
        cin >> a;
        if(a == "Yes") ans += n-l;
    }
    cout << "! " << ans << endl;
    cout.flush();
}
