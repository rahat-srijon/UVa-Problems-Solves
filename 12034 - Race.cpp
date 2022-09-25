#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 10056
ll C[1001][1001],DP[1001];
void genC(){
	for(int i=0;i<1001;i++){
		for(int j=0;j<1001;j++){
			if(j>i)C[i][j]=0;
			else if(i==j||j==0)C[i][j]=1;
			else C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
		}
	}
}
ll dp(ll n){
	if(n<=1)return 1;
	ll &ret=DP[n];
	if(~ret)return ret;
	ret=0;
	for(int i=1;i<=n;i++){
		ret=(ret+C[n][i]*dp(n-i))%mod;
	}
	return ret;
}
int main(){
	genC();
	int t,tc=0;
	scanf("%d",&t);
	while(t--){
		ll n;
		scanf("%lld",&n);
		memset(DP,-1,sizeof(DP));
		ll ans=dp(n);
		printf("Case %d: %lld\n",++tc,ans);
	}
	return 0;
}
