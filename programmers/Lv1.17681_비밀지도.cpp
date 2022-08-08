#include <bits/stdc++.h>

using namespace std;

int N;

vector<int> to_binary(int num){
    vector<int> tmp(N,0);
    int i=0;
    while(num > 0){
        tmp[i]=num%2;
        num = num/2;
        i+=1;
    }
    return tmp;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    N=n;
    
    vector<int> arr;
    vector<int> bina1;
    vector<int> bina2;
    
    for(int i=0; i<arr1.size(); i++){
        bina1 = to_binary(arr1[i]);
        bina2 = to_binary(arr2[i]);

        vector<int> bina3;       
        for(int i=0; i<bina1.size(); i++){
            if(bina1[i]==1 || bina2[i] == 1)
                bina3.push_back(1);
            else
                bina3.push_back(0);
        }
        
        reverse(bina3.begin(), bina3.end());
        
        string tmp="";
        for(auto bin :bina3)
            if(bin==1) tmp+="#";
            else tmp+=" ";
        
        answer.push_back(tmp);
    }
    return answer;
}