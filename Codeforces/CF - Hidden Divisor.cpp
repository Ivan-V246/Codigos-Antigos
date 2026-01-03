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
#define double long double
#define dbg(x) cout << #x << " " << x << endl;
#define EPS 1e-9
const int MAXN = 2e5+5;

signed main() {
    int n; cin >> n;
    vector <int> lista;
    for(int i = 0; i < n; i++) {
        int a; cin >> a;
        lista.emplace_back(a);
    }
    sort(lista.begin(), lista.end());

    if(n == 1 and lista[0] == 1) {
        cout << "*" << endl;
        return 0;
    }

    if(lista[0] != 1) { //Um faltando
        cout << (long long)lista[lista.size()-1] << " " << 1 << endl;
        return 0;
    } 

    if(n%2 == 0) { //Quadrado Perfeito

        double raiz = sqrt(lista[lista.size()-1]);

        if((raiz - (int)raiz) > EPS) {
            cout << (long long)lista[1]*lista[lista.size()-1] << " " << (long long)lista[1]*lista[lista.size()-1]  << endl;
            return 0;
        }

        auto temp = lower_bound(lista.begin(), lista.end(), (int)raiz);
        if((*temp) != (int)raiz) {
            cout << (long long)lista[lista.size()-1] << " " << (long long)raiz << endl;
            return 0;
        }

        for(auto x : lista) {
            int y = lista[lista.size()-1]/x;
            temp = lower_bound(lista.begin(), lista.end(), y);
            if((*temp) != y) {
                cout << (long long)lista[lista.size()-1] << " " << (long long)y << endl;
                return 0;
            }
        }
    } else { //x faltando

        double maior = lista[lista.size()-1];
        int cont = 0;
        int ans = 0;
        for(auto x : lista) {
            double y = maior/x;
            if(y - (int)y > EPS) {
                break;
            }
            auto temp = lower_bound(lista.begin(), lista.end(), y);
            if((*temp) != y) {
                cont++;
                ans = y;
            }
        }

        if(cont == 1) {
            cout << (long long)maior << " " << (long long)ans << endl;
            return 0;
        }
        
    
        int l = 1, r = lista.size()-1;
        int valor = lista[l]*lista[r];
        l++, r--;
        bool faltam = 1;
        while(l <= r) {
            if(lista[l] * lista[r] != valor) {
                faltam = 0;
                break;
            }
            l++;
            r--;
        }
        if(faltam) {
            cout << (long long)valor << " " << (long long)valor << endl;
            return 0;
        }

    }
}