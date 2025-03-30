package ficha04;

/**
 * @author Teodoro Marques
 * @version 1.0
 */

public class aluno extends pessoa{
    public int numeroAluno;
    String missao(){
        System.out.println("aprender");
        return "";
    }
    /**
     * metodo da class aluno
     * @return ""
     */
    public String toString(){
        this.nome = pessoa.nome;
        System.out.print("O aluno com o número de aluno " + String.valueOf(numeroAluno) + " tem uma missão de ");
        missao();
        return "";
    }
}
