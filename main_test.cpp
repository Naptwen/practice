#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int solution(vector<vector<int>> quest) {
    int answer = 0;
    int  n = 0;
    int exp = 0;
    while(n < quest.size())
    {
        if(exp >= quest[n][0]){
            
            exp += quest[n][1];
            quest.erase(quest.begin() + n);
            answer++;
            n = 0;
            continue;
        }
        else
        {
            n++;
        }
    }
    return answer;
}

int main(){
    vector<vector<int>> test  = {{7,4}, {2,4}, {13,5}, {0,3}, {14,10}};
    int ans = solution(test);
    printf("%d\n",ans);
    return 0;
}