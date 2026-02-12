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
    int n, a; cin >> n >> a;
    vector<int> lista(n);
    for(auto &x : lista) cin >> x;

    map <int, int> freq;
    freq[0] = 1;
    int atual = 0;
    int ans = 0;
    for(auto x : lista) {
        atual+= x;
        ans += freq[atual-a];
        freq[atual]++;
    }
    cout << ans << endl;
}

//Malandragem do mapa de frequência; É uma técnica de Prefix-Sum; 
