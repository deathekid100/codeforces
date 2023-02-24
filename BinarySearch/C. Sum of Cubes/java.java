import java.util.*;

public class Main {
    static long[] pow3 = new long[1000001];

    static void pre() {
        for (long i = 0; i < 1000001; i++) {
            pow3[(int)i] = i * i * i;
        }
    }

    static boolean isPow3(long n) {
        if (n <= 0) return false;
        int x = Arrays.binarySearch(pow3, n);
        return x >= 0;
    }

    static void search(long n) {
        int x = (int)Math.pow(n, 1 / 3.00000);
        for (int i = 1; i <= x; i++) {
            long pi = pow3[i];
            long R = n - pi;
            if (isPow3(R)) {
                System.out.println("YES");
                return;
            }
        }
        System.out.println("NO");
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        pre();
        long t, n;
        t = sc.nextLong();
        while (t-- > 0) {
            n = sc.nextLong();
            search(n);
        }
        sc.close();
    }
}
