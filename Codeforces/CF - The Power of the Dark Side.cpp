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

struct jedi{
    vector <int> par;
};

signed main() { 
    int n; cin >> n;
    vector <jedi> lista;
    vector <int> menor;
    vector <int> smenor;
    for(int i = 0; i < n; i++) {
        jedi temp;
        for(int j = 0; j < 3; j++) {
            int a; cin >> a;
            temp.par.emplace_back(a);
        }
        sort(temp.par.begin(), temp.par.end());
        menor.emplace_back(temp.par[0]);
        smenor.emplace_back(temp.par[1]);
        lista.emplace_back(temp);
    }
    sort(menor.begin(), menor.end());
    sort(smenor.begin(), smenor.end());
    int cont = 1;
    vector <int> ans; 
    for(auto x : lista) {
        int v = 0;
        auto pont = upper_bound(menor.begin(), menor.end(), x.par[1]);
        if(distance(menor.begin(), pont) == n) {
            v++;
        } 
        pont = upper_bound(smenor.begin(), smenor.end(), x.par[2]);
        if(distance(smenor.begin(), pont) == n) {
            v++;
        } 
        if(v == 2) {
            ans.emplace_back(cont);
        }
        cont++;
    }
    cout << ans.size() << endl;
    for(auto x : ans) {
        cout << x << " ";
    }
    cout << endl;
}