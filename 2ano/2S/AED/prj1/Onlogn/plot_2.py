import subprocess
import matplotlib.pyplot as plt
import random
import numpy as np
from sklearn.linear_model import LinearRegression

def generate_array(size):
    """Gera um array de números consecutivos de 0 a size, remove um aleatoriamente."""
    full_array = list(range(0, size + 1))  # Gera de 0 a size (size+1 elementos)
    missing = random.choice(full_array)    # Escolhe um número para remover
    array = [x for x in full_array if x != missing]  # Remove o número
    return array, missing

def write_array_to_file(array, filename="array.txt"):
    """Escreve um array em um arquivo, um número por linha."""
    with open(filename, 'w') as f:
        for item in array:
            f.write(f"{item}\n")

def compile_cpp_program(source_filename="Onlogn.cpp", output_filename="Onlogn"):
    """Compila o programa C++."""
    try:
        subprocess.run(["g++", source_filename, "-o", output_filename], check=True, capture_output=True, text=True)
    except subprocess.CalledProcessError as e:
        print(f"Erro de compilação: {e.stderr}")
        return False
    return True

def run_cpp_program(executable_path="./Onlogn"):
    """Executa o programa C++ e retorna o tempo de execução e o número faltante."""
    try:
        result = subprocess.run([executable_path], capture_output=True, text=True, check=True)
        missing_number = None
        execution_time = None
        for line in result.stdout.split('\n'):
            if "O número faltante é:" in line:
                missing_number = int(line.split(":")[1].strip())
            elif "Tempo de execução:" in line:
                time_str = line.split(":")[1].strip().split()[0]
                execution_time = int(time_str)
        return execution_time, missing_number
    except subprocess.CalledProcessError as e:
        print(f"Erro ao executar o programa C++: {e}")
        return None, None

def main():
    array_sizes = [i * 100_000 for i in range(1, 11)]  # Tamanhos de 100.000 a 1.000.000
    execution_times = []

    if not compile_cpp_program():
        return

    for size in array_sizes:
        array, real_missing = generate_array(size)
        write_array_to_file(array)
        execution_time, found_missing = run_cpp_program()
        if execution_time is not None and found_missing is not None:
            print(f"Tamanho: {size}, Faltante real: {real_missing}, Faltante encontrado: {found_missing}, Tempo: {execution_time} microssegundos")
            if real_missing != found_missing:
                print(f"Erro: para tamanho {size}, faltante real {real_missing} != encontrado {found_missing}")
            execution_times.append(execution_time)
        else:
            print(f"Erro na execução para tamanho {size}")
            return

    # Convertendo para arrays NumPy para a regressão
    X = np.array(array_sizes).reshape(-1, 1)
    y = np.array(execution_times)

    # Criando e ajustando o modelo de regressão linear
    model = LinearRegression()
    model.fit(X, y)

    # Coeficientes da regressão
    slope = model.coef_[0]
    intercept = model.intercept_
    r_squared = model.score(X, y)

    print(f"\nCoeficiente angular (slope): {slope}")
    print(f"Intercepto: {intercept}")
    print(f"R²: {r_squared}")

    # Plotando o gráfico
    plt.scatter(array_sizes, execution_times, color='blue', label='Dados observados')
    plt.plot(array_sizes, model.predict(X), color='red', label='Regressão linear')
    plt.xlabel("Tamanho do Array")
    plt.ylabel("Tempo de Execução (microssegundos)")
    plt.title("Tempo de Execução vs. Tamanho do Array (O(n log n))")
    plt.legend()
    plt.grid(True)
    plt.show()

if __name__ == "__main__":
    main()
