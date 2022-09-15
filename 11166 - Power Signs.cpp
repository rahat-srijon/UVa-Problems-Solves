#include<bits/stdc++.h>
using namespace std;
#define ll long long
string S;
int main() {
	while(cin>>S){
		if(S[0]=='0')break;
		else{
			S="0"+S;
			for(int i=S.size()-1;i;i--){
				if(S[i]=='1'){
					int s=i;
					while(S[s]=='1')s--;
					if(i-s>=2){
						if(!s&&i-s==2){
							S[++s]='+';
							S[++s]='+';
						}
						else{
							S[i]='-';
							S[s]='1';
							while(++s<i){
								S[s]='0';
							}
						}
					}
					else S[i]='+';
				}
			}
			if(S[0]=='1')S[0]='+';
			else S.erase(S.begin());
			cout<<S<<"\n";
		}
	}
	return 0;
}
