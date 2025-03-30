public abstract class Etapa{
    private Local localOrigem;
    private Local localDestino;
    private double distancia;
    
    public Etapa(Local localOrigem, Local localDestino, double distancia){
      this.localOrigem = localOrigem;
      this.localDestino = localDestino;
      this.distancia = distancia;
    }
  
    public Local getLocalOrigem(){
      return localOrigem;
    }
  
    public Local getLocalDestino(){
      return localDestino;
    }
  
    public double getDistancia(){
      return distancia;
    }
  }
