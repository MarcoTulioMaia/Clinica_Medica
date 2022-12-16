#ifndef PACIENTE_H_INCLUDED
#define PACIENTE_H_INCLUDED
struct paciente{
char cpf[100];
char nome[100];
char endereco[100];
char telefone[100];
};
typedef struct paciente Paciente;
Paciente digitar_paciente();
void imprimir_paciente(struct paciente);

#endif // PACIENTE_H_INCLUDED
