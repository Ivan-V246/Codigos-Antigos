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
const int MAXN = 1e5+10;
const int MAXL = 9;

multiset <int> filhos[MAXN];
int pai[MAXN];
bool raiva[MAXN];
int sal[MAXN];

signed main() { op
    int n; cin >> n;
    int putos = 0;
    for(int i = 1; i <= n; i++) {
        int a, b; cin >> a >> b;
        pai[i] = a;
        sal[i] = b;
        filhos[a].insert(b);
        filhos[i].insert(0);
        if(sal[i] > sal[a] and !raiva[a]) {
            putos++;
            raiva[a] = 1;
        }
    }
    cout << putos << endl;
    int q; cin >> q;
    for(int i = 0; i < q; i++) {
        int a, b; cin >> a >> b;
        filhos[pai[a]].erase(filhos[pai[a]].find(sal[a]));
        filhos[pai[a]].insert(b);
        sal[a] = b;
        auto pont = filhos[pai[a]].end();
        pont--;
        if(raiva[pai[a]] and sal[pai[a]] >= *pont) {
            raiva[pai[a]] = 0;
            putos--;
        } else if(!raiva[pai[a]] and sal[pai[a]] < *pont) {
            raiva[pai[a]] = 1;
            putos++;
        }

        pont = filhos[a].end();
        pont--;
        if(raiva[a] and b >= *pont) {
            raiva[a] = 0;
            putos--;
        } else if(!raiva[a] and b < *pont) {
            raiva[a] = 1;
            putos++;
        }
        cout << putos << endl;
    }
}
