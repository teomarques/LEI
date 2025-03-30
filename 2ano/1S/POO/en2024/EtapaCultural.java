public class EtapaCultural extends Etapa {
  private double pontosInteresse;

  public EtapaCultural(Local localOrigem, Local localDestino, double distancia, double pontosInteresse) {
      super(localOrigem, localDestino, distancia);
      this.pontosInteresse = pontosInteresse;
  }

  public double getPontosInteresse() {
      return pontosInteresse;
  }
}