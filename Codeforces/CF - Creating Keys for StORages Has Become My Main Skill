#include <bits/stdc++.h>
 
#define ALL(x) x.begin(), x.end()
#define endl '\n'
 
#define F first
#define S second
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
 
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
#define int ll
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
const int MAXN = 5e3+5;
const int MOD = 1e9 +7;


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--) {
        int n, x; cin >> n >> x;
        int sla = 0;
        int pro = 0;
        int tam = n;
        bool ok = 0;
        for(; tam > 1; tam--) {
            if((x | pro) == x) {
                cout << pro << " ";
                sla = (sla|pro);
                pro++;
            } else {
                ok = 1;
                break;
            }
        }
        if(ok) {
            cout << x << " ";
            tam--;
            while(tam--) {
                cout << 0 << " ";
            }
        } else {
            if((sla|pro) == x) {
                cout << pro << " ";
            } else {
                cout << x << " ";
            }
        }
        cout << endl;
    }
}
