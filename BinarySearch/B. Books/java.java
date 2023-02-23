import java.util.*;

public class Main {
    
    public static boolean CanReadMBooks(List<Integer> a, int M, int n, int t) {
        int sum = 0;
        for (int i = 0; i < M; i++) {
            sum += a.get(i);
        }
        if (sum <= t) return true;
        for (int i = M; i < n; i++) {
            sum += a.get(i) - a.get(i - M);
            if (sum <= t) return true;
        }
        return false;
    }
    
    public static int BS(List<Integer> a, int n, int t) {
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
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n, t, x;
        n = sc.nextInt();
        t = sc.nextInt();
        List<Integer> a = new ArrayList<Integer>();
        for (int i = 0; i < n; i++) {
            x = sc.nextInt();
            a.add(x);
        }
        System.out.println(BS(a, n, t));
        sc.close();
    }
}
