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
//#define int long long
#define dbg(x) cout << #x << " " << x << endl;
const int MAXN = 1e6+5;

int colunas[4]; //Cada posição guarda quantas colunas 
                //daquele tipo eu tenho;

int main() { 
    string cima, baixo; 
    cin >> cima >> baixo;
    for(int i = 0; i < cima.size(); i++) {
        if(cima[i] == '.' and baixo[i] == '.') {
            colunas[0]++;
        } else if(cima[i] == '.' and baixo[i] == '#') {
            colunas[1]++;
        } else if(cima[i] == '#' and baixo[i] == '.') {
            colunas[2]++;
        } else {
            colunas[3]++;
        }
    }
    if(colunas[1] > 0 and colunas[2] > 0 and colunas[3] == 0) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        cima = "";
        baixo = "";

        while(colunas[2]--) {
            cima += '#';
            baixo+= '.';
        }

        while(colunas[3]--) {
            cima += '#';
            baixo+= '#';
        }

        while(colunas[1]--) {
            cima += '.';
            baixo+= '#';
        }
        
        while(colunas[0]--) {
            cima += '.';
            baixo+= '.';
        }
        cout << cima << endl << baixo << endl;
    }
    return 0;
}