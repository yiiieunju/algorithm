#include <bits/stdc++.h>

using namespace std;

int N; 
string strs;
int answer = -0xffffff;

//계산하는 함수
int calc(int a, int b, char oper){
    int result = a;

    if(oper=='+') result+=b;
    else if(oper=='*') result*=b;
    else result-=b;

    return result;
} 

void dfs(int index, int curVal){

    //1. 종료조건
    if(index > N-1){
        //answer = max(maxAns, curVal);
        return;
    }

    char oper = (index == 0) ? '+': strs[index - 1];

    //2. 괄호로 묶기
    if(index+2 < N){
        //괄호 먼저 계산
        int bracket = calc(strs[index]-'0', strs[index+2]-'0', strs[index+1]);
        //현재값에 괄호 계산한걸 더하기
        dfs(index+4, calc(curVal, bracket, oper));
    }
    //3. 괄호 안묶고 계산하기 1+3 *4-1+2 1개 값 사용
    dfs(index+2, calc(curVal,strs[index]-'0', oper)); 
}

int main(){

    cin >> N >> strs;
    dfs(0, 0);
    cout << answer;

    return 0;
}