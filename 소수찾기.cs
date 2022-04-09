using System;
using System.Collections.Generic;
using System.Linq;
// - '0'을 활용한 한자릿수를 인트값으로
//리스안에 리스트 넣기 convertAll 혹은 select에 람다함수 값 => 형식 입력
//리스트 깊은복사
//재귀함수사용을 통한 순열문제해결
//루트값을 사용한 소수판별
//사전 키 존재유무팔별 및 사전 값수정
//리스트에 리스트 추가하기 add 아 add range
//서브리스트 구하기
//parse 파싱을 활용한 string join 변화후 int값변화
//Enumerable.Repeat를 활용한 리스트 초기화
namespace test2
{
    public class Solution
    {
        //The num should be greater than 'n'
        //The n indicates the number of selection.
        //The first input v should be 0 size.
        //The size of c should be as smae as the size of num
        public List<int> permu(List<int> num, List<int> v, List<bool> c, int n){
            if(v.Count >= n)
                return v;
            List<int> ans = new List<int>();
            for(int i = 0; i < num.Count; i++)
                if(c[i] == false){
                    List<int> tv = v.ConvertAll(p => p); //deep copy
                    List<bool> tc = c.ConvertAll(p => p); //deep copy
                    tv.Add(num[i]);
                    tc[i] = true;
                    ans.AddRange(permu(num, tv, tc, n));
                } 
            return ans;
        }
        public bool Prime_check(int num){
            for(int i = 2; i * i <= num; i++){
                if(num % i == 0) return false;
            }
            return true;
        }
        public int solution(string numbers) {
            int answer = 0;
            List<int> nums = new List<int>();
            //Conver string to int number
            foreach(var t in numbers)
                nums.Add(t - '0');
            //find permutation
            List<int> v = new List<int>();
            List<bool> c = new List<bool>(Enumerable.Repeat(false, nums.Count));
            List<List<int>> values = new List<List<int>>();
            //1 ~ n 까지 자릿수의 순열을 모두 찾음
            for(int i =1;i <= nums.Count; i++)
                values.Add(permu(nums, v, c, i));
            //중복확인을 위한 dp
            Dictionary<int, bool> prime_list = new Dictionary<int, bool>();
            for(int i =0; i < values.Count; i++){ //리스트안의 리스트
                for(int j = 0; j < values[i].Count; j += i + 1){ //내부 리스트 의 인덱스 i + 1 은 자릿수 크기입니다.
                    List<int> sub = values[i].GetRange(j,i + 1); //서브리스트 구하기
                    var value = int.Parse(string.Join("", sub));//서비리스트를 스트링을 조인을 이용하여 하나로 합쳐줌
                    if(value != 1 && value!= 0 && !prime_list.ContainsKey(value) && Prime_check(value)){ // 그값이 소수면 답 ++ 1을 소수로 하지않음 수학자 유클리드를 따르자
                        prime_list.Add(value, true);
                        answer++;
                        Console.WriteLine("{0} prime",value);
                    }  
                }
            }
            return answer;
        }
        public static void Main()
        {
            Solution a = new Solution();
            string test = "17";
            int ans = a.solution(test);
            System.Console.WriteLine("[{0}]", ans);
        }
    }
}