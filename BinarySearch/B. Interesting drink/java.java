import java.util.*;

public class Main {
    
    private static int binarySearch(List<Integer> a, int x) {
        int ans = 0;
        int l = 0;
        int r = a.size() - 1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (a.get(m) <= x) {
                ans = m + 1;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return ans;
    }
    
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        List<Integer> a = new ArrayList<Integer>();
        for (int i = 0; i < n; i++) {
            int q = input.nextInt();
            a.add(q);
        }
        Collections.sort(a);
        int q = input.nextInt();
        while (q-- > 0) {
            int x = input.nextInt();
            System.out.println(binarySearch(a, x));
        }
        input.close();
    }
}
