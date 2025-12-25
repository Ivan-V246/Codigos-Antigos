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
bool ehprimo[MAXN];

signed main() { op
    for(int i = 2; i < MAXN; i++) {
        if(!ehprimo[i]) {
            primos.emplace_back(i);
            for(int j = i*i; j < MAXN; j+=i) {
                ehprimo[j] = 1;
            }
        }
    }
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        map <int, int> quant;
        for(int i = 0; i < n; i++) {
            int a; cin >> a;
            int j = 0;
            while(a > 1) {
                if(!ehprimo[a]) {
                    quant[a]++;
                    a = 1;
                    break;
                }
                if(a % primos[j] == 0) {
                    quant[primos[j]]++;
                    a = a/primos[j];
                } else {
                    j++;
                }
            }
        }
        bool certo = 1;
        for(auto x : quant) {
            if(x.second % n != 0) {
                certo = 0;
                break;
            }
        }
        if(certo) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}
