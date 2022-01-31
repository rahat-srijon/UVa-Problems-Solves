#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
int n,m,DP[10][100][1<<10];
int bitmask_dp(int prev,int size,int mask){
	if(size>m)return 0;
	if(DP[prev][size][mask]!=-1)return DP[prev][size][mask];
	int ret=mask==(1<<n)-1;
	if(prev>0)ret+=bitmask_dp(prev-1,size+1,mask|(1<<(prev-1)))%mod;
	if(prev<n-1)ret+=bitmask_dp(prev+1,size+1,mask|(1<<(prev+1)))%mod;
	return DP[prev][size][mask]=ret%mod;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		memset(DP,-1,sizeof(DP));
		scanf("%d %d",&n,&m);
		int ans=0,i=0;
		while(++i<n)ans+=bitmask_dp(i,1,1<<i);
		printf("%d\n",ans);
	}
	return 0;
}
