#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b){
    int r=0;
    while(b!=0){
        r = a%b;
        a=b;
        b=r;
    }
    return a;
}

int gcd2(int a, int b){
    while(1){
        int r = a%b;
        if(r==0) return b; //r이 0 일 때, a와b의 최대공약수는 b이다.
        a =b;
        b=r;
    }
}

int main(){
    int a,b; cin >>a >> b;
    cout << gcd(a,b)<<endl;
    cout << a*b/gcd(a,b);

    return 0;
}