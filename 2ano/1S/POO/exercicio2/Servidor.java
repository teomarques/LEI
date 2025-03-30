import java.util.Random;

/**
 * Classe para
 * @author Miguel Quaresma
 * @author Teodoro Marques
 * @version 1.0
 */
public class Servidor extends Computadores {

    /**
     * Método construtor Servidor para a classe Servidor
     * @param id
     * @param ram
     * @param disco
     * @param cpu
     */
    public Servidor(String id, int ram, int disco, float cpu) {
        super(id, ram, disco, cpu, "x64", "Cloud");
        this.cpu = cpu;

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
     * Método para calcular consumo energético do Servidor
     * @return
     */
    @Override
    public double calcularConsumoEnergetico() {
        return 80 * cpu;
    }
}
