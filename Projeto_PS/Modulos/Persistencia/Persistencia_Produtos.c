/**
*   @file persistencia_u_def.h
*   @brief Arquivo de implementa��o da camada de Persist�ncia
*          M�dulo de Persist�ncia - Postagens e Coment�rios
*   @author Bruno Ribeiro
*   @version 1.0
*/

#define PERSISTENCIA_PC_SERV

/* Includes */
#include "Persistencia_Produtos.h"

#include <stdio.h>

int inicializa_persistencia_pc() {
    /* Declara��o de Vari�veis */
    FILE *arqPostcom;
    /* Verifica se existe o arquivo */
    arqPostcom = fopen(DB_POSTCOM, "r");
    if(arqPostcom == NULL) {
        /* Caso n�o exista, abre o arquivo e inicia o primeiro espa�o livre como final da LED */
        arqPostcom = fopen(DB_POSTCOM, "w");
        fprintf(arqPostcom, "%d\t%d\n", FIM_LISTA, FIM_LISTA);
    }
    /* Fecha o arquivo (existindo anteriormente ou n�o) */
    fclose(arqPostcom);
    return SUC_FUNCAO;
}

int armazena_postagem(Postagem *postagem) {
    /* Declara��o de Vari�veis */
    int byteOffset, byteOffsetPost, byteOffsetCom, proximoPost, proximo;
    FILE *arqPostcom;
    /* Abertura dos arquivos */
    arqPostcom = fopen(DB_POSTCOM, "r+");
    /* Procura pelo primeiro espa�o livre no arquivo de usu�rios */
    fscanf(arqPostcom, "%d%d", &byteOffsetPost, &byteOffsetCom);
    if(byteOffsetPost == FIM_LISTA) { /* Arquivo sem espa�os entre os registros */
        fseek(arqPostcom, 0, SEEK_END); /* Vai para o final do arquivo */
        proximoPost = FIM_LISTA;
    }
    else {
        fseek(arqPostcom, byteOffset, SEEK_SET); /* Vai para a posi��o do registro vago */
        fscanf(arqPostcom, "%d", &proximo);
        fseek(arqPostcom, byteOffset, SEEK_SET);
    }
    fprintf(arqPostcom, "%s\t", REG_ENABLE);
    fprintf(arqPostcom, "%.5s\t", postagem->identificador);
    fprintf(arqPostcom, "%.10s\t", postagem->titulo);
    fprintf(arqPostcom, "%.6s\t", postagem->conteudo);
    fprintf(arqPostcom, "%.2d\t", postagem->avaliacaoSoma);
    fprintf(arqPostcom, "%.2d\n", postagem->avaliacaoQuantidade);
    /* Atualiza o pr�ximo espa�o vazio no come�o do arquivo */
    fseek(arqPostcom, 0, SEEK_SET);
    fprintf(arqPostcom, "%.5d", proximo);
    /* Fechamento dos arquivos */
    fclose(arqPostcom);
    return SUC_FUNCAO;
}

int armazena_comentario(Comentario *comentario) {
    /* Declara��o de Vari�veis */
    int byteOffsetPost, byteOffsetCom, proximoPost, byteOffset, proximo;
    FILE *arqPostcom;
    /* Abertura dos arquivos */
    arqPostcom = fopen(DB_POSTCOM, "r+");
    /* Procura pelo primeiro espa�o livre no arquivo de usu�rios */
    fscanf(arqPostcom, "%d%d", &byteOffsetPost, &byteOffsetCom);
    if(byteOffsetCom == FIM_LISTA) { /* Arquivo sem espa�os entre os registros */
        fseek(arqPostcom, 0, SEEK_END); /* Vai para o final do arquivo */
        proximoPost = FIM_LISTA;
    }
    else {
        fseek(arqPostcom, byteOffset, SEEK_SET); /* Vai para a posi��o do registro vago */
        fscanf(arqPostcom, "%d", &proximo);
        fseek(arqPostcom, byteOffset, SEEK_SET);
    }
    fprintf(arqPostcom, "%s\t", REG_ENABLE);
    fprintf(arqPostcom, "%.5s\t", comentario->identificador);
    fprintf(arqPostcom, "%.5s\t", comentario->identificadorPost);
    fprintf(arqPostcom, "%.6s\t", comentario->conteudo);
    fprintf(arqPostcom, "%.5d\t", comentario->proxRelativoPostagem);
    fprintf(arqPostcom, "%.5d\n", comentario->proxRelativoUsuario);
    /* Atualiza o pr�ximo espa�o vazio no come�o do arquivo */
    fseek(arqPostcom, 0, SEEK_SET);
    fprintf(arqPostcom, "%.5d", proximo);
    /* Fechamento dos arquivos */
    fclose(arqPostcom);
    return SUC_FUNCAO;
}

