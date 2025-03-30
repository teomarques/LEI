import java.util.ArrayList;

public class Caminhada {
    private ArrayList<Etapa> etapas;

    public Caminhada(ArrayList<Etapa> etapas) {
        this.etapas = etapas != null ? etapas : new ArrayList<Etapa>();
    }

    public ArrayList<Etapa> getEtapas() {
        return etapas;
    }

    public static void verificaCircular(ArrayList<Etapa> etapas) {
        if (etapas == null || etapas.isEmpty()) {
            System.out.println("não há etapas.");
            return;
        }

        Local primeiroLocalOrigem = etapas.get(0).getLocalOrigem();
        Local ultimoLocalDestino = etapas.get(etapas.size() - 1).getLocalDestino();

        if (primeiroLocalOrigem != null && ultimoLocalDestino != null &&
            primeiroLocalOrigem.getNomeLocal().equalsIgnoreCase(ultimoLocalDestino.getNomeLocal())) {
            System.out.println("A caminhada é circular.");
        } else {
            System.out.println("A caminhada não é circular.");
        }
    }

    public static void mostraEtapaMaisLonga(ArrayList<Etapa> etapas) {
        if (etapas == null || etapas.isEmpty()) {
            System.out.println("etapas Vazio!");
        } else {
            double maiorDistancia = 0;
            Local maiorLocalOrigem = null;
            Local maiorLocalDestino = null;
            for (Etapa etapa : etapas) {
                if (etapa.getDistancia() > maiorDistancia) {
                    maiorDistancia = etapa.getDistancia();
                    maiorLocalOrigem = etapa.getLocalOrigem();
                    maiorLocalDestino = etapa.getLocalDestino();
                }
            }
            System.out.println("maior dist: " + maiorDistancia + 
                               "\nLocal Origem: " + (maiorLocalOrigem != null ? maiorLocalOrigem.getNomeLocal() : "null") + 
                               "\nLocal Destino: " + (maiorLocalDestino != null ? maiorLocalDestino.getNomeLocal() : "null"));
        }
    }
}