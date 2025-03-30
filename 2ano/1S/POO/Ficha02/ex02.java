import java.util.Arrays;

public class ex02 {
    public static void main(String[] args){
        int[] tab1 = new int[]{1, 2, 3};
        int[] tab2 = new int[]{7, 8, 9};
        int[] tab3 = new int[6];
        tab3 = intercalar(tab1, tab2);
        System.out.println(java.util.Arrays.toString(tab3));
    }
    public static int[] intercalar(int[] t1, int[] t2){
        int[] t3 = new int[2*t1.length];
        for(int i = 0; i < t1.length; i++) {
            t3[2 * i] = t1[i];
            t3[2 * i + 1] = t2[i];
        }
        return t3;
    }// end method
}
