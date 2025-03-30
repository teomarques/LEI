package ficha04;

/**
 * @author Teodoro Marques
 * @version 1.0
 */

public class docente extends pessoa{
    public int numeroMecanografico;
    String missao(){
        System.out.println("Ensinar");
        return "";
    }

    /**
     * metodo toString da class pessoa
     * @return ""
     */
    public String toString(){
        String nome = pessoa.nome;
        System.out.print("O docente de número mecanográfico " + numeroMecanografico + " tem uma missão de ");
        missao();
        return "";
    }
}
