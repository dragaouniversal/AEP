
#include <stdio.h>
#include <string.h>
#include "desempenho.h"

int registrarDesempenho(
    Aluno alunos[],
    int quantidadeAluno,
    Desempenho desempenhos[],
    int quantidadeDesempenhos
) {
    int id;
    int encontrado = 0;

    if (quantidadeAluno == 0) {
        printf("\nNenhum aluno cadastrado.\n");
        printf("\nPrecione ENTER para voltar.");
        return quantidadeDesempenhos;
    }

    else if (quantidadeDesempenhos >= 500) {
        printf("\nLimite de registros atingido.\n");
        printf("\nPrecione ENTER para voltar.");
        return quantidadeDesempenhos;
    }

    printf("\nDigite o ID do aluno: ");

    if (scanf("%d", &id) != 1) {
        while (getchar() != '\n');
        printf("\nEntrada invalida!\n");
        printf("\nPrecione ENTER para voltar.");
        return quantidadeDesempenhos;
    }

    while (getchar() != '\n');

    // Verifica se o aluno existe e esta ativo
    for (int i = 0; i < quantidadeAluno; i++) {
        if (alunos[i].id == id) { // Verifica se o ID do aluno corresponde ao ID pesquisado

            if (alunos[i].ativo == 0) { // Verifica se o ID está ativo
                printf("\nEste aluno esta inativo.\n");
                printf("\nPrecione ENTER para voltar.");
                return quantidadeDesempenhos;
            }

            encontrado = 1;
            break;
        }
    }

    if (encontrado == 0) {
        printf("\nAluno nao encontrado.\n");
        printf("\nPrecione ENTER para voltar.");
        return quantidadeDesempenhos;
    }

    // Armazena o ID do aluno
    desempenhos[quantidadeDesempenhos].idAluno = id;

    printf("\nDigite a disciplina: ");
    fgets(desempenhos[quantidadeDesempenhos].disciplina, 50, stdin);
    desempenhos[quantidadeDesempenhos].disciplina[strcspn(desempenhos[quantidadeDesempenhos].disciplina, "\n")] = '\0';

    printf("Digite o periodo (ex: 1o Bimestre 2026): ");
    fgets(desempenhos[quantidadeDesempenhos].periodo, 30, stdin);
    desempenhos[quantidadeDesempenhos].periodo[strcspn(desempenhos[quantidadeDesempenhos].periodo, "\n")] = '\0';

    printf("Digite a nota (0 a 10): ");

    if (scanf("%f", &desempenhos[quantidadeDesempenhos].nota) != 1) {
        while (getchar() != '\n');
        printf("\nNota invalida!\n");
        printf("\nPrecione ENTER para voltar.");
        return quantidadeDesempenhos;
    }

    if (desempenhos[quantidadeDesempenhos].nota < 0 ||
        desempenhos[quantidadeDesempenhos].nota > 10) {
        while (getchar() != '\n');
        printf("\nA nota deve estar entre 0 e 10.\n");
        return quantidadeDesempenhos;
    }

    printf("Digite a frequencia (0 a 100): ");

    if (scanf("%f", &desempenhos[quantidadeDesempenhos].frequencia) != 1) {
        while (getchar() != '\n');
        printf("\nFrequencia invalida!\n");
        printf("\nPrecione ENTER para voltar.");
        return quantidadeDesempenhos;
    }

    if (desempenhos[quantidadeDesempenhos].frequencia < 0 ||
        desempenhos[quantidadeDesempenhos].frequencia > 100) {
        while (getchar() != '\n');
        printf("\nA frequencia deve estar entre 0 e 100.\n");
        printf("\nPrecione ENTER para voltar.");
        return quantidadeDesempenhos;
    }

    while (getchar() != '\n');

    quantidadeDesempenhos++;

    printf("\nDesempenho registrado com sucesso!\n");
    printf("\nPrecione ENTER para voltar.");

    return quantidadeDesempenhos;
}

