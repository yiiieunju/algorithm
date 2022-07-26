#include <bits/stdc++.h>

using namespace std;

#define N 5

int arr[100]={1,2,3,4,5,};
int selected[100];
vector<int> V;

void dfs(int cnt){
    if(cnt == 3) {
        for(auto v : V)
            cout << v << " ";
        cout <<"\n";
        return;
    }

    for(int i=0; i<N; i++){
        if(selected[i]) continue;
        selected[i] = true;
        V.push_back(arr[i]);
        dfs(cnt+1);
        V.pop_back();
        selected[i]=false;
    }
    

}

int main(){

    dfs(0);
    
    return 0;
}