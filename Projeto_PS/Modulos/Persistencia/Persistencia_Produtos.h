/**
*   @file persistencia_u_def.h
*   @brief Arquivo de defini��o da camada de Persist�ncia
*          M�dulo de Persist�ncia - Postagens e Coment�rios
*   @author Bruno Ribeiro
*   @version 1.0
*/
#ifndef PERSISTENCIA_PRODUTOS_H
#define PERSISTENCIA_PRODUTOS_H
#ifdef PERSISTENCIA_PRODUTOS_SERV
#define EXT_PPC
#else
#define EXT_PPC extern
#endif

/* Includes */
#include "..\..\Padroes.h"
#include "..\Logica\Logica.h"

/* Prot�tipos das fun��es */
/**
*   @brief Inicializa e/ou verifica os arquivos necess�rios, garantindo a integridade do banco de dados
*   @param
*   @return Retorna sucesso ou fracasso
*/
EXT_PPC int inicializa_persistencia_pc();

/**
*   @brief Armazena uma postagem, passada por refer�ncia
*   @param postagem: cont�m as informa��es a serem armazenadas, deve vir alocado
*   @return Retorna sucesso ou fracasso
*/
EXT_PPC int armazena_postagem(Postagem *postagem);

/**
*   @brief Armazena um coment�rio, passado por refer�ncia
*   @param comentario: cont�m as informa��es a serem armazenadas, deve vir alocado
*   @return Retorna sucesso ou fracasso
*/
EXT_PPC int armazena_comentario(Comentario *comentario);

/**
*   @brief Remove a postagem com o ID correspondente ao identificador passado
*   @param identificador: ID da postagem
*   @return Retorna sucesso ou fracasso
*/
EXT_PPC int remove_postagem(char *identificador);

/**
*   @brief Remove o coment�rio com o ID correspondente ao identificador passado
*   @param identificador: ID do coment�rio
*   @return Retorna sucesso ou fracasso
*/
EXT_PPC int remove_comentario(char *identificador);

/**
*   @brief Procura sequencialmente pela postagem pelo seu identificador e preenche um objeto com suas informa��es
*   @param identificador: ID da postagem
*   @param postagem: conter� as informa��es atuais do registro, deve vir alocado
*   @return Retorna o pr�ximo nrr ou fim de lista
*/
EXT_PPC int recupera_postagem(char *identificador, Postagem *postagem);

/**
*   @brief Procura sequencialmente pelo coment�rio pelo seu identificador e preenche um objeto com suas informa��es
*   @param identificador: ID do coment�rio
*   @param comentario: conter� as informa��es atuais do registro, deve vir alocado
*   @return Retorna o pr�ximo nrr ou fim de lista
*/
EXT_PPC int recupera_comentario(char *identificador, Comentario *comentario);

/**
*   @brief Procura sequencialmente pela postagem pelo seu nrr e preenche um objeto com suas informa��es
*   @param nrr: posi��o do registro no arquivo
*   @param postagem: conter� as informa��es atuais do registro, deve vir alocado
*   @return Retorna o pr�ximo nrr ou fim de lista
*/
EXT_PPC int recupera_postagem_nrr(int nrr, Postagem *postagem);

/**
*   @brief Procura sequencialmente pelo coment�rio pelo seu nrr e preenche um objeto com suas informa��es
*   @param nrr: posi��o do registro no arquivo
*   @param comentario: conter� as informa��es atuais do registro, deve vir alocado
*   @return Retorna o pr�ximo nrr ou fim de lista
*/
EXT_PPC int recupera_comentario_nrr(int nrr, Comentario *comentario);

#endif /* PERSISTENCIA_PC_H */
