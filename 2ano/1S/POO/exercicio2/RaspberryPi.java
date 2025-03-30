import java.util.Random;

/**
 * Classe RaspberryPi herda classe Computadores
 * @author Miguel Quaresma
 * @author Teodoro Marques
 * @version 1.0
 */
public class RaspberryPi extends Computadores {

    /**
     * Método construtor RaspberryPi para a classe RaspberryPi
     * @param id
     * @param ram
     * @param disco
     * @param cpu
     */
    public RaspberryPi(String id, int ram, int disco, float cpu) {
        super(id, ram, disco, cpu, "ARM", "IoT");
        this.cpu = cpu;
    }

    /**
     * Método para calcular consumo energético do Raspberry Pi
     * @return
     */
    @Override
    public double calcularConsumoEnergetico() {
        return 20 * cpu;
    }
}