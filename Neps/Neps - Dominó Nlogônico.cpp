#include <bits/stdc++.h>
using namespace std;
#define op ios::sync_with_stdio(false); cin.tie(NULL);
#define INF 0x3f3f3f3f
#define pii pair<int, int>
#define ll long long
#define mkp make_pair
#define endl '\n'
#define f first
#define s second
#define int long long 
#define dbg(x) cout << #x << " " << x << endl;
const int MAXN = 3*(1e5+10);
vector <int> pos(MAXN);
vector <int> alt(MAXN);
vector <int> resp;
int n;

signed main() { op
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> pos[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> alt[i];
    }
    stack <pii> pilha;
    for (int i = n; i >= 1; i--) {
        int q = 1;
        if(pilha.empty()) {
            resp.emplace_back(q);
            pilha.push(mkp(pos[i], q));
        } 
        else {
            bool flag = 1;
            while (!pilha.empty() and flag) {
                if (pos[i] + alt[i] >= pilha.top().f) {
                    q += pilha.top().s;
                    pilha.pop();
                } else {
                    flag = 0;
                }

            }
            pilha.push(mkp(pos[i], q));
            resp.emplace_back(q);
        }
    }
    reverse(resp.begin(), resp.end());
    for (auto x : resp) {
        cout << x << " ";
    }
    cout << endl;
}
/*A diferença entre a prata e o ouro na OBI, Dadinho God por ter me dado a solução em tipo, 15 minutos.*/
