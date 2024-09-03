#include <stdio.h>

typedef struct {
    int nota[3];
    char nome[99];
} Rotina;

void cadastraAluno(Rotina rotina[], int posi) {
    int nota=0;
    printf("Digite o nome do aluno: ");
    scanf("%s", rotina[posi].nome);
    for(int i=0; i<3; i++) {
        printf("Digite a %da. nota: ", i+1);
        scanf("%d", &nota);
        if(nota >= 0 && nota <=10) {
            rotina[posi].nota[i] = nota;
        } else {
            printf("Nota inválida\n\n");
            return;
        }

    }
    printf("\n");

}

void mediaAritmetica(Rotina rotina) {
    float mediaRes=0;

    for(int i=0; i<3; i++) {
        mediaRes += rotina.nota[i];
    }
    mediaRes = mediaRes / 3;
    printf("\nMédia aritmética de %s:%.2f\n", rotina.nome, mediaRes);
    printf("SITUAÇÃO: ");
    if(mediaRes >= 7) {
        printf("ALUNO APROVADO\n\n");
    } else {
        printf("ALUNO REPROVADO\n\n");
    }

}




void mediaPonderada(Rotina rotina) {

    float mediaRes=0;

    rotina.nota[0] = rotina.nota[0]*5;
    rotina.nota[1] = rotina.nota[1]*3;
    rotina.nota[2] = rotina.nota[2]*2;
    for(int i = 0; i< 3; i++) {
        mediaRes += rotina.nota[i];
    }
    mediaRes = mediaRes / 10;
    printf("\nA media ponderada de %s é:%.2f\n", rotina.nome, mediaRes);
    printf("SITUAÇÃO: ");
    if(mediaRes >= 7) {
        printf("ALUNO APROVADO\n\n");
    } else {
        printf("ALUNO REPROVADO\n\n");
    }
}

int main() {
    Rotina rotina[5];
    //float mediaRes = 0;
    int op, posi=0;
    char nome_aluno[99];



    printf("IFMA - MONTE CASTELO\n");

    do {
        printf("1-Cadastrar aluno\n");
        printf("2-Calcular média aritmética\n");
        printf("3-Calcular média ponderada\n");
        printf("4-Encerrar\n");
        printf("Digite sua opção: ");
        scanf("%d",&op);

        if(op<1 || op>4) {
            printf("Opção inválida\n");
            exit;
        }
        switch(op) {
        case 1:
            cadastraAluno(rotina,posi);
            posi++;
            break;
        case 2:
            printf("Digite o nome do aluno a ser consultado: ");
            scanf("%s", nome_aluno);
            for(int i=0; i< posi; i++) {
                if(strcmp(nome_aluno, rotina[i].nome)==0) {
                    mediaAritmetica(rotina[i]);
                } else {
                    printf("Aluno não cadastrado\n\n");
                }
            }
            break;

        case 3:
            printf("Digite o nome do aluno a calcular a média: ");
            scanf("%s", nome_aluno);
            for(int i=0; i< posi; i++) {
                if(strcmp(nome_aluno, rotina[i].nome)==0) {
                    mediaPonderada(rotina[i]);
                } else {
                    printf("Aluno não cadastrado\n\n");
                }
            }

            break;

        case 4:
            printf("ENCERRANDO...");

            exit(0);
            break;


        }



    } while(op!=4);


    return 0;
}
