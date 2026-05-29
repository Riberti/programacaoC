#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_HABILIDADE 5

#define AGUA 0
#define NAVIO 3
#define HABILIDADE 5

void criarCone(int cone[TAM_HABILIDADE][TAM_HABILIDADE]) {
    int meio = TAM_HABILIDADE / 2;

    for (int linha = 0; linha < TAM_HABILIDADE; linha++) {
        for (int coluna = 0; coluna < TAM_HABILIDADE; coluna++) {

            if (linha <= meio &&
                coluna >= meio - linha &&
                coluna <= meio + linha) {
                cone[linha][coluna] = 1;
            } else {
                cone[linha][coluna] = 0;
            }
        }
    }
}

void criarCruz(int cruz[TAM_HABILIDADE][TAM_HABILIDADE]) {
    int meio = TAM_HABILIDADE / 2;

    for (int linha = 0; linha < TAM_HABILIDADE; linha++) {
        for (int coluna = 0; coluna < TAM_HABILIDADE; coluna++) {

            if (linha == meio || coluna == meio) {
                cruz[linha][coluna] = 1;
            } else {
                cruz[linha][coluna] = 0;
            }
        }
    }
}

void criarOctaedro(int octaedro[TAM_HABILIDADE][TAM_HABILIDADE]) {
    int meio = TAM_HABILIDADE / 2;
    int raio = 1;

    for (int linha = 0; linha < TAM_HABILIDADE; linha++) {
        for (int coluna = 0; coluna < TAM_HABILIDADE; coluna++) {

            int distanciaLinha = linha - meio;
            int distanciaColuna = coluna - meio;

            if (distanciaLinha < 0) {
                distanciaLinha = distanciaLinha * -1;
            }

            if (distanciaColuna < 0) {
                distanciaColuna = distanciaColuna * -1;
            }

            int distancia = distanciaLinha + distanciaColuna;

            if (distancia <= raio) {
                octaedro[linha][coluna] = 1;
            } else {
                octaedro[linha][coluna] = 0;
            }
        }
    }
}

void aplicarHabilidade(
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO],
    int habilidade[TAM_HABILIDADE][TAM_HABILIDADE],
    int origemLinhaTabuleiro,
    int origemColunaTabuleiro,
    int origemLinhaHabilidade,
    int origemColunaHabilidade
) {
    for (int linha = 0; linha < TAM_HABILIDADE; linha++) {
        for (int coluna = 0; coluna < TAM_HABILIDADE; coluna++) {

            if (habilidade[linha][coluna] == 1) {

                int linhaTabuleiro = origemLinhaTabuleiro + (linha - origemLinhaHabilidade);
                int colunaTabuleiro = origemColunaTabuleiro + (coluna - origemColunaHabilidade);

                if (
                    linhaTabuleiro >= 0 &&
                    linhaTabuleiro < TAM_TABULEIRO &&
                    colunaTabuleiro >= 0 &&
                    colunaTabuleiro < TAM_TABULEIRO
                ) {
                    if (tabuleiro[linhaTabuleiro][colunaTabuleiro] == AGUA) {
                        tabuleiro[linhaTabuleiro][colunaTabuleiro] = HABILIDADE;
                    }
                }
            }
        }
    }
}

int main() {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];

    int tamanhoNavio = 3;

    int navioHorizontal[3] = {NAVIO, NAVIO, NAVIO};
    int navioVertical[3] = {NAVIO, NAVIO, NAVIO};

    int linha, coluna;

    for (linha = 0; linha < TAM_TABULEIRO; linha++) {
        for (coluna = 0; coluna < TAM_TABULEIRO; coluna++) {
            tabuleiro[linha][coluna] = AGUA;
        }
    }

    int linhaHorizontal = 2;
    int colunaHorizontal = 2;

    int linhaVertical = 4;
    int colunaVertical = 7;

    for (int i = 0; i < tamanhoNavio; i++) {
        tabuleiro[linhaHorizontal][colunaHorizontal + i] = navioHorizontal[i];
    }

    for (int i = 0; i < tamanhoNavio; i++) {
        tabuleiro[linhaVertical + i][colunaVertical] = navioVertical[i];
    }

    int cone[TAM_HABILIDADE][TAM_HABILIDADE];
    int cruz[TAM_HABILIDADE][TAM_HABILIDADE];
    int octaedro[TAM_HABILIDADE][TAM_HABILIDADE];

    criarCone(cone);
    criarCruz(cruz);
    criarOctaedro(octaedro);

    /*
        Aplicando as habilidades no tabuleiro.

        Para o cone, a origem da habilidade está no topo central da matriz.
        Para cruz e octaedro, a origem está no centro da matriz.
    */

    aplicarHabilidade(tabuleiro, cone, 0, 5, 0, 2);
    aplicarHabilidade(tabuleiro, cruz, 5, 2, 2, 2);
    aplicarHabilidade(tabuleiro, octaedro, 7, 7, 2, 2);

    printf("Tabuleiro Batalha Naval com Habilidades:\n\n");

    printf("   ");
    for (coluna = 0; coluna < TAM_TABULEIRO; coluna++) {
        printf("%c ", 'A' + coluna);
    }
    printf("\n");

    for (linha = 0; linha < TAM_TABULEIRO; linha++) {
        printf("%2d ", linha + 1);

        for (coluna = 0; coluna < TAM_TABULEIRO; coluna++) {
            printf("%d ", tabuleiro[linha][coluna]);
        }

        printf("\n");
    }

    printf("\nLegenda:\n");
    printf("0 = Agua\n");
    printf("3 = Navio\n");
    printf("5 = Area afetada pela habilidade\n");
    printf("\n");

    return 0;
}