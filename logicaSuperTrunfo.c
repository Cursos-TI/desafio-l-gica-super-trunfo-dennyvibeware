#include <stdio.h>
#include <string.h> // para uso da função strcspn


// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das cartas
// Objetivo: No nível novato você deve criar as cartas representando as cidades utilizando scanf para entrada de dados e printf para exibir as informações.

int main() {
    // Área para definição das variáveis para armazenar as propriedades das cidades
    char estado1 = '\0', estado2 = '\0';
    /* a variavel codigo_da_carta precisa ter tamanho 4 
    - 3 digitos do codigo da carta, exemplo A01 
    - mais 1 digito para o enter que seria o \n
        se o tamanho do codigo da carta for 3, apos digitar o codigo A01 e dar um enter 
        vai causar um estouro de buffer na memória (buffer overflow)
    */
    char codigo_da_carta1[4] = {0}, codigo_da_carta2[4] = {0}; 
    char cidade1[30] = {0}, cidade2[30] = {0};
    int qtd_pontos_turisticos1 = 0, qtd_pontos_turisticos2 = 0;
    unsigned int populacao1 = 0, populacao2 = 0;
    float area1 = 0, area2 = 0, pib1 = 0, pib2 = 0;
    float densidade_populacional1 = 0, densidade_populacional2 = 0;
    float pib_per_capita1 = 0, pib_per_capita2 = 0;
    float super_poder1 = 0, super_poder2 = 0;
    float inverso_densidade_populacional1 = 0, inverso_densidade_populacional2 = 0;
    int carta_vencedora = 0;
    int resultado = 0, opcao_menu=0;

    // Entrada de dados da carta 1 
    printf("\n### DADOS DA CARTA 1 ###\n\n");
    printf("Digite o estado (A-H): \n");
    scanf(" %c",&estado1);
    printf("Digite o código da carta (ex: A01, B03): \n");
    scanf("%s", codigo_da_carta1);
    getchar(); // remover o enter da leitura anterior para nao pular fgets
    printf("Digite o nome da cidade: \n");
    fgets(cidade1, sizeof(cidade1), stdin);
    cidade1[strcspn(cidade1, "\n")] = '\0'; // remover o enter da variavel cidade1
    //scanf("%s", cidade1);
    printf("Digite a população da cidade (ex: 12325000): \n");
    scanf("%u",&populacao1);
    printf("Digite a area(km2) da cidade (ex: 1521, 1521.11): \n");
    scanf("%f",&area1);
    printf("Digite o PIB da cidade (ex: 699280000000, 699280000000.50): \n");
    scanf("%f",&pib1);
    printf("Digite a quantidade de pontos turisticos: \n");
    scanf("%d",&qtd_pontos_turisticos1);
    densidade_populacional1 = populacao1 / area1;
    pib_per_capita1 = pib1 / populacao1;
    inverso_densidade_populacional1 = area1 / populacao1;
    super_poder1 = populacao1 + area1 + pib1 + qtd_pontos_turisticos1 + pib_per_capita1 + inverso_densidade_populacional1;
    
    // Entrada de dados da carta 2
    printf("\n### DADOS DA CARTA 2 ###\n\n");
    printf("Digite o estado (A-H): \n");
    scanf(" %c",&estado2); // colocar espaço antes do especificador de dados para nao ler o enter anterior
    printf("Digite o código da carta (ex: A01, B03): \n");
    scanf("%s", codigo_da_carta2);
    getchar(); // remover o enter da leitura anterior para nao pular fgets
    printf("Digite o nome da cidade: \n");
    fgets(cidade2, sizeof(cidade2), stdin);
    cidade2[strcspn(cidade2, "\n")] = '\0'; // remover o enter da variavel cidade2
    //scanf("%s", cidade2);
    printf("Digite a população da cidade (ex: 6748000): \n");
    scanf("%u",&populacao2);
    printf("Digite a area(km2) da cidade (ex: 1200, 1200.25): \n");
    scanf("%f",&area2);
    printf("Digite o PIB da cidade (ex: 300500000000, 300500000000.50): \n");
    scanf("%f",&pib2);
    printf("Digite a quantidade de pontos turisticos: \n");
    scanf("%d",&qtd_pontos_turisticos2);
    densidade_populacional2 = populacao2 / area2;
    pib_per_capita2 = pib2 / populacao2;
    inverso_densidade_populacional2 = 1 / densidade_populacional2;
    super_poder2 = populacao2 + area2 + pib2 + qtd_pontos_turisticos2 + pib_per_capita2 + inverso_densidade_populacional2;

    printf("\n==========================================================\n");
    printf("\n### RELATÓRIO ### \n");

    // exibição dos dados da cartas 1
    printf("\nCarta 1: \n");
    printf("Estado: %c \n", estado1);
    printf("Código: %s \n", codigo_da_carta1);
    printf("Nome da cidade: %s \n", cidade1); 
    printf("População: %u \n", populacao1);
    printf("Área: %.2f Km2 \n", area1);
    printf("PIB: %.2f Reais\n", pib1);
    printf("Numero de pontos turisticos: %d \n", qtd_pontos_turisticos1);
    printf("Densidade populacional: %.2f hab/km2 \n", densidade_populacional1);
    printf("PIB per capita: %.2f reais\n", pib_per_capita1);
    printf("Inverso densidade populacional: %.6f km2/hab \n", inverso_densidade_populacional1);
    printf("Super poder: %.6f \n", super_poder1);

    // exibição dos dados da cartas 2
    printf("\nCarta 2: \n");
    printf("Estado: %c \n", estado2);
    printf("Código: %s \n", codigo_da_carta2);
    printf("Nome da cidade: %s \n", cidade2); 
    printf("População: %u \n", populacao2);
    printf("Área: %.2f Km2 \n", area2);
    printf("PIB: %.2f Reais\n", pib2);
    printf("Numero de pontos turisticos: %d \n", qtd_pontos_turisticos2);
    printf("Densidade populacional: %.2f hab/km2 \n", densidade_populacional2);
    printf("PIB per capita: %.2f reais\n", pib_per_capita2);
    printf("Inverso densidade populacional: %.6f km2/hab \n", inverso_densidade_populacional2);
    printf("Super poder: %.6f \n", super_poder2);

    //comparação das cartas
    printf("==========================================================\n");
    printf("\n### COMPARAÇÃO DAS CARTAS ### \n\n");
    printf("População               : Carta %d venceu (%d) \n", 2-resultado, resultado = (populacao1 > populacao2)  );
    printf("Area                    : Carta %d venceu (%d) \n", 2-resultado, resultado = (area1 > area2)    );
    printf("PIB                     : Carta %d venceu (%d) \n", 2-resultado, resultado = (pib1 > pib2)  );
    printf("Pontos turisticos       : Carta %d venceu (%d) \n", 2-resultado, resultado = (qtd_pontos_turisticos1 > qtd_pontos_turisticos2)  );
    printf("Densidade populacional  : Carta %d venceu (%d) \n", 2-resultado, resultado = (densidade_populacional1 < densidade_populacional2)    );
    printf("PIB per capita          : Carta %d venceu (%d) \n", 2-resultado, resultado = (pib_per_capita1 > pib_per_capita2)    );
    printf("Super poder             : Carta %d venceu (%d) \n\n", 2-resultado, resultado = (super_poder1 > super_poder2)    );

    // comparacao das cartas, atributo escolhido pelo programador
    printf("\n==========================================================\n");
    printf("\n### COMPARAÇÃO DAS CARTAS - (ATRIBUTO ESCOLHIDO: POPULAÇÃO) ### \n\n");
    printf("Carta 1 - %s: %u  \n", cidade1, populacao1);
    printf("Carta 2 - %s: %u  \n", cidade2, populacao2);
    if(populacao1 > populacao2){
        printf("Resultado: Carta 1 %s venceu! \n",cidade1);
    }
    else{
        printf("Resultado: Carta 2 %s venceu! \n",cidade2);
    }

    //comparação das cartas, atributo escolhido pelo usuario
    printf("\n==========================================================\n");
    printf("\n### COMPARAÇÃO DAS CARTAS - (USUARIO ESCOLHA O ATRIBUTO) ### \n\n");
    printf("1 - Nome \n");
    printf("2 - População \n");
    printf("3 - Area \n");
    printf("4 - PIB \n");
    printf("5 - Nº de pontos turisticos \n");
    printf("6 - Densidade populacional \n");
    scanf("%d", &opcao_menu);
    printf("\n");
    
    switch (opcao_menu)
    {
    case 1:
        printf("Cidade Carta 1: %s \n", cidade1);
        printf("Cidade Carta 2: %s \n", cidade2);
        printf("Atributo escolhido: Nome \n");
        break;
    case 2:
        printf("Cidade Carta 1      : %s\n",cidade1);
        printf("Cidade Carta 2      : %s\n",cidade2);
        printf("Atributo escolhido  : População \n");
        printf("População carta 1   : %u \n", populacao1);
        printf("População carta 1   : %u \n", populacao2);
        if (populacao1 > populacao2){
            printf("A Carta 1 venceu a comparação! \n");
        }
        else if (populacao2 > populacao1){
            printf("A Carta 2 venceu a comparação! \n");

        }else{
            printf("Empate! \n");
        }
        break;
    case 3:
        printf("Cidade Carta 1      : %s\n",cidade1);
        printf("Cidade Carta 2      : %s\n",cidade2);
        printf("Atributo escolhido  : Area \n");
        printf("Area da carta 1     : %.2f \n", area1);
        printf("Area da carta 2     : %.2f \n", area2);
        if (area1 > area2){
            printf("A Carta 1 venceu a comparação! \n");
        }
        else if (area2 > area1){
            printf("A Carta 2 venceu a comparação! \n");

        }else{
            printf("Empate! \n");
        }
        break;
    case 4:
        printf("Cidade Carta 1      : %s\n",cidade1);
        printf("Cidade Carta 2      : %s\n",cidade2);
        printf("Atributo escolhido  : PIB \n");
        printf("PIB da carta 1      : %.2f \n", pib1);
        printf("PIB da carta 2      : %.2f \n", pib2);
        if (pib1 > pib2){
            printf("A Carta 1 venceu a comparação! \n");
        }
        else if (pib2 > pib1){
            printf("A Carta 2 venceu a comparação! \n");

        }else{
            printf("Empate! \n");
        }
        break;    
    case 5:
        printf("Cidade Carta 1      : %s\n",cidade1);
        printf("Cidade Carta 2      : %s\n",cidade2);
        printf("Atributo escolhido  : Nº de pontos turisticos \n");
        printf("Pontos turisticos da carta 1      : %d \n", qtd_pontos_turisticos1);
        printf("Pontos turisticos da carta 2      : %d \n", qtd_pontos_turisticos2);
        if (qtd_pontos_turisticos1 > qtd_pontos_turisticos2){
            printf("A Carta 1 venceu a comparação! \n");
        }
        else if (qtd_pontos_turisticos2 > qtd_pontos_turisticos1){
            printf("A Carta 2 venceu a comparação! \n");

        }else{
            printf("Empate! \n");
        }
        break;    
    case 6:
        printf("Cidade Carta 1      : %s\n",cidade1);
        printf("Cidade Carta 2      : %s\n",cidade2);
        printf("Atributo escolhido  : Densidade populacional \n");
        printf("Densidade populacional da carta 1 : %.2f \n", densidade_populacional1);
        printf("Densidade populacional da carta 2 : %.2f \n", densidade_populacional2);
        if (densidade_populacional1 < densidade_populacional2){
            printf("A Carta 1 venceu a comparação! \n");
        }
        else if (densidade_populacional2 < densidade_populacional1){
            printf("A Carta 2 venceu a comparação! \n");

        }else{
            printf("Empate! \n");
        }
        break;
    default:
        printf("Opção inválida! \n");
        break;
    }


    return 0;
} 
