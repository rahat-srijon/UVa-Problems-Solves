#include <stdio.h>
#include <string.h>
char s[140]={0};
int top,f;
void push(int c)
{
    s[top]=c;
    top++;
}
void pop()
{
    if(top==0)return;
    top=top-1;
}
char tot()
{
    int c;
    if(top==0)return -1;
    c=s[top-1];
    return c;
}
int main()
{
    int j,i,f,t,n;
    scanf("%d%*c",&n);
    char P[140];
    for(j=0;j<n;j++){
        gets(P);
        top=0;
        f=0;
        for(i=0;i<strlen(P);i++){
            if(P[i]=='('||P[i]=='[')push(P[i]);
            else if(P[i]==')' && tot()=='(' && top!=0)pop();
            else if(P[i]==']' && tot()=='[' && top!=0)pop();
            else f=1;
        }
        if(top==0&&f==0)printf("Yes\n",s);
        else printf("No\n",s);
    }
    return 0;
}
