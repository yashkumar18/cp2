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

struct Fenwick{
    typedef int ftt;
    int N;
    vector<ftt> tree;

    void init(int _N){
        N = _N;
        tree.resize(N+1);
        for(int i=0;i<=N;i++)
            tree[i] = 0;
    }
    void Add(int i, ftt key){
        while(i <= N){
            tree[i] += key;
            i += (i & -i);
        }
    }

    ftt sum(int i){
        ftt res = 0;
        while(i){
            res += tree[i];
            i -= (i & -i);
        }
        return res;
    }

    ftt sum(int i,int j){
        return sum(j) - sum(i-1);
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);



    return 0;
}

