#include<bits/stdc++.h>
using namespace std;
vector<stack<string> >V;
bool match(string A,string B){
	return A[0]==B[0]||A[1]==B[1];
}
void pile(int a,int b){
	V[a].push(V[b].top());
	V[b].pop();
	if(V[b].empty()){
		V.erase(V.begin()+b);
	}
}
void move(){
	bool go=0;
	for(int i=0;i<V.size()&&!go;i++){
		if(i>=3&&match(V[i].top(),V[i-3].top())){
			pile(i-3,i);
			go=1;
		}
		else if(i&&match(V[i].top(),V[i-1].top())){
			pile(i-1,i);
			go=1;
		}
	}
	if(go)move();
}
void draw(string C){
	stack<string>S;
	S.push(C);
	V.push_back(S);
	move();
}
int main(){
	while(1){
		V.clear();
		string C;
		cin>>C;
		if(C[0]=='#')break;
		stack<string>S;
		S.push(C);
		V.push_back(S);
		S.pop();
		for(int i=1;i<52;i++){
			cin>>C;
			draw(C);
		}
		printf("%d pile",V.size());
		if(V.size()>1)printf("s");
		printf(" remaining:");
		for(int i=0;i<V.size();i++){
			printf(" %d",V[i].size());
		}
		printf("\n");
	}
	return 0;
}
