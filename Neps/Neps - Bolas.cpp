#include <bits/stdc++.h>
using namespace std;
#define op ios::sync_with_stdio(false); cin.tie(NULL);
#define INF 0x3f3f3f3f
#define pii pair <int, int>
#define ll long long
#define mkp make_pair
#define endl '\n'
#define f first
#define s second
#define int long long
#define dbg(x) cout << #x << " " << x << endl;
const int MAXN = 1e3+5;
const int mod = 1e9+7;
const int raiz = 20;
const int MAXL = 20;

int lista[10];

signed main() {
    for(int i = 1; i <= 8; i++) {
        int a; cin >> a;
        lista[a]++;
    }
    priority_queue <pii> fila;
    for(int i = 0; i <= 9; i++) {
        if(lista[i] > 0) {
            fila.emplace(lista[i], i);
        }
    }
    int ant = 10;
    bool flag = 1;
    while(!fila.empty()) {
        int atual = fila.top().s;
        int qua = fila.top().f;
        fila.pop();
        if(atual == ant and fila.empty()) {
            cout << "N" << endl;
            return 0;
        } else if(atual == ant) { 
            int n1 = fila.top().s; 
            int n2 = fila.top().f;
            fila.pop();
            n2--;
            ant = n1;
            if(n2 > 0) {
                fila.emplace(n2, n1);
            }
            fila.emplace(qua, atual);
        } else if(atual != ant) {
            qua--;
            if(qua > 0) {
                fila.emplace(qua, atual);
            }
            ant = atual;
        }
    }
    cout << "S" << endl;
}
