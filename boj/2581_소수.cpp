#include <bits/stdc++.h>

using namespace std;

int main(){
    int M, N;
    cin >> M >> N;

    vector<int> v;
    
    for(int i=M; i<=N; i++){
        bool isPrime=true;
        for(int j=2; j<i; j++)
            if(i%j==0){
                isPrime=false;
                break;
            } 
        if(i!=1&&isPrime)v.push_back(i);
    }

    if(!v.size()) cout << -1<<endl;
    else{
        int sum=0;
        for(auto v_ : v)
            sum+=v_;
        cout <<sum<<endl;

        int minNum=0xFFFFFF;
        for(auto v_ : v)
            minNum = min(minNum, v_);
        cout <<minNum<<endl;
    }

    


    return 0;
}