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

void KMPconstructlps(string &_s,int _lps[])
{
    int _len=0;
    int _i=1;
    _lps[0]=0;
    while(_i<_s.size())
    {
        if(_s[_i]==_s[_len])
        {	_len++;
            _lps[_i]=_len;
            _i++;		}
        else
        {
            if(_len!=0)
                _len=_lps[_len-1];
            else
            {	_lps[_i]=0;
                _i++;		}
        }
    }
}


int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    string s;cin>>s;
    int lps[1000];
    KMPconstructlps(s,lps);
    for(int i=0;i<s.size();i++)cout<<lps[i]<<" ";

    return 0;
}

