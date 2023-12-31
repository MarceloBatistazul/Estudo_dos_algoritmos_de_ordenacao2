#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void trocar(int *a, int *b);
int partition(int array[], int start, int end);
void quickSort(int array[], int start, int end);

void bubbleSort(int array[], int size);

void selectionSort(int array[], int size);

void insertionSort(int array[], int size);

void merge(int array[], int l, int m, int r);
void mergeSort(int array[], int l, int r);

void heapify(int array[], int size, int i);
void heapSort(int array[], int size);

void printArray(int array[], int size);

void numeros_decrescentes(int a[], int size);
void numeros_crescente(int a[], int size);
void numeros_repetidos(int a[], int size);
void numeros_aleatorios(int a[], int size);


int main() {
    srand(time(NULL));  // Inicializa a semente para números aleatórios

    char encerrar[10];
    int continuar = 1;  // Variável de controle do loop 'do-while'
    int escolhaLista, escolhaAlgoritmo;
    int tamanho = 100;  // Tamanho padrão do array
    int array[100];     // Array a ser ordenado
    int size = 100;     // Variável de controle de tamanho do array

    do {
      // Menu para escolher o tipo de lista ou sair do programa
      printf("\nEscolha o tipo de lista:\n\n");
      printf("1. Números em Ordem Decrescente\n");
      printf("2. Números em Ordem Crescente\n");
      printf("3. Números com Elementos Repetidos\n");
      printf("4. Números em Ordem Aleatória\n");
      printf("\nEscolha o tipo de lista ou digite 'sair' para encerrar:\n\n");
      scanf("%s", encerrar);

          if (strcmp(encerrar, "sair") == 0) {
              continuar = 0;  // Sai do loop se 'sair' for digitado
          } else {
              escolhaLista = atoi(encerrar);  // Converte a entrada para um número inteiro

              if (escolhaLista >= 1 && escolhaLista <= 4) {
                  // Caso seja selecionada uma opção válida, gera o array correspondente
                  switch (escolhaLista) {
                      case 1:
                          printf("Lista em Ordem Decrescente:\n\n");
                          numeros_decrescentes(array, tamanho);
                          break;
                      case 2:
                          printf("Lista em Ordem Crescente:\n\n");
                          numeros_crescente(array, tamanho);
                          break;
                      case 3:
                          printf("Lista com Elementos Repetidos:\n\n");
                          numeros_repetidos(array, tamanho);
                          break;
                      case 4:
                          printf("Lista em Ordem Aleatória:\n\n");
                          numeros_aleatorios(array, tamanho);
                          break;
                      default:
                          printf("Escolha inválida\n");
                  }

                  printf("Lista não ordenada:\n\n");
                  printArray(array, tamanho);

                  // Menu para escolher o algoritmo de ordenação
                  printf("\nEscolha o algoritmo de ordenação:\n");
                  printf("1. Quicksort\n");
                  printf("2. Bubble Sort\n");
                  printf("3. Selection Sort\n");
                  printf("4. Insertion Sort\n");
                  printf("5. Merge Sort\n");
                  printf("6. Heap Sort\n");
                  scanf("%d", &escolhaAlgoritmo);

                  // Ordena o array conforme o algoritmo escolhido
                  switch (escolhaAlgoritmo) {
                      case 1:
                          printf("\nLista ordenada (Quicksort):\n\n");
                          quickSort(array, 0, tamanho - 1);
                          break;
                      case 2:
                          printf("\nLista ordenada (Bubble Sort):\n\n");
                          bubbleSort(array, tamanho);
                          break;
                      case 3:
                          printf("\nLista ordenada (Selection Sort):\n\n");
                          selectionSort(array, tamanho);
                          break;
                      case 4:
                          printf("\nLista ordenada (Insertion Sort):\n\n");
                          insertionSort(array, tamanho);
                          break;
                      case 5:
                          printf("\nLista ordenada (Merge Sort):\n\n");
                          mergeSort(array, 0, tamanho - 1);
                          break;
                      case 6:
                          printf("\nLista ordenada (Heap Sort):\n\n");
                          heapSort(array, tamanho);
                          break;
                      default:
                          printf("\nEscolha inválida\n");
                          continue;
                  }

                  printf("\nLista ordenada:\n\n");
                  printArray(array, tamanho);
              } else {
                  printf("Escolha inválida\n");
              }
          }
      } while (continuar);  // Loop continua enquanto 'continuar' for verdadeiro

      printf("encerrando programa.........>_<.........\n");
      return 0;

      }

// Função que troca os valores de duas variáveis
void trocar(int *a, int *b) {
    int temp = *a;  // Armazena o valor de 'a' em 'temp'
    *a = *b;        // Atribui o valor de 'b' para 'a'
    *b = temp;      // Atribui o valor armazenado em 'temp' para 'b'
}

