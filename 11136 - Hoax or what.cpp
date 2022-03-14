#include<bits/stdc++.h>
using namespace std;
int main(){
	while(1){
		int n;
		scanf("%d",&n);
		if(!n)break;
		multiset<int>S;
		long long int t=0;
		for(int i=0;i<n;i++){
			int m;
			scanf("%d",&m);
			for(int i=0;i<m;i++){
				int x;
				scanf("%d",&x);
				S.insert(x);
			}
			int mn=0,mx=0;
			if(!S.empty()){
				auto it=S.begin();
				mn=*it;
				S.erase(it);
			}
			if(!S.empty()){
				auto it=S.rbegin();
				mx=*it;
				S.erase(S.find(*it));
			}
			t+=abs(mx-mn);
		}
		printf("%lld\n",t);
	}
	return 0;
}
