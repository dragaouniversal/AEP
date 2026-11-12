#include <stdio.h>
#include <string.h>
#include "aluno.h"

int cadastrarAluno(Aluno alunos[], int quantidadeAluno) { // Função para cadastrar um aluno
    //alunos[]: Vetor de alunos, onde eles serão armazenados.
    //quantidadeAluno: Quantidade de alunos já cadastrados, para saber em qual posição do vetor o próximo aluno será armazenado.

    if(quantidadeAluno <100){

     alunos[quantidadeAluno].id = quantidadeAluno + 1; //Alunos: nosso vetor. [quantidadeAluno] = posição do aluno no vetor.
     //id_aluno = quantidadeAlunos + 1 (para que o ID comece em 1 e não em 0)
     //Podemos imaginar assim:
     //Primeiro cadastro: alunos[0].id_aluno = 0 + 1;
     //Segundo cadastro: alunos[1].id_aluno = 1 + 1;
      //Terceiro cadastro: alunos[2].id_aluno = 2 + 1;
     //E assim por diante até chegar em 100
     alunos[quantidadeAluno].ativo = 1; //1 para ativo, 0 para removido (exclusão lógica). Afirmando que o cliente está ativo no sistema.

    getchar(); // Limpar o buffer do teclado

    printf("\nDigite o nome do aluno: ");

    fgets(alunos[quantidadeAluno].nome, 100, stdin); //Usamos fgets para ler o nome do cliente, permitindo que ele contenha espaços.

    alunos[quantidadeAluno].nome[strcspn(alunos[quantidadeAluno].nome, "\n")] = '\0';//Aqui ocorre a leitura ;-;
    //alunos[quantidadeAlunos].nome: Onde o texto será armazenado.
     //100 limite de caracteres que podem ser lidos.
    //stdin: Indica que a entrada será feita pelo teclado.

    //Quando usamos fgets, o ENTER pressionado também pode ser armazenado no final do texto.
     //Para evitar que o ENTER seja armazenado, usamos a função strcspn para encontrar a posição do '\n' (ENTER) e substituí-lo por '\0' (fim da string).
    //Por exemplo, o nome pode ficar assim:
    //Antes: "Pedro Henrique\n"
     //Depois: "Pedro Henrique"
    //A mesma lógica é aplicada para os outros campos, como matrícula, turma e série.

    printf("Digite a matricula do aluno: ");
    fgets(alunos[quantidadeAluno].matricula, 20, stdin);

    alunos[quantidadeAluno].matricula[strcspn(alunos[quantidadeAluno].matricula, "\n")] = '\0';
        
    printf("Digite a turma do aluno:");
    fgets(alunos[quantidadeAluno].turma, 30, stdin);

    alunos[quantidadeAluno].turma[strcspn(alunos[quantidadeAluno].turma, "\n")] = '\0';

    printf("Digite a serie do aluno:");
    fgets(alunos[quantidadeAluno].serie, 30, stdin);

    alunos[quantidadeAluno].serie[strcspn(alunos[quantidadeAluno].serie, "\n")] = '\0';

     quantidadeAluno++;

    printf("\nAluno cadastrado com sucesso");
    }
 else{
     printf("\nLimite de alunos atingido.");
 }
    return quantidadeAluno; // Retorna a nova quantidade de alunos cadastrados
}


void consultarAlunos(Aluno alunos[], int quantidadeAluno){
    int alunosAtivos = 0; // Variável para contar a quantidade de alunos ativos
    
    printf("\n=====Consulta de alunos=====\n");
    if (quantidadeAluno == 0){
        printf("\nNenhum aluno cadastrado.");
        return; // Aqui o return serve para encerrar a função, pois não há alunos cadastrados para serem consultados.
    }
    for (int i = 0; i < quantidadeAluno; i++){

        if (alunos[i].ativo ==1){
            printf("ID: %d | Nome: %s | Matricula: %s | Turma: %s | Serie: %s\n", alunos[i].id, alunos[i].nome, alunos[i].matricula, alunos[i].turma, alunos[i].serie);

            alunosAtivos++; // Incrementa o contador de alunos ativos
        }
    }
    if(alunosAtivos ==0){
        printf("\nNenhum aluno ativo encontrado.");
    }
    printf("\nAperte ENTER para sair.");
}

