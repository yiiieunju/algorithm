#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;

    //모든 문장 검사
    for(int i=0; i<targets.size(); i++){
        string target = targets[i];

        int sumCnt = 0;        
        bool isInKeyMap = false;
        
        for(int j=0; j<target.size(); j++){
            isInKeyMap = false;
            //각 알파벳이 최소 몇번 눌려져야하는지 모든 키맵에서 확인
            int minCnt = 102;
            //모든 키맵 눌러보기
            char ch = target[j];
            for(int k=0; k< keymap.size(); k++){    //어떤 키맵
                for(int c=0; c<keymap[k].size(); c++){  //몇번째 자리
                    //키맵에 같은 문자가 있을 때 최소값이면 갱신
                    if(keymap[k][c] == ch){
                        minCnt = min(minCnt, c+1);
                        isInKeyMap = true;
                        break;
                    }
                }    
            }   
            //안눌러졌으면 더하지않고 멈추기
            if(!isInKeyMap)
                break;
            else
                sumCnt += minCnt;
        }   
        
        if(!isInKeyMap) answer.push_back(-1);
        else answer.push_back(sumCnt);
    }
    
    return answer;
}


int main(){
    vector<string> keymap = {"ABACD", "BCEFD"};
    vector<string> targets = {"ABCD","AABB"};       

    vector<int> ans = solution(keymap, targets);

    for(auto a : ans)
        cout <<a <<endl;
    return 0;
}