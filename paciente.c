#include <stdio.h>
#include "paciente.h"
FILE *fpPaciente;

void AbrirArquivoPaciente(){
    fpPaciente = fopen("Paciente.txt", "rb+");
    if(fpPaciente == NULL){
        fpPaciente = fopen("Paciente.txt", "wb+");
        if(fpPaciente == NULL){
         printf("Não foi possivel abrir o arquivo Paciente.txt\n");
         exit(1);
        }
    }
}

void FecharArquivoPaciente(){
    fclose(fpPaciente);
}

void SalvarNovoPaciente(Paciente P){
    fseek(fpPaciente, 0, SEEK_END);
    fwrite(&P, sizeof(Paciente), 1, fpPaciente);
}

int CarregarPaciente(char Dados[][51]){
    int n=0;
    Paciente P;
    fseek(fpPaciente, 0, SEEK_SET);
    while(fread(&P, sizeof(Paciente), 1, fpPaciente)){
        strcpy(Dados[n], P.nome);
        n++;
    }
    return n;
}



Paciente PesquisarPaciente(){
    char CPF[51]; Paciente P;
    gotoxy(27, 6);
    scanf(" %[^\n]", CPF);
    fseek(fpPaciente, 0, SEEK_SET);
    while(fread(&P, sizeof(Paciente), 1, fpPaciente)){
        if(strcmp(P.cpf, CPF)==0)
            return P;
    }
    strcpy(P.cpf, "");
    return P;
}

void LimparPaciente(){
  gotoxy(27, 6); printf ("                                 ");
  gotoxy(27, 9); printf ("                                 ");
  gotoxy(27, 12); printf("                                 ");
  gotoxy(27, 15); printf("                                 ");
}


Paciente digitar_paciente(){
Paciente P;
  gotoxy(27, 6); scanf(" %[^\n]", P.cpf);
  gotoxy(27, 9); scanf(" %[^\n]", P.nome);
  gotoxy(27, 12); scanf(" %[^\n]", P.endereco);
  gotoxy(27, 15); scanf(" %[^\n]", P.telefone);

  return P;
}
void imprimir_paciente(Paciente P){
    gotoxy(27, 6);printf(" %s\n", P.cpf);
    gotoxy(27, 9);printf(" %s\n", P.nome);
    gotoxy(27, 12);printf(" %s\n", P.endereco);
    gotoxy(27, 15);printf(" %s\n", P.telefone);

}
void TelaPaciente(){
  Borda(14, 3, 60, 18, 1, 1);
  gotoxy(16,  6); printf("     CPF:");
  gotoxy(16,  9); printf("    NOME:");
  gotoxy(16, 12); printf("ENDERECO:");
  gotoxy(16, 15); printf("TELEFONE:");
  Borda(26, 5, 37, 2, 1, 0);
  Borda(26, 8, 37, 2, 1, 0);
  Borda(26, 11, 37, 2, 1, 0);
  Borda(26, 14, 37, 2, 1, 0);
}

void AtivarPaciente(){
    Paciente P;
  AbrirArquivoPaciente();
  char OpcoesConfirma[][51] = {"CONFIRMA", "CANCELA"};
  int escolha = 0;
  char opcoes[][51] = {"NOVO", "PESQUISAR", "ALTERAR", "SAIR"};
    int x[] = {17,17,17,17};
    int y[]= {6,10,14,18};

    int x1[] = {20,36};
    int y1[]= {19,19};
do{
  Borda(14, 3, 60, 18, 1, 1);
  Borda(16, 5, 10, 2, 0, 0);
  Borda(16, 9, 10, 2, 0, 0);
  Borda(16, 13, 10, 2, 0, 0);
  Borda(16, 17, 10, 2, 0, 0);
    escolha = menu(opcoes, x, y, escolha, 4);
    if(escolha==0){
      TelaPaciente();
      P = digitar_paciente();
      Borda(19, 18, 10, 2, 0, 0);
      Borda(35, 18, 10, 2, 0, 0);
      escolha = menu(OpcoesConfirma, x1, y1, escolha, 2);
      if(escolha == 0)SalvarNovoPaciente(P);
    }
    if(escolha==1){
        TelaPaciente();
        P = PesquisarPaciente();
        if(strlen(P.cpf)>0){
            imprimir_paciente(P);
            gotoxy(0,25);system("Pause");}
        //else Borda(30, 30, 10, 2, 0, 0);
    }
  }while(escolha != 3);
 FecharArquivoPaciente();
}


