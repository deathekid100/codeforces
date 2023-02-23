using System;

public class Program
{
    public static int Calc(int p, int k)
    {
        return k + (5 * p * (p + 1)) / 2;
    }

    public static int BS(int n, int k)
    {
        int ans = 0;
        int l = 0;
        int r = n;

        while (l <= r)
        {
            int m = (l + r) / 2;
            int c = Calc(m, k);
            if (c == 240)
            {
                return m;
            }
            if (c < 240)
            {
                ans = m;
                l = m + 1;
            }
            else
            {
                r = m - 1;
            }
        }
        return ans;
    }

    public static void Main()
    {
        string[] input = Console.ReadLine().Split();
        int n = int.Parse(input[0]);
        int k = int.Parse(input[1]);

        Console.WriteLine(BS(n, k));
    }
}
