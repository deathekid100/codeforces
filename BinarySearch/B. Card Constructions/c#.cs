using System;

class Program
{
    static ulong[] arr = new ulong[100002];

    static uint GetL(ulong n)
    {
        uint L = 0;
        uint R = 100001;
        uint ans = 0;
        while(L <= R)
        {
            uint M = (L + R ) / 2;
            if (arr[M] == n) return M;
            else if (arr[M] < n)
            {
                L = M + 1;
                ans = M;
            }
            else
            {
                R = M - 1;
            }
        }
        return ans;
    }

    static void Main()
    {
        arr[0] = 2;
        for (ulong i = 1; i < 100002; i++)
        {
            arr[i] = arr[i - 1] + 3 * i + 2;
        }

        int t = int.Parse(Console.ReadLine());
        while (t-- > 0)
        {
            ulong n = ulong.Parse(Console.ReadLine());
            int c = 0;
            while (n > 1)
            {
                c++;
                ulong L = GetL(n);
                n -= arr[L];
            }
            Console.WriteLine(c);
        }
    }
}
