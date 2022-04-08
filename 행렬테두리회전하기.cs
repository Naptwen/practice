using System;
using System.Collections.Generic;
using System.Linq;
public class Solution {

    public void printf(List<List<int>> cell){
        for(int i =0; i < cell.Count; i++){
            for(int j =0; j < cell[0].Count; j++)
                Console.Write("{0:D2}, ", cell[i][j]);
            Console.WriteLine();
        }
        Console.WriteLine("------------");
    }
    public int[] solution(int rows, int columns, int[,] queries) {
        int[] answer = new int[queries.GetLength(0)];
        List<List<int>> cell = new List<List<int>>(rows); 
        for(int i =0; i < rows; i++){ //벡터와 다른 초기화 방법
            cell.Add(new List<int>());
            cell[i].AddRange(Enumerable.Range(i * columns + 1, columns).ToList());
        }
        printf(cell);
 
        for(int k = 0; k < queries.GetLength(0); k++){
            List<int> mini = new List<int>();
            int N = queries[k,0]-1;
            int W = queries[k,1]-1;
            int S = queries[k,2]-1; 
            int E = queries[k,3]-1;
            int temp = cell[N][W];
            for(int i = N; i < S; i++){ 
                cell[i][W] = cell[i+1][W];      mini.Add(cell[i][W]);}
            for(int i = W; i < E; i++){ 
                cell[S][i] = cell[S][i+1];      mini.Add(cell[S][i]);}
            for(int i = S; i > N; i--){
                cell[i][E] = cell[i - 1][E];    mini.Add(cell[i][E]);}
            for(int i = E; i > W; i--){ 
                cell[N][i] = cell[N][i - 1];    mini.Add(cell[N][i]);}
            cell[N][W + 1] = temp; 
            mini.Add(temp);
            answer[k] = mini.Min();


            printf(cell);
        }
        return answer;
    }
    // public static void Main(){
    //     Console.Write("Hello wrold\n");
    //     Solution a = new Solution();
    //     int [,] queries = {{2,2,5,4},{3,3,6,6},{5,1,6,3}};
    //     System.Console.Write( String.Join(" ",a.solution(6,6, queries)) );
    // }
}