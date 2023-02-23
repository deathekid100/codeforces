import java.util.Scanner;

public class Main {
    public static int calc(int p, int k) {
        return k + (5 * p * (p + 1)) / 2;
    }

    public static int BS(int n, int k) {
        int ans = 0;
        int l = 0;
        int r = n;

        while (l <= r) {
            int m = (l + r) / 2;
            int c = calc(m, k);
            if (c == 240) {
                return m;
            }
            if (c < 240) {
                ans = m;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return ans;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();

        System.out.println(BS(n, k));
    }
}
