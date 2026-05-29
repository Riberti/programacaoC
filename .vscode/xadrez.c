#include <stdio.h>

// Função recursiva para mover a Torre
void moverTorre(int casas) {
    if (casas <= 0) {
        return;
    }

    printf("Direita\n");

    moverTorre(casas - 1);
}

// Função recursiva para mover a Rainha
void moverRainha(int casas) {
    if (casas <= 0) {
        return;
    }

    printf("Esquerda\n");

    moverRainha(casas - 1);
}

// Função recursiva para mover o Bispo
// Usa também loops aninhados:
// loop externo = movimento vertical
// loop interno = movimento horizontal
void moverBispo(int casas) {
    int vertical;
    int horizontal;

    if (casas <= 0) {
        return;
    }

    for (vertical = 1; vertical <= 1; vertical++) {
        printf("Cima\n");

        for (horizontal = 1; horizontal <= 1; horizontal++) {
            printf("Direita\n");
        }
    }

    moverBispo(casas - 1);
}

// Função para mover o Cavalo usando loops complexos
void moverCavalo(int casasCima, int casasDireita) {
    int etapa;
    int tentativa;
    int cima = 0;
    int direita = 0;
    int totalMovimentos = casasCima + casasDireita;

    for (etapa = 1; etapa <= totalMovimentos; etapa++) {

        for (tentativa = 1; tentativa <= totalMovimentos; tentativa++) {

            if (cima < casasCima) {
                printf("Cima\n");
                cima++;
                continue;
            }

            if (direita < casasDireita) {
                printf("Direita\n");
                direita++;
                break;
            }
        }

        if (cima == casasCima && direita == casasDireita) {
            break;
        }
    }
}

int main() {
    int opcao;

    int casasTorre = 5;
    int casasBispo = 5;
    int casasRainha = 8;

    int casasCavaloCima = 2;
    int casasCavaloDireita = 1;

    printf("=== Movimento das Pecas de Xadrez ===\n");
    printf("Escolha uma peca para mover:\n");
    printf("1 - Torre\n");
    printf("2 - Bispo\n");
    printf("3 - Rainha\n");
    printf("4 - Cavalo\n");
    printf("Digite sua opcao: ");

    if (scanf("%d", &opcao) != 1) {
        printf("\nEntrada invalida! Digite apenas numeros.\n");
        return 1;
    }

    switch (opcao) {
        case 1:
            printf("\nMovimento da Torre:\n\n");
            moverTorre(casasTorre);
            break;

        case 2:
            printf("\nMovimento do Bispo:\n\n");
            moverBispo(casasBispo);
            break;

        case 3:
            printf("\nMovimento da Rainha:\n\n");
            moverRainha(casasRainha);
            break;

        case 4:
            printf("\nMovimento do Cavalo:\n\n");
            moverCavalo(casasCavaloCima, casasCavaloDireita);
            break;

        default:
            printf("\nOpcao invalida!\n");
            break;
    }

    return 0;
}