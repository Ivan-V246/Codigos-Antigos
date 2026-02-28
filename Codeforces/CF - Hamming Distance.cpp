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
    int n; cin >> n;
    vector <string> nomes;
    for(int i = 0; i < 3; i++) {
        string a; cin >> a;
        nomes.emplace_back(a);
    }
    string ans = "";
    for(int i = 0; i < n; i++) {
        map <char, int> sla;
        for(int j = 0; j < 3; j++) {
            sla[nomes[j][i]]++;
        }
        int ma = 0;
        char letra = 'a';
        for(auto x : sla) {
            if(x.second > ma) {
                ma = x.second;
                letra = x.first;
            }
        }
        ans += letra;
    }
    cout << ans << endl;
}