import java.util.*;
public class NoOfSquares {
    public static int getNoOfSquares(int n) {
        if(n < 0)
            return -1;
        int squares = 0;
        while(n > 0) {
            squares += n * n;
            n--;
        }
        return squares;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        System.out.println(getNoOfSquares(n));
        sc.close();
    }
}