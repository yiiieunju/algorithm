#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer(2,0);

    // 특정 범위의 보석
    // 오른쪽으로 직진하다가 모든 보석이 하나씩 생기는 순간이 오면 슬라이딩 윈도우

    map<string, int> m;
    set<string> s(gems.begin(), gems.end());

    vector<pair<int,int>> v;

    int start=0, end=0;
    int cnt = s.size();
    int distance = gems.size();
    cout << cnt<<endl;

    //보석이 0인게 없으면 정답+=1
    //보석이 0인게 없어지면 start를 오른쪽으로 옮기기
    
    while(1){
        // for(int i=start ; i<end; i++)
        //  cout << gems[i]<<" ";
        //  cout <<m.size()<<endl;

        if(cnt == m.size()){//보석을 다  찾았으면 start를 ++해서 범위를 줄여봄
            //보석의 개수가 1개이면 map에서 delete
            //그 외에는 개수만 --
            if(end - start < distance){
                distance = end - start;
                answer[0] = start+1;
                answer[1] = end;
                // v.push_back({start+1,end});

            }
            if(m[gems[start]]==1){
                m.erase(gems[start]);
            }
            else{
                m[gems[start]]--;
            }
            start++;
        }
        else if(end == gems.size()) break;
        else if(m.size() < cnt){    //보석을 다 못찾았으면
            m[gems[end]]+=1;
            end++;
        }
    }
    // for(auto V:v){
    //     cout << V.first<<" "<<V.second <<endl;
    // }
    for(auto a:answer){
        cout << a <<" ";
    }

    return answer;
}

int main(){

    vector<string> gems = {"ZZZ", "YYY", "NNNN", "YYY", "BBB"};
    // vector<string> gems = {"AA", "AB", "AC", "AA", "AC"};
    // vector<string> gems = {"DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA"};
    // vector<string> gems = {"DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA"};

    solution(gems);

    return 0;
}