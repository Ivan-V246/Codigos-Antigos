#include <bits/stdc++.h>
using namespace std;
#define op ios::sync_with_stdio(false); cin.tie(NULL);
#define INF 1e18
#define pii pair<int, int>
#define ll long long
#define mkp make_pair
#define endl '\n'
#define f first
#define s second
#define int long long
// #define vi vector <int>
#define dbg(x) cout << #x << " " << x << endl;
const int MAXN = 1e5+10;
int n, m, t;
int lista[MAXN];

signed main() { op 
    cin >> t;
    for(int j = 0; j < t; j++) {
        cin >> n >> m;
        for(int i = 0; i < n; i++){
            cin >> lista[i];
        }
        int tam = m + 2;
        priority_queue <pii> maior;
        priority_queue <pii, vector<pii>, greater<pii> > menor;
        int x = 0, y = 0, ans = -INF;
        while(y < n) {
            menor.emplace(lista[y], y);
            maior.emplace(lista[y], y);
            if((y-x) + 1 > tam) {
                x++;
                while(menor.top().s < x) {
                    menor.pop();
                }
                while(maior.top().s < x) {
                    maior.pop();
                }
            }
            ans = max(maior.top().f - menor.top().f, ans);
            y++;
        }
        cout << ans << endl;
    }
}
/*Two Pointers com guloso, ideia interessante de usar duas Pqs pra guardar o menor e o maior.*/
