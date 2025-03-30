import java.util.ArrayList;
import java.io.Serializable;

public class Main() {
  public static void main(String[] args) {
    // etc etc
    double maior = 0.0;
    ArrayList<Etapa> etapasAtuais = new ArrayList<>();
    for(Caminhada caminhada : caminhadas){
      etapasAtuais = caminhada.getEtapas();
      for(int i = 0; i < etapasAtuais.size(); i++){
        if(etapasAtuais.get(i).getDistancia() > maior){maior = etapasAtuais.get(i).getDistancia()}
      }
    }
  }
}

public class Empresa() {
  private ArrayList<Caminhada> caminhadas;
  public Empresa(ArrayList<Caminhada> caminhadas){
    this.caminhadas = caminhadas != null ? caminhadas : new ArrayList<Caminhada>();
  }
  public ArrrayList<Caminhada>getCaminhadas(){
    return caminhadas;
  }
}

public class Caminhada{
  private ArrayList<Etapa> etapas;
  public Caminhadas(ArrayList<Etapa> etapas){
    this.etapas = etapas != null ? etapas : new ArrayList<Etapa>();
  }
  public ArrrayList<Etapa>getEtapas(){
    return etapas;
  }
}

public abstract class Etapas{
  private Local localOrigem;
  private Local localDestino;
  private double distancia;
  public Etapas(Local localOrigem, Local localDestino, double distancia){
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

public class EtapaCultural extends Etapas{
  private double pontosInteresse;
  public EtapaCultural(Local localOrigem, Local localDestino, double distancia, double pontosInteresse){
    super(localOrigem, localDestino, distancia);
    this.pontosInteresse = pontosInteresse;
  }
  public double getPontosInteresse(){
    return pontosInteresse;
  }
} 

public class EtapaMontanha extends Etapa{
  private double decliveAcumulado;
  public EtapaMontanha(Local localOrigem, Local localDestino, double distancia, double decliveAcumulado){
    super(localOrigem, localDestino, distancia);
    this.decliveAcumulado = decliveAcumulado;
  }
}

public class Local{
  private String nome;
  public Local(String nome){
    this.nome = nome;
  }
  public String getNome(){
    return nome;
  }
}
