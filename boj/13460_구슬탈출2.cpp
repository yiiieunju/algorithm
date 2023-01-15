#include <bits/stdc++.h>

using namespace std;

struct{
    int x; int y; int cnt;
}typedef Point;

struct{
    Point R, B;
    int stage;
}typedef Step;

//x,y에다가 r,b구분
bool visited[10][10][10][10];
char board[10][10];
int N, M;
int dirX[] = {-1,0,1,0};
int dirY[] = {0,-1,0,1};


void move(Point &p, int &dist, int d){
    // d 방향으로 끝까지 움직이기
    // #과 O를 만날 때까지 반복문 진행
    while(board[p.x+dirX[d]][p.y+dirY[d]]!='#' && board[p.x][p.y]!='O'){
        p.x += dirX[d];
        p.y += dirY[d];
        dist +=1;
    }
}

void bfs(Point r, Point b){
    queue<Step> q;
    q.push({r, b, 0});
    visited[r.x][r.y][r.x][r.y] = true;

    while(!q.empty()){
        //첫 stage의 구슬 꺼내기
        Point pr = q.front().R;
        Point pb = q.front().B;
        int stage = q.front().stage;
        q.pop();

        if(stage >= 10) break;

        for(int i=0; i<4; i++){
            Point npr = pr;
            Point npb = pb;
            int r_dist = 0, b_dist = 0;
            int nstage = stage+1;

            //r,b 각각 4방향으로 기울여서 좌표 변경
            move(npr, r_dist, i);
            move(npb, b_dist, i);

            //b공이 홀로 나오면 실패, 실행 큐에 넣지x
            if(board[npb.x][npb.y]=='O') continue;
            if(board[npr.x][npr.y]=='O'){
                cout << 1<<"\n";
                return;
            }

            //옮긴 위치가 r,b가 서로 겹치면
            if(npr.x ==npb.x && npr.y == npb.y){
                //더 많이 움직인거 한칸 뒤로
                if(r_dist > b_dist)
                    npr.x-=dirX[i], npr.y-=dirY[i];
                else
                    npb.x-=dirX[i], npb.y -=dirY[i];
            }

            if(visited[npr.x][npr.y][npb.x][npb.y]) continue;
            visited[npr.x][npr.y][npb.x][npb.y] = true;
            q.push({npr,npb, nstage});

        }
    }

    cout << 0;
}

int main(){

    
    cin >> N >> M;

    Point R, B;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> board[i][j];
            if(board[i][j] =='B')
                B = {i,j};
            
            else if(board[i][j]=='R')
                R = {i,j};
        }
    }
    bfs(R, B);


    //구슬 
    //바둑판을 기울이는 경우의 수를 bfs로
    //바둑판을 기울일 때 일어나는 상황
    //1. 벽을 만난다.
    //2. 구멍을 만난다.
    //3. 구슬을 만났다.
    return 0;
}







//https://hagisilecoding.tistory.com/112