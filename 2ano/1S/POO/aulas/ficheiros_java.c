//W matches any non word character
//w matches any word character (a-z, A-Z)
ex: 
while((s = br.readline()) != null){
  words = s.split("//W");
  for (String word : words){
    if (word.equalsIgnoreCase(input){counter++;}
  }
}

utilizar rotas relativas

File f = new File("temp.txt")
File f.rawFile("nome.txt")

tipos de objetos:
	File f = new File
	FileReader fr = new FileReader(f)
	FileWriter fw = new FileWriter(f)
	BufferedReader br = new BufferedReader(fr)
	BufferedWriter bw = new BufferedWriter(fw)
	
if(f.exists() && f.isFile()){
	try {...}
	catch (FileNotFoundException ex) {
		System.out.println("Erro ao ler ficheiro);
	}
} else{
	System.out.println("Ficheiro não existe.");
}
