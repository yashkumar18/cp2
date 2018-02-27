/*
By : Yash Kumar
Dhirubhai Ambani Institute Of Information And Communication Technology, Gandhinagar (DA-IICT GANDHINAGAR)
1st Year ICT BTECH student
*/
#include<bits/stdc++.h>

#define lli long long int
#define llu unsigned long long int

const double EPS = 1e-24;
const lli MOD = 1000000007ll;
const double PI = 3.14159265359;
int INF = 2147483645;

template <class T>T Max2(T a,T b){return a<b?b:a;}
template <class T>T Min2(T a,T b){return a<b?a:b;}
template <class T>T Max3(T a,T b,T c){return Max2(Max2(a,b),c);}
template <class T>T Min3(T a,T b,T c){return Min2(Min2(a,b),c);}
template <class T>T Max4(T a,T b,T c,T d){return Max2(Max2(a,b),Max2(c,d));}
template <class T>T Min4(T a,T b,T c,T d){return Min2(Min2(a,b),Max2(c,d));}

using namespace std;

lli bit_count(lli _x){lli _ret=0;while(_x){if(_x%2==1)_ret++;_x/=2;}return _ret;}
lli bit(lli _mask,lli _i){return (_mask&(1<<_i))==0?0:1;}
lli powermod(lli _a,lli _b,lli _m){lli _r=1;while(_b){if(_b%2==1)_r=(_r*_a)%_m;_b/=2;_a=(_a*_a)%_m;}return _r;}

/*
    call init;
    change MAXN, mod
*/

namespace NCR{
    const int MAXN = 100010;
    int N;
    lli fact[MAXN],invfact[MAXN];
    lli mod = MOD;

    void init(int _N){
        N = _N;
        fact[0]=1;
        invfact[0]=invfact[1]=1;
        for(int i=1;i<=N;i++)
            fact[i]=(fact[i-1]*i)%mod;
        for(int i=2;i<=N;i++)
            invfact[i]=(invfact[i-1]*powermod(i,mod-2,mod))%mod;
    }

    lli getVal(int n,int r){
        if(n<r || r<0 || r>n || n<0)
            return 0;
        lli ret=fact[n];
        ret=(ret*invfact[r])%mod;
        ret=(ret*invfact[n-r])%mod;
        return ret;
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);



    return 0;
}

