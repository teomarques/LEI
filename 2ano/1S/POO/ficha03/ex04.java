package ficha03;

import java.util.Scanner;

public class ex04 {
    public static void main(String[] args) {
        Scanner entrada = new Scanner(System.in);
        System.out.print("Escreva uma frase: ");
        String frase = entrada.nextLine();
        juntap(frase);
    }

    public static void juntap(String frase){
        String vogals = "aeiou";
        int contador = 0;
        String sub1 = new String();
        String sub2 = new String();
        int stop = 0;
        String novaFrase = "";
        for(int i = 0; i < frase.length(); i++){
            for(int j = 0; j < vogals.length(); j++){
                if(frase.charAt(i) == vogals.charAt(j)){
                    contador++;
                    if(contador == 2) {
                        sub1 = frase.substring(stop, i - 1);
                        sub2 = frase.substring(i);
                        System.out.println(sub1 + " " + sub2);
                        novaFrase = (sub1 + "p").concat(sub2);
                        stop = i;
                        System.out.println(novaFrase);
                        contador = 0;
                    }
                    break;
                }
            }
        }
    }
}
