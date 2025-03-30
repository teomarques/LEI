/**
 * Classe RaspberryPi que herda da classe Computador.
 * Representa um dispositivo Raspberry Pi com baixo consumo energético.
 *
 * @version 1.0
 */
public class RaspberryPi extends Computador {

    /**
     * Construtor da classe RaspberryPi.
     * @param id Identificador do Raspberry Pi.
     * @param ram Quantidade de RAM em GB.
     * @param disco Capacidade de armazenamento em disco em GB.
     * @param cpu Velocidade da CPU em GHz.
     */
    public RaspberryPi(String id, int ram, int disco, float cpu) {
        super(id, ram, disco, cpu, "IoT");
    }

    /**
     * Calcula o consumo energético do Raspberry Pi.
     * @return O consumo energético baseado na CPU, em watts.
     */
    @Override
    public double calcularConsumoEnergetico() {
        return 20 * cpu;
    }
}
