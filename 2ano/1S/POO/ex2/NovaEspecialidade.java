public class NovaEspecialidade{
  private String nomeEspecialidade;
  private int salarioBase;
  private int horaExtra;

  public NovaEspecialidade(String nomeEspecialidade, int salarioBase, int horaExtra){
    this.nomeEspecialidade = nomeEspecialidade;
    this.salarioBase = salarioBase;
    this.horaExtra = horaExtra;
  }

  public String getNomeEspecialidade(){
    return nomeEspecialidade;
  }

  public int getSalarioBase(){
    return salarioBase;
  }

  public int getHoraExtra(){
    return horaExtra;
  }
  
  public String toString(){
    return "nome da especialidade: " + nomeEspecialidade + "; salário base: " + salarioBase + "; horas extra: " + horaExtra;
  }
}
