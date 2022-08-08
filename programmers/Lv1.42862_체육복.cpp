#include <bits/stdc++.h>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    //여벌 체육복이 있는 학생 중 도난당한 학생 제외
    for(int i=0; i<lost.size(); i++){
        for(int j=0; j<reserve.size(); j++){
            if(reserve[j] == lost[i]){
                reserve.erase(reserve.begin()+j);
                lost.erase(lost.begin()+i);
                i-=1;
                break;
            }
        }
    }
    
    answer = n-lost.size();
    
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    
    //lost를 가지고 모든 reserve들을 보면서 빌려 줄 사람이 잇는 지 확인한다.
    for(int i=0; i<lost.size(); i++){
        for(int j=0; j<reserve.size(); j++){
            if(lost[i]-1 == reserve[j] || lost[i]+1 == reserve[j]){
                answer++;
                reserve.erase(reserve.begin()+j);
                break;
            }
        }
    }
    
    return answer;
}