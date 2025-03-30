package ficha01;
import java.util.Arrays;
import java.util.Objects;
import java.util.Scanner;

public class ex03 {

    // Main Method
    public static void main(String[] args){
        Scanner entrada = new Scanner(System.in);
        System.out.print("Digite um nº binário: ");
        int valor = entrada.nextInt();
        System.out.println(valor);
        System.out.println("Nº de zeros: "+contagem(converteNum(valor))[0]);
        System.out.println("Nº de uns: "+contagem(converteNum(valor))[1]);
        System.out.println("Valor em decimal: "+contagem(converteNum(valor))[2]);
    }

    // Calculate the size of the value (number of characters)
    public static int tamanhoNum(int n){
        int tamanho = 0;
        while(n >= 1){
            tamanho++;
            n /= 10;
        }
        return tamanho;
    }

    // Convert integer into an array[]
    public static String[] converteNum(int b){
        int tamanho = tamanhoNum(b);
        int bResto = 0;
        String[] bString = new String[tamanho];
        for(int i = 0; i < tamanho; i++){
            bResto = b % 10;
            b /= 10;
            bString[tamanho - i - 1] = bResto + "";
        }
        return bString;
    }
    public static String[] contagem(String[] bString){
        int tamanho = bString.length;
        String[] contagem = new String[3];
        int numZeros = 0;
        int numUns = 0;
        int potencia = 0;
        for(int i = 0; i < tamanho; i++){
            if(Objects.equals(bString[i], "0")) {
                numZeros++;
            }
            else{
                numUns++;
                potencia += (int) Math.pow(2, tamanho - i - 1);
            }
        }
        contagem[0] = String.valueOf(numZeros);
        contagem[1] = String.valueOf(numUns);
        contagem[2] = String.valueOf(potencia);
        return contagem;
    }

}
