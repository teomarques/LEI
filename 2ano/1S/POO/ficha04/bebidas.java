package ficha04;

public class bebidas {
    protected String nome;
    protected double temperatura;
    protected double quantidade;

    /**
     * Construtor para bebida
     * @param nome
     * @param temperatura
     * @param quantidade
     */
    public void bebida(String nome, int temperatura, int quantidade){
        this.nome = nome;
        this.temperatura = temperatura;
        this.quantidade = quantidade;
        return;
    }

    /**
     * metodo toString da class bebidas
     * @override
     */
    public String toString() {
        return nome + " - " + temperatura + "ºC - " + quantidade + "ml";
    }
}
