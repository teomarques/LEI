package ficha01;
import java.util.Scanner;

public class ex01 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("ALGORITMO DE COMBINATÓRIA");
        System.out.print("Indique o valor de n: ");
        int n = sc.nextInt();
        System.out.print("Indique o  valor de k: ");
        int k = sc.nextInt();
        System.out.println(combinations(n, k));
    }
    public static int combinations(int n, int k){
        int combinations = factorial(n) / (factorial(k)*factorial(n-k));
        return combinations;
    }
    public static int factorial(int n){
        int nFact = 1;
        for(int i = n; i > 0; i--){
            nFact *= i;
        }
        return nFact;
    }
}
