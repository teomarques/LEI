#include <stdio.h>
#include <stdlib.h>

void bin_img_c(unsigned char *ptr, int w, int h) {
    int i, total_pixels = w * h;
    unsigned long long sum = 0; // Para evitar overflow

    // Calcula a soma de todos os pixels
    for (i = 0; i < total_pixels; i++) {
        sum += ptr[i];
    }

    // Calcula o limiar
    unsigned char threshold = sum / total_pixels;

    // Aplica a binarização
    for (i = 0; i < total_pixels; i++) {
        ptr[i] = (ptr[i] < threshold) ? 0 : 255;
    }
}
