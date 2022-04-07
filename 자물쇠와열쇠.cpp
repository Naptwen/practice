#include <string>
#include <vector>
#include <iostream>
#include <bitset>
#include <climits>
using namespace std;



/*
010     001
010 ->  111 
111     001

100 
111
100          

111   
010
010

001
111
001           
*/
bool map_sum(vector<vector<int>>* key, vector<vector<int>> map, int a,  int b){
    for(int i = 0; i < key->size(); i++)
        for(int j = 0; j < key->size(); j++)
            map[a + i][b + j] += (*key)[i][j];

    for(int i = key->size() - 1; i <= map.size() - key->size(); i++)
        for(int j = key->size() - 1; j <= map.size() - key->size(); j++)
            if(map[i][j] != 1) return false;

    return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = true;
    vector<vector<int>> key2(key.size(),  vector<int>(key.size()));
    vector<vector<int>> key3(key.size(),  vector<int>(key.size()));
    vector<vector<int>> key4(key.size(),  vector<int>(key.size()));
    vector<vector<int>> map(lock.size() + key.size() * 2 - 2, vector<int>(lock.size() + key.size() * 2 - 2, 1)); 
    for(int i = 0; i < lock.size(); i++)
        for(int j = 0; j < lock.size(); j++){
            if(lock[i][j] == 0) map[i + key.size() - 1][j + key.size() - 1] = 0;
            if(i < key.size() && j < key.size()){
                key2[i][j] = key[j][key.size() - i - 1]; // , i = j / j = key.size() - i - 1
                key3[i][j] = key[key.size() - i - 1][key.size() - j - 1]; // i =key.size() - i - 1, j = key.size() - j - 1
                key4[i][j] = key[key.size() - j - 1][key.size() - (key.size() - i - 1) - 1]; // key4[i][j] = key3[j][key.size() - i - 1];
            }
        }
    for(int i = 0; i < lock.size(); i++)
        for(int j = 0; j < lock.size(); j++)
            if(lock[i][j] == 0) map[i + key.size() - 1][j + key.size() - 1] = 0;

    for(int i = 0; i <= map.size() - key.size(); i++)
        for(int j = 0; j <= map.size() - key.size(); j++){
            answer = map_sum(&key, map, i, j);
            if(answer) return answer;
            answer = map_sum(&key2, map, i, j);
            if(answer) return answer;
            answer = map_sum(&key3, map, i, j);
            if(answer) return answer;
            answer = map_sum(&key4, map, i, j);
            if(answer) return answer;
        }
    return false;
}
int main(){
    vector<vector<int>> key = {
        {1}};
    vector<vector<int>> lock = {
        {0}};
    bool ans = solution(key, lock);
    cout << ans  <<endl;
    return 0;
}