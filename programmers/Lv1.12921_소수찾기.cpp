#include <bits/stdc++.h>
using namespace std;

int solution(int n) {
    bool arr[n+1];    
    fill(arr, arr+n+1,false);
    arr[0] = arr[1] = true;
    
    int answer = 0;
       
    for(int i=2; i<=n; i++){
        if(arr[i]) continue;
        for(int j=i*2; j<=n; j+=i){
            arr[j] = true;
        }
    }
    
    for(int i=2; i<=n; i++)
        if(!arr[i])
            answer+=1;
    
    return answer;
}