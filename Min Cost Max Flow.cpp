#include <bits/stdc++.h>

#define LOCAL 1

#define lli long long int
#define llu unsigned long long int
#define ld long double
#define all(v) v.begin(),v.end()
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define si(n) scanf("%d",&n)
#define slli(n) scanf("%lld",&n);
#define ss(n) scanf("%s",n);

const long double EPS = 1e-10;
const int MOD = 1000000007ll;
const int mod1 = 1000000009ll;
const int mod2 = 1100000009ll;
int INF = (int)1e9;
lli INFINF = (lli)1e18;
int debug = 0;
long double PI = acos(-1.0);

using namespace std;

int bit_count(lli _x){lli _ret=0;while(_x){if(_x%2==1)_ret++;_x/=2;}return _ret;}
int bit(lli _mask,int _i){return (_mask&(1ll<<_i))==0?0:1;}
int add(int a,int b,int m=MOD){int x=a+b;while(x>=m)x-=m;while(x<0)x+=m;return x;}
int sub(int a,int b,int m=MOD){int x=a-b;while(x<0)x+=m;while(x>=m)x-=m;return x;}
int mul(int a,int b,int m=MOD){lli x=a*1ll*b;x%=m;while(x<0)x+=m;return (int)x;}
int ldtoint(ld x){return (int)(x+0.5);}lli ldtolli(ld x){return (lli)(x+0.5);}
int powermod(lli _a,lli _b,int _m=MOD){lli _r=1;while(_b){if(_b%2==1)_r=mul(_r,_a,_m);_b>>=1;_a=mul(_a,_a,_m);}return _r;}

template<class T1,class T2>ostream&operator<<(ostream& os,const pair<T1,T2>&p){os<<"["<<p.first<<","<<p.second<<"]";return os;}
template<class T>ostream&operator<<(ostream& os,const vector<T>&v){os << "[";bool first=true;for (T it:v){if (!first)os<<", ";first = false;os<<it;}os<<"]";return os;}
template<class T>ostream&operator<<(ostream& os,set<T>&v){os<<"[";bool first=true;for (T it:v){if(!first)os<<", ";first=false;os<<it;}os<<"]";return os;}
template<class T1,class T2>ostream&operator<<(ostream& os,map<T1,T2>&v){os<<"[";bool first=true;for(pair<T1,T2> it:v){if(!first)os<<", ";first=false;os<<"("<<it.F<<","<<it.S<<")";}os<<"]";return os;}
template<class T>void parr(T a[],int s,int e){cout<<"[";for(int i=s;i<e;i++)cout<<a[i]<<", ";cout<<a[e]<<"]\n";}

struct MinimumCostMaximumFlow {
    static const int MAXN = 500;
    int nodes = MAXN;
    int prio[MAXN], curflow[MAXN], prevedge[MAXN], prevnode[MAXN], q[MAXN], pot[MAXN];
    bool inqueue[MAXN];
    struct Edge {
        int to, f, cap, cost, rev;
        Edge(int a, int b, int c, int d, int e){
            to = a; f = b; cap = c; cost = d; rev = e;
        }
    };
    vector<Edge> graph[MAXN];
    void addEdge(int s, int t, int cap, int cost) {
        Edge a(t, 0, cap, cost, graph[t].size());
        Edge b(s, 0, 0, -cost, graph[s].size());
        graph[s].push_back(a);
        graph[t].push_back(b);
    }
    void bellmanFord(int s, int dist[]) {
        fill(dist, dist + nodes, INT_MAX);
        dist[s] = 0;
        int qt = 0;
        q[qt++] = s;
        for (int qh = 0; (qh - qt) % nodes != 0; qh++) {
            int u = q[qh % nodes];
            inqueue[u] = false;
            for (int i = 0; i < (int) graph[u].size(); i++) {
                Edge &e = graph[u][i];
                if (e.cap <= e.f) continue;
                int v = e.to;
                int ndist = dist[u] + e.cost;
                if (dist[v] > ndist) {
                    dist[v] = ndist;
                    if (!inqueue[v]) {
                        inqueue[v] = true;
                    q[qt++ % nodes] = v;
                    }
                }
            }
        }
    }
    pair<lli,lli> minCostFlow(int s, int t, int maxf) {
        // bellmanFord can be safely commented if edges costs are non-negative
        bellmanFord(s, pot);
        int flow = 0;
        int flowCost = 0;
        while (flow < maxf) {
            priority_queue<lli, vector<lli>, greater<lli> > q;
            q.push(s);
            fill(prio, prio + nodes, INT_MAX);
            prio[s] = 0;
            curflow[s] = INT_MAX;
            while (!q.empty()) {
                lli cur = q.top();
                int d = cur >> 32;
                int u = cur;
                q.pop();
                if (d != prio[u])
                    continue;
                for (int i = 0; i < (int) graph[u].size(); i++) {
                    Edge &e = graph[u][i];
                    int v = e.to;
                    if (e.cap <= e.f) continue;
                    int nprio = prio[u] + e.cost + pot[u] - pot[v];
                    if (prio[v] > nprio) {
                        prio[v] = nprio;
                        q.push(((lli) nprio << 32) + v);
                        prevnode[v] = u;
                        prevedge[v] = i;
                        curflow[v] = min(curflow[u], e.cap - e.f);
                    }
                }
            }
            if (prio[t] == INT_MAX)
                break;
            for (int i = 0; i < nodes; i++)
                pot[i] += prio[i];
            int df = min(curflow[t], maxf - flow);
            flow += df;
            for (int v = t; v != s; v = prevnode[v]) {
                Edge &e = graph[prevnode[v]][prevedge[v]];
                e.f += df;
                graph[v][e.rev].f -= df;
                flowCost += df * e.cost;
            }
        }
        return make_pair(flow, flowCost);
    }
};

int main()
{
if(LOCAL){
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //debug = 1;
}
    srand (time(NULL));
    //ios::sync_with_stdio(0);cin.tie(0);



    return 0;
}