// Função que implementa a partição no algoritmo Quicksort
int partition(int array[], int start, int end) {
    int pivo = array[end];  // Define o pivô como o último elemento do array
    int i = (start - 1);    // Define o índice 'i' inicial como 'start - 1'

    // Loop para percorrer o array
    for (int j = start; j <= end - 1; j++) {
        if (array[j] <= pivo) {
            i++;  // Incrementa 'i' se o elemento atual for menor ou igual ao pivô
            trocar(&array[i], &array[j]);  // Troca os elementos do array
        }
    }

    // Troca o pivô para a posição correta
    trocar(&array[i + 1], &array[end]);
    return (i + 1);
}

// Função que implementa o algoritmo Quicksort de maneira recursiva
void quickSort(int array[], int start, int end) {
    if (start < end) {
        int pivo = partition(array, start, end);

        // Chamadas recursivas para ordenar as sublistas
        quickSort(array, start, pivo - 1);
        quickSort(array, pivo + 1, end);
    }
}

// Função para ordenar pelo método Bubble Sort
void bubbleSort(int array[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                trocar(&array[j], &array[j + 1]);
            }
        }
    }
}

// Função para ordenar pelo método Selection Sort
void selectionSort(int array[], int size) {
    int minIndex;

    for (int i = 0; i < size - 1; i++) {
        minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (array[j] < array[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            trocar(&array[minIndex], &array[i]);
        }
    }
}

// Função para ordenar pelo método Insertion Sort
void insertionSort(int array[], int size) {
    int chave, j;
    for (int i = 1; i < size; i++) {
        chave = array[i];
        j = i - 1;

        while (j >= 0 && array[j] > chave) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = chave;
    }
}

// Função para o Merge Sort
void merge(int array[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;  // Tamanho do subarray da esquerda
    int n2 = r - m;      // Tamanho do subarray da direita

    // Arrays temporários para armazenar os subarrays
    int L[n1], R[n2];

    // Copiando os dados para os arrays temporários L[] e R[]
    for (i = 0; i < n1; i++)
        L[i] = array[l + i];
    for (j = 0; j < n2; j++)
        R[j] = array[m + 1 + j];

    i = 0;  // Índice inicial do subarray da esquerda
    j = 0;  // Índice inicial do subarray da direita
    k = l;  // Índice inicial do subarray a ser mesclado

    // Mescla os arrays temporários de volta ao array original
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            array[k] = L[i];  // Elemento do subarray da esquerda
            i++;
        } else {
            array[k] = R[j];  // Elemento do subarray da direita
            j++;
        }
        k++;
    }

    // Copia os elementos restantes de L[], se houver algum
    while (i < n1) {
        array[k] = L[i];
        i++;
        k++;
    }

    // Copia os elementos restantes de R[], se houver algum
    while (j < n2) {
        array[k] = R[j];
        j++;
        k++;
    }
}

// Função recursiva para o Merge Sort
void mergeSort(int array[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;  // Encontra o meio do array

        // Chama mergeSort() para dividir e ordenar a primeira e a segunda metade
        mergeSort(array, l, m);      // Ordena a metade esquerda
        mergeSort(array, m + 1, r);  // Ordena a metade direita

        // Combina as metades ordenadas
        merge(array, l, m, r);
    }
}

// Função auxiliar para o Heap Sort
void heapify(int array[], int size, int i) {
    int maior = i;             // Inicializa o maior como a raiz
    int esquerda = 2 * i + 1;  // Calcula o índice do filho esquerdo
    int direita = 2 * i + 2;   // Calcula o índice do filho direito

    // Verifica se o filho esquerdo é maior que o root
    if (esquerda < size && array[esquerda] > array[maior])
        maior = esquerda;

    // Verifica se o filho direito é maior que o maior encontrado até agora
    if (direita < size && array[direita] > array[maior])
        maior = direita;

    // Se o maior não for a raiz
    if (maior != i) {
        trocar(&array[i], &array[maior]);  // Troca o root com o maior
        heapify(array, size, maior);       // Chama recursivamente o heapify no subárvore afetado
    }
}

// Função para o Heap Sort
void heapSort(int array[], int size) {
    // Constrói o heap (reorganiza o array)
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(array, size, i);
    }

    // Extrai elementos um por um do heap
    for (int i = size - 1; i > 0; i--) {
        trocar(&array[0], &array[i]);  // Move a raiz atual para o final
        heapify(array, i, 0);          // Chama o heapify no heap reduzido
    }
}

// Função para imprimir os elementos de um array
void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);  // Imprime cada elemento do array
    }
    printf("\n");  // Nova linha após imprimir o array
}

// Função para gerar um array com números em ordem decrescente
void numeros_decrescentes(int a[], int size) {
    for (int i = 0; i < size; i++) {
        a[i] = size - i;
    }
}

// Função para gerar um array com números em ordem crescente
void numeros_crescente(int a[], int size) {
    for (int i = 0; i < size; i++) {
        a[i] = i + 1;
    }
}

// Função para gerar um array com números repetidos
void numeros_repetidos(int a[], int size) {
    for (int i = 0; i < size; i++) {
        a[i] = (i % 10) + 1;
    }
}

// Função para gerar um array com números em ordem aleatória
void numeros_aleatorios(int a[], int size) {
    for (int i = 0; i < size; i++) {
        a[i] = rand() % 100; // Gere números aleatórios
    }
}