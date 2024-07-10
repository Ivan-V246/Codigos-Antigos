#include <bits/stdc++.h>
using namespace std;
#define op ios::sync_with_stdio(false); cin.tie(NULL);
#define INF 0x3f3f3f3f
#define pii pair <int, int>
#define ll long long
#define mkp make_pair
#define endl '\n'
#define f first
#define s second
#define int long long
#define dbg(x) cout << #x << " " << x << endl;
const int MAXN = 1e3+5;
const int mod = 1e9+7;
const int raiz = 20;
const int MAXL = 20;

char grid[MAXN][MAXN];

signed main() {
    int n; cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> grid[i][j];
        }
    }
    bool regular = 1;
    for(int i = 1; i <= n; i++) {
        bool mancha = 0, cabou = 0; 
        for(int j = 1; j <= n; j++) {
            if(!mancha and grid[i][j] == '*') {
                mancha = 1;
            } else if(mancha and grid[i][j] == '.') {
                cabou = 1;
            } else if(cabou and grid[i][j] == '*') {
                regular = 0;
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        bool mancha = 0, cabou = 0;
        for(int j = 1; j <= n; j++) {
            if(!mancha and grid[j][i] == '*') {
                mancha = 1;
            } else if(mancha and grid[j][i] == '.') {
                cabou = 1;
            } else if(cabou and grid[j][i] == '*') {
                regular = 0;
            }
        }
    }
    cout << "NS"[regular] << endl;
}
