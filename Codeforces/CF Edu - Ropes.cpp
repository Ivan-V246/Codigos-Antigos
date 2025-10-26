#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

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
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
#define int ll
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

#define ordered_set tree<os_type, null_type,less<os_type>, rb_tree_tag,tree_order_statistics_node_update>
vector <double> lista;
int n, k; 

bool check(double teste) {
    int cont = 0;
    for(auto x : lista) {
        cont += x/teste;    
    }
    return cont >= k;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    lista.resize(n);
    double resp = 0;
    for(int i = 0; i < n; i++) {
        cin >> lista[i];
    }
    double l = 0, r = 1e7+5;
    while(abs(r-l) >= 0.0000001) {
        double mid = (l+r)/2;
        bool f = check(mid);
        if(f) {
            l = mid;
            resp = max(resp, mid);
        } else {
            r = mid;
        }
    }
    cout << fixed << setprecision(6) << resp << endl;
    return 0;
}