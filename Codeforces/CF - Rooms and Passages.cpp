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
const int MAXN = 5e5+5;

int achado[MAXN];
int pulo[MAXN];

signed main() { 
    int n; cin >> n;
    memset(achado, -1, sizeof achado);
    vector <int> lista;
    for(int i = 0; i < n; i++) {
        int a; cin >> a;
        lista.emplace_back(a);
    }
    for(int i = n-1; i >= 0; i--) {
        if(lista[i] < 0) {
            if(achado[-lista[i]] == -1) {
                pulo[i] = pulo[i+1]+1;
            } else {
                pulo[i] = min(pulo[i+1]+1, (achado[-lista[i]] - i));
            }
        } else {
            achado[lista[i]] = i;
            pulo[i] = pulo[i+1]+1;
        }
    }
    for(int i = 0; i < n; i++) {
        cout << pulo[i] << " ";
    }
    cout << endl;
}