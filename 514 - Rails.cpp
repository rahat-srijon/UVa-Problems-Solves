#include<bits/stdc++.h>
using namespace std;
int main(){
	bool sp=0;
	while(1){
		if(sp)printf("\n");
		else sp=1;
		int n,x;
		bool cs=0;
		scanf("%d",&n);
		if(!n)break;
		while(1){
			stack<int>A,B,S;
			for(int i=0;i<n;i++){
				scanf("%d",&x);
				if(!x){
					cs=1;
					break;
				}
				B.push(x);
			}
			if(cs)break;
			bool go=1;
			A.push(n+1);
			while(1){
				if(!S.empty()){
					if(A.top()==S.top()+1){
						A.push(S.top());
						S.pop();
					}
					else if(!B.empty()){
						S.push(B.top());
						B.pop();
					}
					else break;
				}
				else{
					if(!B.empty()){
						S.push(B.top());
						B.pop();
					}
					else break;
				}
			}
			if(A.size()<n+1)printf("No\n");
			else printf("Yes\n");
		}
	}
	return 0;
}
