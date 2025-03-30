import random

def create_random_files():
    # Definir tamanhos dos arquivos (K = 1000)
    file_sizes = [100, 200, 300, 400, 500, 600, 700, 800, 900, 1000]
    
    # Para cada tamanho, criar um arquivo correspondente
    for size in file_sizes:
        # Calcular o número real de elementos (size * 1000)
        num_elements = size * 1000
        
        # Gerar uma lista de números inteiros aleatórios distintos
        # Utilizando random.sample para garantir que não há repetições
        random_numbers = random.sample(range(10000000), num_elements)  # Escolhendo de um intervalo grande
        
        # Nome do arquivo baseado na quantidade de elementos
        filename = f"{size}Karray.txt"
        
        # Escrever os números no arquivo, um por linha
        with open(filename, 'w') as file:
            for number in random_numbers:
                file.write(f"{number}\n")
        
        print(f"Arquivo {filename} criado com {num_elements} números inteiros aleatórios distintos.")

# Executar a função para criar todos os arquivos
if __name__ == "__main__":
    create_random_files()
