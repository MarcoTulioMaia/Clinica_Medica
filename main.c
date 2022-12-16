#include <stdio.h>
#include <stdlib.h>
#include "interface.h"

void TelaPrincipal()
{
    Borda(0, 0, 79, 23, 1, 0);
    gotoxy(32,1);
    printf("CLINICA MEDICA");
}
char opcoes[][51] = {"PACIENTE", "MEDICO", "CONSULTA", "RELATORIO", "FECHAR"};
int x[] = {2,2,2,2,2};
int y[]= {4,6,8,10,12};

int main()
{
    int i;
    int escolha=0;
    do
    {
        TelaPrincipal();
        escolha=menu(opcoes, x, y, escolha, 5);
        if(escolha == 0)AtivarPaciente();
        if(escolha == 2)
        {
            AbrirArquivoPaciente();
            char OpcoesPaciente[100][51];
            int n;
            int xp[100], yp[100];
            n = CarregarPaciente(OpcoesPaciente);
            FecharArquivoPaciente();
            for(i=0; i<n; i++)
            {
                xp[i]=20;
                yp[i]=10+i;
            }
            escolha = 0;
            escolha = menu(OpcoesPaciente, xp, yp, escolha, n);
        }
        if(escolha == 4)break;
    }
    while(escolha!=-1);
    gotoxy(0,25);
    return 0;
}
