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

pair<int,vector<int> > GetMinCut(vector<vector<int> > &weights){
    int N=weights.size();
    vector<int> used(N),cut,best_cut;
    int best_weight=-1;
    for (int phase=N-1;phase>=0;phase--){
        vector<int> w=weights[0];
        vector<int> added=used;
        int prev,last=0;
        for(int i=0;i<phase;i++){
            prev=last;
            last=-1;
            for(int j=1;j<N;j++)
                if(!added[j] && (last==-1 || w[j]>w[last]))
                    last=j;
            if(i==phase-1){
                for (int j=0;j<N;j++)weights[prev][j]+=weights[last][j];
                for (int j=0;j<N;j++)weights[j][prev]=weights[prev][j];
                used[last]=true;
                cut.push_back(last);
                if(best_weight==-1 || w[last]<best_weight){
                  best_cut=cut;
                  best_weight=w[last];
                }
            }
            else{
                for(int j=0;j<N;j++)
                  w[j]+=weights[last][j];
                added[last]=true;
            }
        }
    }
  return make_pair(best_weight, best_cut);
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

