import java.util.*;
import java.io.*;

public class NovaMain{
  protected final Scanner sc = new Scanner(System.in);
  private final ArrayList<NovoMedico> medicos = new ArrayList<NovoMedico>();

  public static void main(String[] args){
    NovaMain executa = new NovaMain();
    executa.Executa();
  }

  public void Executa(){
    NovaEspecialidade especialidadeJoao = new NovaEspecialidade("Pulmonioníese", 90, 15);
    NovoMedico medicoJoao = new NovoMedico("João Espinhão", especialidadeJoao, 15, 24);
    medicos.add(medicoJoao);
    mostrarMenu();
    int opcao = -1;
    boolean out = false;
    System.out.println("opção --> ");
    opcao = sc.nextInt();
    while(!out){
      switch(opcao){
        case 0 -> {
          System.out.println("Adeus!");
          out = true;
          break;
        }
        case 1 -> criarMedico();
        case 2 -> listarMedicos(medicos);
        case 3 -> removerMedico(medicos);
      }
    }
  }

  public void mostrarMenu(){
    System.out.println("---------MENU---------");
    System.out.println("1 - Criar novo médico");
    System.out.println("2 - Ver lista de médicos");
    System.out.println("3 - Remover médico da lista");
    System.out.println("0 - Encerrar programa");
  }

  public void criarMedico(){
    System.out.printf("Nome do médico: ");
    String nome = sc.nextLine();
    sc.nextLine();

    System.out.printf("especialidade do médico: ");
    String nomeEspecialidade = sc.nextLine();

    System.out.println("salário base da especialidade: ");
    int salarioBase = sc.nextInt();

    System.out.println("custo das horas extra da especialidade: ");
    int custoHoraExtra = sc.nextInt();

    // criar nova especialidade para o médico
    NovaEspecialidade especialidade = new NovaEspecialidade(nomeEspecialidade, salarioBase, custoHoraExtra);

    System.out.println("Tempo de serviço do medico: ");
    int tempoServico = sc.nextInt();

    System.out.println("Horas Extra do médico: ");
    int horasExtra = sc.nextInt();

    // criar novo médico
    NovoMedico medico = new NovoMedico(nome, especialidade, tempoServico, horasExtra);
    medicos.add(medico);
  }

  public void listarMedicos(ArrayList<NovoMedico> medicos){
    String opcao;
    int i = 0;
    for(NovoMedico medico : medicos){
      i++;
      System.out.printf("%d - ", i);
      System.out.println(medico.getNome());
      System.out.printf("Mostrar informações detalhadas do médico %s? (s/n)\n", medico.getNome());
      opcao = sc.nextLine();
      if(opcao.equalsIgnoreCase("s")){
        System.out.println(medico);
      }
    }
  }

  public void removerMedico(ArrayList<NovoMedico> medicos){
    int opcao;
    System.out.println("Qual médico desejas remover (por índice)? ");
    opcao = sc.nextInt();
    int i = 0;
    for(NovoMedico medico : medicos){
      if(i == opcao){
        medicos.remove(i);
      }
      i++;
    }
  }
} 

