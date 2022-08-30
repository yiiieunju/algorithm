#include <bits/stdc++.h>

using namespace std;

int N,M;
string board[100];
bool visited[100][100]={false};
vector<vector<int > > dist(100,vector<int>(100,0));
int dirX[4] = {-1,0,1,0};
int dirY[4] = {0,1,0,-1};


void bfs(int x, int y){
    queue<pair<int,int>> q;
    q.push({x,y});
    visited[x][y] = true;
    
    while(!q.empty()){
        pair<int,int> tmp = q.front();
        q.pop();

        for(int i=0; i<4; i++){
            int nx = tmp.first + dirX[i];
            int ny = tmp.second + dirY[i];
                    
            if(nx < 0 || nx >N-1 || ny <0 || ny>M-1) continue;
            if(visited[nx][ny] || board[nx][ny]=='0')  continue;

            visited[nx][ny] = true;
            dist[nx][ny] = dist[tmp.first][tmp.second] + 1;
            q.push({nx,ny});
        }
    }

}

void solve(){

    bfs(0,0);
    cout << dist[N-1][M-1]+1;

}

int main(){

    
    cin >> N >> M;
    for(int i=0; i<N; i++)
        cin >> board[i];

    solve();

    return 0;
}