void inativarAluno(Aluno alunos[], int quantidadeAluno){ //void: significa que a função não precisa devolver nenhum valor.
    //alunos[]: recebe o vetor de alunos que está no main.c, para que possamos acessar os dados dos alunos cadastrados.
    //quantidadeAluno: recebe a quantidade de alunos cadastrados.
    //encontrado: variável para verificar se o aluno foi encontrado ou não.
    int id;
    int encontrado = 0;

    if (quantidadeAluno == 0){
        printf("\nNenhum aluno cadastrado.\n");
        return; // Aqui o return serve para encerrar a função, pois não há alunos cadastrados para serem inativados.
    }
    for (int i=0; i < quantidadeAluno; i++){
        if (alunos[i].ativo == 1){ // Verifica se o aluno está ativo antes de exibir
            printf("Alunos ativos:\n ID: %d | Nome: %s | Matricula: %s | Turma: %s | Serie: %s\n", alunos[i].id, alunos[i].nome, alunos[i].matricula, alunos[i].turma, alunos[i].serie);
        }
    }
    printf("\nDigite o ID do aluno que deseja inativar: ");
    if (scanf("%d", &id) != 1){
        while (getchar() != '\n'); // Limpa o buffer do teclado, caso a entrada seja inválida (não seja um número inteiro).
        printf("\nEntrada invalida!\n");
        return; // Retorna para encerrar a função, pois a entrada foi inválida.
    }
    for (int i = 0; i < quantidadeAluno; i++){ //Percorre o vetor de alunos para encontrar o aluno com o ID informado.
        if (alunos[i].id == id){
            encontrado = 1; // Aluno encontrado, abaixo é o processo de inativação do aluno.
            if (alunos[i].ativo == 0){
                printf("\nAluno ja inativado.\n");
            } else {
                alunos[i].ativo = 0; // Inativa o aluno
                printf("\nAluno inativado com sucesso.\n");
            }
            break; // Sai do loop após encontrar o aluno
        }
    }
    if (encontrado == 0){
        printf("\nAluno nao encontrado.\n");
    }
}

void edicaoAlunos(Aluno alunos[], int quantidadeAluno){
    int id;
    int encontrado = 0;

    if (quantidadeAluno == 0){
        printf("\nNenhum aluno cadastrado.\n");
        return; // Aqui o return serve para encerrar a função, pois não há alunos cadastrados para serem editados.
    }
    printf("\nDigite o ID do aluno que deseja editar: ");
    if (scanf("%d", &id) != 1){
        while (getchar() != '\n'); // Limpa o buffer do teclado, caso a entrada seja inválida (não seja um número inteiro).
        printf("\nEntrada invalida!\n");
        return; // Retorna para encerrar a função, pois a entrada foi inválida.
    }
    while (getchar() != '\n'); //Um laço de repetição que limpa todos os caracteres até encontrar um ENTER.
    //Isso é necessário porque, após o scanf, o ENTER pressionado pelo usuário ainda permanece no buffer do teclado,
    //e precisamos removê-lo antes de ler novas entradas com fgets.

    for (int i = 0; i < quantidadeAluno; i++){
        if (alunos[i].id ==id){
            encontrado =1; // Aluno encontrado, abaixo é o processo de edição do aluno.

            printf("\n===== Dados atuais do aluno =====\n");
            printf("Nome: %s\n", alunos[i].nome); //alunos[i].nome é o nome armazenado no aluno encontrado.
            printf("Matricula: %s\n", alunos[i].matricula); //alunos[i].matricula é a matrícula armazenada no aluno encontrado.
            printf("Turma: %s\n", alunos[i].turma); //alunos[i].turma é a turma armazenada no aluno encontrado.
            printf("Serie: %s\n", alunos[i].serie); //alunos[i].serie é a série armazenada no aluno encontrado.

            printf("\n===== Novos Dados =====\n");

            printf("Digite o novo nome: ");
            fgets(alunos[i].nome, 100, stdin); //alunos[i]: aluno encontrado. | .nome: Campo que queremos modificar.
            //100: Limite de caracteres que podem ser lidos. | stdin: Indica que a entrada será feita pelo teclado.
            //fgets tem a mesma função do scanf, mas permite que o usuário digite espaços no nome do aluno.
            alunos[i].nome[strcspn(alunos[i].nome, "\n")] = '\0'; //strcspn é uma função da biblioteca string.h,
            //que retorna o índice do primeiro caractere encontrado na string que corresponde a qualquer caractere da segunda string.
            //No caso, estamos procurando o caractere '\n' (ENTER) na string alunos[i].nome.
            //Se o ENTER for encontrado, ele será substituído por '\0' (que indica o final do texto), removendo assim o ENTER do final do nome do aluno.
            printf("Digite a nova matricula: ");
            fgets(alunos[i].matricula, 20, stdin);
            alunos[i].matricula[strcspn(alunos[i].matricula, "\n")] = '\0';

            printf("Digite a nova turma: ");
            fgets(alunos[i].turma, 30, stdin);
            alunos[i].turma[strcspn(alunos[i].turma, "\n")] = '\0';

            printf("Digite a nova serie: ");
            fgets(alunos[i].serie, 30, stdin);
            alunos[i].serie[strcspn(alunos[i].serie, "\n")] = '\0';

            printf("\nEdicao realizada com sucesso.\n");
            break; // Sai do loop após encontrar o aluno
        }
    }
    if (encontrado == 0){
        printf("\nAluno nao encontrado.\n");
    }
}

