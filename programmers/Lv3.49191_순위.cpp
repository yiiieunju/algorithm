#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b){
    return a.first < b.first;
}

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    vector<vector<int> > winner(n+1,vector<int>());
    
    //방향이 있는 그래프 만들기
    for(int i=0; i<results.size(); i++){
        int win = results[i][0];
        int lose = results[i][1];
        winner[win].push_back(lose);
    }

    vector<int> lose_cnt(n+1,0); //각 노드가 몇명에게 졌는지
    vector<int> rank_cnt(n+1,0); //순위가 몇개인지
    vector<pair<int,int>> rank;
    for(int player=1; player<=n; player++){
        bool visited[n+1];
        fill(visited,visited+n+1,false);
        
        //node를 담을 곳
        queue<int> q;
        q.push(player);
        visited[player] = true;
        while(!q.empty()){
            int tmp=q.front();
            q.pop();
            //내가 이긴사람 찾아가기
            for(int i=0; i<winner[tmp].size(); i++){
                int next_player = winner[tmp][i];
                if(visited[next_player]) continue;
                q.push(next_player);
                lose_cnt[next_player]+=1;
                visited[next_player]=true;
            }
        }
    }

    //각 노드가 진 횟수가 적은 순으로 sort
    for(int node=1; node<lose_cnt.size(); node++){
        //rank_cnt
        rank_cnt[lose_cnt[node]]+=1; 
        rank.push_back({lose_cnt[node],node});
    }
    rank_cnt[0]=2
    rank_cnt[1]=1
    rank_cnt[3]=1
    rank_cnt[4]=1
    
    sort(rank.begin(),rank.end(),cmp);

    for(int i=0; i<rank.size(); i++)
        if(rank[i].first == i && rank_cnt[rank[i].first]==1) 
            answer+=1;
 
    return answer;
}

int main(){
    int n = 5;
    // vector<vector<int>> results = {{4, 3}, {4, 2}, {3, 2}, {1, 2}, {2, 5}};
    vector<vector<int>> results = {{1, 4}, {4, 2}, {2, 5}, {5, 3}};
    cout << solution(n, results);
    return 0;
}
