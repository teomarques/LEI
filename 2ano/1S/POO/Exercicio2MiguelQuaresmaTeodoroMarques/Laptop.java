/**
 * Classe Laptop que herda da classe Computador.
 * Representa um laptop que pode ter uma GPU opcional para maior consumo energético.
 *
 * @version 1.0
 */
public class Laptop extends Computador {
    private boolean hasGPU;

    /**
     * Construtor da classe Laptop.
     * @param id Identificador do laptop.
     * @param hasGPU Indica se o laptop possui uma GPU (true/false).
     * @param ram Quantidade de RAM em GB.
     * @param disco Capacidade de armazenamento em disco em GB.
     * @param cpu Velocidade da CPU em GHz.
     */
    public Laptop(String id, boolean hasGPU, int ram, int disco, float cpu) {
        super(id, ram, disco, cpu, "Edge");
        this.hasGPU = hasGPU;
    }

    /**
     * Calcula o consumo energético do laptop.
     * @return O consumo energético baseado na CPU e na presença de uma GPU, em watts.
     */
    @Override
    public double calcularConsumoEnergetico() {
        return hasGPU ? 50 * cpu * 1.2 : 50 * cpu;
    }
}
