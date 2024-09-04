#include <stdio.h>

#define MAX_PESSOAS 100

// Estrutura da pessoa
typedef struct {
    int idade;
    int genero;
    float altura;
    float peso;
} Pessoa;

// Função para ler os dados das pessoas
void lerDados(Pessoa pessoas[], int *n) {
    for (int i = 0; i < *n; i++) {
        printf("\nPessoa %d:\n", i + 1);

        // Ler idade
        printf("Idade (>0): ");
        scanf("%d", &pessoas[i].idade);
        while (pessoas[i].idade <= 0) {
            printf("Idade inválida. Digite uma nova idade: ");
            scanf("%d", &pessoas[i].idade);
        }

        // Ler gênero
        printf("Escolha seu gênero (1 - masculino, 2 - feminino): ");
        scanf("%d", &pessoas[i].genero);
        while (pessoas[i].genero != 1 && pessoas[i].genero != 2) {
            printf("Gênero inválido. Escolha entre 1 para masculino e 2 para feminino: ");
            scanf("%d", &pessoas[i].genero);
        }

        // Ler altura
        printf("Altura (>0): ");
        scanf("%f", &pessoas[i].altura);
        while (pessoas[i].altura <= 0) {
            printf("Altura inválida. Digite uma altura positiva: ");
            scanf("%f", &pessoas[i].altura);
        }

        // Ler peso
        printf("Peso (>0): ");
        scanf("%f", &pessoas[i].peso);
        while (pessoas[i].peso <= 0) {
            printf("Peso inválido. Digite um peso válido: ");
            scanf("%f", &pessoas[i].peso);
        }
    }
}

// Função para calcular a maior idade
int calcularMaiorIdade(Pessoa pessoas[], int n) {
    int maior = 0;
    for (int i = 0; i < n; i++) {
        if (pessoas[i].idade > maior) {
            maior = pessoas[i].idade;
        }
    }
    return maior;
}

// Função para calcular a menor idade
int calcularMenorIdade(Pessoa pessoas[], int n) {
    int menor = 500;  // Um valor suficientemente alto para garantir a atualização
    for (int i = 0; i < n; i++) {
        if (pessoas[i].idade < menor) {
            menor = pessoas[i].idade;
        }
    }
    return menor;
}

// Função para calcular o percentual de homens
float calcularPercentualMasculino(Pessoa pessoas[], int n) {
    int cont = 0;
    for (int i = 0; i < n; i++) {
        if (pessoas[i].genero == 1) {
            cont++;
        }
    }
    return (cont * 100.0) / n;
}

// Função para calcular o percentual de mulheres
float calcularPercentualFeminino(Pessoa pessoas[], int n) {
    int cont = 0;
    for (int i = 0; i < n; i++) {
        if (pessoas[i].genero == 2) {
            cont++;
        }
    }
    return (cont * 100.0) / n;
}

// Função para calcular a média da altura
float calcularMediaAltura(Pessoa pessoas[], int n) {
    float soma = 0;
    for (int i = 0; i < n; i++) {
        soma += pessoas[i].altura;
    }
    return soma / n;
}

// Função para calcular a soma dos pesos
float calcularSomaPeso(Pessoa pessoas[], int n) {
    float soma = 0;
    for (int i = 0; i < n; i++) {
        soma += pessoas[i].peso;
    }
    return soma;
}

// Função para calcular a média do IMC
float calcularMediaIMC(Pessoa pessoas[], int n) {
    float somaIMC = 0;
    for (int i = 0; i < n; i++) {
        somaIMC += pessoas[i].peso / (pessoas[i].altura * pessoas[i].altura);
    }
    return somaIMC / n;
}

// Função para contar menores de idade
int contarMenoresDeIdade(Pessoa pessoas[], int n) {
    int cont = 0;
    for (int i = 0; i < n; i++) {
        if (pessoas[i].idade < 18) {
            cont++;
        }
    }
    return cont;
}

// Função para contar maiores de idade
int contarMaioresDeIdade(Pessoa pessoas[], int n) {
    int cont = 0;
    for (int i = 0; i < n; i++) {
        if (pessoas[i].idade >= 18) {
            cont++;
        }
    }
    return cont;
}

// Função para imprimir o relatório
void imprimirRelatorio(Pessoa pessoas[], int n) {
    printf("\nRelatorio de Dados:\n");
    printf("+-----------------------------+------------------------------+\n");
    printf("| Descricao                   | Valor                        |\n");
    printf("+-----------------------------+------------------------------+\n");
    printf("| Maior idade                 |  %27d |\n", calcularMaiorIdade(pessoas, n));
    printf("| Menor idade                 |  %27d |\n", calcularMenorIdade(pessoas, n));
    printf("| Percentual masculino        |  %26.2f%% |\n", calcularPercentualMasculino(pessoas, n));
    printf("| Percentual feminino         |  %26.2f%% |\n", calcularPercentualFeminino(pessoas, n));
    printf("| Media da altura             | %26.2f m |\n", calcularMediaAltura(pessoas, n));
    printf("| Soma de todos os pesos      |%26.2f kg |\n", calcularSomaPeso(pessoas, n));
    printf("| Media do IMC                |  %27.2f |\n", calcularMediaIMC(pessoas, n));
    printf("| Pessoas menores de idade    |  %27d |\n", contarMenoresDeIdade(pessoas, n));
    printf("| Pessoas maiores de idade    |  %27d |\n", contarMaioresDeIdade(pessoas, n));
    printf("+-----------------------------+------------------------------+\n");
}

int main() {
    Pessoa pessoas[MAX_PESSOAS];
    int n;

    printf("Digite o número de pessoas: ");
    scanf("%d", &n);

    // Verifica se o número de pessoas é válido
    while (n <= 0) {
        printf("Número inválido. Digite um número positivo: ");
        scanf("%d", &n);
    }

    // Ler os dados das pessoas
    lerDados(pessoas, &n);

    // Imprimir o relatório com os dados
    imprimirRelatorio(pessoas, n);

    return 0;
}