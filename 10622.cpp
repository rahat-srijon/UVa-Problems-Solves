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
		bool neg=0;
		scanf("%lld",&n);
		if(!n)break;
		if(n<0){
			neg=1;
			n=-n;
		}
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
		int gcd=0;
		for(auto &x:PF){
			gcd=__gcd(gcd,x.first);
		}
		bool f=x==1;
		for(int i=0;i<PF.size()&&f;i++){
			PF[i].first/=gcd;
			for(int j=0;j<PF[i].first;j++){
				cb*=PF[i].second;
			}
		}
		if(f){
			int cnt=0;
			while(n>1){
				n/=cb;
				cnt++;
			}
			if(neg)while(cnt%2==0)cnt/=2;
			printf("%d\n",cnt);
		}
		else printf("1\n");
	}
	return 0;
}
