    import java.util.*;
     
    public class Program {
    static long[] arr = new long[100002];
    static int getL(long n) {
        int L = 0;
        int R = 100001;
        int ans = 0;
        while (L <= R) {
            int M = (L + R) / 2;
            if (arr[M] == n) return M;
            else if (arr[M] < n) {
                L = M + 1;
                ans = M;
            } else {
                R = M - 1;
            }
        }
        return ans;
    }
     
    public static void main(String[] args) {
        arr[0] = 2;
        for (long i = 1; i < 100002; i++) {
            arr[(int)i] = arr[(int)i - 1] + 3 * i + 2;
        }
     
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            long n = sc.nextLong();
            int c = 0;
            while (n > 1) {
                c++;
                int L = getL(n);
                n -= arr[L];
            }
            System.out.println(c);
        }
    }}