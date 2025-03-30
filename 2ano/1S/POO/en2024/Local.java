public class Local{
    private String nomeLocal;
    private double densidade;
  
    public Local(String nomeLocal, double densidade){
      this.nomeLocal = nomeLocal;
      this.densidade = densidade;
    }
  
    public String getNomeLocal(){
      return nomeLocal;
    }
  
    public double getDensidade(){
      return densidade;
    }
  }