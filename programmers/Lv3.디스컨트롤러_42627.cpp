#include <bits/stdc++.h>

using namespace std;

struct compare{
    bool operator()(vector<int> a, vector<int> b){
        if(a[1] >b[1]) return true;
        else if(a[1]==b[1]) return true;
        return false;
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int time=0;
    int index=0;
    priority_queue<vector<int>, vector<vector<int>>, compare> pq;
    sort(jobs.begin(), jobs.end());

    while(!pq.empty() && index < jobs.size()){
        //time 기준에 실행 가능한 job push  
        if(index < jobs.size() || time >= jobs[index][0]){
            pq.push(jobs[index]);
            index+=1;
            continue;
        }
        //실행가능한 job이 큐에 있다면
        if(!pq.empty()){
            time+=pq.top()[1]; //현재 시간을 큐의 작업 종료 시간으로 업데이트
            answer+= time-pq.top()[0];  // 현재 job의 종료시간 - 현재 job이 들어온 시간  = 기다린 시간
            pq.pop();   //사용한 job제거
        }
        //없다면 다음에 실행 가능한 시간으로 업데이트 
        else{
            time = jobs[index][0];
        }
    }
    return answer/jobs.size();
} 

int main(){
    vector<vector<int>> jobs = {{0, 3}, {1, 9}, {2, 6}};
    cout <<solution(jobs);
    return 0;
}