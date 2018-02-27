/*
By : Yash Kumar
Dhirubhai Ambani Institute Of Information And Communication Technology, Gandhinagar (DA-IICT GANDHINAGAR)
2nd Year ICT BTECH student
*/
#include<bits/stdc++.h>

#define lli long long int
#define llu unsigned long long int
#define all(v) v.begin(),v.end()

const double EPS = 1e-24;
const lli MOD = 1000000007ll;
const double PI = 3.14159265359;
int INF = 2147483645;
lli INFINF = 9223372036854775807;

template <class T>T Max2(T a,T b){return a<b?b:a;}
template <class T>T Min2(T a,T b){return a<b?a:b;}
template <class T>T Max3(T a,T b,T c){return Max2(Max2(a,b),c);}
template <class T>T Min3(T a,T b,T c){return Min2(Min2(a,b),c);}
template <class T>T Max4(T a,T b,T c,T d){return Max2(Max2(a,b),Max2(c,d));}
template <class T>T Min4(T a,T b,T c,T d){return Min2(Min2(a,b),Max2(c,d));}

using namespace std;

lli slowPhi(lli n)
{
	lli ret=n;
	for(int i=2;i*i<=n;i++)
	{
	    if(n%i==0)
		{
		    while(n%i==0)
				n/=i;
			ret-=(ret/i);
		}
	}
	if(n>1)
		ret-=(ret/n);
	return ret;
}

void pre(){
    for(int i=1;i<=n;i++)
        isp[i]=true;
    for(int i=1;i<=n;i++)
        phi[i]=i;
    for(int i=2;i<=n;i++)
        if(isp[i])
            for(int j=i;j<=n;j+=i)
            {    isp[j]=false;
	    phi[j]-=phi[j]/i;	}
}


int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cout<<slowPhi(3);

    return 0;
}

