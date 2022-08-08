#include <bits/stdc++.h>

using namespace std;

vector<int> v;
vector<int> c;
set<int> s;
vector<int> answer;
bool selected[100];

void dfs(int index, int cnt){
    if(cnt ==2){
        s.insert(c[0]+c[1]);
        return;
    }
    
    for(int i=index; i<v.size(); i++){
        if(selected[i]) continue;
        
        selected[i] = true;
        c.push_back(v[i]);
        dfs(i, cnt+1);
        c.pop_back();
        selected[i] = false;
    }
    
}

vector<int> solution(vector<int> numbers) {
    
    
    v.resize(numbers.size());
    copy(numbers.begin(), numbers.end(), v.begin());
    fill(&selected[0], selected+100, false);
    
    dfs(0,0);
    answer.resize(s.size());
    copy(s.begin(), s.end(), answer.begin());
    return answer;
}