/**
 * Classe principal da aplicação.
 * Esta classe contém o método principal que inicia o programa.
 * O programa é responsável por gerenciar diferentes tipos de computadores.
 *
 * @author Miguel Quaresma
 * @author Teodoro Marques
 * @version 1.0
 */
public class Main {
    /**
     * Construtor padrão da classe Main.
     * Este construtor não realiza nenhuma operação específica.
     */
    public Main() {
        // Construtor vazio
    }

    /**
     * Método principal que inicia a aplicação.
     *
     * @param args Argumentos de linha de comando (não utilizados).
     */
    public static void main(String[] args) {
        // Código para iniciar a aplicação
        NCSLab lab = new NCSLab();

        System.out.println("Todos os Computadores:");
        lab.imprimirComputadores();

        System.out.println("\nComputadores com Arquitetura x64:");
        lab.mostrarComputadoresX64();

        System.out.println("\nConsumo Energético dos Computadores:");
        lab.mostrarConsumoEnergetico();
    }
}
