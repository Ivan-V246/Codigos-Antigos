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

struct obj{
    int id, pont;

    bool operator<(const obj& outro) const {
        if(pont != outro.pont) {
            return (pont > outro.pont);
        } 
        return (id < outro.id);
    }
};
map <int, string> aluno;
map <int, int> pontos;

signed main() { 
    int n; string senha; cin >> n >> senha;
    for(int i = 1; i <= n; i++) {
        string nome; cin >> nome;
        aluno[i] = nome;
    }
    int m; cin >> m;
    while(m--) {
        string com; cin >> com;
        if(com == "bonus") {
            int a, b; string c; cin >> a >> b >> c;
            if(c != senha) {
                cout << "Wrong password please try again" << endl;
            } else {
                pontos[a]+=b;
                cout << "Updated successfully" << endl;
            }
        } else {
            vector<obj> rank;
            for(auto x : pontos) {
                obj a = {x.first, x.second};
                rank.emplace_back(a);
            }
            sort(rank.begin(), rank.end());
            int pos = 0;
            int num = -1;
            for(auto x : rank) {
                if(x.pont != num) {
                    pos++;
                    num = x.pont;
                }
                cout << pos << " " << x.id << " " << aluno[x.id] << " " << x.pont << endl;
            }
        }
        cout << "---" << endl;
    }
}