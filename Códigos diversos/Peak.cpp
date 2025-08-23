#include <bits/stdc++.h>
using namespace std;
#define op ios::sync_with_stdio(false); cin.tie(NULL);
#define INF 0x3f3f3f3f
#define pii pair<int, pair<int,int>>
#define ll long long
#define mkp make_pair
#define endl '\n'
#define f first
#define s second
#define int long long
#define dbg(x) cout << #x << " " << x << endl;
const int MAXN = 1e5+10;
int n, m;
vector <int> lista;
set <int> cara;

signed main() { 
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        lista.emplace_back(a);
        cara.insert(a);
    }
    sort(lista.begin(), lista.end());
    int resp = 0;
    for(auto x : cara) {
        auto a = lower_bound(lista.begin(), lista.end(), x);
        auto b = lower_bound(lista.begin(), lista.end(), (x+m));
        int temp = distance(a, b);
        resp = max(resp, temp);
    }
    cout << resp << endl;
}
/*Só busca binária pra saber quantos caras da lista tem um valor entre um intervalo.*/
