#include <bits/stdc++.h>

using namespace std;

int arr[50][50];
int check_arr[50][50];
bool visited[50][50];
int N, L, R;
int dirX[] = {1,0,-1,0};
int dirY[] = {0, 1,0,-1};

bool check_turn=false;

bool check_union(int a, int b){
    //���� ĭ�� ���� ĭ ��
    int diff = a-b<0 ? b-a : a-b;
    if(diff >=L && diff <= R) return true;
    return false;
}


void bfs(int i, int j){
    if(check_arr[i][j]=1) return;
    check_turn=0;

    //bfs
    queue<pair<int,int> > q;
    q.push({i,j});
    visited[i][j] = true;

    vector<pair<int,int> > people;
    while(!q.empty()){
        pair<int,int> tmp;
        tmp = q.front();
        q.pop();

        int x = tmp.first;
        int y = tmp.second;


        for(int d=0; d<4; d++){
            int nx=x+dirX[d]; int ny= y+dirY[d];

            if(nx <0 || nx>N-1 || ny < 0 || ny >N-1 || visited[nx][ny])
                continue;

                if(check_union(arr[x][y], arr[nx][ny])){
                    if(people.size()==0) people.push_back({x,y});
                    people.push_back({nx,ny});

                    visited[nx][ny] = true;
                    q.push({nx,ny});
                }
        }

        //ť�� 0�� �� �� �α� ����
        if(q.empty()){
            int sum=0;
            for(int i=0; i<people.size(); i++){
                int x=people[i].first;
                int y=people[i].second;

                sum += arr[x][y];
            }

            int avg = sum / people.size();

            //�α� ����
            for(int i=0; i<people.size(); i++){
                int x=people[i].first;
                int y=people[i].second;

                check_arr[x][y]=1;

                arr[x][y]=avg;
            }


        }
    }
}

bool condition1(int x, int y){
    int d;
    for(int i=0; i<4; i++){
        int nx=x+dirX[d];
        int ny= y+dirY[d];

        if(nx <0 || nx>N-1 || ny < 0 || ny >N-1){
            if(check_union(arr[x][y], arr[nx][ny])) return true;
        }
    }
    return false;
}

void solve(){

    int day = 0;

    while(check_turn){

        check_turn = false;

        // �α��̵��� �Ͼ�� �ʾ����鼭
        // �����¿� ���ؼ� �α��̵��� �Ͼ�� ������ üũ
        for(int i=0; i<N; i++){
            for(int j=0; i<N; j++){
                if(visited[i][j] == false && condition1(i,j)){
                     bfs(i,j);
                     check_turn = true;
                }
            }
        }

        if(check_turn) day++;
        fill(visited, visited+N*N, false);

    }



}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);


    //input
	cin >> N >> L >>R;

	for(int i=0; i<N; i++){
        for(int j=0; i<N; j++)
            cin >> arr[i][j];
	}



    solve();



	return 0;
}
