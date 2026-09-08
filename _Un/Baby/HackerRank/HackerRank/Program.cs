using System;
using System.Collections;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Linq;
using System.Net.Http.Headers;
using System.Text;
using System.Threading.Tasks;

namespace HackerRank
{
    static class Extension
    {
        public static string timeConversion(string s)
        {
            string type = s.Substring(8, 2);
            int hour = Convert.ToInt16(s.Substring(0, 2));
            string minAndSec = s.Substring(2, 6);
            string result;

            if (type == "AM")
            {
                if (hour >= 12)
                {
                    result = Convert.ToString(hour - 12).PadLeft(2, '0') + minAndSec;
                }
                else
                {
                    {
                        result = s.Remove(8, 2);
                    }
                }
            }
            else
            {
                if (hour >= 12)
                {
                    result = s.Remove(8, 2);
                }
                else
                {
                    result = Convert.ToString(hour + 12).PadLeft(2, '0') + minAndSec;
                }
            }

            return result;
        }

        public static void countApplesAndOranges(int s, int t, int a, int b, List<int> apples, List<int> oranges)
        {
            int applesCounter = 0;
            int orangesCounter = 0;

            for (int i = 0; i < apples.Count; i++)
            {
                if (apples[i] > 0 && Math.Abs(s - a) <= apples[i] && apples[i] <= Math.Abs(a - t))
                {
                    applesCounter += 1;
                }
            }

            for (int i = 0; i < oranges.Count; i++)
            {
                if (oranges[i] < 0 && Math.Abs(t - b) <= Math.Abs(oranges[i]) && Math.Abs(oranges[i]) <= Math.Abs(s - b))
                {
                    orangesCounter += 1;
                }
            }

            Console.WriteLine(applesCounter);
            Console.WriteLine(orangesCounter);

        }

        public static string kangaroo(int x1, int v1, int x2, int v2)
        {
           if (v1 == v2 && x1 == x2)
            {
                return "YES";
            }
           else if (v1 == v2)
            {
                return "NO";
            }
           else if ((x1 - x2) % (v1 - v2) == 0 && (v1 - v2) * (x1 - x2) < 0)
            {
                return "YES";
            }
           else
            {
                return "NO";
            }
        }

        public static void /*List<int>*/ climbingLeaderboard(List<int> ranked, List<int> player)
        {
            List<int> results = new List<int>();

            ranked.AddRange(player);
            ranked.Sort();
            ranked.Reverse();

            foreach (int i in ranked)
            {
                Console.WriteLine(i);
            }

            foreach (int i in player)
            {
                if (ranked.IndexOf(i) != -1)
                {


                    results.Add(ranked.IndexOf(i));
                }
            }

            
        }

        public static int designerPdfViewer(List<int> h, string word)
        {
            List<char> alphabet = new List<char>() { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
            List<int> heights = new List<int>();

            for (int i = 0; i < word.Length; i++)
            {
                heights.Add(h[alphabet.IndexOf(word.ToCharArray()[i])]);
            }

            heights.Sort();
            heights.Reverse();

            return heights[0] * word.Length;
        }

        public static List<int> permutationEquation(List<int> p)
        {
            //List<int> result = new List<int>();

            foreach (int i in p)
            {
                Console.WriteLine(i);
            }

            return new List<int> {1 };
        }

        public static void queensAttack(int n, int k, int r_q, int c_q, List<List<int>> obstacles)
        {
            // X = rowPos
            // Y = colPos

            int upObstaclePosY = n;
            int downObstaclePosY = 1;
            int leftObstaclePosX = 1;
            int rightObstaclePosX = n;

            int changeCounter = 0;

            int result = 0;

            // col obstacles posY:
            foreach (List<int> obstaclePos in obstacles)
            {
                if (obstaclePos[0] == r_q)
                {
                    if (obstaclePos[1] <= upObstaclePosY && obstaclePos[1] > c_q)
                    {
                        upObstaclePosY = obstaclePos[1];
                        changeCounter += 1;
                    }
                    if (obstaclePos[1] >= downObstaclePosY && obstaclePos[1] < c_q)
                    {
                        downObstaclePosY = obstaclePos[1];
                        changeCounter += 1;
                    }
                }
            }

            // row obstacle posX:
            foreach (List<int> obstaclePos in obstacles)
            {
                if (obstaclePos[1] == c_q)
                {
                    if (obstaclePos[0] >= leftObstaclePosX && obstaclePos[0] < r_q)
                    { 
                        leftObstaclePosX = obstaclePos[0];
                        changeCounter += 1;
                    }
                    if (obstaclePos[0] <= rightObstaclePosX && obstaclePos[0] > r_q)
                    {
                        rightObstaclePosX = obstaclePos[0];
                        changeCounter += 1;
                    }
                }
            }
            // diagonal obstacle pos:
            foreach (List<int> obstaclePos in obstacles)
            {
                if (Math.Abs(obstaclePos[0] - r_q) == Math.Abs(obstaclePos[1] - c_q))
            }
            
            result += Math.Abs(upObstaclePosY - c_q) + Math.Abs(c_q - downObstaclePosY) + Math.Abs(r_q - leftObstaclePosX) + Math.Abs(rightObstaclePosX - r_q) - changeCounter;
            
            


            Console.WriteLine(result);
            // Up
            //while (c_q < n && c_q != )
            //{

            //}
        }
    }


    internal class Program
    {
        static void Main(string[] args)
        {
            List<int> pos = new List<int>() { 3, 4};

            Extension.queensAttack(5, 1, 3, 3, new List<List <int>> { new List<int> {1, 5}, new List<int> { 4, 1 } });

            Console.ReadLine();
        }
    }
}
