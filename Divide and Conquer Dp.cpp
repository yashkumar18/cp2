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

using namespace std;

lli bit_count(lli _x){lli _ret=0;while(_x){if(_x%2==1)_ret++;_x/=2;}return _ret;}
lli bit(lli _mask,lli _i){return (_mask&(1<<_i))==0?0:1;}
lli powermod(lli _a,lli _b,lli _m=MOD){lli _r=1;while(_b){if(_b%2==1)_r=(_r*_a)%_m;_b/=2;_a=(_a*_a)%_m;}return _r;}
lli add(lli a,lli b,lli m=MOD){lli x=a+b;while(x>=m)x-=m;return x;}
lli sub(lli a,lli b,lli m=MOD){lli x=a-b;while(x<0)x+=m;return x;}
lli mul(lli a,lli b,lli m=MOD){lli x=a*1ll*b;x%=m;if(x<m)x+=m;return x;}

int T,N,K;
lli cost[510][510];
lli dp[510][510];

void solve(int k,int s,int e,int x,int y){
    if(x>y)
        return;

    int cut;
    int m = (x+y)>>1;
    dp[m][k] = INFINF;

    for(int i=s;i<=min(m,e);i++){
        lli temp = dp[i-1][k-1] + cost[i][m];
        if(temp < dp[m][k]){
            dp[m][k] = temp;
            cut = i;
        }
    }
    solve(k,s,cut,x,m-1);
    solve(k,cut,e,m+1,y);
}

int main()
{
if(LOCAL){
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    debug = 1;
}
    srand (time(NULL));

    for(int i=1;i<=N;i++)
        dp[i][1] = cost[1][i];
    for(int k=2;k<=N;k++)
        solve(k,k,N,k,N);

    cout<<dp[N][K];

    return 0;
}
