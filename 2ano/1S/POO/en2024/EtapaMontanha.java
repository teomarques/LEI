public class EtapaMontanha extends Etapa {
  private double declive;

  public EtapaMontanha(Local localOrigem, Local localDestino, double distancia, double declive) {
      super(localOrigem, localDestino, distancia);
      this.declive = declive;
  }

  public double getDeclive() {
      return declive;
  }
}