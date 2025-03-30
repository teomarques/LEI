#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>

int main() {
    std::vector<int> numbers;
    std::ifstream file("array.txt");
    int num;

    // Verificar se o arquivo foi aberto corretamente
    if (!file.is_open()) {
        std::cerr << "Erro ao abrir o arquivo." << std::endl;
        return 1;
    }

    // Ler números do arquivo
    while (file >> num) {
        numbers.push_back(num);
    }
    file.close();

    // Medir o tempo de execução
    auto start = std::chrono::high_resolution_clock::now();

    // Calcular a soma dos elementos no array
    long long sum = 0;
    for (int n : numbers) {
        sum += n;
    }

    // Tamanho do array
    size_t S = numbers.size();
    // Soma esperada de 0 a S (pois o array tem S elementos, mas deveria ter de 0 a S)
    long long expected_sum = (static_cast<long long>(S) * (S + 1)) / 2;

    // Encontrar o número faltante
    long long missing_number = expected_sum - sum;

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    std::cout << "O número faltante é: " << missing_number << std::endl;
    std::cout << "Tempo de execução: " << duration.count() << " microssegundos" << std::endl;

    return 0;
}
