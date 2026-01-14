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
    int t; cin >> t;
    while(t--) {
        int n; string s; cin >> n >> s;
        vector <int> div;
        for(int i = 1; i*i <= n; i++) {
            if(n%i == 0) {
                div.emplace_back(i);
                if(i != n/i) {
                    div.emplace_back(n/i);
                }
            }
        }
        sort(div.begin(), div.end());
        reverse(div.begin(), div.end());
        int ans = 0;
        for(auto x : div) {
            map <string, int> freq;
            for(int i = 0; i < n; i+=x) {
                freq[s.substr(i, x)]++;
            }
            if(freq.size() <= 2) {
                vector <string> lista;
                for(auto y : freq) {
                    lista.emplace_back(y.first);
                }
                int erro = 0;
                if(lista.size() > 1) {
                    if(freq[lista[0]] > 1 and freq[lista[1]] > 1) {
                        erro = 2;
                    }
                    for(int i = 0; i < lista[0].size(); i++) {
                        if(lista[0][i] != lista[1][i]) {
                            erro++;
                        }
                    }
                }
                if(erro <= 1) {
                    ans = x;
                };
            }
        }
        cout << ans << endl;
    }
}
