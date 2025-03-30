#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <chrono>

int main(int argc, char* argv[]) {
    std::vector<int> sequence;
    std::ifstream file("array.txt");

    // Verifica erros ao abrir o arquivo
    if (file.fail() || !file.is_open()) {
        std::cerr << "Could not open file" << std::endl;
        return 1;
    }

    // Lê os números do arquivo para o vetor
    int number;
    while (file >> number) {
        sequence.push_back(number);
    }
    file.close();

    // Inicia a medição do tempo
    auto start = std::chrono::high_resolution_clock::now();

    // Classifica o vetor
    std::sort(sequence.begin(), sequence.end());

    // Encontra o gap
    for (size_t i = 0; i < sequence.size() - 1; ++i) {
        if (sequence[i + 1] - sequence[i] > 1) {
            std::cout << "O número faltante é: " << sequence[i] + 1 << std::endl;
            break; // Assume apenas um número faltante
        }
    }

    // Finaliza a medição do tempo
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    std::cout << "Tempo de execução: " << duration.count() << " microssegundos" << std::endl;

    return 0;
}
