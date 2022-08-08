#include <bits/stdc++.h>

using namespace std;

//O(n)
bool isprime1(int n){
    if(n < 2) return false;

    for(int i=2; i<=n; i++)
        if(n%i==0) return false;
    return true;

}

//O(root n)
bool isprime2(int n){
    if(n < 2) return false;

    for(int i=2; i*i<=n; i++)
        if(n%i==0) return false;
    return true;

}

bool isprime3(int n){
    if(n < 2) return false;

    for(int i=n*n; i<=n; i+=n)
        if(n%i==0) return false;
    return true;

}

//아리트소테네스의 체
//o(nlogn(logn))
bool isprime4(int n){
    bool arr[n+1];
    arr[0]=true; arr[1]=true;

    for(int i=2;i<=n;i++) {
        if(arr[i]) continue; // 이미 지워진 수라면 건너뜀
        // 이미 지워진 숫자가 아니라면, 해당 숫자의 배수를 모두 true로 만듦
        for(int j=2*i;j<=n; j+=i) {
            arr[j] = true;
        }
    }

}

// 81의 약수는 1, 3, 9, 27, 81
bool isprime5(int n){
    if(n < 2) return false;

    for(int i=2; i<=sqrt(n); i+=n)
        if(n%i==0) return false;
    return true;

}

int main(){

    for(int i=2; i<100; i++)
        if(isprime1(i)) cout << i<<" ";

    isprime4(120);
    return 0;
}