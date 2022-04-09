using System;
using System.Collections.Generic;
using System.Linq;
//using upper bound
namespace hahahah
{
    public class Solution
    {

        public bool checking(int w, int h, int yellow, int brown)
        {
            if ((w - 2) * (h - 2) > yellow) return true;
            if (w * h  > brown + (w - 2) * (h - 2)) return true;
            return false;
        }
        public int[] solution(int brown, int yellow)
        {
            int[] answer = new int[2] { 0,0};
            int r = 2000002;
            int l = 0;
            int area = brown + yellow;
            int w = 0;
            int h = 0;
            while (l + 1 < r) //using Upper bound find the maximum for w or h
            {
                int mid = (r + l) / 2;
                if (checking(mid, area / mid, yellow, brown))
                    r = mid;
                else
                    l = mid;
            }
            w = l + 1;
            h = area/w;
            int max = w > h? w : h;
            for(int  j = max; j >= 3; j--){
                w = j;
                if(area%w == 0){
                    h = area/w;
                    if((w - 2) * (h - 2) == yellow && w * h  == brown + (w - 2) * (h - 2))
                    {
                        answer[0] = (w > h)? w : h;
                        answer[1] = (h < w)? h : w;
                    }
                }
            }
            return answer;
        }

        // public static void Main()
        // {
        //     Solution a = new Solution();
        //     int case1 = 24;
        //     int case2 = 24;
        //     int[] ans = a.solution(case1, case2);
        //     System.Console.WriteLine(string.Join(" ", ans));
        // }
    }
}