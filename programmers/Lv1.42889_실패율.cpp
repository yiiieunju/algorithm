#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<int,double> &a, pair<int,double> &b){
    if(a.second > b.second) return true;
    else if(a.second == b.second) return a.first<b.first;
    return false;  
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    map<int,double> m;
    vector<int> cur(N+2,0); //각 스테이지에 몇명잇는 지
    vector<int> challenger(N+2,0);    //각 스테이지에 몇명이 도전했는지
    
    for(int i=0; i<stages.size(); i++){
        for(int c=1; c<=stages[i]; c++){
            challenger[c]+=1;
        }
        cur[stages[i]] +=1;   
    }
    
    
    // N+1번까지 깬사람은  N번째까지 다 꺤거니까 실패율에 포함하지 않는다.
    for(int i=1; i<N+2 -1; i++){
        if(challenger[i]>0)
            m[i] = (double)cur[i]/(double)challenger[i];
        else
            m[i] =0;
    }
    
    vector<pair<int,double>> v;
    v.resize(m.size());
    copy(m.begin(), m.end(), v.begin());
    sort(v.begin(), v.end(), cmp);
    
    
    for(int i=0; i<v.size(); i++){
        answer.push_back(v[i].first);
    }
    

    return answer;
}