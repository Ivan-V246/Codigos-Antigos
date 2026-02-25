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
    int valor[70]; 
    int a = 1;
    for(int i = 0;; i++) {
        if( (a << i) > 1e18) break; //Até o 59
        valor[i] = (a << i);
    }
    int t; cin >> t; 
    while(t--) {
        int s, m; cin >> s >> m;
        vector <int> ligados;
        a = 1;
        for(int i = 59; i >= 0; i--) {
            if( (m | (a << i)) == m) ligados.emplace_back(i);
        }
        int r = 1e18, l = 1;
        int ans = 1e18+10;
        bool flag = 0;
        while(l <= r) {
            int mid = (l+ ((r-l)/2));
            int soma = s;
            for(auto x : ligados) {
                if(mid > (int)(soma/valor[x])) {
                    soma %= valor[x];
                } else {
                    soma -= mid*valor[x];
                }
            }
            if(soma == 0) {
                r = mid-1;
                ans = min(ans, mid);
                flag = 1;
            } else {
                l = mid+1;
            }
        }

        if(flag) {
            cout << ans << endl;
        } else {
            cout << -1 << endl;
        }
    }
    
}