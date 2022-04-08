using System;
using System.Collections.Generic;

namespace ConsolApplication{
    public class Solution {

        public int solution(int[] numbers) {
            int answer = -1;
            List<int> nums = new List<int>(){0,1,2,3,4,5,6,7,8,9};
            foreach(int i in numbers)
                nums.RemoveAt(nums.FindIndex( x => x == i ));
            foreach(int i in nums)
                answer += i;
            answer = answer > 0 ? ++answer : -1;
            return answer;
        }

        // public static void Main(){
        //     Console.Write("Hello wrold\n");
        //     int[] test = {1, 2, 3, 4, 6, 7, 8, 0};
        //     Solution a = new Solution();
        //     System.Console.Write("{0}\n", a.solution(test));
        // }
    }
}