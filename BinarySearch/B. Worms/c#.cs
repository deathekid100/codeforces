using System;

public class Program
{
    public static void BS(int[] a, int n, int x)
    {
        int L = 0;
        int R = n - 1;
        int ans = 0;
        while (L <= R)
        {
            int M = (L + R) / 2;
            if (a[M] >= x)
            {
                ans = M;
                R = M - 1;
            }
            else
            {
                L = M + 1;
            }
        }
        Console.WriteLine(ans + 1);
    }

    public static void Main()
    {
        int n, x;
        n = int.Parse(Console.ReadLine());
        int[] a = new int[n];
        var ss = Console.ReadLine().Split();
        a[0] = int.Parse(ss[0]);
        for (int i = 1; i < n; i++)
        {
            x = int.Parse(ss[i]);
            a[i] = a[i - 1] + x;
        }
        int q = int.Parse(Console.ReadLine());
        ss = Console.ReadLine().Split();
        for (int i = 0; i < q; i++)
        {
            x = int.Parse(ss[i]);
            BS(a, n, x);
        }
    }
}
