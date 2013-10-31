/**
*   @file persistencia_u_def.h
*   @brief Arquivo de implementação da camada de Persistência
*          Módulo de Persistência - Postagens e Comentários
*   @author Bruno Ribeiro
*   @version 1.0
*/

#define PERSISTENCIA_PC_SERV

/* Includes */
#include "Persistencia_Produtos.h"

#include <stdio.h>

int inicializa_persistencia_pc() {
    /* Declaração de Variáveis */
    FILE *arqPostcom;
    /* Verifica se existe o arquivo */
    arqPostcom = fopen(DB_POSTCOM, "r");
    if(arqPostcom == NULL) {
        /* Caso não exista, abre o arquivo e inicia o primeiro espaço livre como final da LED */
        arqPostcom = fopen(DB_POSTCOM, "w");
        fprintf(arqPostcom, "%d\t%d\n", FIM_LISTA, FIM_LISTA);
    }
    /* Fecha o arquivo (existindo anteriormente ou não) */
    fclose(arqPostcom);
    return SUC_FUNCAO;
}

int armazena_postagem(Postagem *postagem) {
    /* Declaração de Variáveis */
    int byteOffset, byteOffsetPost, byteOffsetCom, proximoPost, proximo;
    FILE *arqPostcom;
    /* Abertura dos arquivos */
    arqPostcom = fopen(DB_POSTCOM, "r+");
    /* Procura pelo primeiro espaço livre no arquivo de usuários */
    fscanf(arqPostcom, "%d%d", &byteOffsetPost, &byteOffsetCom);
    if(byteOffsetPost == FIM_LISTA) { /* Arquivo sem espaços entre os registros */
        fseek(arqPostcom, 0, SEEK_END); /* Vai para o final do arquivo */
        proximoPost = FIM_LISTA;
    }
    else {
        fseek(arqPostcom, byteOffset, SEEK_SET); /* Vai para a posição do registro vago */
        fscanf(arqPostcom, "%d", &proximo);
        fseek(arqPostcom, byteOffset, SEEK_SET);
    }
    fprintf(arqPostcom, "%s\t", REG_ENABLE);
    fprintf(arqPostcom, "%.5s\t", postagem->identificador);
    fprintf(arqPostcom, "%.10s\t", postagem->titulo);
    fprintf(arqPostcom, "%.6s\t", postagem->conteudo);
    fprintf(arqPostcom, "%.2d\t", postagem->avaliacaoSoma);
    fprintf(arqPostcom, "%.2d\n", postagem->avaliacaoQuantidade);
    /* Atualiza o próximo espaço vazio no começo do arquivo */
    fseek(arqPostcom, 0, SEEK_SET);
    fprintf(arqPostcom, "%.5d", proximo);
    /* Fechamento dos arquivos */
    fclose(arqPostcom);
    return SUC_FUNCAO;
}

int armazena_comentario(Comentario *comentario) {
    /* Declaração de Variáveis */
    int byteOffsetPost, byteOffsetCom, proximoPost, byteOffset, proximo;
    FILE *arqPostcom;
    /* Abertura dos arquivos */
    arqPostcom = fopen(DB_POSTCOM, "r+");
    /* Procura pelo primeiro espaço livre no arquivo de usuários */
    fscanf(arqPostcom, "%d%d", &byteOffsetPost, &byteOffsetCom);
    if(byteOffsetCom == FIM_LISTA) { /* Arquivo sem espaços entre os registros */
        fseek(arqPostcom, 0, SEEK_END); /* Vai para o final do arquivo */
        proximoPost = FIM_LISTA;
    }
    else {
        fseek(arqPostcom, byteOffset, SEEK_SET); /* Vai para a posição do registro vago */
        fscanf(arqPostcom, "%d", &proximo);
        fseek(arqPostcom, byteOffset, SEEK_SET);
    }
    fprintf(arqPostcom, "%s\t", REG_ENABLE);
    fprintf(arqPostcom, "%.5s\t", comentario->identificador);
    fprintf(arqPostcom, "%.5s\t", comentario->identificadorPost);
    fprintf(arqPostcom, "%.6s\t", comentario->conteudo);
    fprintf(arqPostcom, "%.5d\t", comentario->proxRelativoPostagem);
    fprintf(arqPostcom, "%.5d\n", comentario->proxRelativoUsuario);
    /* Atualiza o próximo espaço vazio no começo do arquivo */
    fseek(arqPostcom, 0, SEEK_SET);
    fprintf(arqPostcom, "%.5d", proximo);
    /* Fechamento dos arquivos */
    fclose(arqPostcom);
    return SUC_FUNCAO;
}

int remove_postagem(char *identificador) {
    /* Declaração de Variáveis */
    FILE *arqPostcom;
    Postagem *postagem;
    int byteOffset, proximo;
    /* Procura pelo usuário correspondente */
    byteOffset = recupera_postagem(identificador, postagem);
    /* Indica a posição do registro removido como primeiro espaço livre */
    arqPostcom = fopen(DB_POSTCOM, "r+");
    fscanf(arqPostcom, "%d", &proximo); /* Armazena o primeiro espaço livre anterior */
    fseek(arqPostcom, 0, SEEK_SET);
    fprintf(arqPostcom, "%.5d", byteOffset);
    /* Compõe a Lista Invertida */
    fseek(arqPostcom, byteOffset, SEEK_SET);
    fprintf(arqPostcom, "%.5d", proximo);
    /* Fechamento dos arquivos */
    free(postagem);
    fclose(arqPostcom);
    return SUC_FUNCAO;
}

int remove_comentario(char *identificador) {
    /* Declaração de Variáveis */
    FILE *arqPostcom;
    Comentario *comentario;
    int byteOffset, proximo;
    /* Procura pelo usuário correspondente */
    byteOffset = recupera_comentario(identificador, comentario);
    /* Indica a posição do registro removido como primeiro espaço livre */
    arqPostcom = fopen(DB_POSTCOM, "r+");
    fscanf(arqPostcom, "%d", &proximo); /* Armazena o primeiro espaço livre anterior */
    fseek(arqPostcom, 0, SEEK_SET);
    fprintf(arqPostcom, "%.5d", byteOffset);
    /* Compõe a Lista Invertida */
    fseek(arqPostcom, byteOffset, SEEK_SET);
    fprintf(arqPostcom, "%.5d", proximo);
    /* Fechamento dos arquivos */
    free(comentario);
    fclose(arqPostcom);
    return SUC_FUNCAO;
}

int recupera_postagem(char *identificador, Postagem *postagem) {
    /* Declaração de Variáveis */
    FILE *arqPostcom;
    int ativo, linha = 0, proximo;
    /* Abertura dos arquivos */
    arqPostcom = fopen(DB_USUARIO, "r");
    fscanf(arqPostcom, "%d", &proximo);
    /* Procura usuário correspondente */
    while(!feof(arqPostcom)) {

    }
    /* Fechamento dos arquivos */
    fclose(arqPostcom);
    return SUC_FUNCAO;
}

int recupera_comentario(char *identificador, Comentario *comentario) {
    /* Declaração de Variáveis */
    FILE *arqPostcom;
    int ativo, linha = 0, proximo;
    /* Abertura dos arquivos */
    arqPostcom = fopen(DB_USUARIO, "r");
    fscanf(arqPostcom, "%d", &proximo);
    /* Procura usuário correspondente */
    while(!feof(arqPostcom)) {

    }
    /* Fechamento dos arquivos */
    fclose(arqPostcom);
    return SUC_FUNCAO;
}
