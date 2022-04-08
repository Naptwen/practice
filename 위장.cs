using System;
using System.Collections.Generic;

namespace undercover
{
    public class Solution
    {
        public int solution(string[,] clothes)
        {
            int answer = 1;
            List<int> combination =  new List<int>();
            var c = new Dictionary<string, List<string>>();
            for (int i = 0; i < clothes.GetLength(0); i++) //해쉬 리스트 연습을 위해서
            {
                if (c.ContainsKey(clothes[i, 1])){
                    c[clothes[i, 1]].Add(clothes[i, 0]);
                    continue;
                }
                var txt = new List<string>(){clothes[i, 0]};
                c.Add(clothes[i, 1], txt);
            }
            foreach(var item in c){
                Console.WriteLine("{0} = {1}", item.Key, item.Value.Count() + 1);
                answer *= item.Value.Count + 1;

            }
            return --answer;
        }

        private static void Main()
        {
            Console.Write("Hello wrold\n");
            Solution a = new Solution();
            string[,] clothes = { { "r", "head" }, { "b", "eye" }, { "g", "head" },{"r", "eye"}, {"r", "body"} };
            int ans = a.solution(clothes);
            Console.WriteLine("{0}\n", ans);
        }
    }
    /*
왜 이렇게 풀수 있나?
    중복없는 조합 j = nCk n개의 옷종류중 k개를 뽑느다.
    뽑은 옷종루에서 m개의 서로다른 옷들이 있으며 1 개씩만 빼입음으로 있으므로 (m1C1) * (m2C1) ... j번
    N(n) = sigma(nCk) where k = [1, n] 
    pi(xi + 1) - 1 => all combination
    ex)(a,b,c,d)
    (a + 1)(b + 1)(c + 1)(d + 1)                                                    - 1
    = (ab + a + b + 1)(c + 1)(d + 1)                                                - 1
    = (abc + ab + ac + bc + a + b + c + 1)(d + 1)                                   - 1
    = (abcd + abd + acd + bcd + ab + ac + ad + bc + bd + cd + a + b + c + d + 1)    - 1
    What is interportation for this equation?
    -> Binomial Thorem 
    -> (a+1)^n = sigma bio(n, k) a^(n-k)
    -> if n = 4 -> a^4 + 4a^3 + 6a^2 + 4a + 1
    -> Let's thinking like thi the degree means using a 4 times, 3 times.... 0times
    -> Thus as let the degree 1 (a+1) menas just indicate use or not
    -> now as multiplying all the values 
    -> Therefore it shows the all combination from 0 ~ n
    -> Hence as subtract -1 (0 use anything) return the answer
    */
}