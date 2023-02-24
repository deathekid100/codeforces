using System;

class Program
{
    static ulong DivInRange(ulong min, ulong max, ulong k)
    {
        min--;
        return max / k - (min / k);
    }

    static ulong BS(ulong n, ulong k)
    {
        ulong L = 1;
        ulong R = n * k;
        ulong ans = 0;
        while (L <= R)
        {
            ulong M = (L + R) / 2;
            ulong min = n + M - 1;
            ulong max = n * M;
            ulong count = DivInRange(min, max, k);

            if (count > 0)
            {
                ans = M;
                R = M - 1;
            }
            else
            {
                L = M + 1;
            }
        }
        return ans;
    }

    static void Main()
    {
        ulong t, n, k;
        t = ulong.Parse(Console.ReadLine());
        while (t-- > 0)
        {
            string[] tokens = Console.ReadLine().Split();
            n = ulong.Parse(tokens[0]);
            k = ulong.Parse(tokens[1]);
            Console.WriteLine(BS(n, k));
        }
    }
}