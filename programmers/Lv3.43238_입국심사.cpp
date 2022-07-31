#include <bits/stdc++.h>

using namespace std;

// long long solution(int n, vector<int> times) {
//     long long answer = 0;
    
//     priority_queue<pair<long long ,int> > pq;
    
//     for(int i=0; i<times.size(); i++)
//         pq.push({-times[i], i});
    
//     int min_time, cur_idx;
//     for(int i=1; i<=n; i++){
//         // 7,10, pop, 10,14, pop, 14,20 pop, 20,21, pop 21,30, pop, 30,28, pop  14 20 21 end_time도 계산해준다.
//         min_time = pq.top().first;
//         cur_idx = pq.top().second;
//         pq.pop();
//         pq.push({min_time-times[cur_idx], cur_idx});
//     }
//     answer = -1*min_time;
//     return answer;
// }


long long solution(int n, vector<int> times) {
    long long answer = 0;
    long long start = 1;
    long long end = *max_element(times.begin(), times.end()) * (long long)n;
    
    while(start <=end){
        long long mid = (start + end) / 2;
        long long cnt = 0;
        for(auto t :times)
            cnt += (mid/t);

        if(cnt < n) //처리 가능한 사람 수가 N보다 적을때 -> 시간을 늘려야 함
            start = mid+1;
        else{    //mid 시간동안 처리 가능한 사람 수가 N보다 많이 처리할 수 있을 때
            end = mid-1;
            answer = mid;
        }
    }

    return answer;
}
