#include <bits/stdc++.h>

using namespace std;

bool check_diff(int diff, int condi_diff, char oper){
    if(diff > condi_diff) return oper == '>';
    else if(diff < condi_diff) return oper == '<';
    else return oper == '=';
}

int solution(int n, vector<string> data) {
    int answer = 0;
    string charactor = "ACFJMNRT";

    sort(charactor.begin(), charactor.end());

    do{

        //이 조건을 모두 만족하는 지 check
        bool check = true;
        for(auto condi:data){
            int first = charactor.find(condi[0]);
            int second = charactor.find(condi[2]);
            int diff = abs(first-second) - 1;
            
            if(!check_diff(diff, condi[4]-'0',condi[3])){
                check = false;
                break;
            }
        }
        if(check) answer+=1;

    }  while(next_permutation(charactor.begin(), charactor.end()));
    
    return answer;
}

int main(){
    int n=2;
    vector<string> data = {"N~F=0", "R~T>2"};
    // vector<string> data = {"M~C<2", "C~M>1"};
    cout << solution(n,data);
    return 0;
}