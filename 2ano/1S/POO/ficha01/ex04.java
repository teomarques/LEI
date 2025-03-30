package ficha01;
import java.util.Scanner;

public class ex04 {
    public static void main(String[] args) {
        Scanner entrada = new Scanner(System.in);
        System.out.print("Indique o valor: ");
        int n = entrada.nextInt();
        System.out.println("número: "+n);
        System.out.println("Quantidade de múltiplos menores que 100: "+multiplos(n));
    }
    public static int multiplos(int n){
        int i = 0;
        int store = 0;
        while(store <= 100){
            i++;
            store = n * i;
            if(store > 100) break;
            System.out.println(store);
        }
        return i-1;
    }
}
