/*
By : Yash Kumar
Dhirubhai Ambani Institute Of Information And Communication Technology, Gandhinagar (DA-IICT GANDHINAGAR)
2nd Year ICT BTECH student
*/
#include<bits/stdc++.h>

#define lli long long int
#define llu unsigned long long int
#define all(v) v.begin(),v.end()
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define si(n) scanf("%d",&n)
#define slli(n) scanf("%lld",&n);
#define ss(n) scanf("%s",n);

const double EPS = 1e-9;
const lli MOD = 1000000007ll;
const lli HASHMOD[2]={1000000009ll,1100000009ll};
const double PI = 3.14159265359;
int INF = 2147483645;
lli INFINF = 9223372036854775807;
int debug = 0;

template <class T>T Max2(T a,T b){return a<b?b:a;}
template <class T>T Min2(T a,T b){return a<b?a:b;}
template <class T>T Max3(T a,T b,T c){return Max2(Max2(a,b),c);}
template <class T>T Min3(T a,T b,T c){return Min2(Min2(a,b),c);}
template <class T>T Max4(T a,T b,T c,T d){return Max2(Max2(a,b),Max2(c,d));}
template <class T>T Min4(T a,T b,T c,T d){return Min2(Min2(a,b),Min2(c,d));}

using namespace std;

lli bit_count(lli _x){lli _ret=0;while(_x){if(_x%2==1)_ret++;_x/=2;}return _ret;}
lli bit(lli _mask,lli _i){return (_mask&(1<<_i))==0?0:1;}
lli powermod(lli _a,lli _b,lli _m){lli _r=1;while(_b){if(_b%2==1)_r=(_r*_a)%_m;_b/=2;_a=(_a*_a)%_m;}return _r;}
lli add(lli a,lli b){lli x=a+b;if(x>MOD)x-=MOD;return x;}
lli sub(lli a,lli b){lli x=a-b;if(x<0)x+=MOD;return x;}
lli mul(lli a,lli b){lli x=a*b;x%=MOD;return x;}

/*
call init(N)
add edges using AddEdge(from,to,capacity) // directed edges
get flow using GetMaxFlow(source,sink)
*/

namespace Dinic {
    struct Edge {
      int from, to, cap, flow, index;
      Edge(int from, int to, int cap, int flow, int index) :
        from(from), to(to), cap(cap), flow(flow), index(index) {}
      lli rcap() { return cap - flow; }
    };
    int N;
    vector<vector<Edge> > G;
    vector<vector<Edge *> > Lf;
    vector<int> layer;
    vector<int> Q;

    void init(int _N){
        N = _N;
        G.resize(N);
        Q.resize(N);
    }

    void AddEdge(int from, int to, int cap) {
        if (from == to)
            return;
        G[from].push_back(Edge(from, to, cap, 0, G[to].size()));
        G[to].push_back(Edge(to, from, 0, 0, G[from].size() - 1));
    }

    lli BlockingFlow(int s, int t) {
        layer.clear(); layer.resize(N, -1);
        layer[s] = 0;
        Lf.clear(); Lf.resize(N);
        int head = 0, tail = 0;
        Q[tail++] = s;
        while (head < tail) {
            int x = Q[head++];
            for (int i = 0; i < G[x].size(); i++) {
                Edge &e = G[x][i];
                if (e.rcap() <= 0)
                    continue;
                if (layer[e.to] == -1) {
                    layer[e.to] = layer[e.from] + 1;
                    Q[tail++] = e.to;
                }
                if (layer[e.to] > layer[e.from])
                    Lf[e.from].push_back(&e);
            }
        }
        if (layer[t] == -1)
            return 0;
        lli totflow = 0;
        vector<Edge *> P;
        while (!Lf[s].empty()) {
            int curr = P.empty() ? s : P.back()->to;
            if (curr == t) { // Augment
                lli amt = P.front()->rcap();
                for (int i = 0; i < P.size(); ++i)
                    amt = min(amt, P[i]->rcap());
                totflow += amt;
                for (int i = P.size() - 1; i >= 0; --i) {
                    P[i]->flow += amt;
                    G[P[i]->to][P[i]->index].flow -= amt;
                    if (P[i]->rcap() <= 0) {
                        Lf[P[i]->from].pop_back();
                        P.resize(i);
                    }
                }
            }
            else if (Lf[curr].empty()) { // Retreat
                P.pop_back();
                for (int i = 0; i < N; ++i)
                    for (int j = 0; j < Lf[i].size(); ++j)
                        if (Lf[i][j]->to == curr)
                            Lf[i].erase(Lf[i].begin() + j);
            }
            else { // Advance
                P.push_back(Lf[curr].back());
            }
        }
        return totflow;
    }

    lli GetMaxFlow(int s, int t) {
        lli totflow = 0;
        while (lli flow = BlockingFlow(s, t))
            totflow += flow;
        return totflow;
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    debug = 1;
#endif
    srand (time(NULL));



    return 0;
}

