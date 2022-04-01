#include <string>
#include <vector>
#include <cctype>
#include <iostream>
using namespace std;
//문자 치완및 변형 
string solution(string new_id) {
    string answer = "";
    string edit_id = new_id;
    string::iterator it = edit_id.begin(); 
    while (it != edit_id.end()){
        if(!islower(*it)) *it = tolower(*it);
        ++it;
    }
    cout << edit_id << endl;
    it = edit_id.begin(); 
    while (it != edit_id.end()){
        if(!(islower(*it) || isdigit(*it) || *it == '-' || *it =='_' || *it =='.')) edit_id.erase(it), it = edit_id.begin();
        else ++it;
    }
    cout << edit_id << endl;
    it = edit_id.begin(); 
    while (it != edit_id.end()){
        if(*it == '.' and *(it+1) == '.') edit_id.erase(it), it = edit_id.begin();
        else ++it;
    }
    cout << edit_id << endl;
    it = edit_id.begin(); 
    while (it != edit_id.end()){
        if(*it == '.' and (it == edit_id.begin() || it == edit_id.end())) edit_id.erase(it), it = edit_id.begin();
        else ++it;
    }   
    cout << edit_id << endl;
    if(edit_id.size() <= 0) edit_id += "a";
    cout << edit_id << endl;
    if(edit_id.size() >= 16) edit_id = edit_id.substr(0,15);
    cout << edit_id << endl;
    if(*(edit_id.end()-1)== '.') edit_id.pop_back();
    cout << edit_id << endl;
    if(edit_id.size() <= 2) while(edit_id.size() < 3) edit_id += *(edit_id.end() - 1);
    cout << edit_id << endl;
    answer = edit_id;
    return answer;
}

int main(){
    string answer = solution("abcdefghijklmn.p");
    printf("%s\n", answer.c_str());
    return 0;
}