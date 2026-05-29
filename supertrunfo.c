#include <stdio.h>

int main() {
    
    // Carta 1
    char estado1[20];
    char cidade1[20];
    char codigo_da_carta1[4];
    int populacao1;
    int pontos_turisticos1;
    float area_em_km1;
    float PIB1;

    // Carta 2
    char estado2[20];
    char cidade2[20];
    char codigo_da_carta2[4];
    int populacao2;
    int pontos_turisticos2;
    float area_em_km2;
    float PIB2;

    float densidade_populacional1, PIB_per_capita1;
    float densidade_populacional2, PIB_per_capita2;

    int opcao1, opcao2;

    float valor1_atributo1, valor2_atributo1;
    float valor1_atributo2, valor2_atributo2;

    float soma_carta1, soma_carta2;

    const char *atributo1;
    const char *atributo2;
    const char *resultado_final;

    // Cadastro Carta 1
    printf("Cadastro Carta 1:\n");

    printf("Insira o estado:\n");
    scanf("%19s", estado1);

    printf("Insira o codigo da carta:\n");
    scanf("%3s", codigo_da_carta1);

    printf("Insira a cidade:\n");
    scanf("%19s", cidade1);

    printf("Insira a populacao:\n");
    scanf("%d", &populacao1);

    printf("Insira a area da cidade:\n");
    scanf("%f", &area_em_km1);

    printf("Insira o PIB:\n");
    scanf("%f", &PIB1);

    printf("Insira o numero de pontos turisticos:\n");
    scanf("%d", &pontos_turisticos1);

    densidade_populacional1 = (float) populacao1 / area_em_km1;
    PIB_per_capita1 = PIB1 / populacao1;

    // Cadastro Carta 2
    printf("\nCadastro Carta 2:\n");

    printf("Insira o estado:\n");
    scanf("%19s", estado2);

    printf("Insira o codigo da carta:\n");
    scanf("%3s", codigo_da_carta2);

    printf("Insira a cidade:\n");
    scanf("%19s", cidade2);

    printf("Insira a populacao:\n");
    scanf("%d", &populacao2);

    printf("Insira a area da cidade:\n");
    scanf("%f", &area_em_km2);

    printf("Insira o PIB:\n");
    scanf("%f", &PIB2);

    printf("Insira o numero de pontos turisticos:\n");
    scanf("%d", &pontos_turisticos2);

    densidade_populacional2 = (float) populacao2 / area_em_km2;
    PIB_per_capita2 = PIB2 / populacao2;

    // Exibir Carta 1
    printf("\nCarta 1:\n");
    printf("Estado: %s\n", estado1);
    printf("Codigo da Carta: %s\n", codigo_da_carta1);
    printf("Cidade: %s\n", cidade1);
    printf("Populacao: %d habitantes\n", populacao1);
    printf("Area: %.2f km2\n", area_em_km1);
    printf("PIB: %.2f trilhoes de Reais\n", PIB1);
    printf("Pontos Turisticos: %d\n", pontos_turisticos1);
    printf("Densidade Populacional: %.2f habitantes/km2\n", densidade_populacional1);
    printf("PIB per capita: %.2f\n", PIB_per_capita1);

    // Exibir Carta 2
    printf("\nCarta 2:\n");
    printf("Estado: %s\n", estado2);
    printf("Codigo da Carta: %s\n", codigo_da_carta2);
    printf("Cidade: %s\n", cidade2);
    printf("Populacao: %d habitantes\n", populacao2);
    printf("Area: %.2f km2\n", area_em_km2);
    printf("PIB: %.2f trilhoes de Reais\n", PIB2);
    printf("Pontos Turisticos: %d\n", pontos_turisticos2);
    printf("Densidade Populacional: %.2f habitantes/km2\n", densidade_populacional2);
    printf("PIB per capita: %.2f\n", PIB_per_capita2);

    // Menu para escolher dois atributos
    printf("\n===== ESCOLHA DOS ATRIBUTOS =====\n");
    printf("Escolha dois atributos diferentes para comparar:\n");
    printf("1 - Populacao\n");
    printf("2 - Area\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turisticos\n");
    printf("5 - Densidade Populacional\n");
    printf("6 - PIB per capita\n");

    printf("\nDigite o primeiro atributo: ");
    scanf("%d", &opcao1);

    printf("Digite o segundo atributo: ");
    scanf("%d", &opcao2);

    if (opcao1 < 1 || opcao1 > 6 || opcao2 < 1 || opcao2 > 6) {
        printf("\nOpcao invalida!\n");
        return 0;
    }

    if (opcao1 == opcao2) {
        printf("\nVoce nao pode escolher o mesmo atributo duas vezes!\n");
        return 0;
    }

    // Primeiro atributo
    switch (opcao1) {
        case 1:
            valor1_atributo1 = populacao1;
            valor2_atributo1 = populacao2;
            atributo1 = "Populacao";
            break;

        case 2:
            valor1_atributo1 = area_em_km1;
            valor2_atributo1 = area_em_km2;
            atributo1 = "Area";
            break;

        case 3:
            valor1_atributo1 = PIB1;
            valor2_atributo1 = PIB2;
            atributo1 = "PIB";
            break;

        case 4:
            valor1_atributo1 = pontos_turisticos1;
            valor2_atributo1 = pontos_turisticos2;
            atributo1 = "Pontos Turisticos";
            break;

        case 5:
            valor1_atributo1 = densidade_populacional1;
            valor2_atributo1 = densidade_populacional2;
            atributo1 = "Densidade Populacional";
            break;

        case 6:
            valor1_atributo1 = PIB_per_capita1;
            valor2_atributo1 = PIB_per_capita2;
            atributo1 = "PIB per capita";
            break;
    }

    // Segundo atributo
    switch (opcao2) {
        case 1:
            valor1_atributo2 = populacao1;
            valor2_atributo2 = populacao2;
            atributo2 = "Populacao";
            break;

        case 2:
            valor1_atributo2 = area_em_km1;
            valor2_atributo2 = area_em_km2;
            atributo2 = "Area";
            break;

        case 3:
            valor1_atributo2 = PIB1;
            valor2_atributo2 = PIB2;
            atributo2 = "PIB";
            break;

        case 4:
            valor1_atributo2 = pontos_turisticos1;
            valor2_atributo2 = pontos_turisticos2;
            atributo2 = "Pontos Turisticos";
            break;

        case 5:
            valor1_atributo2 = densidade_populacional1;
            valor2_atributo2 = densidade_populacional2;
            atributo2 = "Densidade Populacional";
            break;

        case 6:
            valor1_atributo2 = PIB_per_capita1;
            valor2_atributo2 = PIB_per_capita2;
            atributo2 = "PIB per capita";
            break;
    }

    // Soma dos atributos escolhidos
    soma_carta1 = valor1_atributo1 + valor1_atributo2;
    soma_carta2 = valor2_atributo1 + valor2_atributo2;

    // Resultado final usando operador ternario
    resultado_final = soma_carta1 == soma_carta2 ?
                      "Empate!" :
                      soma_carta1 > soma_carta2 ? "Carta 1 venceu!" : "Carta 2 venceu!";

                      // Exibicao do resultado

    printf("\n===== RESULTADO DA COMPARACAO =====\n");

    printf("\nCidades:\n");
    printf("Carta 1: %s\n", cidade1);
    printf("Carta 2: %s\n", cidade2);

    printf("\nAtributos escolhidos:\n");
    printf("Primeiro atributo: %s\n", atributo1);
    printf("Segundo atributo: %s\n", atributo2);

    printf("\nValores do primeiro atributo:\n");
    printf("%s - %s: %.2f\n", cidade1, atributo1, valor1_atributo1);
    printf("%s - %s: %.2f\n", cidade2, atributo1, valor2_atributo1);

    if (valor1_atributo1 == valor2_atributo1) {
        printf("Resultado do primeiro atributo: Empate!\n");
    } else if (opcao1 == 5) {
        printf("Resultado do primeiro atributo: %s venceu!\n",
               valor1_atributo1 < valor2_atributo1 ? cidade1 : cidade2);
    } else {
        printf("Resultado do primeiro atributo: %s venceu!\n",
               valor1_atributo1 > valor2_atributo1 ? cidade1 : cidade2);
    }

    printf("\nValores do segundo atributo:\n");
    printf("%s - %s: %.2f\n", cidade1, atributo2, valor1_atributo2);
    printf("%s - %s: %.2f\n", cidade2, atributo2, valor2_atributo2);

    if (valor1_atributo2 == valor2_atributo2) {
        printf("Resultado do segundo atributo: Empate!\n");
    } else if (opcao2 == 5) {
        printf("Resultado do segundo atributo: %s venceu!\n",
               valor1_atributo2 < valor2_atributo2 ? cidade1 : cidade2);
    } else {
        printf("Resultado do segundo atributo: %s venceu!\n",
               valor1_atributo2 > valor2_atributo2 ? cidade1 : cidade2);
    }

   // printf("\nSoma dos atributos:\n");
   //printf("%s: %.2f\n", cidade1, soma_carta1);
   // printf("%s: %.2f\n", cidade2, soma_carta2);

    printf("\nResultado final: %s\n", resultado_final);

    return 0;

    
}