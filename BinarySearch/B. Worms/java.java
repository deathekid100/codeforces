import java.util.Scanner;

public class Main {
    public static void BS(int[] a, int n, int x) {
        int L = 0;
        int R = n - 1;
        int ans = 0;
        while (L <= R) {
            int M = (L + R) / 2;
            if (a[M] >= x) {
                ans = M;
                R = M - 1;
            } else {
                L = M + 1;
            }
        }
        System.out.println(ans + 1);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        a[0] = sc.nextInt();
        for (int i = 1; i < n; i++) {
            int x = sc.nextInt();
            a[i] = a[i - 1] + x;
        }
        int q = sc.nextInt();
        while (q-- > 0) {
            int x = sc.nextInt();
            BS(a, n, x);
        }
    }
}
