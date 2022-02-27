#include<bits/stdc++.h>
using namespace std;
int main(){
	while(1){
		int n,a,b;
		scanf("%d",&n);
		if(!n)break;
		scanf("%d %d",&a,&b);
		map<int,int>M;
		long long int cur=0,cnt=0;
		while(M[cur]<=2){
			M[cur]++;
			if(M[cur]==2)cnt++;
			cur=((((((cur%n)*(cur%n))%n)*a)%n)+b)%n;
		}
		printf("%lld\n",n-cnt);
	}
	return 0;
}
