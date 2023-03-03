using System;

class Program
{
    static ulong[] arr = new ulong[100002];

    static int GetL(int n, ulong k)
    {
        int x = Array.BinarySearch(arr, 0, n + 1, k);
        return (x < 0) ? ~x : x;
    }

    static void Main(string[] args)
    {
        arr[0] = 0;
        for (int i = 1; i < 100002; i++)
        {
            arr[i] = arr[i - 1] + i;
        }

        int t = int.Parse(Console.ReadLine());
        while (t-- > 0)
        {
            string[] input = Console.ReadLine().Split();
            int n = int.Parse(input[0]);
            ulong k = ulong.Parse(input[1]);

            int L = GetL(n, k);
            ulong lower = (L * (L - 1)) / 2L;
            ulong R = k - lower;
            L = n - L - 1;
            R = n - R;

            char[] s = new char[n];
            for (int i = 0; i < n; i++)
            {
                s[i] = 'a';
            }
            s[L] = s[R] = 'b';

            Console.WriteLine(new string(s));
        }
    }
}