int remove_postagem(char *identificador) {
    /* Declara��o de Vari�veis */
    FILE *arqPostcom;
    Postagem *postagem;
    int byteOffset, proximo;
    /* Procura pelo usu�rio correspondente */
    byteOffset = recupera_postagem(identificador, postagem);
    /* Indica a posi��o do registro removido como primeiro espa�o livre */
    arqPostcom = fopen(DB_POSTCOM, "r+");
    fscanf(arqPostcom, "%d", &proximo); /* Armazena o primeiro espa�o livre anterior */
    fseek(arqPostcom, 0, SEEK_SET);
    fprintf(arqPostcom, "%.5d", byteOffset);
    /* Comp�e a Lista Invertida */
    fseek(arqPostcom, byteOffset, SEEK_SET);
    fprintf(arqPostcom, "%.5d", proximo);
    /* Fechamento dos arquivos */
    free(postagem);
    fclose(arqPostcom);
    return SUC_FUNCAO;
}

int remove_comentario(char *identificador) {
    /* Declara��o de Vari�veis */
    FILE *arqPostcom;
    Comentario *comentario;
    int byteOffset, proximo;
    /* Procura pelo usu�rio correspondente */
    byteOffset = recupera_comentario(identificador, comentario);
    /* Indica a posi��o do registro removido como primeiro espa�o livre */
    arqPostcom = fopen(DB_POSTCOM, "r+");
    fscanf(arqPostcom, "%d", &proximo); /* Armazena o primeiro espa�o livre anterior */
    fseek(arqPostcom, 0, SEEK_SET);
    fprintf(arqPostcom, "%.5d", byteOffset);
    /* Comp�e a Lista Invertida */
    fseek(arqPostcom, byteOffset, SEEK_SET);
    fprintf(arqPostcom, "%.5d", proximo);
    /* Fechamento dos arquivos */
    free(comentario);
    fclose(arqPostcom);
    return SUC_FUNCAO;
}

int recupera_postagem(char *identificador, Postagem *postagem) {
    /* Declara��o de Vari�veis */
    FILE *arqPostcom;
    int ativo, linha = 0, proximo;
    /* Abertura dos arquivos */
    arqPostcom = fopen(DB_USUARIO, "r");
    fscanf(arqPostcom, "%d", &proximo);
    /* Procura usu�rio correspondente */
    while(!feof(arqPostcom)) {

    }
    /* Fechamento dos arquivos */
    fclose(arqPostcom);
    return SUC_FUNCAO;
}

int recupera_comentario(char *identificador, Comentario *comentario) {
    /* Declara��o de Vari�veis */
    FILE *arqPostcom;
    int ativo, linha = 0, proximo;
    /* Abertura dos arquivos */
    arqPostcom = fopen(DB_USUARIO, "r");
    fscanf(arqPostcom, "%d", &proximo);
    /* Procura usu�rio correspondente */
    while(!feof(arqPostcom)) {

    }
    /* Fechamento dos arquivos */
    fclose(arqPostcom);
    return SUC_FUNCAO;
}
