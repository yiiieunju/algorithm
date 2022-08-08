#include <bits/stdc++.h>

using namespace std;

int solution(string s){
    int answer = s.size();
    for(int n=1; n<s.size()/2+1; n++){
        string pattern = s.substr(0,n);
        string tmp ="";
        int cnt = 1;
        for(int i=n; i<s.size(); i+=n){
            string cmp = s.substr(i,n);
            if(pattern == cmp){
                cnt+=1;
            }
            else{
                if(cnt > 1) tmp+=to_string(cnt);
                tmp+=pattern;
                cnt = 1;
                pattern = s.substr(i,n);
            }
        }
        if(cnt > 1) tmp+=to_string(cnt);
        tmp+=pattern;
        answer = min(answer, (int)tmp.size());
    }
    return answer;
}

int main(){
    string s = "aabbaccc";
    cout << solution(s);
    return 0;
}