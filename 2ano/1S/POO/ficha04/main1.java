package ficha04;

/**
 * @author Teodoro Marques
 * @version 1.0
 */

public class main1 {
    /**
     * metodo main da class main
     * @param args
     */
    public static void main(String[] args) {
        aluno joao = new aluno();
        joao.nome = "João Mendes";
        joao.numeroAluno = 20228828;
        joao.comunica();
        joao.missao();
        joao.toString();

        docente clovis = new docente();
        clovis.nome = "Clóvis de Barros";
        clovis.numeroMecanografico = 201888467;
        clovis.comunica();
        clovis.missao();
        clovis.toString();
    }
}
