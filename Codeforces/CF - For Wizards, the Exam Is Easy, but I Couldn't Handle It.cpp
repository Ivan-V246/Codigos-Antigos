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
        int n; cin >> n;
        int array[n+1];
        for(int i = 1; i <= n; i++) {
            cin >> array[i];
        }
        int inv = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = i+1; j <= n; j++) {
                if(array[i] < array[j]) inv++;
            }
        }
        int l = 0, r = 0;
        int ans = INF;
        for(int i = 1; i <= n; i++) {
            int sla = inv;
            for(int j = i; j <= n; j++) {
                if(array[i] > array[j]) {
                    sla--;
                } else if(array[i] < array[j]) {
                    sla++;
                }
                if(sla < ans) {
                    ans = sla;
                    l = i;
                    r = j;
                }
            }
        }
        cout << l << " " << r << endl;
    }
}
