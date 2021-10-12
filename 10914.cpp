#include<bits/stdc++.h>
using namespace std;
#define lint long long int
//----------shimuler_sieve---O(n)___niche
const lint mxN=1e7+7;
lint prime[mxN],pCnt;
bitset<mxN>pmark;
void sieve()
{
    lint limit=sqrt(mxN*1.0)+2;
    pmark[0]=pmark[1]=1;
    prime[pCnt++]=2;
    prime[pCnt++]=3;
    for(lint i=4;i<mxN;i+=2){
        pmark[i]=1;
    }
    for(lint i=9;i<mxN;i+=6){
        pmark[i]=1;
    }
    for(lint i=5;i<mxN;i+=6){
        if(!pmark[i]){
            prime[pCnt++]=i;
            if(i<=limit){
                for(lint j=i*i;j<mxN;j+=i*2){
                    pmark[j]=1;
                }
            }
        }
        if(!pmark[i+2]){
            lint x=i+2;
            prime[pCnt++]=x;
            if(x<=limit){
                for(lint j=x*x;j<mxN;j+=2*x){
                    pmark[j]=1;
                }
            }
        }
    }
}
//----------shimuler_sieve---O(n)___upre
//----------sum_of_divisors_________niche
lint SOD(lint n){
    lint sum=1;
    for(lint i=0;prime[i]*prime[i]<=n;i++){
        if(n%prime[i]==0){
            lint p=prime[i];
            while(n%prime[i]==0){
                n/=prime[i];
                p*=prime[i];
            }
            sum*=(p-1)/(prime[i]-1);
        }
    }
    if(n>1)sum*=(n*n-1)/(n-1);
    return sum;
}
//----------sum_of_divisors_________upre
lint abun[mxN];
bool nodd[mxN];
void pre(){
    for(int i=1;i<pCnt;i++){
        lint c=prime[i];
        while(1){
            c*=2;
            if(c>mxN)break;
            nodd[c]=1;
        }
    }
    lint c=0;
    for(lint i=2;i<mxN;i++){
        if(nodd[i])c+=SOD(i)-2*i;
        abun[i]=c;
    }
}
int main(){
    sieve();
    pre();
    while(1){
        lint n;
        scanf("%lld",&n);
        if(!n)break;
        printf("%lld %lld\n",n,abun[n]);
    }
    return 0;
}
