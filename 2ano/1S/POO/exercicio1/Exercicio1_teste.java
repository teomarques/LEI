package exercicio1;

import java.util.Arrays;

public class Exercicio1_teste {
    public static void main(String[] args) {
        String[] especialidades = {
                // nome / salário base / custo da hora extra
                "radiologia/2030/50",
                "oftamologia/2500/70",
                "pediatria/2700/75"
        };
        String[] medicos = {
                // nome / especialidade / anos de serviço / horas extra
                "Vasco Santana/radiologia/15/10",
                "Laura Alves/oftalmologista/5/7",
                "António Silva/oftalmologista/12/5"
        };
        partir(medicos, especialidades);
    }
    public static void partir(String[] medicos, String[] especialidades) {
        String[] infosPartir = new String[medicos.length*2];
        for(int i = 0; i < medicos.length; i++){
            infosPartir[i] = Arrays.toString(medicos[i].split("/"));
        }
        for(int i = 0; i < medicos.length; i++){
            infosPartir[i] = Arrays.toString(especialidades[i].split("/"));
        }
    }
}
