package exercicio1;

import java.util.Arrays;

public class Exercicio1_leo {
    public static void main(String[] args) {
        String[] especialidades = {
                //nome/salário base/custo da hora extra
                "Radiologia/2030/50",
                "Oftalmologia/2500/70",
                "Pediatria/2700/75"
        };
        String[] medicos = {
                //nome/especialidade/anos de serviço/horas extra
                "Vasco Santana/radiologia/15/10",
                "Laura Alves/oftalmologia/5/7",
                "António Silva/oftalmologia/12/5"
        };

        String[][] tabela1 = partir(especialidades, 3);
        String[][] tabela2 = partir(medicos, 4);

        resultado(tabela1, tabela2);

    }

    public static String[][] partir(String [] tab, int categorias){
        int size = tab.length;
        String [][] tab_org = new String[size][categorias];

        for (int i = 0; i < size; i++){
            tab_org[i] = tab[i].split("/");
        }
        return tab_org;

    }

    public static void resultado(String[][] especialidades, String[][] medicos){
        int doutores = medicos.length;
        double [] ordenados_total = new double[doutores];

        int categorias = especialidades.length;
        double [] valores_total = new double[categorias];

        for (int x = 0; x < doutores; x++){

            for (int i = 0; i < categorias; i++){
                if ( (especialidades[i][0]).equalsIgnoreCase(medicos[x][1]) ){
                    double base = Double.parseDouble(especialidades[i][1]);
                    double extra = Double.parseDouble(especialidades[i][2]);

                    double anos = Double.parseDouble(medicos[x][2]);
                    double horas = Double.parseDouble(medicos[x][3]);

                    double bonus_anos = Math.pow(1.04, (int) (anos / 5));

                    ordenados_total[x] = base * bonus_anos + horas*extra;
                    // percorrendo sempre as especialidades, para cada médico analisado, o seu salário será somado na respectiva especialidade, por ordem que aparece
                    valores_total[i] += ordenados_total[x];
                }
            }
        }

        System.out.print("Resultado:\n");
        imprimir_info(medicos, ordenados_total);
        imprimir_info(especialidades, valores_total);
    }

    public static void imprimir_info(String [][] tabela, double [] valores){
        for (int i = 0; i < tabela.length; i++) {
            if (valores[i] != 0){
                System.out.printf("%s: %.1f€ \n", tabela[i][0], valores[i]);
            }
        }
        System.out.print('\n');
    }
}