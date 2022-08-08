#include <bits/stdc++.h>

using namespace std;

bool visited[20001] = {false};
vector<int> dist(20001,0xffffff);
vector<int> vertex[20001];

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;

    //선처리
    for(auto e : edge){
        vertex[e[0]].push_back(e[1]);
        vertex[e[1]].push_back(e[0]);
    }

    //bfs

    queue<int> q;
    q.push(1);
    visited[1] = true;
    dist[0]=0;
    dist[1]=0;

    while(!q.empty()){
        int x = q.front();
        q.pop();

        for(int i=0; i<vertex[x].size(); i++){
            int nx=vertex[x][i];
            
            if(visited[nx]) continue;
            visited[nx]=true;
            dist[nx] = min(dist[nx],dist[x] + 1);
            q.push(nx);
        }
    }
    
    int maxdist = *max_element(dist.begin(), dist.begin()+n);

    for(auto d : dist){
        if(d==maxdist) answer+=1;
    }
    return answer;
}

int main(){

    int n=6;
    vector<vector<int>> edge = {{3, 6}, {4, 3}, {3, 2}, {1, 3}, {1, 2}, {2, 4}, {5, 2}};
    cout << solution(n,edge);

    return 0;
}