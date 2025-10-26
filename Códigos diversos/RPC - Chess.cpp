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
#define vi vector<int>
#define dbg(x) cout << #x << " " << x << endl;
const int MAXN = 1e5+5;


bool l[1000];
bool c[1000];
bool diagome[405];
bool diagoma[405];

signed main() {
    int n, m; cin >> n >> m;
    bool array[n+2][n+2];
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            array[i][j] = 0;
        }
    }
    vector <pair<int, int>> que, kin, rook; 
    while(m--) {
        char p; int x, y; cin >> p >> x >> y;
        if(p == 'Q') {
            que.emplace_back(x, y);
        } else if(p == 'R') {
            rook.emplace_back(x, y);
        } else {
            kin.emplace_back(x, y);
        }
    }
    for(auto x : que) {
        if(!l[x.first]) {
            l[x.first] = 1;
            for(int i = 1; i <= n; i++) {
                array[x.first][i] = 1;
            }
        }
        if(!c[x.second]) {
            c[x.second] = 1;
            for(int i = 1; i <= n; i++) {
                array[i][x.second] = 1;
            }
        } 
        if(!diagome[(x.second - x.first)+200]) {
            diagome[(x.second - x.first)+200] = 1;
            for(int i = x.first, j = x.second;; i++, j++) {
                if(i > n or j > n) break;
                array[i][j] = 1;
            }
            for(int i = x.first, j = x.second;; i--, j--) {
                if(i < 1 or j < 1) break;
                array[i][j] = 1;
            }
        }
        if(!diagoma[(x.second + x.first)]) {
            diagoma[(x.second + x.first)] = 1;
            for(int i = x.first, j = x.second;; i--, j++) {
                if(i < 1 or j > n) break;
                array[i][j] = 1;
            }
            for(int i = x.first, j = x.second;; i++, j--) {
                if(i > n or j < 1) break;
                array[i][j] = 1;
            }
        }
    }
    for(auto x : rook) {
        if(!l[x.first]) {
            l[x.first] = 1;
            for(int i = 1; i <= n; i++) {
                array[x.first][i] = 1;
            }
        }
        if(!c[x.second]) {
            c[x.second] = 1;
            for(int i = 1; i <= n; i++) {
                array[i][x.second] = 1;
            }
        }
    }
    for(auto x : kin) {
        array[x.first][x.second] = 1;
        if(x.first-1 >= 1 and x.second-2 >= 1) {
            array[x.first-1][x.second-2] = 1;
        }
        if(x.first-2 >= 1 and x.second-1 >= 1) {
            array[x.first-2][x.second-1] = 1;
        }
        if(x.first+1 <= n and x.second+2 <= n) {
            array[x.first+1][x.second+2] = 1;
        }
        if(x.first+2 <= n and x.second+1 <= n) {
            array[x.first+2][x.second+1] = 1;
        }
        if(x.first-1 >= 1 and x.second+2 <= n) {
            array[x.first-1][x.second+2] = 1;
        }
        if(x.first-2 >= 1 and x.second+1 <= n) {
            array[x.first-2][x.second+1] = 1;
        }
        if(x.first+1 <= n and x.second-2 >= 1) {
            array[x.first+1][x.second-2] = 1;
        }
        if(x.first+2 <= n and x.second-1 >= 1) {
            array[x.first+2][x.second-1] = 1;
        }
    }
    int resp = 0;
    for(int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            resp += array[i][j];
        }
    }
    cout << resp << endl;
}