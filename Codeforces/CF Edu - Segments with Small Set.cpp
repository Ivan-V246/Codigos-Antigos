#include <bits/stdc++.h>

#define ALL(x) x.begin(), x.end()
#define DBG(x) cout << #x << " = " << x << endl;
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())
#define endl '\n'
#define F first
#define S second
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define int ll
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

// #define ordered_set tree<os_type, null_type,less<os_type>, rb_tree_tag,tree_order_statistics_node_update>


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m; cin >> n >> m;
    vi lista(n);
    for(auto &x : lista) cin >> x;
    int l = 0, r = 0, resp = 0;
    set <int> con;
    multiset <int> aux;
    while(r < n) {
        if(con.size() <= m) {
            con.insert(lista[r]);
            aux.insert(lista[r]);
            r++;
            if(con.size() <= m) resp += r-l;
        } else {
            aux.erase(aux.find(lista[l]));
            if(aux.find(lista[l]) == aux.end()) {
                con.erase(lista[l]);
            }
            l++;
            if(con.size() <= m) resp += r-l; 
        }
    }
    while(con.size() > m) {
        aux.erase(aux.find(lista[l]));
        if(aux.find(lista[l]) == aux.end()) {
            con.erase(lista[l]);
        }
        l++;
        if(con.size()<= m) resp += r-l;
    }
    cout << resp << endl;
    return 0;
}