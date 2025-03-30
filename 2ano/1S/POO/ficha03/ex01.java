package ficha03;
import java.util.Scanner;

public class ex01 {
    public static void main(String[] args){
        Scanner entrada = new Scanner(System.in);
        System.out.print("Escreva uma frase: ");
        String frase = entrada.nextLine();
        caracteres(frase);
    }

    public static void caracteres(String frase){
        char[] letras = frase.toCharArray();
        for(int i = 0; i < frase.length(); i++){
            if(letras[i] != ' '){
                System.out.println(letras[i]);
            }
        }
    }
}
