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
const int MAXN = 1e13+5;

signed main() { op
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector <int> lista;
        for(int i = 0; i < n; i++) {
            int a; cin >> a;
            lista.emplace_back(a);
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            int sum = 0;
            int mmc = 1;
            for(int j = i; j < n; j++) {
                sum += lista[j];
                int div = gcd(mmc, lista[j]);
                mmc /= div;
                mmc *= lista[j];
                if(mmc > MAXN) break;
                if(sum%mmc == 0) ans++;
            }
        }
        cout << ans << endl;
    }
}

//Funções prontas do C++; 
//gcd(x, y) = Maior Divisor Comum;
//lcm(x, y) = Menor Múltiplo Comum;