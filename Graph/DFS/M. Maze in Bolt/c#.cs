using System;
using System.Collections.Generic;

class Program
{
    static string s;
    static int n, R, C;
    static List<string> M;
    static bool[,] mark;
    static bool fit(int i, int j)
    {
        for (int k = 0; k < n; k++)
        {
            if (s[k] == '1' && M[j][(i + k) % n] == '1')
                return false;
        }
        return true;
    }
    static bool DFSStack(int xi, int xj)
    {
        var st = new Stack<(int, int)>();
        st.Push((xi, xj));
        while (st.Count > 0)
        {
            var p = st.Pop();
            int i = p.Item1;
            int j = p.Item2;
            mark[i, j] = true;
            if (j == R - 1) return true;
            //up
            int J = j - 1;
            if (J >= 0)
            {
                if (!mark[i, J] && fit(i, J))
                {
                    st.Push((i, J));
                }
            }
            //right
            int I = (i + 1 ) % n;
            if (!mark[I, j] && fit(I, j))
            {
                st.Push((I, j));
            }
            //left
            I = (i - 1 + n) % n;
            if (!mark[I, j] && fit(I, j))
            {
                st.Push((I, j));
            }
            J = j + 1;
            if (J < R)
            {
                if (!mark[i, J] && fit(i, J))
                {
                    st.Push((i, J));
                }
            }
        }
        return false;
    }
    static void Main()
    {
        string a;
        string[] input = Console.ReadLine().Split();
        R = int.Parse(input[0]);
        C = int.Parse(input[1]);
        s = Console.ReadLine();
        n = C;
        M = new List<string>();

        for (int i = 0; i < R; i++)
        {
            a = Console.ReadLine();
            M.Add(a);
        }

        mark = new bool[C + 1, R + 1];

        for (int i = 0; i < n; i++)
        {
            if (fit(i, 0))
            {
                bool ans = DFSStack(i, 0);
                if (ans)
                {
                    Console.WriteLine("Y");
                    return;
                }
            }
        }

        Array.Clear(mark, 0, mark.Length);

        char[] charArray = s.ToCharArray();
        Array.Reverse(charArray);
        s = new string(charArray);

        for (int i = 0; i < n; i++)
        {
            if (fit(i, 0))
            {
                bool ans = DFSStack(i, 0);
                if (ans)
                {
                    Console.WriteLine("Y");
                    return;
                }
            }
        }

        Console.WriteLine("N");
    }
}
