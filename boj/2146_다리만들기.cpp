#include <bits/stdc++.h>

using namespace std;

#define MAX 100

int N;
int board[MAX][MAX];
int area[MAX][MAX];
int dirX[4] = {0,-1,0,1}; //left up right down
int dirY[4] = {-1,0,1,0};
bool visited[MAX][MAX];
int ans=0xFFFFFF;

void input(){
    cin >> N;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            cin >>board[i][j];

}

int make_bridge(int landNum){

    int dist=0;
    queue<pair<int,int>> q;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(area[i][j]==landNum){
                visited[i][j] = true;
                q.push({i,j});
            }
        }
    }

    while(!q.empty()){
        int landSize = q.size();
        for(int i=0; i<landSize; i++){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for(int j=0; j<4; j++){
                int nx = x+dirX[j];
                int ny = y+dirY[j];
                
                if(visited[nx][ny] || area[nx][ny]==landNum) continue;
                if(nx<0 || nx>=N || ny<0 || ny>=N) continue;    
                 if(area[nx][ny]!=0 && area[nx][ny]!=landNum) return dist;
                else if(area[nx][ny]==0){
                    visited[nx][ny] = true;
                    q.push({nx,ny});

                }
            }
        }

        dist+=1;
    }
    return 0xFFFFFF;
}

void bfs(int x, int y, int cnt){

    queue<pair<int,int> > q;
    q.push({x,y});
    visited[x][y] = true;
    area[x][y] = cnt;

    while(!q.empty()){
        pair<int,int> point;
        point = q.front();
        q.pop();

        // 1. 같은 섬 1,2, 3인지 
        // 2. 판을 벗어나지 않았는지
        // 3. 엣지인지 -> vector에 inserts
        for(int i=0 ; i<4; i++){
            int nx = point.first + dirX[i];
            int ny = point.second + dirY[i];  

            if(nx<0 || nx>=N || ny<0 || ny>=N) continue;
            if(visited[nx][ny]) continue;
            if(board[nx][ny] != 1) continue;

            visited[nx][ny] = true;
            q.push({nx,ny});
            area[nx][ny]=cnt;   

        }
    }
}

int make_label(){

    int cnt=1;

    fill(&visited[0][0], &visited[N-1][N], false);
    
    for(int i=0;i<N; i++){
        for(int j=0; j<N; j++){
            if(board[i][j] == 1 && !visited[i][j])
                bfs(i,j,cnt++);
        }
    }
    return cnt;
}

void solve(){
    int cnt = make_label();
    
    for(int i=1; i<cnt; i++){
        fill(&visited[0][0], &visited[N-1][N], false);
        ans = min(ans, make_bridge(i));
    }
    cout << ans;
}

int main(){
    input();
    solve();
    return 0;
}
//fill을 쓸 때는 row에 N-1을 넣어줘야한다 ㅠ 64%에서 계속 틀려서 뭔가 했다 ㅠ 