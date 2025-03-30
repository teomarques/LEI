package exercicio1;
import java.util.Arrays;
import java.util.Objects;

public class exercicio1 {
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
        calculaMedico(medicos);
    }
    public static void calculaMedico(String[] medicos){

        // separa médicos, ofícios, anos de serviço e horas extra
        int tamanho = medicos.length;

        // criar array de pessoas (médicos)
        int index = 0;
        String[] medicos1 = new String[tamanho];
        medicos1 = medicos;
        String[] pessoas = new String[medicos.length];
        for(int i = 0; i < tamanho; i++){
            index = medicos1[i].indexOf('/');
            pessoas[i] = medicos1[i].substring(0, index);
            medicos1[i] = medicos1[i].substring(index+1);
        }

        // criar array de ofícios
        String[] oficios = new String[medicos.length];
        for(int i = 0; i < tamanho; i++){
            index = medicos1[i].indexOf('/');
            oficios[i] = medicos1[i].substring(0, index);
            medicos1[i] = medicos1[i].substring(index+1);
        }

        // criar array de anos de trabalho
        String[] anos = new String[medicos.length];
        for(int i = 0; i < tamanho; i++){
            index = medicos1[i].indexOf('/');
            anos[i] = medicos1[i].substring(0, index);
            medicos1[i] = medicos1[i].substring(index+1);
        }

        // criar array de horas extra de trabalho
        String[] horasExtra = new String[medicos.length];
        for(int i = 0; i < tamanho; i++){
            index = medicos1[i].indexOf('/');
            horasExtra[i] = medicos1[i];
        }

        System.out.println("médicos: "+ Arrays.toString(pessoas));
        System.out.println("ofícios: "+ Arrays.toString(oficios));
        System.out.println("anos: "+ Arrays.toString(anos));
        System.out.println("horas extra: "+ Arrays.toString(horasExtra));
    }
}

