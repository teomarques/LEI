import java.util.ArrayList;
import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    ArrayList<Caminhada> caminhadas = new ArrayList<>();

    System.out.println("Quantas caminhadas deseja adicionar?");
    int numCaminhadas = scanner.nextInt();
    scanner.nextLine(); // Consume newline

    for (int i = 0; i < numCaminhadas; i++) {
      ArrayList<Etapa> etapas = new ArrayList<>();
      System.out.println("Quantas etapas para a caminhada " + (i + 1) + "?");
      int numEtapas = scanner.nextInt();
      scanner.nextLine(); // Consume newline

      for (int j = 0; j < numEtapas; j++) {
        System.out.println("Etapa " + (j + 1) + ":");
        System.out.print("Nome do Local de Origem: ");
        String nomeOrigem = scanner.nextLine();
        System.out.print("Densidade do Local de Origem: ");
        double densidadeOrigem = scanner.nextDouble();
        scanner.nextLine(); // Consume newline

        System.out.print("Nome do Local de Destino: ");
        String nomeDestino = scanner.nextLine();
        System.out.print("Densidade do Local de Destino: ");
        double densidadeDestino = scanner.nextDouble();
        scanner.nextLine(); // Consume newline

        System.out.print("Distância: ");
        double distancia = scanner.nextDouble();
        scanner.nextLine(); // Consume newline

        System.out.print("Tipo de Etapa (cultural/montanha): ");
        String tipo = scanner.nextLine();

        Local localOrigem = new Local(nomeOrigem, densidadeOrigem);
        Local localDestino = new Local(nomeDestino, densidadeDestino);

        Etapa etapa;
        if (tipo.equalsIgnoreCase("cultural")) {
          System.out.print("Pontos de Interesse: ");
          double pontosInteresse = scanner.nextDouble();
          scanner.nextLine(); // Consume newline
          etapa = new EtapaCultural(localOrigem, localDestino, distancia, pontosInteresse);
        } else if (tipo.equalsIgnoreCase("montanha")) {
          System.out.print("Declive: ");
          double declive = scanner.nextDouble();
          scanner.nextLine(); // Consume newline
          etapa = new EtapaMontanha(localOrigem, localDestino, distancia, declive);
        } else {
          System.out.println("Tipo de etapa inválido. Pulando esta etapa.");
          continue;
        }

        etapas.add(etapa);
      }

      Caminhada caminhada = new Caminhada(etapas);
      caminhadas.add(caminhada);
    }

    // Example of using mostraEtapaMaisLonga
    for (Caminhada caminhada : caminhadas) {
      Caminhada.mostraEtapaMaisLonga(caminhada.getEtapas());
      System.out.println("------------------------");
      Caminhada.verificaCircular(caminhada.getEtapas());
    }

    scanner.close();
  }
}
