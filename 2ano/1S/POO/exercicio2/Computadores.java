/**
 * Superclasse Computadores
 * @author Miguel Quaresma
 * @author Teodoro Marques
 * @version 1.0
 */
public class Computadores {
    protected String id;
    protected int ram;
    protected int armDisco;
    protected float cpu;
    protected String arq;
    protected String nivel;

    /**
     * Método construtor Computadores para a classe Computadores
     * @param id
     * @param ram
     * @param armDisco
     * @param cpu
     * @param arq
     * @param nivel
     */
    public Computadores(String id, int ram, int armDisco, float cpu, String arq, String nivel) {
        this.id = id;
        this.ram = ram;
        this.armDisco = armDisco;
        this.cpu = cpu;
        setArq(arq);
        this.nivel = nivel;
    }

    /**
     * Método setter para a arquitetura, aceitando apenas "x64" ou "ARM"
     * @param arq
     */
    public void setArq(String arq) {
        if (!arq.equals("x64") && !arq.equals("ARM")) {
            throw new IllegalArgumentException("A arquitetura só pode ser x64 ou ARM.");
        }
        this.arq = arq;
    }

    /**
     * Método getter para a arquitetura
     * @return
     */
    public String getArq() {
        return arq;
    }

    /**
     * Método getter para ID
     * @return
     */
    public String getId() {
        return id;
    }

    /**
     * Método toString para exibir informações do computador
     * @return
     */
    @Override
    public String toString() {
        return String.format("ID: %s, RAM: %dGB, Disco: %dGB, CPU: %.1fGHz, Nível: %s, Arquitetura: %s",
                id, ram, armDisco, cpu, nivel, arq);
    }

    /**
     * Método polimórfico de cálculo de consumo energético (sobrescrito nas subclasses)
     * @return
     */
    public double calcularConsumoEnergetico() {
        return 0; // valor padrão, será sobrescrito nas subclasses
    }
}