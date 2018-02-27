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

struct Segtree{
    typedef int stt;
    static const int MAXN = 100010;
    stt Segtree[4*MAXN];

    stt MergeSegTree(stt a,stt b){
        return add(a,b);
    }

    void BuildSegTree(int s,int e,int idx,int c[]){
        if(s==e)
            Segtree[idx] = c[s];
        else{
            int mid = (s+e)>>1;
            BuildSegTree(s,mid,2*idx+1,c);
            BuildSegTree(mid+1,e,2*idx+2,c);
            Segtree[idx] = MergeSegTree(Segtree[2*idx+1],Segtree[2*idx+2]);
        }
    }

    void UpdateSegTree(int s,int e,int x,stt y,int idx){
        if(s==e){
            Segtree[idx] = y;
            return;
        }
        int mid = (s+e)>>1;
        if(x<=mid)
            UpdateSegTree(s,mid,x,y,2*idx+1);
        else
            UpdateSegTree(mid+1,e,x,y,2*idx+2);
        Segtree[idx] = MergeSegTree(Segtree[2*idx+1],Segtree[2*idx+2]);
    }

    stt QuerySegTree(int s,int e,int x,int y,int idx){
        if(s==x && e==y)
            return Segtree[idx];
        int mid = (s+e)>>1;
        if(y<=mid)
            return QuerySegTree(s,mid,x,y,2*idx+1);
        if(x>mid)
            return QuerySegTree(mid+1,e,x,y,2*idx+2);
        return MergeSegTree(QuerySegTree(s,mid,x,mid,2*idx+1),QuerySegTree(mid+1,e,mid+1,y,2*idx+2));
    }
};

struct HLD{
    const static int MAXN = 100010;
    const static int LOGN = 20;
    int chainInd[MAXN],chainSize[MAXN],chainHead[MAXN],chainPos[MAXN];
    int base[MAXN],posInBase[MAXN],starttime[MAXN],endtime[MAXN];
    int N,chainNo,hldtime,dfstime;
    int subsz[MAXN];
    int lca[LOGN][MAXN],depth[MAXN];
    Segtree segt;

    void init(int _N,vector<int> G[],int to[], int wei[]){
        chainNo = hldtime = dfstime = 1;
        N = _N;
        for(int i=1;i<=N;i++){
            chainInd[i] = chainSize[i] = chainHead[i] = chainPos[i] = 0;
            base[i] = posInBase[i] = starttime[i] = endtime[i] = 0;
            subsz[i] = 0;
            depth[i] = 0;
        }
        for(int j=0;j<LOGN;j++)
            for(int i=1;i<=N;i++)
                lca[j][i] = 0;

        dfs1(1,0,G,to,0);
        dfs2(1,0,0,G,to,wei);

        segt.BuildSegTree(1,N,0,base);
        for(int j=1;j<LOGN;j++)
            for(int i=1;i<=N;i++)
                lca[j][i] = lca[j-1][lca[j-1][i]];
    }

    void dfs1(int u,int p,vector<int> G[],int to[],int d){
        lca[0][u] = p;
        depth[u] = d;
        subsz[u] ++;
        for(int i : G[u]){
            int v = to[i];
            if(v == p)
                continue;
            dfs1(v,u,G,to,d+1);
            subsz[u] += subsz[v];
        }
    }

    void dfs2(int u,int p,int e,vector<int> G[],int to[],int wei[]){
        if(chainHead[chainNo]==0)
            chainHead[chainNo] = u;
        chainInd[u] = chainNo;
        chainPos[u] = chainSize[chainNo];
        chainSize[chainNo]++;

        base[hldtime] = e;
        posInBase[u] = hldtime++;
        starttime[u] = dfstime;

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

        if(idx != -1){
            dfstime++;
            dfs2(to[idx],u,wei[idx],G,to,wei);
        }

        for(int i : G[u]){
            int v = to[i];
            if(v != p && i != idx){
                chainNo++;
                dfstime++;
                dfs2(v,u,wei[i],G,to,wei);
            }
        }
        endtime[u] = dfstime;
    }

    int LCAquery(int u,int v)
    {
        if(depth[u]<depth[v])
            swap(u,v);
        int diff=depth[u]-depth[v];
        for(int i=0;i<LOGN;i++){
            if( (diff>>i)&1 ){
                u=lca[i][u];
            }
        }
        if(u==v)
            return u;
        for(int j=LOGN-1;j>=0;j--){
            if(lca[j][u]!=lca[j][v]){
                u=lca[j][u];
                v=lca[j][v];
            }
        }
        return lca[0][u];
    }

    int query(int u,int v){
        int uchain;
        int vchain = chainInd[v];
        int ret = 0;
        while(1){
            uchain = chainInd[u];
            if(uchain == vchain){
                ret = add(ret,segt.QuerySegTree(1,N,posInBase[v],posInBase[u],0));
                break;
            }
            ret = add(ret,segt.QuerySegTree(1,N,posInBase[chainHead[uchain]],posInBase[u],0));
            u = chainHead[uchain];
            u = lca[0][u];
        }
        return ret;
    }

    int HLDquery(int u,int v){
        int l = LCAquery(u,v);
        int ret;
        ret = add(query(u,l),query(v,l));
        ret = sub(ret,2*base[posInBase[l]]);
        return ret;
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

