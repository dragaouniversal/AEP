#include <stdio.h>
#include <string.h>
#include "acompanhamento.h"
#include "estruturas.h"

int registrarAcompanhamento(Aluno alunos[], int quantidadeAlunos, Acompanhamento acompanhamentos[], int quantidadeAcompanhamentos){
    int id;
    int encontrado = 0;

    if (quantidadeAlunos == 0){
        printf("\nNenhum aluno cadastrado.\n");
        return quantidadeAcompanhamentos; // Retorna a quantidade atual de acompanhamentos, pois não há alunos cadastrados para registrar acompanhamento.
    }

    if (quantidadeAcompanhamentos  >= 500){
        printf("\nQuantidade maximo de acompanhamentos atingida.\n");
        return quantidadeAcompanhamentos; // Retorna a quantidade atual de acompanhamentos, pois não é possível registrar mais acompanhamentos.
    }


    printf("Digite o ID do aluno: ");
    scanf("%d", &id);
    while(getchar() != '\n'); // Limpa o buffer do teclado

    for (int i = 0; i < quantidadeAlunos; i++){
        if (alunos[i].id == id){
            if (alunos[i].ativo == 0){ // Verifica se o aluno está inativo antes de registrar o acompanhamento.
                printf("\nAluno inativo. Nao e possivel registrar acompanhamento.\n");
                return quantidadeAcompanhamentos; // Retorna a quantidade atual de acompanhamentos, pois o aluno está inativo.
            }
            encontrado = 1; // Aluno encontrado, abaixo é o processo de registro do acompanhamento.
            break; // Sai do loop após encontrar o aluno
        }
    }
    if (encontrado == 0){
        printf("\nAluno nao encontrado.\n");
        return quantidadeAcompanhamentos; // Retorna a quantidade atual de acompanhamentos, pois o aluno não foi encontrado.
    }

    acompanhamentos[quantidadeAcompanhamentos].idAluno = id;

    printf("\nDigite a data do acompanhamento(DD/MM/AAAA): ");
    fgets(acompanhamentos[quantidadeAcompanhamentos].data, 11, stdin);
    acompanhamentos[quantidadeAcompanhamentos].data[strcspn(acompanhamentos[quantidadeAcompanhamentos].data, "\n")] = '\0';

    getchar();

    printf("\nDescreva a dificuldade identificada: ");
    fgets(acompanhamentos[quantidadeAcompanhamentos].dificuldades, 200, stdin);
    acompanhamentos[quantidadeAcompanhamentos].dificuldades[strcspn(acompanhamentos[quantidadeAcompanhamentos].dificuldades, "\n")] = '\0';

    printf("\nDescreva a estrategia de apoio: ");
    fgets(acompanhamentos[quantidadeAcompanhamentos].estrategia, 200, stdin);
    acompanhamentos[quantidadeAcompanhamentos].estrategia[strcspn(acompanhamentos[quantidadeAcompanhamentos].estrategia, "\n")] = '\0';

    printf("\nAdicione uma observacao: ");
    fgets(acompanhamentos[quantidadeAcompanhamentos].observacao, 300, stdin);
    acompanhamentos[quantidadeAcompanhamentos].observacao[strcspn(acompanhamentos[quantidadeAcompanhamentos].observacao, "\n")] = '\0';

    quantidadeAcompanhamentos++;
    printf("\nAcompanhamento registrado com sucesso!\n");

    return quantidadeAcompanhamentos;
}

void consultarAcompanhamentos(
    Aluno alunos[],
    int quantidadeAlunos,
    Acompanhamento acompanhamentos[],
    int quantidadeAcompanhamentos
){
    int id;
    int alunoEncontrado = 0;
    int acompanhamentoEncontrado = 0;

    if (quantidadeAlunos == 0){
        printf("\nNenhum aluno cadastrado.\n");
        return;
    }
    printf("\nDigite o ID do aluno: ");

    if (scanf("%d", &id) != 1) {
        while (getchar() != '\n');
        printf("\nEntrada invalida!\n");
        return;
    }

    while (getchar() != '\n');

    // Procura o aluno pelo ID
    for (int i = 0; i < quantidadeAlunos; i++) {
        if (alunos[i].id == id) {
            alunoEncontrado = 1;

            printf("\n================================\n");
            printf("ALUNO: %s\n", alunos[i].nome);
            printf("ID: %d\n", alunos[i].id);
            printf("================================\n");

            break;
        }
    }

    if (alunoEncontrado == 0) {
        printf("\nAluno nao encontrado.\n");
        return;
    }

    for (int i = 0; i < quantidadeAcompanhamentos; i++) {
        if (acompanhamentos[i].idAluno == id) { // Verifica se o ID do aluno no acompanhamento corresponde ao ID do aluno pesquisado.
            acompanhamentoEncontrado = 1;

            printf("\nData: %s\n", acompanhamentos[i].data);
            printf("Dificuldade: %s\n", acompanhamentos[i].dificuldades);
            printf("Estrategia: %s\n", acompanhamentos[i].estrategia);
            printf("Observacao: %s\n", acompanhamentos[i].observacao);

            printf("--------------------------------\n");
        }
    }

    if (acompanhamentoEncontrado == 0) {
        printf("\nEste aluno ainda nao possui acompanhamentos.\n");
    }

}

void salvarAcompanhamentos(Acompanhamento acompanhamentos[], int quantidadeAcompanhamentos){
    FILE *arquivo = fopen("acompanhamentos.txt", "w");

    if (arquivo == NULL) {
        printf("\nErro ao abrir o arquivo de acompanhamentos.\n");
        return;
    }

    for (int i = 0; i < quantidadeAcompanhamentos; i++) {

        fprintf(arquivo, "%d|%s|%s|%s|%s\n",
            acompanhamentos[i].idAluno,
            acompanhamentos[i].data,
            acompanhamentos[i].dificuldades,
            acompanhamentos[i].estrategia,
            acompanhamentos[i].observacao
        );
    }

    fclose(arquivo);

    printf("\nAcompanhamentos salvos com sucesso!\n");
}

int carregarAcompanhamentos(Acompanhamento acompanhamentos[], int limite){
    FILE *arquivo = fopen("acompanhamentos.txt", "r");

    if (arquivo == NULL) {
        return 0;
    }

    int quantidadeAcompanhamentos = 0;

    while (quantidadeAcompanhamentos < limite &&
        fscanf(arquivo, "%d|%11[^|]|%199[^|]|%199[^|]|%299[^\n]\n",
            &acompanhamentos[quantidadeAcompanhamentos].idAluno,
            acompanhamentos[quantidadeAcompanhamentos].data,
            acompanhamentos[quantidadeAcompanhamentos].dificuldades,
            acompanhamentos[quantidadeAcompanhamentos].estrategia,
            acompanhamentos[quantidadeAcompanhamentos].observacao
        ) == 5) {

        quantidadeAcompanhamentos++;
    }

    fclose(arquivo);

    return quantidadeAcompanhamentos;
}
