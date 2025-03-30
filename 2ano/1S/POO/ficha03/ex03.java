package ficha03;
import java.util.Scanner;

public class ex03 {
    public static void main(String[] args) {
        Scanner entrada = new Scanner(System.in);
        System.out.print("Escreva uma frase: ");
        String frase = entrada.nextLine();
        System.out.println(palindromo(frase));
    }

    public static boolean palindromo(String frase) {
        Boolean palindromo = false;
        String novaFrase = frase.toLowerCase().replace(" ", "");
        for(int i = 0; i < novaFrase.length(); i++) {
            if(novaFrase.charAt(i) == novaFrase.charAt(novaFrase.length()-1-i)){
                palindromo = true;
            } else{
                palindromo = false;
            }
        }
        return palindromo;
    }
}
