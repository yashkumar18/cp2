#include<bits/stdc++.h>

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
const lli MOD = 1000000007ll;
const lli mod1 = 1000000009ll;
const lli mod2 = 1100000009ll;
int INF = (int)1e9;
lli INFINF = (lli)1e18;
int debug = 0;
long double PI = acos(-1.0);

using namespace std;

lli bit_count(lli _x){lli _ret=0;while(_x){if(_x%2==1)_ret++;_x/=2;}return _ret;}
lli bit(lli _mask,lli _i){return (_mask&(1<<_i))==0?0:1;}
lli powermod(lli _a,lli _b,lli _m=MOD){lli _r=1;while(_b){if(_b%2==1)_r=(_r*_a)%_m;_b/=2;_a=(_a*_a)%_m;}return _r;}
lli add(lli a,lli b,lli m=MOD){lli x=a+b;while(x>=m)x-=m;while(x<0)x+=m;return x;}
lli sub(lli a,lli b,lli m=MOD){lli x=a-b;while(x<0)x+=m;while(x>=m)x-=m;return x;}
lli mul(lli a,lli b,lli m=MOD){lli x=a*1ll*b;x%=m;if(x<0)x+=m;return x;}

/*
    change MAXN
    change edgetype
    change directed boolean

    edges numbered from 2 to 2*E+1 for undirected
    edges numbered as 2,4,6...2*E for directed
*/

struct Graph{
    static const int MAXN = 1000010;
    typedef int etype;
    bool directed = false;

    int N;
    int ecnt;
    vector<int> G[MAXN];
    int to[2*MAXN],from[2*MAXN];
    etype wei[2*MAXN];

    void init(int _N){
        N = _N;
        ecnt = 0;
        for(int i=1;i<=N;i++)
            G[i].clear();
    }

    int dual(int e){
        if(e%2==0) return e+1;
        return e-1;
    }

    void addEdge(int u,int v,etype w = 0){
        ecnt ++;
        G[u].pb(2*ecnt);from[2*ecnt] = u;to[2*ecnt] = v;wei[2*ecnt] = w;
        if(!directed)
            G[v].pb(2*ecnt+1);from[2*ecnt+1] = v;to[2*ecnt+1] = u;wei[2*ecnt+1] = w;
    }
};


int main()
{
if(LOCAL){
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    debug = 1;
}
    srand (time(NULL));



    return 0;
}
