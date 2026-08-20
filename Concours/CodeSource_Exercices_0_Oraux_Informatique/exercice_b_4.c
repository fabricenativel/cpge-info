#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

int nb_occurrences(int n, int* tab, int x) {
  // À compléter
  return -42;
}

int une_occurrence(int n, int* tab, int x) {
  int d = 0;
  int f = n - 1;
  int res = -1;
  /* À compléter :
  while (d <= f) {
    int m = (d + f) / 2;
    if ([???]) {
      res = m;
      break;
    } else if (tab[m] < x) {
      [???]
    }
    else {
      [???]
    }
  }
  */
  return res;
}

int premiere_occurrence(int n, int* tab, int x) {
  // À compléter
  return -42;
}

int nombre_occurrences(int n, int* tab, int x) {
  // À compléter
  return -42;
}

int main(void) {

  int tab[17] = {0, 1, 1, 2, 2, 2, 4, 4, 5, 6, 6, 6, 8, 8, 8, 8, 9};
  int occ[10] = {1, 2, 3, 0, 2, 1, 3, 0, 4, 1};
  int fst[10] = {0, 1, 3, -1, 6, 8, 9, -1, 12, 16};

  // Test de `nb_occurrences` [ne pas modifier]
  bool test = true;
  test = test && nb_occurrences(0, tab, 0) == 0;
  test = test && nb_occurrences(1, tab, 0) == 1;
  test = test && nb_occurrences(1, tab, 1) == 0;
  test = test && nb_occurrences(2, tab, 0) == 1;
  for (int i = 0; i < 10; i += 1) {
    test = test && nb_occurrences(17, tab, i) == occ[i];
  }
  printf("Test nb_occurrences : %s\n", test ? "validé" : "échec");

  // Test de `une_occurrence` [ne pas modifier]
  test = true;
  test = test && une_occurrence(0, tab, 0) == -1;
  test = test && une_occurrence(1, tab, 0) == 0;
  test = test && une_occurrence(1, tab, 1) == -1;
  test = test && une_occurrence(2, tab, 0) == 0;
  for (int i = 0; i < 10; i += 1) {
    int k = une_occurrence(17, tab, i);
    if (occ[i] > 0) {
      test = test && 0 <= k && k < 17 && tab[k] == i;
    } else {
      test = test && k == -1;
    }
  }
  printf("Test une_occurrence : %s\n", test ? "validé" : "échec");

  // Test de `premiere_occurrence` [ne pas modifier]
  test = true;
  test = test && premiere_occurrence(0, tab, 0) == -1;
  test = test && premiere_occurrence(1, tab, 0) == 0;
  test = test && premiere_occurrence(1, tab, 1) == -1;
  test = test && premiere_occurrence(2, tab, 0) == 0;
  for (int i = 0; i < 10; i += 1) {
    test = test && premiere_occurrence(17, tab, i) == fst[i];
  }
  printf("Test première occurrence : %s\n", test ? "validé" : "échec");

  // Test de `nombre_occurrences` [ne pas modifier]
  test = true;
  test = test && nombre_occurrences(0, tab, 0) == 0;
  test = test && nombre_occurrences(1, tab, 0) == 1;
  test = test && nombre_occurrences(1, tab, 1) == 0;
  test = test && nombre_occurrences(2, tab, 0) == 1;
  for (int i = 0; i < 10; i += 1) {
    test = test && nombre_occurrences(17, tab, i) == occ[i];
  }
  printf("Test nombre_occurrences : %s\n", test ? "validé" : "échec");

}
