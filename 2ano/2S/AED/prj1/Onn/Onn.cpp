#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
#include <algorithm>

int find_missing(const std::vector<int>& arr) {
    // Início da medição do tempo
    auto start_time = std::chrono::high_resolution_clock::now();

    // Variáveis
    int length = arr.size();
    int minEl = *std::min_element(arr.begin(), arr.end());
    int maxEl = *std::max_element(arr.begin(), arr.end());
    bool flag = false;
    int missing = -1;

    // Dois loops aninhados, resultando em complexidade O(n²)
    for (int i = 0; i < length - 1; ++i) {
        flag = false;
        for (int j = 0; j < length - 1; ++j) {
            if (arr[j] == arr[i] + 1 && arr[i] < maxEl) {
                flag = true;
                break;
            }
        }
        if (!flag && arr[i] < maxEl) {
            missing = arr[i] + 1;
            break;
        }
    }

    // Fim da medição do tempo
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end_time - start_time;

    std::cout << "Elemento faltante: " << missing << std::endl;
    std::cout << "Tempo de execução: " << duration.count() << " segundos" << std::endl;

    return missing;
}

int main() {
    // Leitura do array a partir do arquivo
    std::vector<int> arr;
    std::ifstream file("array.txt");
    if (!file.is_open()) {
        std::cerr << "Erro ao abrir o arquivo array.txt" << std::endl;
        return 1;
    }

    int num;
    while (file >> num) {
        arr.push_back(num);
    }
    file.close();

    find_missing(arr);
    return 0;
}