void consultarDesempenho(Aluno alunos[], int quantidadeAlunos, Desempenho desempenhos[], int quantidadeDesempenhos)
{int id;
    int alunoEncontrado = 0;
    int desempenhoEncontrado = 0;

    if (quantidadeAlunos == 0){
        printf("\nNenhum aluno cadastrado.\n");
        printf("\nPrecione ENTER para voltar.");
        return;
    }
    printf("\nDigite o ID do aluno: ");

    if (scanf("%d", &id) != 1) {
        while (getchar() != '\n');
        printf("\nEntrada invalida!\n");
        printf("\nPrecione ENTER para voltar.");
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
        printf("\nPrecione ENTER para voltar.");
        return;
    }

    for (int i = 0; i < quantidadeDesempenhos; i++) {
        if (desempenhos[i].idAluno == id) { // Verifica se o ID do aluno no acompanhamento corresponde ao ID do aluno pesquisado.
            desempenhoEncontrado = 1;

            printf("\nDisciplina: %s\n", desempenhos[i].disciplina);
            printf("Periodo: %s\n", desempenhos[i].periodo);
            printf("Nota: %s\n", desempenhos[i].nota);
            printf("Frequencia: %s\n", desempenhos[i].frequencia);

            printf("--------------------------------\n");
        }
    }

    if (desempenhoEncontrado == 0) {
        printf("\nEste aluno ainda nao possui acompanhamentos.\n");
        printf("\nPrecione ENTER para voltar.");
    }
}

