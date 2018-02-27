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

const double EPS = 1e-9;
const lli MOD = 1000000007ll;
const lli HASHMOD[2]={1000000009ll,1100000009ll};
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

/*
    1 based
    N on left side, M on right side
    addEdge(x,y) x on left to y on right
*/

struct BipartiteMatching{
    vector<vector<int> > w;
    vector<int> mr,mc;

    BipartiteMatching(int N,int M){
        w.resize(N);
        for(int i=0;i<N;i++)
            w[i].resize(M,0);
    }

    void addEdge(int x,int y){
        w[x-1][y-1] = 1;
    }

    bool FindMatch(int i, const vector<vector<int> > &w, vector<int> &mr, vector<int> &mc, vector<int> &seen) {
        for (int j = 0; j < w[i].size(); j++) {
            if (w[i][j] && !seen[j]) {
                seen[j] = true;
                if (mc[j] < 0 || FindMatch(mc[j], w, mr, mc, seen)) {
                    mr[i] = j;
                    mc[j] = i;
                    return true;
                }
            }
        }
        return false;
    }

    int Matching(const vector<vector<int> > &w, vector<int> &mr, vector<int> &mc) {
        mr = vector<int>(w.size(), -1);
        mc = vector<int>(w[0].size(), -1);
        int ct = 0;
        for (int i = 0; i < w.size(); i++) {
            vector<int> seen(w[0].size());
            if (FindMatch(i, w, mr, mc, seen)) ct++;
        }
        return ct;
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

