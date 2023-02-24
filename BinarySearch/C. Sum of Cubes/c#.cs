using System;

class Program {
    static ulong[] pow3 = new ulong[1000001];

    static void Pre() {
        for (ulong i = 0; i < 1000001; i++) {
            pow3[i] = i * i * i;
        }
    }

    static bool isPow3(ulong n) {
        if (n <= 0) return false;
        int x = Array.BinarySearch(pow3, n);
        return x >= 0;
    }

    static void Search(ulong n) {
        int x = (int)Math.Pow(n, 1 / 3.00000);
        for (int i = 1; i <= x; i++) {
            ulong pi = pow3[i];
            ulong R = n - pi;
            if (isPow3(R)) {
                Console.WriteLine("YES");
                return;
            }
        }
        Console.WriteLine("NO");
    }

    static void Main(string[] args) {
        Pre();
        ulong t, n;
        t = Convert.ToUInt64(Console.ReadLine());
        while (t-- > 0) {
            n = Convert.ToUInt64(Console.ReadLine());
            Search(n);
        }
    }
}
