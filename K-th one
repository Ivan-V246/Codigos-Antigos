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
const int MAXN = 1e5+10;
int n, m;
bool lista[MAXN];
vector <int> seg(4*(MAXN));

void update(int no, int l, int r, int obj) {
    if(obj > r or obj < l) return;
    if(l == r) {
        seg[no] = lista[obj];
        return;
    }    

    int esq = no*2, dir = esq+1, mid = (l+r)/2;

    update(esq, l, mid, obj);
    update(dir, mid+1, r, obj);

    seg[no] = seg[esq]+seg[dir];
}

void query(int no, int l, int r, int ini, int fim, int obj) {

    if(l == r) {
        cout << l << endl;
        return;
    }
    int esq = no*2, dir = esq+1, mid = (l+r)/2;

    if(seg[esq] == 0) {
        query(dir, mid+1, r, ini, fim, obj);
    } else if(seg[dir] == 0) {
        query(esq, l, mid, ini, fim, obj);
    } else {
        if(obj >= ini and obj <= (ini+seg[esq])-1) {
            query(esq, l, mid, ini, (ini+seg[esq])-1, obj);
        } else {
            query(dir, mid+1, r, ini+seg[esq], fim, obj);
        }
    }

}

signed main() { op
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> lista[i];
        update(1, 0, n-1, i);
    }
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        if(a == 2) {
            query(1, 0, n-1, 0, seg[1]-1, b);
        } else {
            lista[b] = !lista[b];
            update(1, 0, n-1, b);
        }
    }
}
/*Questão de Seg que eu consegui adaptar. Usei a mesma lógica dela mesmo de marcar qual segmento aquele nó representava.*/
