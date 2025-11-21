// ============================================================================
//         PROJETO WAR ESTRUTURADO - DESAFIO DE CÓDIGO
// ============================================================================
//        
// ============================================================================
//
// OBJETIVOS:
// - Modularizar completamente o código em funções especializadas.
// - Implementar um sistema de missões para um jogador.
// - Criar uma função para verificar se a missão foi cumprida.
// - Utilizar passagem por referência (ponteiros) para modificar dados e
//   passagem por valor/referência constante (const) para apenas ler.
// - Foco em: Design de software, modularização, const correctness, lógica de jogo.
//
// ============================================================================

// Inclusão das bibliotecas padrão necessárias para entrada/saída, alocação de memória, manipulação de strings e tempo.
#include <stdio.h>
#include <string.h>
// --- Constantes Globais ---
// Definem valores fixos para o número de territórios, missões e tamanho máximo de strings, facilitando a manutenção.

// --- Estrutura de Dados ---
// Define a estrutura para um território, contendo seu nome, a cor do exército que o domina e o número de tropas.
typedef struct {
    char nome[30];    // Nome do território (ex: America, Europa)
    char cor[10];     // Cor do exército que domina (ex: Azul, Verde)
    int tropas;       // Número de tropas alocadas no território
} Territorio;
// --- Protótipos das Funções ---
// Declarações antecipadas de todas as funções que serão usadas no programa, organizadas por categoria.
// Funções de setup e gerenciamento de memória:
// Funções de interface com o usuário:
// Funções de lógica principal do jogo:
// Função utilitária:
// Previne problemas com leitura de strings após scanf
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
// --- Função Principal (main) ---
// Função principal que orquestra o fluxo do jogo, chamando as outras funções em ordem.
int main() {
    // Declaração do vetor de structs para armazenar 5 territórios
    Territorio territorios[5];
    
    // Cabeçalho do sistema
    printf("========================================\n");
    printf("Vamos cadastrar os 5 territorios iniciais do nosso mundo.\n");
    
    // ===================================
    // FASE 1: CADASTRO DOS TERRITORIOS
    // ===================================
    
    // Laço para cadastrar cada um dos 5 territórios
    for (int i = 0; i < 5; i++) {
        printf("\n--- Cadastrando Territorio %d ---\n", i + 1);
        
        // Entrada do nome do território
        printf("Nome do Territorio: ");
        fgets(territorios[i].nome, 30, stdin);
        // Remove o caractere de nova linha que o fgets captura
        territorios[i].nome[strcspn(territorios[i].nome, "\n")] = '\0';
        
        // Entrada da cor do exército
        printf("Cor do Exercito (ex: Azul, Verde): ");
        fgets(territorios[i].cor, 10, stdin);
        // Remove o caractere de nova linha
        territorios[i].cor[strcspn(territorios[i].cor, "\n")] = '\0';
        
        // Entrada do número de tropas
        printf("Numero de Tropas: ");
        scanf("%d", &territorios[i].tropas);
        limparBuffer(); // Limpa o buffer após scanf
    }
    
    // ===================================
    // FASE 2: EXIBIÇÃO DOS DADOS
    // ===================================
    
    printf("\n========================================\n");
    printf("   MAPA DO MUNDO - ESTADO ATUAL\n");
    printf("========================================\n");
    
    // Laço para exibir os dados de todos os territórios cadastrados
    for (int i = 0; i < 5; i++) {
        printf("\nTERRITORIO %d:\n", i + 1);
        printf("  - Nome: %s\n", territorios[i].nome);
        printf("  - Dominado por: Exercito %s\n", territorios[i].cor);
        printf("  - Tropas: %d\n", territorios[i].tropas);
    }
    
    printf("\n========================================\n");
    
    return 0;
}

// --- Implementação das Funções ---

// alocarMapa():
// Aloca dinamicamente a memória para o vetor de territórios usando calloc.
// Retorna um ponteiro para a memória alocada ou NULL em caso de falha.

// inicializarTerritorios():
// Preenche os dados iniciais de cada território no mapa (nome, cor do exército, número de tropas).
// Esta função modifica o mapa passado por referência (ponteiro).

// liberarMemoria():
// Libera a memória previamente alocada para o mapa usando free.

// exibirMenuPrincipal():
// Imprime na tela o menu de ações disponíveis para o jogador.

// exibirMapa():
// Mostra o estado atual de todos os territórios no mapa, formatado como uma tabela.
// Usa 'const' para garantir que a função apenas leia os dados do mapa, sem modificá-los.

// exibirMissao():
// Exibe a descrição da missão atual do jogador com base no ID da missão sorteada.

// faseDeAtaque():
// Gerencia a interface para a ação de ataque, solicitando ao jogador os territórios de origem e destino.
// Chama a função simularAtaque() para executar a lógica da batalha.

// simularAtaque():
// Executa a lógica de uma batalha entre dois territórios.
// Realiza validações, rola os dados, compara os resultados e atualiza o número de tropas.
// Se um território for conquistado, atualiza seu dono e move uma tropa.

// sortearMissao():
// Sorteia e retorna um ID de missão aleatório para o jogador.

// verificarVitoria():
// Verifica se o jogador cumpriu os requisitos de sua missão atual.
// Implementa a lógica para cada tipo de missão (destruir um exército ou conquistar um número de territórios).
// Retorna 1 (verdadeiro) se a missão foi cumprida, e 0 (falso) caso contrário.

// limparBufferEntrada():
// Função utilitária para limpar o buffer de entrada do teclado (stdin), evitando problemas com leituras consecutivas de scanf e getchar.
