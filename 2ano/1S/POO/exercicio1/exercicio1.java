package exercicio1;
import java.util.Arrays;

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
        calculaMedico(medicos, especialidades);
    }
    public static void calculaMedico(String[] medicos, String[] especialidades){

        String[][] valorPessoa = new String[medicos.length][2];
        String[][] valorEspecialidades = new String[especialidades.length][2];

        // Initialize to avoid null values
        for (int i = 0; i < valorPessoa.length; i++) {
            valorPessoa[i][1] = "0";
        }
        for (int i = 0; i < valorEspecialidades.length; i++) {
            valorEspecialidades[i][1] = "0";
        }

        // Separate fields
        int tamanhoMedicos = medicos.length;
        String[] pessoas = new String[tamanhoMedicos];
        String[] oficios = new String[tamanhoMedicos];
        String[] anos = new String[tamanhoMedicos];
        String[] horasExtra = new String[tamanhoMedicos];

        for(int i = 0; i < tamanhoMedicos; i++) {
            String[] parts = medicos[i].split("/");
            pessoas[i] = parts[0];  // doctor's name
            oficios[i] = parts[1];  // specialty
            anos[i] = parts[2];     // years of service
            horasExtra[i] = parts[3]; // extra hours
        }

        int tamanhoEspecialidades = especialidades.length;
        String[] espec = new String[tamanhoEspecialidades];
        String[] salario = new String[tamanhoEspecialidades];
        String[] extra = new String[tamanhoEspecialidades];

        for(int i = 0; i < tamanhoEspecialidades; i++) {
            String[] parts = especialidades[i].split("/");
            espec[i] = parts[0];     // specialty
            salario[i] = parts[1];   // base salary
            extra[i] = parts[2];     // extra hour cost
        }

        // Calculate earnings per doctor
        for(int i = 0; i < pessoas.length; i++) {
            double baseSalario = 0;
            double custoExtraHora = 0;

            // Find matching specialty for doctor
            for(int j = 0; j < espec.length; j++) {
                if(oficios[i].equals(espec[j])) {
                    baseSalario = Double.parseDouble(salario[j]);
                    custoExtraHora = Double.parseDouble(extra[j]);
                    break;
                }
            }

            // Calculate earnings: Base salary + (Extra Hours * Cost of Extra Hour)
            double totalEarnings = baseSalario * (Integer.parseInt(anos[i])) + (Integer.parseInt(horasExtra[i]) * custoExtraHora);
            valorPessoa[i][0] = pessoas[i];
            valorPessoa[i][1] = String.format("%.1f€", totalEarnings);

            // Add to specialty total earnings
            for(int j = 0; j < espec.length; j++) {
                if(oficios[i].equals(espec[j])) {
                    double currentTotal = Double.parseDouble(valorEspecialidades[j][1]);
                    valorEspecialidades[j][0] = espec[j];
                    valorEspecialidades[j][1] = String.format("%.1f", currentTotal + totalEarnings);
                }
            }
        }

        // Print results
        printValores(valorPessoa);
        printValoresEspecialidades(valorEspecialidades);
    }

    public static boolean repetido(String[] array, String target){
        int c = 0;
        for(int i = 0; i < array.length; i++){
            if(array[i].equals(target)){
                c++;
                if(c > 1) {
                    return true;
                }
            }
        }
        return false;
    }

    public static void printValores(String[][] array) {
        for (String[] strings : array) {
            if(strings[0] != null) {
                System.out.println(strings[0] + ": " + strings[1]);
            }
        }
    }

    public static void printValoresEspecialidades(String[][] array) {
        for (String[] strings : array) {
            if(strings[0] != null) {
                System.out.println(strings[0] + ": " + strings[1] + "€");
            }
        }
    }
}
