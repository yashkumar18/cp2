#include<bits/stdc++.h>

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
int INF = 2147483645;
lli INFINF = 9223372036854775807;
int debug = 0;

using namespace std;

lli bit_count(lli _x){lli _ret=0;while(_x){if(_x%2==1)_ret++;_x/=2;}return _ret;}
lli bit(lli _mask,lli _i){return (_mask&(1<<_i))==0?0:1;}
lli powermod(lli _a,lli _b,lli _m){lli _r=1;while(_b){if(_b%2==1)_r=(_r*_a)%_m;_b/=2;_a=(_a*_a)%_m;}return _r;}
lli add(lli a,lli b,lli m){lli x=a+b;while(x>=m)x-=m;return x;}
lli sub(lli a,lli b,lli m){lli x=a-b;while(x<0)x+=m;return x;}
lli mul(lli a,lli b,lli m){lli x=a*b;x%=m;return x;}

/*
    change MAXN
    change LOGN
    initialize segment tree
    write segment tree queries
    complete HLDquery()
*/

struct HLD{
    const static int MAXN = 200010;
    int chainInd[MAXN],chainSize[MAXN],chainHead[MAXN],chainPos[MAXN];
    int base[MAXN],posInBase[MAXN];
    int N,chainNo,hldtime;
    int subsz[MAXN], parent[MAXN];

    void init(int _N,vector<int> G[],int to[]){
        chainNo = hldtime = 1;
        N = _N;
        for(int i=1;i<=N;i++){
            chainInd[i] = chainSize[i] = chainHead[i] = chainPos[i] = 0;
            base[i] = posInBase[i] = 0;
            subsz[i] = 0;
            parent[i] = 0;
        }

        dfs1(1,0,G,to,0);
        dfs2(1,0,G,to);

        //segt.BuildSegTree(1,N,0,base);
    }

    void dfs1(int u,int p,vector<int> G[],int to[],int d){
        subsz[u] ++;
        for(int i : G[u]){
            int v = to[i];
            if(v == p)
                continue;
            dfs1(v,u,G,to,d+1);
            subsz[u] += subsz[v];
        }
    }

    void dfs2(int u,int p,vector<int> G[],int to[]){
        if(chainHead[chainNo]==0)
            chainHead[chainNo] = u;
        chainInd[u] = chainNo;
        chainPos[u] = chainSize[chainNo];
        chainSize[chainNo]++;
        //base[hldtime] = ;
        posInBase[u] = hldtime++;
        parent[u] = p;

        int idx=-1;
        for(int i:G[u]){
            int v = to[i];
            if(v != p){
                if(idx==-1)
                    idx = i;
                else if(subsz[v] > subsz[to[idx]])
                    idx = i;
            }
        }

        if(idx != -1)
            dfs2(to[idx],u,G,to);

        for(int i : G[u]){
            int v = to[i];
            if(v != p && i != idx){
                chainNo++;
                dfs2(v,u,G,to);
            }
        }
    }

    int HLDquery(int u, int v){
        //int l = lca.LCAquery(u,v);
        // query(u,l), query(v,l);
    }

private:
    int query(int u, int v){
        int uchain;
        int vchain = chainInd[v];
        //int ret = INF;
        while(1){
            uchain = chainInd[u];
            if(uchain == vchain){
                //segt.QuerySegTree(1,N,posInBase[v],posInBase[u],0));
                break;
            }
            //segt.QuerySegTree(1,N,posInBase[chainHead[uchain]],posInBase[u],0));
            u = chainHead[uchain];
            u = parent[u];
        }
        //return ret;
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

