import subprocess
import time
import matplotlib.pyplot as plt
import random
import os
import numpy as np
from sklearn.linear_model import LinearRegression

def generate_array(size):
    """Gera um array de números aleatórios únicos."""
    array = random.sample(range(size + 1), size)
    return array

def write_array_to_file(array, filename="array.txt"):
    """Escreve um array em um arquivo, um número por linha."""
    with open(filename, 'w') as f:
        for item in array:
            f.write(f"{item}\n")

def run_cpp_program(executable_path="./Onn"):
    """Executa o programa C++ compilado e retorna o tempo de execução em segundos."""
    try:
        result = subprocess.run([executable_path], capture_output=True, text=True, check=True)
        output = result.stdout
        print(output)  # Exibe a saída do programa C++
        # Extrai o tempo de execução da saída
        for line in output.split('\n'):
            if "Tempo de execução:" in line:
                time_str = line.split(":")[1].strip().split()[0]
                return float(time_str)
    except subprocess.CalledProcessError as e:
        print(f"Erro ao executar o programa C++: {e}")
        return -1

def compile_cpp_program(source_filename="Onn.cpp", output_filename="Onn"):
    """Compila o programa C++."""
    try:
        subprocess.run(["g++", source_filename, "-o", output_filename], check=True, capture_output=True, text=True)
    except subprocess.CalledProcessError as e:
        print(f"Erro de compilação: {e.stderr}")
        return False
    return True

def main():
    array_sizes = [i * 100_000 for i in range(1, 11)]  # Tamanhos dos arrays de 100.000 a 1.000.000
    execution_times = []

    if not compile_cpp_program():
        return

    for size in array_sizes:
        array = generate_array(size)
        write_array_to_file(array)
        execution_time = run_cpp_program()
        if execution_time != -1:
            execution_times.append(execution_time)
        else:
            return

    # Convertendo para numpy arrays para facilitar a manipulação
    X = np.array(array_sizes).reshape(-1, 1)
    y = np.array(execution_times)

    # Criando e ajustando o modelo de regressão linear
    model = LinearRegression()
    model.fit(X, y)
    y_pred = model.predict(X)

    # Plotando o gráfico
    plt.plot(array_sizes, execution_times, marker='o', label='Dados Reais')
    plt.plot(array_sizes, y_pred, color='red', linestyle='--', label='Regressão Linear')
    plt.xlabel("Tamanho do Array")
    plt.ylabel("Tempo de Execução (segundos)")
    plt.title("Tempo de Execução vs. Tamanho do Array")
    plt.legend()
    plt.grid(True)
    plt.show()

if __name__ == "__main__":
    main()

