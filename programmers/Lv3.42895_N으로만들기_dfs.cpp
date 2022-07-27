
#include <bits/stdc++.h>

using namespace std;


//나누기, 곱하기 더하기 빼기
//중요한 부분! N을 최대 N번 사용해서 숫자를 만든다
int answer = 9;

void dfs(int N, int number,int calc, int cnt){
    if(cnt > 8) return; //최대 N개 사용 가능
    if(calc == number){
        answer = min(answer, cnt);
        return;
    }

    int iter=0;
    for(int i=1; i<=8; i++){
        iter=(iter*10)+N; // 1자리~ 8자리일 때
        
        dfs(N,number,calc+iter,cnt+i); //+
        dfs(N,number,calc-iter,cnt+i); //-
        
        if(calc==0) continue; // 현재 수가 0이면 *,/  할필요 없음
        dfs(N,number,calc/iter,cnt+i); ///
        dfs(N,number,calc*iter,cnt+i); //* 
    }

}

int solution(int N, int number) {

    dfs(N,number,0,0);

    return answer > 8 ? -1:answer;
}

int main(){

    int N, number;
    cin >> N;
    cin >> number;
    
    solution(N, number);


    return 0;
}