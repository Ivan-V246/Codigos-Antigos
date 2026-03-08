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

map <int, int> mapa;

signed main() { 
    mapa[2] = 9;
    mapa[4] = 909;
    mapa[6] = 90909;
    mapa[8] = 9090909;
    mapa[10] = 909090909;
    mapa[12] = 90909090909;
    mapa[14] = 9090909090909;
    mapa[16] = 909090909090909;
    mapa[18] = 90909090909090909;
    mapa[1] = 0;
    mapa[3] = 99;
    mapa[5] = 9999;
    mapa[7] = 999999;
    mapa[9] = 99999999;
    mapa[11] = 9999999999;
    mapa[13] = 999999999999;
    mapa[15] = 99999999999999;
    mapa[17] = 9999999999999999;
    mapa[19] = 999999999999999999;
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int temp = n;
        int tam = 0;
        while(temp > 0) {
            tam++;
            temp/= 10;
        }
        int ans = 0;
        for(int i = 2; i <=18; i+=2) {
            if(tam >= i) ans = mapa[i];
        }
        if(tam%2 == 1) {
            ans += n-mapa[tam];
        }
        cout << ans << endl;
    }
}