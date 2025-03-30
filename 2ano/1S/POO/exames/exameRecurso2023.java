import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {
        // Criando passageiros
        ArrayList<Reserva> reservas1 = new ArrayList<>();
        ArrayList<Reserva> reservas2 = new ArrayList<>();
        PassageiroRegular passageiro1 = new PassageiroRegular("João", "joao@example.com", reservas1);
        PassageiroFrequente passageiro2 = new PassageiroFrequente("Maria", "maria@example.com", reservas2, "+31938473923");
        
        // Criando lugares (exemplo)
        Lugar lugar1 = new Lugar(1, true);
        Lugar lugar2 = new Lugar(2, false);
        
        // Criando reservas
        reservas1.add(new Reserva(passageiro1, lugar1));
        reservas1.add(new Reserva(passageiro1, lugar2));
        reservas2.add(new Reserva(passageiro2, lugar1));
        
        // Criando a lista de passageiros
        ArrayList<Passageiro> passageiros = new ArrayList<>();
        passageiros.add(passageiro1);
        passageiros.add(passageiro2);
        
        // Criando a empresa
        Empresa empresa = new Empresa(new ArrayList<>(), passageiros);
        int maxReservas = 0;
        int desconto = -1;
        String passageiroMax = "";

        for(Viagem viagem : empresa.getViagens()){
          for(Reserva reserva : viagem.getReservas()) {
            passageiro = reserva.getPassageiro();
            if (passageiro.getNumReservas() > maxReservas) {
                maxReservas = passageiro.getNumReservas();
                passageiroMax = passageiro.getNome();
            }
            try{
              if(passageiro.getTel() && passageiro.getNumReservas() > 8){
                System.out.printf("nome do passageiro frequente com mais de 8 reservas: %s, telemóvel: %s", passageiro.getNome(), passageiro.getTel());
                desconto = passageiro.calculaPrecoReserva(viagem.getPrecoBase(), passageiro.getNumReservas());
                if(desconto == 0){
                  System.out.println("desconto invalido.");
                } else {
                System.out.printf("desconto: %d", desconto);
                }
              }
            } catch(NoSuchMethodException e) {
              if(passageiro.getNumReservas() > 5) {
                System.out.printf("Nome do passageiro regular com mais de 5 reservas: %s, email: %s", passageiro.getNome(), passageiro.getEmail());
              }
              desconto = passageiro.calculaPrecoReserva(viagem.getPrecoBase(), passageiro.getNumReservas());
              if(desconto == 0){
                  System.out.println("desconto invalido.");
              } else {
                System.out.println("desconto: %d", desconto);
              }
              continue;
            }
          }
        }
        System.out.printf("O passageiro com maior número de reservas é %s e tem %d reservas.%n", passageiroMax, maxReservas);
    }
}

public class Viagem {
  private float precoBase;
  private ArrayList<Reserva> reservas;

  public Viagem(float precoBase, ArrayList<Reserva> reservas) {
    this.precoBase = precoBase;
    this.reservas = (reservas != null) ? reservas : new ArrayList<Reserva>();
  }

  public float getPrecoBase(){
    return precoBase;
  }

  public ArrayList<Reserva> getReservas() {
    return reservas;
  }
}

public class Empresa {
    private ArrayList<Viagem> viagens;
    private ArrayList<Passageiro> passageirosTotal;

    public Empresa(ArrayList<Viagem> viagens, ArrayList<Passageiro> passageirosTotal) {
        this.viagens = (viagens != null) ? viagens : new ArrayList<Viagem>();
        this.passageirosTotal = (passageirosTotal != null) ? passageirosTotal : new ArrayList<Passageiro>();
    }

    public ArrayList<Viagem> getViagens() {
        return viagens;
    }

    public ArrayList<Passageiro> getPassageirosTotal() {
        return passageirosTotal;
    }
}

public abstract class Passageiro {
    private String nome;
    private String email;
    private ArrayList<Reserva> reservas;
  
    public Passageiro(String nome, String email, ArrayList<Reserva> reservas) {
        this.nome = nome;
        this.email = email;
        this.reservas = reservas != null ? reservas : new ArrayList<Reserva>();
    }

    public String getNome() {
        return nome;
    }

    public String getEmail() {
        return email;
    }

    public ArrayList<Reserva> getReservas() {
        return reservas;
    }

    public int getNumReservas() {
        return reservas.size();
    }

    public float calculaPrecoReserva(float precoBase, int numReservas);
}

public class PassageiroRegular extends Passageiro{
  public PassageiroRegular(String nome, String email, ArrayList<Reserva> reservas){
    super(nome, email, reservas);
  } 

 public float calculaPrecoReserva(float precoBase, int numReservas){
    return (precoBase * (numReservas / 30.0)) - precoBase <= precoBase/2 ? (precoBase * (1 - numReservas / 30.0)) : 0; 
  }
}

public class PassageiroFrequente extends Passageiro{
  private String tel;
  public PassageiroFrequente(String nome, String email, ArrayList<Reserva> reservas, String tel){
    super(nome, email, reservas);
    this.tel = tel;
  }

  public String getTel(){
    return tel;
  }

  public float calculaPrecoReserva(float precoBase, int numReservas){
    return (precoBase * (Math.pow(1.02, numReservas))) - precoBase <= precoBase/2 ? (precoBase * (1 - Math.pow(1.02, numReservas))) : 0; 
  }
}

public class Reserva {
    private Passageiro passageiro;
    private Lugar lugar;

    public Reserva(Passageiro passageiro, Lugar lugar) {
        this.passageiro = passageiro;
        this.lugar = lugar;
    }

    public Passageiro getPassageiro() {
        return passageiro;
    }

    public Lugar getLugar() {
        return lugar;
    }
}

public class Lugar {
    private int numero;
    private boolean usb;

    public Lugar(int numero, boolean usb) {
        this.numero = numero;
        this.usb = usb;
    }

    public int getNumero() {
        return numero;
    }

    public boolean isUsb() {
        return usb; // Changed to return boolean
    }
}
