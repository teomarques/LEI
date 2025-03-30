public class NovoMedico{
  private String nome;
  private NovaEspecialidade especialidade;
  private int tempoServico;
  private int horasExtra;

  public NovoMedico(String nome, NovaEspecialidade especialidade, int tempoServico, int horasExtra){
    this.nome = nome;
    this.especialidade = especialidade;
    this.tempoServico = tempoServico;
    this.horasExtra = horasExtra;
  }

  public String getNome(){
    return nome;
  }

  public NovaEspecialidade getEspecialidade(){
    return especialidade;
  }

  public int getTempoServico(){
    return tempoServico;
  }

  public int getHorasExtra(){
    return horasExtra;
  }

  public String toString(){
    return "Nome do médico: " + nome + "; Especialidade: " + especialidade + "; Tempo de serviço: " + tempoServico + "; Horas Extra: " + horasExtra;
  }
}
