#include <bits/stdc++.h>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    
    // double a = sqrt(n);
    //long long 자료형을 사용하므로 n의 제곱근이 자연수가 아닌 경우, 값은 정수형으로 바뀌어 저장된다.
    long long a = sqrt(n);
    
    if(a*a == n) return pow(a+1,2);
    else return -1;
    
    return answer;
}