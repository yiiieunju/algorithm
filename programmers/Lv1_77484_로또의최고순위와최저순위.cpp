#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    vector<int> score = {6,6,5,4,3,2,1,0};
    
    int zero = 0;
    int same = 0;
    for(int i=0; i<lottos.size(); i++){
        if(lottos[i]==0){
            zero+=1;
            continue;
        }
        for(int j=0; j<win_nums.size(); j++){
            if(win_nums[j]==lottos[i]){
                same+=1;
            }
        }
    }

    
    answer.push_back(score[same+zero]);
    answer.push_back(score[same]);
    
    
    return answer;
}