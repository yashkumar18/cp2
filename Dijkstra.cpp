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
    verify data types
*/

void dijkstra(vector<int> G[],int N,int source,int to[],int length[],lli dist[]){
    for(int i=1;i<=N;i++)
        dist[i] = INFINF;
    dist[source] = 0;
    priority_queue<pair<int,int> > Q;
    Q.push({-dist[source],source});

    while(!Q.empty()){
        pair<int,int> it = Q.top();
        Q.pop();
        int u = it.S;
        for(int e:G[u]){
            int v = to[e];
            if(dist[v] > dist[u] + length[e]){
                dist[v] = dist[u] + length[e];
                Q.push({-dist[v],v});
            }
        }
    }
    return;
}

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
