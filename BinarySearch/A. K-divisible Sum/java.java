import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    static BigInteger divInRange(BigInteger min, BigInteger max, BigInteger k) {
        min = min.subtract(BigInteger.ONE);
        return max.divide(k).subtract(min.divide(k));
    }

    static BigInteger BS(BigInteger n, BigInteger k) {
        BigInteger L = BigInteger.ONE;
        BigInteger R = n.multiply(k);
        BigInteger ans = BigInteger.ZERO;
        while (L.compareTo(R) <= 0) {
            BigInteger M = L.add(R).divide(BigInteger.valueOf(2));
            BigInteger min = n.add(M).subtract(BigInteger.ONE);
            BigInteger max = n.multiply(M);
            BigInteger count = divInRange(min, max, k);

            if (count.compareTo(BigInteger.ZERO) > 0) {
                ans = M;
                R = M.subtract(BigInteger.ONE);
            } else {
                L = M.add(BigInteger.ONE);
            }
        }
        return ans;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        BigInteger t, n, k;
        t = scanner.nextBigInteger();
        while (t.compareTo(BigInteger.ZERO) > 0) {
            n = scanner.nextBigInteger();
            k = scanner.nextBigInteger();
            System.out.println(BS(n, k));
            t = t.subtract(BigInteger.ONE);
        }
    }
}
