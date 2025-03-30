package ficha01;
import java.util.Scanner;

public class ex02 {
    public static void main(String[] args) {
        Scanner entrada = new Scanner(System.in);
        System.out.print("Digite um número: ");
        int n = entrada.nextInt();
        System.out.println("= " + somaDigitos(n));
    }
    public static int somaDigitos(int n){
        int soma = 0;
        for(int i = n; i > 0; i--){
            soma += i;
            System.out.print(i + " + ");
        }
        return soma;
    }
}
