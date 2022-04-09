using System;
using System.Collections.Generic;
using System.Linq;

namespace wire{
    public class Solution {

            public int elec(Dictionary<int, List<int>> connection, 
                            List<bool> check, int[] disconnect,
                            List<int> que, int many){
                if(que.Count <= 0) return many;
                int id = que.First();
                check[id] = true;
                many++;
                que.RemoveAt(0);
                foreach(var c in connection[id]){
                    if((disconnect[0] == id && disconnect[1] == c )
                    || (disconnect[1] == id && disconnect[0] == c) )
                        continue;
                    if(!check[c]){
                        que.Add(c);
                        check[c] = true;
                    }
                }
                return elec(connection, check, disconnect, que, many);
            }

            public int solution(int n, int[,] wires) {
            Dictionary<int, List<int>> connection = new Dictionary<int, List<int>>();
            for(int i =0; i < wires.GetLength(0); i++){
                if(connection.ContainsKey(wires[i,0] - 1)) connection[wires[i,0] - 1].Add(wires[i,1] - 1);
                else connection.Add(wires[i,0] - 1, new List<int>(){wires[i,1] - 1});
                if(connection.ContainsKey(wires[i,1] - 1)) connection[wires[i,1] - 1].Add(wires[i,0] - 1);
                else connection.Add(wires[i,1] - 1, new List<int>(){wires[i,0] - 1});
            }
            List<int> mini_diff = new List<int>();
            for(int j =0; j < wires.GetLength(0); j++){
                int[] disconnect = new int[]{wires[j,0] -1, wires[j,1] - 1};
                int[] diff = new int[]{0,0};
                for(int a = 0; a <2; a++){
                    List<bool> check = new List<bool>(Enumerable.Repeat(false, n));
                    List<int> que = new List<int>();
                    que.Add(wires[j,a] - 1);
                    diff[a] = elec(connection, check, disconnect, que, 0) - 1;
                }
                System.Console.WriteLine( "diff {0} {1}{2} 1. {3} .2 {4} = {5}", j,wires[j,0], wires[j,1],  diff[0], diff[1], Math.Abs(diff[0] - diff[1]) );
                mini_diff.Add( Math.Abs(diff[0] - diff[1]) );
            }
            int answer = mini_diff.Min();
            return answer;
        }
        public static void Main(){
            Solution a = new Solution();
            int [,] wires ={{1,2},{2,3},{3,1}};
            System.Console.WriteLine( a.solution(3, wires) );
        }
    }
}