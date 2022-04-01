#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

string string_edit(string txt, char x)
{
    string new_str;
    stringstream s(txt);
    string temp;
    while (getline(s, temp, x))
    {
        new_str += temp;
    }
    return new_str;
}

void rule2(string txt, map<char, vector<int>> lower_list, map<char, bool> *rs)
{
    for (auto vec : lower_list)
        if (vec.second.size() == 2 && (*rs).count(vec.first) != 1) //규칙 1과 2를 모두 만족하는 경우를 고려 하나만 선택 (알고리즘 순서에 따름)
        {
            int index1 = vec.second[0];
            int index2 = vec.second[1];
            if (index1 + 1 == index2 )// 2개의 같은 소문자가 붙어있을 경우 혹은 규칙 한단어에 두가지 규칙이 적용되었을 경우
            { 
                rs->clear(); //invalid
                break;
            }
            (*rs)[vec.first] = 1;
        }
}

void rule1(string txt, map<char, vector<int>> lower_list, map<char, bool> *rs)
{
    for (auto vec : lower_list)
    {
        bool check = false;
        if (vec.second.size() == 1) //한 글자일때
        {
            if (isupper(txt[vec.second[0] - 1]) && isupper(txt[vec.second[0] + 1])) //양쪽이 대문자 인지 확인
                (*rs)[vec.first] = 0; //글자와 규칙을 저장한다.
        }
        else //2글자 이상일때
        {
            //추정되는 사잇글자 간의 인덱스가 거리가 2인지 확인 이작업으로 규칙 1과 규칙 2를 구분한다. (중복일경우 규칙1우선)
            for (int k = 0; k + 1 < vec.second.size(); k++)
            {
                int index1 = vec.second[k];
                int index2 = vec.second[k + 1];
                if (index2 - index1 != 2) //2가 아니라면 규칙 2일 수 있다.
                {
                    check = false;
                    break;
                }
                check = true;
            }
            if(check == true                            //간격2라면
            && isupper(txt[vec.second.front() - 1])     //맨앞글가자 대문자
            && isupper(txt[vec.second.back() + 1])      //맨뒷글자가 대문자
            && (*rs).count(vec.first) != 1)             //비어 있는 규칙이라면
                (*rs)[vec.first] = 0;
        }
    }
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
string solution(string sentence)
{
    string answer = sentence;
    map<char, vector<int>> str;
    for (int i = 0; i < answer.size(); i++)
    {
        if (islower(answer[i])) 
            str[answer[i]].push_back(i); //소문자를 map에 모아둠
        else if (answer[i] == ' ') //띄어 쓰기 검시
            return "invalid";
    }
    if (str.size() > 0)
    {
        map<char, bool> clear_list; //규칙과 문자를 모아둠
        map<int, pair<char, string>> slicer;
        rule1(answer, str, &clear_list); //규칙 1적용
        rule2(answer, str, &clear_list); //규칙 2 적용
        if (clear_list.size() > 0) //규칙 적용된 글자가 있을 경우
        {
            for (int i = 0; i < clear_list.size(); i++) 
            {
                auto key = clear_list.begin();
                advance(key, i);
                if (key->second == 0) //규칙 1
                {
                    int word_pos = str[key->first].front() - 1; //규칙1의 제일 처음 대문자 위치
                    int word_length = str[key->first].size() * 2 + 1; //문장 길이(처음과 마지막 대문자 포함)
                    string sub = answer.substr(word_pos, word_length); 
                    slicer[word_pos] = make_pair(key->first, sub); //글자와 단어 저장
                }
                else
                {
                    int word_pos = str[key->first].front(); //규칙2의 제일 처음 소문자
                    int word_length = str[key->first].back() - str[key->first].front() + 1; //마지막 소문자까지의 길이
                    string sub = answer.substr(word_pos, word_length);
                    slicer[word_pos] = make_pair(key->first, sub); //글자와 단어 저장
                }
            }
            //map을 통해 index 오름차순으로 정렬되어있으므로 순서대로 풀이를 할 수 있다.
            for (auto key : slicer)
            {
                //중복 규칙 확인 순서대로 풀이를 하므로 한단어에 중복된 규칙검사가 가능하다.
                for(int j =0; j< key.second.second.size(); j++){ 
                        if(islower(key.second.second[j]) &&             //소문자 발견.
                        key.second.second[j] != key.second.first &&     // 발견된 소문자가 같은 글자가 아니다.
                        clear_list[key.second.second[j]] == clear_list[key.second.first]){ //같은 규칙이 적용되어있다.
                            return "invalid";
                        }
                    }
                string new_sub = string_edit(key.second.second, key.second.first); //주어진 단어에서
                if (answer.find(key.second.second) != string::npos)
                    answer.replace(answer.find(key.second.second), key.second.second.length(), " " + new_sub + " "); //단어의 앞뒤에 공백
            }
            size_t ptr = answer.find("  ");//중복된 공백 제거
            while (ptr != string::npos)
            {
                answer.replace(ptr, 2, " ");
                ptr = answer.find("  ");
            }
            if (answer.front() == ' ') //제일 앞의 공백 제거
                answer.erase(answer.begin());
            if (answer.back() == ' ') //제일 뒤의 공백 제거
                answer.pop_back();
            for (int i = 0; i < answer.size(); i++) //단하나의 소문자라도 포함되어있는지 검사
                if (islower(answer[i]))
                    return "invalid";
            return answer;
        }
        return "invalid";
    }
    return "invalid"; //전부 대문자일 경우 고려
}

int main()
{
    vector<string> test = {"SpIpGpOpNpGJqOqA", "AxAxAxAoBoBoB", "HaEaLaLaObWORLDb", "AA",
                           "aJaOOOcAc", "aIaAM", "bAaOb", "aaAA", "S B", "XcXbXcX", "a", "aA", "aaA", "Aaa",
                           "HaEaLaLaOWaOaRaLaD", "aHbEbLbLbOacWdOdRdLdDcaHbEbLbLbOacWdOdRdLdDc",
                           "baHELLOabWORLD", "bAaOb","AbAaAbAaCa",  "aHbEbLbLbOacWdOdRdLdDc", "AbAaAbAaCa", "AaABbBCcC",
                           "TxTxTxbAb", "bTxTxTaTxTbkABaCDk",  "AAAaBaAbBBBBbCcBdBdBdBcCeBfBeGgGGjGjGRvRvRvRvRvR", "aHELLOWORLDa",
                           "xAaAbAaAx", "aAbAbAbAacBdBdBdBc", "AbAbAbABdBdBdB", "AbAbAbAcBBBBc", "cBc", "AxAxAxABcBcBcB",
                           "AaAaAcA ","aHELLOa bWORLDb", "HaEaLaLObWORLDb", "aHELLOWORLDa", "HaEaLaLaOWaOaRaLaD", "abHELLObaWORLD",
                           "aPbPbb", "aPbPb", "aPPPb", "PaP", "PPPP","aGbWbFbDakGnWnLk", "aCaCa","oBBoA", "aBcAadDeEdvAvlElmEEEEm",
                           "aMAXabTcOcPb", "aBBc", "aBcB", "aTaAM"};
    vector<string> sol = {"SIGONG J O A", "invalid", "HELLO WORLD", "invalid",
                          "J OOO A", "I AM", "AO", "invalid", "invalid", "X XX X", "invalid", "invalid", "invalid", "invalid",
                          "invalid", "invalid",
                          "invalid", "AO", "invalid", "HELLO WORLD", "invalid", "AA BB CC",
                          "invalid", "invalid", "AA ABA BBBB C BBBB C BB GG GGG RRRRRR", "HELLOWORLD",
                          "invalid", "AAAA BBBB", "AAAA BBBB", "AAAA BBBB", "B", "AAAA BBBB",
                          "invalid", "invalid", "invalid||HELL O WORLD", "invalid ||HELLOWORD", "invalid", "invalid",
                          "invalid", "invalid", "invalid", "PP", "PPPP", "GWFD GWL", "invalid", "BB A", "BA DE A E EEEE",
                          "MAX TOP", "invalid", "invalid", "T AM"};

    for (int i = 0; i < test.size(); i++)
    {
        string ans = solution(test[i]);
        printf("Input       : .%s.\n", test[i].c_str());
        printf("Expected    : .%s.\n", sol[i].c_str());
        printf("Result      : .%s.\n", ans.c_str());
        printf("\n");
    }

    
    return 0;
}