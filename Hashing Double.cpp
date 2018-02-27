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
    Call init_hashing(int N)

    1-based string
*/

namespace Helper{
    int p1 = 6666;
    int p2 = 5555;
    vector<int> pow1,pow2;
    vector<int> invpow1,invpow2;

    void init_hashing(int n){
        pow1.resize(n+1);pow2.resize(n+1);
        invpow1.resize(n+1);invpow2.resize(n+1);
        pow1[0] = pow2[0] = 1;
        for(int i=1;i<=n;i++){
            pow1[i] = mul(pow1[i-1],p1,mod1);
            pow2[i] = mul(pow2[i-1],p2,mod2);
        }
        for(int i=0;i<=n;i++){
            invpow1[i] = powermod(pow1[i],mod1-2,mod1);
            invpow2[i] = powermod(pow2[i],mod2-2,mod2);
        }
    }
}


struct Hashing {
    vector<int> hash1, hash2;
    int n;
    Hashing(string s) {
        n = s.size() - 1;
        hash1.resize(n+1);hash2.resize(n+1);
        for(int i=1;i<=n;i++){
            hash1[i] = add(hash1[i-1],mul(s[i],Helper::pow1[i-1],mod1),mod1);
            hash2[i] = add(hash2[i-1],mul(s[i],Helper::pow2[i-1],mod2),mod2);
        }
    }
    pair<int,int> getHash(int i, int j){
        pair<int,int> ret;
        ret = {mul(sub(hash1[j],hash1[i-1],mod1),Helper::invpow1[i],mod1),mul(sub(hash2[j],hash2[i-1],mod2),Helper::invpow2[i],mod2)};
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

