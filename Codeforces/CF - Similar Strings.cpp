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

string reg(string sla) {
    map <char, char> alfa;
    char letra = 'a';
    string nova = "";
    for(auto x : sla) {
        if(alfa.count(x) == 0) {
            alfa[x] = letra;
            letra++;
        } 
        nova+=alfa[x];
    }
    return nova;
}

signed main() { 
    int n; cin >> n;
    map <string, int> mapa;
    for(int i = 0; i < n; i++) {
        string str; cin >> str;
        mapa[reg(str)]++;
    }
    int ans = 0;
    for(auto x : mapa) {
        ans += (x.second*(x.second-1))/2;
    }
    cout << ans << endl;
}