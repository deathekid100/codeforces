using System;
using System.Collections.Generic;

public class Program {
    
    static bool CanReadMBooks(List<int> a, int M, int n, int t) {
        int sum = 0;
        for (int i = 0; i < M; i++) {
            sum += a[i];
        }
        if (sum <= t) return true;
        for (int i = M; i < n; i++) {
            sum += a[i] - a[i - M];
            if (sum <= t) return true;
        }
        return false;
    }
    
    static int BS(List<int> a, int n, int t) {
        int L = 0;
        int R = n;
        int ans = 0;
        while (L <= R) {
            int M = (L + R) / 2;
            if (CanReadMBooks(a, M, n, t)) {
                L = M + 1;
                ans = M;
            }
            else {
                R = M - 1;
            }
        }
        return ans;
    }
    
    static void Main() {
        int n, t, x;
        string[] input = Console.ReadLine().Split();
        n = int.Parse(input[0]);
        t = int.Parse(input[1]);
        List<int> a = new List<int>();
        string[] arr = Console.ReadLine().Split();
        for (int i = 0; i < n; i++) {
            x = int.Parse(arr[i]);
            a.Add(x);
        }
        Console.WriteLine(BS(a, n, t));
    }
}
