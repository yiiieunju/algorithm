#include <bits/stdc++.h>

using namespace std;

bool solution(int x) {
    bool answer = true;
    vector<int> lst;
    int tmp=x;
    while(x>0){   
        lst.push_back(x%10);
        x=x/10;
    }
    int sum = accumulate(lst.begin(), lst.end(),0);
    if(tmp%sum) answer = false;
    
    return answer;
}