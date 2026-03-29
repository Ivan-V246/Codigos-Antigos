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
    string cima, baixo; cin >> cima >> baixo;
    int array[4] = {0, 0, 0, 0};
    for(int i = 0; i < cima.size(); i++) {
        if(cima[i] == '.' and baixo[i] == '.')  array[0]++;
        if(cima[i] == '.' and baixo[i] == '#')  array[1]++;
        if(cima[i] == '#' and baixo[i] == '.')  array[2]++;
        if(cima[i] == '#' and baixo[i] == '#')  array[3]++;
    }
    if(array[1] > 0 and array[2] > 0 and array[3] == 0) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        string ansc = "";
        string ansb = "";
        while(array[0]--) {
            ansc+= '.';
            ansb+= '.';
        }
        while(array[1]--) {
            ansc+= '.';
            ansb+= '#';
        }
        while(array[3]--) {
            ansc+= '#';
            ansb+= '#';
        }
        while(array[2]--) {
            ansc+= '#';
            ansb+= '.';
        }
        cout << ansc << endl;
        cout << ansb << endl;
    }
}