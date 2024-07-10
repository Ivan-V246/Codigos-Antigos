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

char num[MAXN];
bool flag = 0;
int zero;
int cinco;
int menor;

signed main() {
    int n; cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> num[i];
        if(num[i] == '5') {
            menor = i;
        }
    }
    for(int i = n; i >= 1; i--) {
        if(num[i] == '0') {
            zero = i;
        }
        if(num[i] == '5') {
            cinco = i;
        }
    }
    int temp = num[n] - '0';
    if(temp > 5) {
        if(zero < cinco) {
            swap(num[n], num[zero]);
            flag = 1;
        } else if(cinco < zero) {
            swap(num[n], num[cinco]);
            flag = 1;
        }
    } else {
        if(zero != 0) {
            swap(num[zero], num[n]);
            flag = 1;
        } else if(menor != 0) {
            swap(num[menor], num[n]);
            flag = 1;
        }
    }
    if(!flag) {
        cout << -1 << endl;
    } else {
        for(int i = 1; i <= n; i++) {
            cout << num[i] << " ";
        }
    }
}
