#include <bits/stdc++.h>

#define MAX 5

using namespace std;

int arr[MAX];
bool select[MAX];

void print(){
    for(int i=0; i<MAX; i++){
        if(select[i] == true)
            cout << arr[i]<<" ";
    }
    cout <<"\n";
}


void dfs(int idx, int cnt){
    if(cnt == 3){
        print();
        return;
    }


    for(int i=idx; i<MAX; i++){
        if(select[i]==true)
            continue;
        
        select[i] = true;

        dfs(i, cnt+1);
        select[i] = false; 
        // 앞전에 이미 쓴 수이지만
        // 그 다음 회차에 쓰게하려고 false로 해제시켜줌
    }
}

int main(){

    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    arr[3] = 4;
    arr[4] = 5;

    dfs(0,0);

    return 0;
}