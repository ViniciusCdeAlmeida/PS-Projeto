/**
*   @file persistencia_u_def.h
*   @brief Arquivo de definição da camada de Persistência
*          Módulo de Persistência - Usuários
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

/* Protótipos das funções */

/**
*   @brief Inicialização da persistência
*   @param
*   @return Retorna sucesso ou fracasso
*/
EXT_PU int inicializa_persistencia_u(void);

/**
*   @brief Armazena um usuário em arquivo
*   @param usuario: informações a serem armazenadas, deve vir preenchido
*   @return Retorna sucesso ou fracasso
*/
EXT_PU int armazena_usuario(Usuario *usuario);

/**
*   @brief Atualiza um usuário pela posição do registro no arquivo
*   @param nrr: posição do registro do arquivo, usuario: novas informações do registro, deve vir preenchido
*   @return Retorna sucesso ou fracasso
*/
EXT_PU int atualiza_usuario(int nrr, Usuario *usuario);

/**
*   @brief Remove um usuário do arquivo
*   @param identificador: identificador do registro a ser removido
*   @return Retorna sucesso ou fracasso
*/
EXT_PU int remove_usuario(char *identificador);

/**
*   @brief Procura sequencialmente pelo usuário pelo seu identificador e preenche um objeto com suas informações
*   @param identificador: chave primária do usuário, usuario: conterá as informações atuais do registro, deve vir alocado
*   @return Retorna o nrr do registro
*/
EXT_PU int recupera_usuario(char *identificador, Usuario *usuario);

/**
*   @brief Procura sequencialmente pelo usuário pelo seu nrr e preenche um objeto com suas informações
*   @param nrr: posição do registro no arquivo, usuario: conterá as informações atuais do registro, deve vir alocado
*   @return Retorna o próximo nrr ou fim de lista
*/
EXT_PU int recupera_usuario_nrr(int nrr, Usuario *usuario);
#endif /* PERSISTENCIA_U_H */
