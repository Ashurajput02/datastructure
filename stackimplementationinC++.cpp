#include<iostream>
#include<stack>
#include<cstring>
using namespace std;
int main()
{
    stack<int> S;
    S.push(50);
    S.push(150);
    S.push(250);
    S.push(350);
    S.push(450);
    printf("%d\n",S.top());
S.pop();
S.pop();

    printf("%d",S.top());
    

}