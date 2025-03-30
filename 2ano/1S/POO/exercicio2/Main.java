/**
 * @author Miguel Quaresma
 * @author Teodoro Marques
 * @version 1.0
 */
public class Main {
    /**
     * Método main
     * @param args
     */
    public static void main(String[] args) {
        NCSLab lab = new NCSLab();

        System.out.println("Todos os Computadores:");
        lab.imprimirComputadores();

        System.out.println("\nComputadores com Arquitetura x64:");
        lab.mostrarComputadoresX64();

        System.out.println("\nConsumo Energético dos Computadores:");
        lab.mostrarConsumoEnergetico();
    }
}