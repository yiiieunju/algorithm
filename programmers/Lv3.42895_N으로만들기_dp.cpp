
#include <bits/stdc++.h>

using namespace std;


//나누기, 곱하기 더하기 빼기
//중요한 부분! N을 최대 N번 사용해서 숫자를 만든다



int solution(int N, int number) {

    if(number==N) return 1;
    
    set<int> dp[9];
    int iter = 0;
    for(int i=1; i<=8; i++){
        iter = (iter*10)+N;
        dp[i].insert(iter); //N, NN, NNN, NNN, NNNN, NNNNN,...
        //각 set에다가 i개로 만들어진 N값을 넣어준다
    }

    // for(int i=1; i<=8; i++){
    //     for(auto d : dp[i]){
    //         cout << d <<" ";
    //     }
    //     cout <<endl;
    // }

    for(int i=1; i<=8; i++){
    //     //1~i(N의 개수)를 써서 사칙연산
    //     //전 index 상에서 사칙연산 된 결과를 다음 set에 insert
        for(int j=1; j<i; j++){

            for(auto op1 : dp[j]){
                for(auto op2 : dp[i-j]){

                    dp[i].insert(op1+op2);
                    dp[i].insert(op1-op2);

                    if(op1!=0&&op2!=0){
                        dp[i].insert(op1/op2);
                        dp[i].insert(op1*op2);
                    }
                    
                }
            }
        }
        if(dp[i].find(number)!=dp[i].end()){
            //  for(int i=1; i<=8; i++){
            //     cout <<i<<" :"<<endl;
            //     for(auto d : dp[i]){
            //         cout << d <<" ";
            //     }
            //     cout <<endl;
            // }
            return i;
        } 
    }
    return -1;
}

int main(){

    int N, number;
    cin >> N;
    cin >> number;
    
    cout << solution(N, number);


    return 0;
}