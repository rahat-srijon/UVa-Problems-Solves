#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
	ll k;
	while(scanf("%lld",&k)>0){
		vector<pair<ll,ll>>ans;
		ll x,y=k;
		while(++y){
			ll x=(k*y)/(y-k);
			if(x<y)break;
			if(x*(y-k)==(k*y))ans.push_back({x,y});
		}
		sort(ans.rbegin(),ans.rend());
		printf("%d\n",ans.size());
		for(auto [x,y]:ans){
			printf("1/%lld = 1/%lld +1/%lld\n",k,x,y);
		}
	}
	return 0;
}
