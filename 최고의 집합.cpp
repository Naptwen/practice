#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>

using namespace std;
//최고의 집합 표준편차를 이용하여 가장 작은값 (너무 어렵게 풀었다 난 바보다)
vector<int> solution(int n, int s)
{
    if(s - n + 1 <= 0) return {-1};
    int x = s/n;
    int y = s%n;
    int* ans = (int*)calloc(n, sizeof(int));
    for(int i=n-1; i>= 0; i--){
        ans[i] = x + ((y > 0)? 1 : 0);
        y--;
    }
    vector<int> answer(ans, ans + n); 
    free(ans);
    return answer;
}
// Non linear optimazation
int main()
{
    vector<int> ans = solution(2, 9);
    for(auto vec: ans)
        cout << vec << ", ";
    cout<<endl;
    return 0;
}