/**
*   @file persistencia_u_def.h
*   @brief Arquivo de defini��o da camada de Persist�ncia
*          M�dulo de Persist�ncia - Usu�rios
*   @author Bruno Ribeiro
*   @version 1.2
*/

#ifndef PERSISTENCIA_USUARIO_H
#define PERSISTENCIA_USUARIO_H
#ifdef PERSISTENCIA_USUARIO_SERV
#define EXT_PU
#else
#define EXT_PU extern
#endif

/* Includes */

#include "..\..\Padroes.h"
#include "..\Logica\Logica.h"

/* Prot�tipos das fun��es */

/**
*   @brief Inicializa��o da persist�ncia
*   @param
*   @return Retorna sucesso ou fracasso
*/
EXT_PU int inicializa_persistencia_u(void);

/**
*   @brief Armazena um usu�rio em arquivo
*   @param usuario: informa��es a serem armazenadas, deve vir preenchido
*   @return Retorna sucesso ou fracasso
*/
EXT_PU int armazena_usuario(Usuario *usuario);

/**
*   @brief Atualiza um usu�rio pela posi��o do registro no arquivo
*   @param nrr: posi��o do registro do arquivo, usuario: novas informa��es do registro, deve vir preenchido
*   @return Retorna sucesso ou fracasso
*/
EXT_PU int atualiza_usuario(int nrr, Usuario *usuario);

/**
*   @brief Remove um usu�rio do arquivo
*   @param identificador: identificador do registro a ser removido
*   @return Retorna sucesso ou fracasso
*/
EXT_PU int remove_usuario(char *identificador);

/**
*   @brief Procura sequencialmente pelo usu�rio pelo seu identificador e preenche um objeto com suas informa��es
*   @param identificador: chave prim�ria do usu�rio, usuario: conter� as informa��es atuais do registro, deve vir alocado
*   @return Retorna o nrr do registro
*/
EXT_PU int recupera_usuario(char *identificador, Usuario *usuario);

/**
*   @brief Procura sequencialmente pelo usu�rio pelo seu nrr e preenche um objeto com suas informa��es
*   @param nrr: posi��o do registro no arquivo, usuario: conter� as informa��es atuais do registro, deve vir alocado
*   @return Retorna o pr�ximo nrr ou fim de lista
*/
EXT_PU int recupera_usuario_nrr(int nrr, Usuario *usuario);
#endif /* PERSISTENCIA_U_H */
