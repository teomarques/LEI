import java.util.ArrayList;
import java.util.Random;

/**
 * @author Miguel Quaresma
 * @author Teodoro Marques
 * @version 1.0
 */
public class NCSLab {
    private ArrayList<Computadores> computadores;

    /**
     * Método NCSLab para criar objeto ArrayList computadores
     */
    public NCSLab() {
        computadores = new ArrayList<>();
        inicializarComputadores();
    }

    /**
     * Método para inicializar Computadores dentro do ArrayList
     */
    private void inicializarComputadores() {
        Random random = new Random();

        // Adiciona 5 servidores
        for (int i = 0; i < 5; i++) {
            computadores.add(new Servidor("S" + i, gerarRamServidor(), gerarDiscoServidor(), gerarCpuServidor(random)));
        }

        // Adiciona 5 laptops com GPU aleatório
        for (int i = 0; i < 5; i++) {
            computadores.add(new Laptop("L" + i, random.nextBoolean(), gerarRamLaptop(), gerarDiscoLaptop(), gerarCpuLaptop(random)));
        }

        // Adiciona 5 Raspberry Pis
        for (int i = 0; i < 5; i++) {
            computadores.add(new RaspberryPi("R" + i, gerarRamRaspberry(), gerarDiscoRaspberry(), gerarCpuRaspberry(random)));
        }
    }

    /**
     * Método getter para gerar Ram aleatória do Servidor
     * @return new int[]{128, 256, 512}[new Random().nextInt(3)]
     */
    private int gerarRamServidor() { return new int[]{128, 256, 512}[new Random().nextInt(3)]; }

    /**
     * Método getter para gerar Disco aleatório do Servidor
     * @return new int[]{1024, 2048, 4096, 8192, 16384}[new Random().nextInt(5)]
     */
    private int gerarDiscoServidor() { return new int[]{1024, 2048, 4096, 8192, 16384}[new Random().nextInt(5)]; }

    /**
     * Método getter para gerar Cpu aleatório do Servidor
     * @param random
     * @return 3.0f + random.nextFloat()
     */
    private float gerarCpuServidor(Random random) { return 3.0f + random.nextFloat(); }

    /**
     * Método getter para gerar Ram aleatória do Laptop
     * @return new int[]{16, 32, 64}[new Random().nextInt(3)]
     */
    private int gerarRamLaptop() { return new int[]{16, 32, 64}[new Random().nextInt(3)]; }

    /**
     * Método getter para gerar Disco aleatória do Laptop
     * @return new int[]{256, 512, 1024}[new Random().nextInt(3)]
     */
    private int gerarDiscoLaptop() { return new int[]{256, 512, 1024}[new Random().nextInt(3)]; }

    /**
     * Método getter para gerar Cpu aleatório do Laptop
     * @param random
     * @return 2.0f + random.nextFloat()
     */
    private float gerarCpuLaptop(Random random) { return 2.0f + random.nextFloat(); }

    /**
     * Método getter para gerar Ram aleatória do RaspberryPi
     * @return new int[]{2, 4, 8}[new Random().nextInt(3)]
     */
    private int gerarRamRaspberry() { return new int[]{2, 4, 8}[new Random().nextInt(3)]; }

    /**
     * Método getter para gerar Disco Aleatória do RaspberryPi
     * @return new int[]{16, 32, 64, 128}[new Random().nextInt(4)]
     */
    private int gerarDiscoRaspberry() { return new int[]{16, 32, 64, 128}[new Random().nextInt(4)]; }

    /**
     * Método getter para gerar Cpu aleatório do RaspberryPi
     * @param random
     * @return 1.0f + random.nextFloat()
     */
    private float gerarCpuRaspberry(Random random) { return 1.0f + random.nextFloat(); }

    /**
     * Método para imprimir todos os Computadores
     */
    public void imprimirComputadores() {
        for (Computadores comp : computadores) {
            System.out.println(comp);
        }
    }

    /**
     * Método para imprimir todos os Computadores x64
     */
    public void mostrarComputadoresX64() {
        for (Computadores comp : computadores) {
            if (comp.getArq().equals("x64")) {
                System.out.println(comp);
            }
        }
    }

    /**
     * Método para imprimir o consumo energético dos Computadores
     */
    public void mostrarConsumoEnergetico() {
        for (Computadores comp : computadores) {
            System.out.println(comp.getId() + " Consumo: " + comp.calcularConsumoEnergetico() + "W");
        }
    }
}