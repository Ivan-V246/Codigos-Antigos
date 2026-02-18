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

string ponto(int tam) {
    string res = "";
    while(tam--) res+='.';
    return res;
}

signed main() { 
    int n; cin >> n;
    vector <string> lista;
    int ma = 0;
    for(int i = 0; i < n; i++) {
        string a; cin >> a;
        ma = max(ma, (int)a.size());
        lista.emplace_back(a);
    }
    vector <string> ans;
    for(auto x : lista) {
        int sla = ma - x.size();
        string p = ponto(sla/2);
        string atual = p;
        atual+=x;
        atual+=p;
        ans.emplace_back(atual);
    }
    for(auto x : ans) cout << x << endl;
}
