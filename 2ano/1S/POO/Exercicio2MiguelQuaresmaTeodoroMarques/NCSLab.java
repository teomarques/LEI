import java.util.ArrayList;
import java.util.Random;

/**
 * Classe NCSLab que gerencia uma lista de diferentes computadores no laboratório.
 * Esta classe inicializa vários tipos de computadores e fornece métodos para exibi-los.
 *
 * @version 1.0
 */
public class NCSLab {
    private ArrayList<Computador> computadores;

    /**
     * Construtor da classe NCSLab que inicializa a lista de computadores.
     */
    public NCSLab() {
        computadores = new ArrayList<>();
        inicializarComputadores();
    }

    /**
     * Inicializa a lista de computadores com servidores, laptops e dispositivos Raspberry Pi.
     */
    private void inicializarComputadores() {
        Random random = new Random();

        for (int i = 0; i < 5; i++) {
            computadores.add(new Servidor("S" + i, gerarRamServidor(), gerarDiscoServidor(), gerarCpuServidor(random)));
        }

        for (int i = 0; i < 5; i++) {
            computadores.add(new Laptop("L" + i, random.nextBoolean(), gerarRamLaptop(), gerarDiscoLaptop(), gerarCpuLaptop(random)));
        }

        for (int i = 0; i < 5; i++) {
            computadores.add(new RaspberryPi("R" + i, gerarRamRaspberry(), gerarDiscoRaspberry(), gerarCpuRaspberry(random)));
        }
    }

    private int gerarRamServidor() { return new int[]{128, 256, 512}[new Random().nextInt(3)]; }
    private int gerarDiscoServidor() { return new int[]{1024, 2048, 4096, 8192, 16384}[new Random().nextInt(5)]; }
    private float gerarCpuServidor(Random random) { return 3.0f + random.nextFloat(); }

    private int gerarRamLaptop() { return new int[]{16, 32, 64}[new Random().nextInt(3)]; }
    private int gerarDiscoLaptop() { return new int[]{256, 512, 1024}[new Random().nextInt(3)]; }
    private float gerarCpuLaptop(Random random) { return 2.0f + random.nextFloat(); }

    private int gerarRamRaspberry() { return new int[]{2, 4, 8}[new Random().nextInt(3)]; }
    private int gerarDiscoRaspberry() { return new int[]{16, 32, 64, 128}[new Random().nextInt(4)]; }
    private float gerarCpuRaspberry(Random random) { return 1.0f + random.nextFloat(); }

    /**
     * Exibe informações sobre todos os computadores no laboratório.
     */
    public void imprimirComputadores() {
        for (Computador comp : computadores) {
            System.out.println(comp);
        }
    }

    /**
     * Exibe computadores com arquitetura x64.
     */
    public void mostrarComputadoresX64() {
        for (Computador comp : computadores) {
            if ("x64".equals(comp.getArq())) {
                System.out.println(comp);
            }
        }
    }

    /**
     * Exibe o consumo energético de cada computador.
     */
    public void mostrarConsumoEnergetico() {
        for (Computador comp : computadores) {
            System.out.println(comp.getId() + " Consumo: " + comp.calcularConsumoEnergetico() + "W");
        }
    }
}
