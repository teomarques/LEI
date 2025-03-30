/**
 * Classe Servidor que herda da classe Computador.
 * Representa um servidor com requisitos específicos de RAM, disco e CPU.
 *
 * @version 1.0
 */
public class Servidor extends Computador {
    /**
     * Construtor da classe Servidor.
     * @param id Identificador do servidor.
     * @param ram Quantidade de RAM em GB.
     * @param disco Capacidade de armazenamento em disco em GB.
     * @param cpu Velocidade da CPU em GHz.
     * @throws IllegalArgumentException se os valores de RAM, disco ou CPU estiverem fora dos limites permitidos.
     */
    public Servidor(String id, int ram, int disco, float cpu) {
        super(id, ram, disco, cpu, "Cloud");

        if (ram < 128 || ram > 512) {
            throw new IllegalArgumentException("A RAM do servidor deve estar entre 128 e 512 GB.");
        }
        if (disco < 1024 || disco > 16384) {
            throw new IllegalArgumentException("O disco deve estar entre 1024 e 16384 GB.");
        }
        if (cpu < 3.0f || cpu > 4.0f) {
            throw new IllegalArgumentException("A CPU deve estar entre 3.0 e 4.0 GHz.");
        }
    }

    /**
     * Calcula o consumo energético do servidor.
     * @return O consumo energético baseado na CPU, em watts.
     */
    @Override
    public double calcularConsumoEnergetico() {
        return 80 * cpu;
    }
}
