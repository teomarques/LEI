package ficha04;

/**
 * @author Teodoro Marques
 * @version 1.0
 */

public class pessoa {
    protected static String nome;
    /**
     * metodo comunica da class pessoa
     * @return nome
     */
    public String comunica(){
        this.nome = nome;
        System.out.println(nome + " a comunicar.");
        return nome;
    }
}
