
#include<iostream>
#include<stack>
#include<cstring>
using namespace std;
int main()
{printf("enter size\n");
int n;
scanf("%d",&n);
    string c[n];
    stack<int> S;
    
    printf("enter parenthesis\n");
    scanf("%s",&c);
for(int i=0;i<n-1;i++){
if(c[i]=='('||c[i]=='{'||c[i]='[')
S.push(c[i]);
     else if(c[i]==')' || c[i]=='}'|| c[i]==']')
    {
    if(!S.empty()==0 ||S.top()!=c[i] )
    return(false);

    else
    S.pop();
    }
    }
    return (!S.empty()?true:false);
}
