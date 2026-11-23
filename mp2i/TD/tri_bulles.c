#include <stdbool.h>
#include <stdio.h>

// Tri à bulles avec détection d'arrêt anticipé
void tri_bulles(int t[], int n) {
    bool modif = true;
    int passage = 0;
    while (modif && passage < n - 1) {
        modif = false;
        for (int i = 0; i < n - 1 - passage; i++) {
            if (t[i] > t[i + 1]) {
                int tmp = t[i];
                t[i] = t[i + 1];
                t[i + 1] = tmp;
                modif = true;
            }
        }
        passage++;
    }
}

int main(void) {
    int t[6] = {5, 1, 4, 2, 8, 0};
    tri_bulles(t, 6);
    for (int i = 0; i < 6; i++) {
        printf("%d ", t[i]);
    }
    printf("\n");
    return 0;
}
