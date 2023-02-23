import java.util.Scanner;

public class Main {
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

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            long n = sc.nextLong();
            long k = sc.nextLong();
            System.out.println(BS(n, k));
        }
        sc.close();
    }
}
