import java.util.Random;

/**
 * Superclasse que representa um computador.
 * Esta classe contém informações básicas sobre o computador, como
 * identificação, especificações de hardware e arquitetura.
 *
 * @author Miguel Quaresma
 * @author Teodoro Marques
 * @version 1.0
 */
public class Computador {
    /** Identificador do computador */
    protected String id;          // Identificador do computador

    /** Memória RAM em GB */
    protected int ram;           // Memória RAM em GB

    /** Capacidade do disco em GB */
    protected int armDisco;      // Capacidade do disco em GB

    /** Frequência da CPU em GHz */
    protected float cpu;         // Frequência da CPU em GHz

    /** Arquitetura (x64 ou ARM) */
    protected String arq;        // Arquitetura (x64 ou ARM)

    /** Nível do computador (ex: Cloud, Edge, IoT) */
    protected String nivel;      // Nível do computador (ex: Cloud, Edge, IoT)

    /**
     * Construtor da classe Computador.
     *
     * @param id    Identificador do computador
     * @param ram   Quantidade de memória RAM em GB
     * @param armDisco Capacidade do disco em GB
     * @param cpu   Frequência da CPU em GHz
     * @param nivel Nível do computador (ex: Cloud, Edge, IoT)
     */
    public Computador(String id, int ram, int armDisco, float cpu, String nivel) {
        this.id = id;
        this.ram = ram;
        this.armDisco = armDisco;
        this.cpu = cpu;
        this.arq = gerarArquiteturaAleatoria(); // Geração aleatória de arquitetura
        this.nivel = nivel;
    }

    /**
     * Gera uma arquitetura aleatória (x64 ou ARM).
     *
     * @return Uma string representando a arquitetura (x64 ou ARM).
     */
    private String gerarArquiteturaAleatoria() {
        return new Random().nextBoolean() ? "x64" : "ARM";
    }

    /**
     * Método getter para a arquitetura.
     *
     * @return A arquitetura do computador.
     */
    public String getArq() {
        return arq;
    }

    /**
     * Método getter para o ID do computador.
     *
     * @return O identificador do computador.
     */
    public String getId() {
        return id;
    }

    /**
     * Método toString que fornece uma representação em String do computador.
     *
     * @return Uma String formatada com as informações do computador.
     */
    @Override
    public String toString() {
        return String.format("ID: %s, RAM: %dGB, Disco: %dGB, CPU: %.1fGHz, Nível: %s, Arquitetura: %s",
                id, ram, armDisco, cpu, nivel, arq);
    }

    /**
     * Método polimórfico de cálculo de consumo energético.
     * Este método deve ser sobrescrito nas subclasses para fornecer
     * um cálculo específico para cada tipo de computador.
     *
     * @return O consumo energético do computador, que é 0 por padrão.
     */
    public double calcularConsumoEnergetico() {
        return 0; // Valor padrão, será sobrescrito nas subclasses
    }
}
