package ficha04;

public class cafe extends bebidas{
    String tipoCafe;
    if(String(tipoCafe) == "expresso") // fazer outra classe expresso

    /**
     * metodo getQuantidade da class cafe
     * @param tipoCafe
     * @return
     */
    private int getQuantidade(String tipoCafe) {
        switch (tipoCafe) {
            case "curto":
                return 25;
            case "cheio":
                return 50;
            case "normal":
                return 35;
            default:
                return 100;
        }
    }
}