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

vector <int> primos;
map <int, bool> eh;

signed main() { 

    for(int i = 2; i <= 1e6; i++) {
        if(eh[i]) continue;
        primos.emplace_back(i);
        for(int j = i*i; j <= 1e6; j+=i) {
            eh[j] = 1;
        }
    }
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int ans = 1;
        for(auto x : primos) {
            if(n%x == 0) {
                ans *= x;
                while(n%x == 0) n /= x;
            }
        }
        cout << ans*n << endl;
    }
}