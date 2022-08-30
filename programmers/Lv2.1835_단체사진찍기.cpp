#include <bits/stdc++.h>

using namespace std;

vector<char> ppl = {'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};
bool selected[8];
vector<char> tmp;
int answer = 0;

bool check_diff(int diff, int condi_diff, char condi){
    if(diff > condi_diff) return condi == '>';
    else if(diff < condi_diff) return condi == '<';
    else return condi == '=';
}

bool check(vector<string> data){
    bool condi = true;
    string tmpstr = "";

    for(auto t : tmp) tmpstr+=t;

    //이 조건을 모두 만족하는 지 체크
    for(auto condition:data){
        int first = tmpstr.find(condition[0]);
        int second = tmpstr.find(condition[2]);
        int diff = abs(first - second) -1;
        if(!check_diff(diff, condition[4]-'0',condition[3])){
            condi = false;
            break;
        }
    }

    return condi;
}


void dfs(int index, int cnt, vector<string> data){

    if(cnt==8){
        if(check(data)) answer+=1;
    }

    for(int i=0; i<8 ; i++){
        if(selected[i]==true) continue;
        selected[i] = true;
        tmp.push_back(ppl[i]);
        dfs(i,cnt+1,data);
        tmp.pop_back();
        selected[i]=false;
    }

}

int solution(int n, vector<string> data) {
    answer = 0;
    dfs(0,0, data);
    return answer;
}

int main(){
    int n=2;
    vector<string> data = {"N~F=0", "R~T>2"};
    // vector<string> data = {"M~C<2", "C~M>1"};

    cout << solution(n,data);
    return 0;
}