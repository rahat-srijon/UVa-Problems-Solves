#include<bits/stdc++.h>
using namespace std;
int main(){
	int mx=1+1<<16;
	vector<int>primes;
	bool prime[mx];
	memset(prime,1,sizeof(prime));
	for(int i=2;i*i<mx;i++){
		if(prime[i]){
			for(int j=i*i;j<mx;j+=i){
				prime[j]=0;
			}
		}
	}
	for(int i=2;i<mx;i++){
		if(prime[i])primes.push_back(i);
	}
	while(1){
		long long int n,x,i=0,cb=1,c=0;
		scanf("%lld",&n);
		if(!n)break;
		x=n;
		vector<pair<int,int> >PF;
		while(i<primes.size()&&primes[i]*primes[i]<=x){
			if(x%primes[i]==0){
				c=0;
				while(x%primes[i]==0){
					x/=primes[i];
					c++;
				}
				PF.push_back({c,primes[i]});
			}
			i++;
		}
		sort(PF.begin(),PF.end());
		bool f=x==1;
		for(int i=1;i<PF.size()&&f;i++){
			if(PF[i].first%PF[0].first)f=0;
			else{
				PF[i].first/=PF[0].first;
				for(int j=0;j<PF[i].first;j++){
					cb*=PF[i].second;
				}
			}
		}
		if(f){
			cb*=PF[0].second;
			int cnt=0;
			while(n>1){
				n/=cb;
				cnt++;
			}
			printf("%d\n",cnt);
		}
		else printf("1\n");
	}
	return 0;
}
