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

const double EPS = 1e-10;
const lli MOD = 1000000007ll;
const lli mod1 = 1000000009ll;
const lli mod2 = 1100000009ll;
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

lli MinCostMatching(const vector<vector<lli> > &cost, vector<int> &Lmate, vector<int> &Rmate) {
    int n=int(cost.size());
    vector<lli> u(n);
    vector<lli> v(n);
    for(int i=0;i<n;i++){
        u[i]=cost[i][0];
        for(int j=1;j<n;j++)
            u[i]=min(u[i],cost[i][j]);
    }
    for (int j=0;j<n;j++){
        v[j]=cost[0][j]-u[0];
        for(int i=1;i<n;i++)
            v[j]=min(v[j],cost[i][j]-u[i]);
    }
    Lmate=vector<int>(n,-1);
    Rmate=vector<int>(n,-1);
    int mated=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) {
            if(Rmate[j]!=-1)continue;
            if(fabs(cost[i][j]-u[i]-v[j])<EPS){
                Lmate[i]=j;
                Rmate[j]=i;
                mated++;
                break;
            }
        }
    }
    vector<lli> dist(n);
    vector<int> dad(n);
    vector<int> seen(n);
    while(mated<n){
        int s=0;
        while(Lmate[s]!=-1)s++;
        fill(dad.begin(),dad.end(),-1);
        fill(seen.begin(),seen.end(),0);
        for (int k=0;k<n;k++)
            dist[k]=cost[s][k]-u[s]-v[k];
        int j=0;
        while(true){
            j=-1;
            for(int k=0;k<n;k++){
                if(seen[k])continue;
                if (j==-1 || dist[k]<dist[j])j=k;
            }
            seen[j]=1;
            if(Rmate[j]==-1)break;
            const int i=Rmate[j];
            for(int k=0;k<n;k++){
                if(seen[k])continue;
                const lli new_dist=dist[j]+cost[i][k]-u[i]-v[k];
                if(dist[k]>new_dist){
                    dist[k]=new_dist;
                    dad[k]=j;
                }
            }
        }
        for(int k=0;k<n;k++){
            if (k==j || !seen[k])continue;
            const int i=Rmate[k];
            v[k]+=dist[k]-dist[j];
            u[i]-=dist[k]-dist[j];
        }
        u[s]+=dist[j];
        while(dad[j]>=0){
            const int d=dad[j];
            Rmate[j]=Rmate[d];
            Lmate[Rmate[j]]=j;
            j=d;
        }
        Rmate[j]=s;
        Lmate[s]=j;
        mated++;
    }
    lli value=0;
    for(int i=0;i<n;i++)
        value += cost[i][Lmate[i]];
    return value;
}

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

