import java.util.Scanner;

public class Main {
    static int[][] Sum = new int[4][200001];

    static boolean Can(int i, int j) {
        if(i == 0) {
            int s1 = Sum[1][j];
            int s2 = Sum[2][j];
            int s3 = Sum[3][j];
            return s1 > 0 && s2 > 0 && s3 > 0;
        }
        else {
            int s1 = Sum[1][j] - Sum[1][i - 1];
            int s2 = Sum[2][j] - Sum[2][i - 1];
            int s3 = Sum[3][j] - Sum[3][i - 1];
            return s1 > 0 && s2 > 0 && s3 > 0;
        }
    }

    static int BS(String s) {
        // pre
        for (int i = 0; i < s.length(); i++) {
            int x = s.charAt(i) - '0';
            Sum[1][i] = i == 0 ? 0 : Sum[1][i - 1];
            Sum[2][i] = i == 0 ? 0 : Sum[2][i - 1];
            Sum[3][i] = i == 0 ? 0 : Sum[3][i - 1];
            Sum[x][i]++;
        }
        if (!Can(0, s.length() - 1)) return 0;

        int mx = Integer.MAX_VALUE;

        for (int i = 0; i < s.length(); i++) {
            int L = i;
            int R = s.length() - 1;
            while (L <= R) {
                int M = (L + R) / 2;
                if (Can(i, M)) {
                    R = M - 1;
                    mx = Math.min(mx, M - i + 1);
                    if (mx == 3) return 3;
                } else {
                    L = M + 1;
                }
            }
        }
        return mx;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        while (t-- > 0) {
            String s = scanner.next();
            System.out.println(BS(s));
        }
    }
}
