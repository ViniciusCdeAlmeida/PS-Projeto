/**
*   \file persistencia_u_def.h
*   \brief Arquivo de implementação da camada de Persistência
*          Módulo de Persistência - Usuários
*   \author Bruno Ribeiro
*   \version 1.0
*/

#define PERSISTENCIA_U_SERV

/* Includes */

#include "Persistencia_Usuario.h"
#include "..\Logica\Logica.h"

int inicializa_persistencia_u() {
    /* Declaração de Variáveis */
    FILE *arqUsuario;
    /* Verifica se existe o arquivo */
    arqUsuario = fopen(DB_USUARIO, "r");
    if(arqUsuario == NULL) {
        /* Caso não exista, abre o arquivo e inicia o primeiro espaço livre como final da LED */
        arqUsuario = fopen(DB_USUARIO, "w");
        fprintf(arqUsuario, "%d\n", FIM_LISTA);
    }
    /* Fecha o arquivo (existindo anteriormente ou não) */
    fclose(arqUsuario);
    return SUC_FUNCAO;
}

int armazena_usuario(Usuario *usuario) {
    /* Declaração de Variáveis */
    int byteOffset, proximo;
    FILE *arqUsuario;
    /* Abertura dos arquivos */
    arqUsuario = fopen(DB_USUARIO, "r+");
    /* Procura pelo primeiro espaço livre no arquivo de usuários */
    fscanf(arqUsuario, "%d", &byteOffset);
    if(byteOffset == FIM_LISTA) { /* Arquivo sem espaços entre os registros */
        fseek(arqUsuario, 0, SEEK_END); /* Vai para o final do arquivo */
        proximo = FIM_LISTA;
    }
    else {
        fseek(arqUsuario, byteOffset, SEEK_SET); /* Vai para a posição do registro vago */
        fscanf(arqUsuario, "%d", &proximo);
        fseek(arqUsuario, byteOffset, SEEK_SET);
    }
    fprintf(arqUsuario, "%s\t", REG_ENABLE);
    fprintf(arqUsuario, "%.5s\t", usuario->identificador);
    fprintf(arqUsuario, "%.10s\t", usuario->nome);
    fprintf(arqUsuario, "%.6s\t", usuario->senha);
    fprintf(arqUsuario, "%.5d\t", usuario->primPostagem);
    fprintf(arqUsuario, "%.5d\n", usuario->primComentario);
    /* Atualiza o próximo espaço vazio no começo do arquivo */
    fseek(arqUsuario, 0, SEEK_SET);
    fprintf(arqUsuario, "%.5d", proximo);
    /* Fechamento dos arquivos */
    fclose(arqUsuario);
    return SUC_FUNCAO;
}

int atualiza_usuario(int nrr, Usuario *usuario) {
    /* Declaração de Variáveis */
    FILE *arqUsuario;
    /* Abertura de arquivos */
    arqUsuario = fopen(DB_USUARIO, "r+");
    /* Faz o posicionamento no local desejado (nrr) */
    fseek(arqUsuario, TAM_REGUSUARIO * nrr + 4, SEEK_SET);
    /* Sobrescreve */

    /* Fechamento do arquivo */
    fclose(arqUsuario);
    return SUC_FUNCAO;
}

int remove_usuario(char *identificador) {
    /* Declaração de Variáveis */
    FILE *arqUsuario;
    Usuario *usuario;
    int byteOffset, proximo;
    /* Procura pelo usuário correspondente */
    byteOffset = recupera_usuario(identificador, usuario);
    /* Indica a posição do registro removido como primeiro espaço livre */
    arqUsuario = fopen(DB_USUARIO, "r+");
    fscanf(arqUsuario, "%d", &proximo); /* Armazena o primeiro espaço livre anterior */
    fseek(arqUsuario, 0, SEEK_SET);
    fprintf(arqUsuario, "%.5d", byteOffset);
    /* Compõe a Lista Invertida */
    fseek(arqUsuario, byteOffset, SEEK_SET);
    fprintf(arqUsuario, "%.5d", proximo);
    /* Fechamento dos arquivos */
    free(usuario);
    fclose(arqUsuario);
    return SUC_FUNCAO;
}

int recupera_usuario(char *identificador, Usuario *usuario) {
    /* Declaração de Variáveis */
    FILE *arqUsuario;
    int ativo, linha = 0, proximo;
    /* Abertura dos arquivos */
    arqUsuario = fopen(DB_USUARIO, "r");
    fscanf(arqUsuario, "%d", &proximo);
    /* Procura usuário correspondente */
    while(!feof(arqUsuario)) {
        fscanf(arqUsuario, "%d%s", &ativo, usuario->identificador);
        fgets(usuario->nome, TAM_NOME, arqUsuario);
        fscanf(arqUsuario, "%s%d%d", usuario->senha, &usuario->primPostagem, &usuario->primComentario);
        if(ativo == REG_ENABLE) /* Só compara registros habilitados */
            if(!strcmp(usuario->identificador, identificador)) {
                fclose(arqUsuario);
                return CTE_CABECALHO + linha * TAM_REGUSUARIO;
            }
        linha++;
    }
    /* Fechamento dos arquivos */
    fclose(arqUsuario);
    return SUC_FUNCAO;
}

int recupera_usuario_nrr(int nrr, Usuario *usuario) {
    FILE *arqUsuario;
    int ativo, proximo;
    /* Abertura dos arquivos */
    arqUsuario = fopen(DB_USUARIO, "r");
    fscanf(arqUsuario, "%d", &proximo);
    /* Faz o posicionamento no local desejado (nrr) */
    fseek(arqUsuario, TAM_REGUSUARIO * nrr + 5, SEEK_SET);
    /* Recupera o usuário, se existir */
    fscanf(arqUsuario, "%d", &ativo);
    if(!feof(arqUsuario)) {
        if(ativo == REG_ENABLE) {
            fscanf(arqUsuario, "%s", usuario->identificador);
            fgets(usuario->nome, TAM_NOME, arqUsuario);
            fscanf(arqUsuario, "%s%d%d", usuario->senha, &usuario->primPostagem, &usuario->primComentario);
            fclose(arqUsuario);
            return SUC_FUNCAO;
        }
    }
    /* Senão, retorna INX_REGISTRO */
    fclose(arqUsuario);
    //return INX_REGISTRO;
}