void pesquisarAluno(Aluno alunos[], int quantidadeAlunos){
    int criterio; // Essa veriável deixa a opção de escolha ao usuário. Deixando ele escolher a pesquisa ou por nome, ou por matricula.
    int encontrado =0;
    char pesquisa[100];

    if (quantidadeAlunos == 0){
        printf("\nNenhum aluno cadastrado.\n");
        return;
    }

    printf("\n===== PESQUISAR ALUNO =====\n");
    printf("1 - Pesquisar por nome\n");
    printf("2 - Pesquisar por matricula\n");
    printf("Escolha uma opcao: \n");

    if (scanf("%d", &criterio) != 1){
        while(getchar() != '\n');
        printf("\nEntrada invalida\n");
        return;
    }
    if (criterio != 1 && criterio != 2){
        printf("\nOpcao inexistente\n");
        return;
    }

    while(getchar() != '\n');

    if (criterio == 1){
        printf("\nDigite o nome ou parte do nome: ");
    } else {
        printf("\nDigite a matricula: ");
    }

    fgets(pesquisa, 100, stdin);
    pesquisa[strcspn(pesquisa, "\n")] = '\0';

    for (int i = 0; i < quantidadeAlunos; i++){
        if (criterio == 1 && strstr(alunos[i].nome, pesquisa) != NULL){ // A função "strstr" procura um texto dentro de outro.
            // Imagine que temo:
            // alunos[i].nome = "Pedro Henrique";
            // pesquisa = "Pedro";
            // A função encontra "Pedro" dentro de "Pedro Henrique"
            encontrado = 1;
        } else if (criterio == 2 && strcmp(alunos[i].matricula, pesquisa) == 0){ // A função "strcmp" compara dois textos.
            // Diferente da pesqusia de nomes, a pesquisa por matricula precisa ser exata, comparando o valor digitado com o valor armazenado.
            // Caso esteja errado, não irá encontrar nada.
            encontrado = 1;
        } else{
            continue; // Continue apenas pula para a próxima repetição.
        }
        printf("\nID: %d | Nome: %s | Matricula: %s\n", alunos[i].id, alunos[i].nome, alunos[i].matricula);
        printf("\nTurma: %s | Serie %s\n", alunos[i].turma, alunos[i].serie);

        if (alunos[i].ativo == 1){
            printf("Status: Ativo\n");
        } else {
            printf("Status: Inativo\n");
        }

        printf("------------------------------------\n");
    }
    if (encontrado == 0){
        printf("\nNenhum aluno encontrado.\n");
    }
}

int menuGerenciamento(void) {
    int opcao;

    printf("\n==============================\n");
    printf("    GERENCIAMENTO DE ALUNOS   \n");
    printf("==============================\n");

    printf("\n1 - Editar aluno\n");
    printf("2 - Inativar aluno\n");
    printf("3 - Pesquisar aluno\n");
    printf("0 - Voltar ao menu principal\n");

    printf("\nEscolha uma opcao: ");

    if (scanf("%d", &opcao) != 1) { // Verifica se a entrada é um número inteiro.
        while (getchar() != '\n'); // Limpa o buffer do teclado, caso a entrada seja inválida (não seja um número inteiro).
        return -1; // Retorna -1 para indicar que a entrada foi inválida.
    } //Isso ocorre porque, se o usuário digitar uma letra ou um símbolo, o scanf não conseguirá ler um número inteiro e retornará 0, indicando que a leitura falhou.

    return opcao;
}