// Essa bomba aqui embaixo eu demorei pra entender ;-;
void avaliarDesempenho(
    Aluno alunos[],
    int quantidadeAluno,
    Desempenho desempenhos[],
    int quantidadeDesempenhos
){
    int id;
    int alunoEncontrado = 0;
    int possuiDesempenho = 0; //Informa se encontramos algum registro academico (ta 0 então é falso)

    if (quantidadeAluno == 0) {
        printf("\nNenhum aluno cadastrado.\n");
        printf("\nPrecione ENTER para voltar.");
        return; //Isso cancela a função, pois se o if for True, não tem nenhum aluno para ser avaliado.
    }

    printf("\nDigite o ID do aluno: ");

    if (scanf("%d", &id) != 1) {
        while (getchar() != '\n');
        printf("\nEntrada invalida!\n");
        printf("\nPrecione ENTER para voltar.");
        return; //Isso cancela a função, pois se o if for True, não foi digitado um número.
    }

    while (getchar() != '\n');

    // Procura o aluno
    for (int i = 0; i < quantidadeAluno; i++) {
        if (alunos[i].id == id) {
            alunoEncontrado = 1;

            printf("\n================================\n");
            printf("ANALISE DE DESEMPENHO\n");
            printf("ALUNO: %s\n", alunos[i].nome);
            printf("================================\n");

            break; //Esse bloco passa por todos os alunos até encontrar o aluno com o ID digitado no bloco anterior.
            //O break faz com que o for se repita até encontrar o ID do aluno desejado, parando logo em seguida.
        }
    }

    if (alunoEncontrado == 0) {
        printf("\nAluno nao encontrado.\n");
        printf("\nPrecione ENTER para voltar.");
        return; // Isso é caso o for não encontre nenhum aluno com o ID informado.
    }

    // Analisa cada disciplina do aluno, sendo a parte MAIS IMPORTANTE DA FUNÇÃO!!!! (deus me ajude...)
    for (int i = 0; i < quantidadeDesempenhos; i++) {

        if (desempenhos[i].idAluno != id) { // Aqui estamos percorrendo o vetor desempenhos[i], diferente do alunos[] que estava usando antes.
            continue; // Aqui evitamos de misturar dados de diferentes alunos das mesmas matérias, pois caso o ID seja diferente do desejado, nós pulamos ele.
            //Por ex: queremos avaliar as materias do ID 1, não faz sentido avaliarmos o ID 2 ou ID 3, por isso pulamos os diferentes.
        }

        // Aqui resolvemos o problema de calcular a media da mesma disciplina duas vezes.
        // O problema é que: se um aluno tivesse 1. matematica 2. matematica 3. portugues 4. portugues, normalmente calcularia matemtatica, matematica dnv, 
        //e dps o mesmo com portugues. Por isso criamos a variável "int jaListada = 0"
        int jaListada = 0; //Ela começa em 0 pois não sabemos quais materias ja foram ou não listadas.

        for (int j = 0; j < i; j++) {// O segundo for verifica os registros anteriores, descobrindo se aquela disciplina já apareceu.
        // j > i porque queremos olhar apenas as posições anteriores da posição atual.
            if (desempenhos[j].idAluno == id && strcmp(desempenhos[j].disciplina, desempenhos[i].disciplina) == 0){
                //A primeira condição garante que estamos comparando registros do mesmo aluno.
                //O strcmp compara os dois textos dentro dos parâmetros e, no nosso caso, retorna 0.
                jaListada = 1; // se o if for verdadeiro, a variavel "jaListada" vira 1(True).
                break;
            }
        }

        if (jaListada == 1) { // Aqui simplesmente dizemos para o programa que, se a disciplina já foi listada, para ele ir para a próxima.
            continue;
        }

        float somaNotas = 0; //Soma todas as notas da disciplina
        float somaFrequencia = 0; //soma todas as frequências
        float notaAnterior = 0; //Guarda a penultima nota.
        float ultimaNota = 0; //Guarda a nota mais recente.

        char periodoAnterior[30] = ""; //Guardar o período da penúltima nota.
        char ultimoPeriodo[30] = ""; //Guardar o período da última nota.

        int quantidadeRegistros = 0; //Contar quantos registros existem para aquela disciplina.

        // Calcula as medias e identifica as duas ultimas notas
        for (int j = 0; j < quantidadeDesempenhos; j++) {

            if (desempenhos[j].idAluno == id && strcmp(desempenhos[j].disciplina, desempenhos[i].disciplina) == 0) {

                somaNotas += desempenhos[j].nota;
                somaFrequencia += desempenhos[j].frequencia;

                if (quantidadeRegistros > 0) { //Essa condição verifica se já encontramos pelo menos UM registro daquela disciplina.
                //Se já encontramos, significa que temos uma nota anterior que podemos guardar.
                    notaAnterior = ultimaNota; //Copiamos a nota que estava guardada em ultimaNota para notaAnteior.
                    strcpy(periodoAnterior, ultimoPeriodo); //Aqui copiamos o período usando a strcpy.
                }

                ultimaNota = desempenhos[j].nota;
                strcpy(ultimoPeriodo, desempenhos[j].periodo);

                quantidadeRegistros++;
            }
        }

        possuiDesempenho = 1;

        printf("\nDISCIPLINA: %s\n",
               desempenhos[i].disciplina);

        printf("Media das notas: %.2f\n",
               somaNotas / quantidadeRegistros);

        printf("Media de frequencia: %.2f%%\n",
               somaFrequencia / quantidadeRegistros);

        // Compara as duas ultimas notas
        if (quantidadeRegistros >= 2) {

            printf("\nUltima comparacao:\n");
            printf("%s: %.2f\n",
                   periodoAnterior, notaAnterior);

            printf("%s: %.2f\n",
                   ultimoPeriodo, ultimaNota);

            if (ultimaNota < notaAnterior) {
                printf("ALERTA: Queda de %.2f pontos.\n",
                       notaAnterior - ultimaNota);
            }
            else if (ultimaNota > notaAnterior) {
                printf("Melhora de %.2f pontos.\n",
                       ultimaNota - notaAnterior);
            }
            else {
                printf("Desempenho mantido.\n");
            }

        } else {
            printf("\nAinda nao existem registros suficientes para comparar.\n");
            printf("\nPrecione ENTER para voltar.");
        }

        printf("--------------------------------\n");
    }

    if (possuiDesempenho == 0) {
        printf("\nEste aluno ainda nao possui registros de desempenho.\n");
        printf("\nPrecione ENTER para voltar.");
    }
}
