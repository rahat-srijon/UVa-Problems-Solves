#include<bits/stdc++.h>
using namespace std;
#define lint long long int
lint gcd(lint a,lint b){return b?gcd(b,a%b):a;}
lint lcm(lint a,lint b){return (a*b)/gcd(a,b);}
int main(){
	while(1){
		int n,t;
		scanf("%d %d",&n,&t);
		if(!n&&!t)break;
		lint N[n],Q[t],L[t],G[t];
		for(int i=0;i<n;i++){
			scanf("%lld",&N[i]);
		}
		for(int i=0;i<t;i++){
			scanf("%lld",&Q[i]);
			L[i]=INT_MAX;
			G[i]=-1;
		}
		for(int m=0;m<t;m++){
			for(int i=0;i+3<n;i++){
				for(int j=i+1;j+2<n;j++){
					for(int k=j+1;k+1<n;k++){
						for(int l=k+1;l<n;l++){
							lint c=lcm(lcm(lcm(N[i],N[j]),N[k]),N[l]);
							L[m]=min(L[m],((Q[m]+c-1)/c)*c);
							G[m]=max(G[m],(Q[m]/c)*c);
						}
					}
				}
			}
		}
		for(int i=0;i<t;i++)printf("%lld %lld\n",G[i],L[i]);
	}
	return 0;
}
