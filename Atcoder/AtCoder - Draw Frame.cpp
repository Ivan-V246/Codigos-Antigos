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
    int n, m; cin >> n >> m;
    char grafo[n][m];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) grafo[i][j] = '.';
    }
    for(int i = 0; i < n; i++) grafo[i][0] = '#';
    for(int i = 0; i < n; i++) grafo[i][m-1] = '#';
    for(int i = 0; i < m; i++) grafo[0][i] = '#';
    for(int i = 0; i < m; i++) grafo[n-1][i] = '#';

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) cout << grafo[i][j];
        cout << endl;
    }
}