#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ALL(x) x.begin(), x.end()
#define DBG(x) cout << #x << " = " << x << endl;
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())
#define endl '\n'
#define F first
#define S second
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f



using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
#define int ll
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

#define ordered_set tree<os_type, null_type,less<os_type>, rb_tree_tag,tree_order_statistics_node_update>


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m; cin >> n >> m;
    vi lista(n+1, 0);
    for(int i = 1; i <= n; i++) {
        cin >> lista[i];
    }
    while(m--) {
        int a; cin >> a;
        int l = 1, r = n;
        int ans = INFLL;
        bool f = 0;
        while(l <= r) {
            int mid = l + (r-l)/2;
            if(lista[mid] >= a) {
                ans = min(ans, mid);
                f = 1;
                r = mid-1;
            } else {
                l = mid+1;
            }
        }
        if(f) {
            cout << ans << endl;
        } else {
            cout << n+1 << endl;
        }
    }
    return 0;
}