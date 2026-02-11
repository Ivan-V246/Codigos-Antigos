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

signed main() {
    int t; cin >> t;
    while(t--) {
        int a, b; cin >> a >> b;
        if(a%2 == 0 and b%2 == 0) {
            cout << "abdullah" << endl;
        } else {
            cout << "hasan" << endl;
        }
    }
}

// Teoria dos jogos: 

// Se um estado vai pra um estado Perdedor, ele é Vencedor;
// Se um estado só vai pra estados Vencedores, ele é Perdedor;