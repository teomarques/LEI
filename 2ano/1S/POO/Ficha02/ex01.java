import java.util.Random;
import java.util.Arrays;

public class ex01 {
    public static void main(String[] args){
        int[] tab = new int[10];
        System.out.println(java.util.Arrays.toString(tabelaAleatorios(tab)));
    }
    public static int[] tabelaAleatorios(int[] tab){
        for(int i = 0; i < tab.length; i++){
            Random rand = new Random();
            int rand_val = rand.nextInt(100);
            tab[i] = rand_val;
        }
        return tab;
    }
}
