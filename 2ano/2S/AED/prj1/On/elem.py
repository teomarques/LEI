import random

def generate_array():
    # Garante a unicidade dos elementos e seleciona aleatoriamente
    array = random.sample(range(999999), 999998)
    return array

# Escreve o array num ficheiro para o programa C++ ler
with open('array.txt', 'w') as f:
    for item in generate_array():
        f.write(f"{item}\n")

