#include <bits/stdc++.h>
using namespace std;

#define op ios::sync_with_stdio(false); cin.tie(NULL);
#define INF 0x3f3f3f3f
#define int long long
#define pii pair<int,int>
#define vi vector<int>
#define mkp make_pair
#define f first
#define s second
#define endl '\n'

#define dbg(x) cout << #x << " -> " << x << endl;
#define dbgv(x) cout << #x << endl; for(auto y : x) cout << y << " "; cout << endl;
#define ALL(x) (x).begin(), (x).end()

const int MAXN = 1e6+5;
const int MOD = 1e9+7;

signed main() { op
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        string com; cin >> com;
        vector <bool> impresso(n+1, false);
        stack <int> pilha;
        for(int i = 1; i <= n; i++) {
            if(com[i-1] == '1') {
                pilha.emplace(i);
            } else if(com[i-1] == '2') {
                if(pilha.size()) {
                    impresso[pilha.top()] = 1;
                    pilha.pop();
                } else {
                    impresso[i] = 1;
                }
            } else {
                impresso[i] = 1;
            }
        }
        vi ans;
        int tot = 0;
        for(int i = 1; i <= n; i++) {
            if(!impresso[i]) {
                tot++;
                ans.emplace_back(i);
            }
        }
        cout << tot << endl;
        for(auto x : ans) {
            cout << x << " ";
        }
        cout << endl;
    }
}
