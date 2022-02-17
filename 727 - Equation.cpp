#include<bits/stdc++.h>
using namespace std;
int p(char C){
	return C=='*'||C=='/'?1:C=='+'||C=='-'?0:-1;
}
string in2post(string S){
	string ret="";
	stack<char>stk;
	for(int i=0;i<S.size();i++){
		if(S[i]>='0'&&S[i]<='9'){
			ret+=S[i];
		}
		else if(S[i]=='('){
			stk.push('(');
		}
		else if(S[i]==')'){
			while(stk.top()!='('){
				ret+=stk.top();
				stk.pop();
			}
			stk.pop();
		}
		else{
			while(!stk.empty()&&p(S[i])<=p(stk.top())){
				ret+=stk.top();
				stk.pop();
			}
			stk.push(S[i]);
		}
	}
	while(!stk.empty()){
		ret+=stk.top();
		stk.pop();
	}
	return ret;
}
int main()
{
	int t;
	scanf("%d ",&t);
	while(t--){
		string sss="";
		char C;
		while(scanf("%c",&C)>0&&C!='\n'){
			scanf("%*c");
			sss+=C;
		}
		printf("%s\n",in2post(sss).c_str());
		if(t)printf("\n");
	}
	return 0;
}
