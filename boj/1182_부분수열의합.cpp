#include <bits/stdc++.h>

using namespace std;

int N, S;
int arr[20];
bool selected[20];
int sum=0;
int ans = 0;
void sequence_dfs(int index, int cnt){

    // if(cnt == N){  
    //     return;
    // }

    if(sum == S && cnt!=0)
        ans+=1;

    for(int i=index; i<N; i++){
        
        if(selected[i]) continue;

        selected[i] = true;
        sum+=arr[i];
        sequence_dfs(i, cnt+1);
        sum-=arr[i];
        selected[i] = false;
    }
}

int main(){


    cin >>N >> S;

    for(int i=0; i<N; i++)
        cin >> arr[i];

    sequence_dfs(0,0);
    cout << ans;

    return 0;
}