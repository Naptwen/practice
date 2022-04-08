using System;
using System.Collections.Generic;

namespace test
{
    public class Solution
    {
        public int[] solution(int[] progresses, int[] speeds)
        {
            List<int> answer = new List<int>();
            List<int> left = new List<int>(new int[progresses.Length]);
            for (int i = 0; i < progresses.Length; i++)
                left[i] = (100 - progresses[i]) / speeds[i] + (( progresses[i] % speeds[i]) > 0 ? 1 : 0 ); // 7,3,9
            int day = -1;
            int k = -1;
            foreach(int  i in left){
                if(day < i){
                    day = i;
                    answer.Add(1);
                    k++;
                    continue;
                }
                answer[k] += 1;
            }   
            return answer.ToArray();
        }
    // public static void Main()
    // {
    //     Solution a = new Solution();
    //     int[] test = new int[] { 95, 90, 99, 99, 80, 99 };
    //     int[] spd = new int[] { 1, 1, 1, 1, 1, 1 };
    //     int[] ans = a.solution(test, spd);
    //     System.Console.WriteLine("[{0}]", string.Join(", ", ans));
    // }
}
}