using System;
using System.Collections.Generic;

public class Program
{
    private static int BS(List<int> a, int x)
    {
        int ans = 0;
        int l = 0;
        int r = a.Count - 1;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (a[m] <= x)
            {
                ans = m + 1;
                l = m + 1;
            }
            else
            {
                r = m - 1;
            }
        }
        return ans;
    }

    private static void Main()
    {
        int n, q, x;
        n = int.Parse(Console.ReadLine());
        var a = new List<int>();
        var s = Console.ReadLine().Split();
        for (int i = 0; i < n; i++)
        {
            a.Add(int.Parse(s[i]));
        }
        a.Sort();
        q = int.Parse(Console.ReadLine());
        while (q-- > 0)
        {
            x = int.Parse(Console.ReadLine());
            Console.WriteLine(BS(a, x));
        }
    }
}
