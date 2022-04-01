#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <iostream>
using namespace std;
//나갔다 들어오는거 변경하기
vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string>  dict;
    vector<string> text;
    for(string  vec : record){
        stringstream str(vec);
        string temp[3];
        getline(str,temp[0], ' ');
        getline(str,temp[1], ' ');
        if(temp[0].compare("Enter")==0|| temp[0].compare("Change")==0) 
            getline(str,temp[2], ' '),
            dict[temp[1]] = temp[2];
        text.push_back(temp[1]);
        text.push_back(temp[0]);
    } 
    for(int i = 0; i< text.size(); i +=2){
        if(text[i + 1].compare("Enter") == 0) answer.push_back(dict[text[i]] + "님이 들어왔습니다.");
        else if(text[i + 1].compare("Leave") == 0)  answer.push_back(dict[text[i]] + "님이 나갔습니다.");
    }
    return answer;
}

int main(){
    string  a[] = {"Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo",
                    "Change uid4567 Ryan", "Enter uid1234 Mazzi", "Enter uid4567 asd","Leave uid1234"} ;
    vector<string> sv(a, a+sizeof(a)/sizeof(string));
    solution(sv);
    return 0;
}