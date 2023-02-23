using System;

public class Program {
    static long kth(long M, long n) {
        return M - M / n;
    }

    static long BS(long n, long k) {
        long L = 1;
        long R = n * k;
        while (L <= R) {
            long M = (L + R) / 2;
            long K = kth(M, n);
            if (K == k && M % n != 0) {
                return M;
            }
            if (K < k) {
                L = M + 1;
            } else {
                R = M - 1;
            }
        }
        return 0;
    }

    public static void Main() {
        int t = int.Parse(Console.ReadLine());
        while (t-- > 0) {
            string[] line = Console.ReadLine().Split();
            long n = long.Parse(line[0]);
            long k = long.Parse(line[1]);
            Console.WriteLine(BS(n, k));
        }
    }
}