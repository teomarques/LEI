package ficha01;
import java.util.Scanner;

public class ex05 {
    public static void main(String[] args) {
        Scanner entrada = new Scanner(System.in);
        System.out.print("Digite um valor para o número 1: ");
        int num1 = entrada.nextInt();
        System.out.print("Digite um valor para o numero 2: ");
        int num2 = entrada.nextInt();
        numeroAmigo(num1, num2);
    }
    public static boolean numeroAmigo(int numero1, int numero2){
        int soma1 = 0;
        for(int i = 1; i < numero1; i++){
            if(numero1 % i == 0){
                soma1 += i;
            }
        }
        int soma2 = 0;
        for(int i = 1; i < numero2; i++){
            if(numero2 % i == 0){
                soma2 += i;
            }
        }
        if(soma1 == numero2 && soma2 == numero1){
            System.out.println("Os números são amigos. Têm soma " + soma1);
            return true;
        }
        System.out.println("Os números não são amigos. O primeiro tem soma " + soma1 + "de  divisores, e o segundo soma " + soma2 + "de divisores.");
        return false;
    }
}
