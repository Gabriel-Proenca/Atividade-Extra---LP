// funcoes.h
#ifndef FUNCOES_H
#define FUNCOES_H

// Definindo o número máximo de pessoas
#define MAX_PESSOAS 100

// Estrutura da pessoa
typedef struct {
    int idade;
    int genero;
    float altura;
    float peso;
} Pessoa;

// Declaração das funções
void lerDados(Pessoa pessoas[], int *n);
int calcularMaiorIdade(Pessoa pessoas[], int n);
int calcularMenorIdade(Pessoa pessoas[], int n);
float calcularPercentualMasculino(Pessoa pessoas[], int n);
float calcularPercentualFeminino(Pessoa pessoas[], int n);
float calcularMediaAltura(Pessoa pessoas[], int n);
float calcularSomaPeso(Pessoa pessoas[], int n);
float calcularMediaIMC(Pessoa pessoas[], int n);
int contarMenoresDeIdade(Pessoa pessoas[], int n);
int contarMaioresDeIdade(Pessoa pessoas[], int n);
void imprimirRelatorio(Pessoa pessoas[], int n);

#endif // FUNCOES_H
