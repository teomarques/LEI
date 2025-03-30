package ficha03;

import java.util.Scanner;

public class ex02 {
    public static void main(String[] args){
        Scanner entrada = new Scanner(System.in);
        System.out.print("Escreva uma frase: ");
        String frase = entrada.nextLine();
        System.out.println(vogais(frase));
    }

    public static int vogais(String frase){
        String vogals = "aeiou";
        int contador = 0;
        for(int i = 0; i < frase.length(); i++){
            for(int j = 0; j < vogals.length(); j++){
                if(frase.charAt(i) == vogals.charAt(j)){
                    contador++;
                    break;
                }
            }
        }
        return contador;
    }
}
