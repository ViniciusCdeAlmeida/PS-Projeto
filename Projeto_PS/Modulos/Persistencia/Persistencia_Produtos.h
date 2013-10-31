/**
*   @file persistencia_u_def.h
*   @brief Arquivo de definição da camada de Persistência
*          Módulo de Persistência - Postagens e Comentários
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

/* Protótipos das funções */
/**
*   @brief Inicializa e/ou verifica os arquivos necessários, garantindo a integridade do banco de dados
*   @param
*   @return Retorna sucesso ou fracasso
*/
EXT_PPC int inicializa_persistencia_pc();

/**
*   @brief Armazena uma postagem, passada por referência
*   @param postagem: contém as informações a serem armazenadas, deve vir alocado
*   @return Retorna sucesso ou fracasso
*/
EXT_PPC int armazena_postagem(Postagem *postagem);

/**
*   @brief Armazena um comentário, passado por referência
*   @param comentario: contém as informações a serem armazenadas, deve vir alocado
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
*   @brief Remove o comentário com o ID correspondente ao identificador passado
*   @param identificador: ID do comentário
*   @return Retorna sucesso ou fracasso
*/
EXT_PPC int remove_comentario(char *identificador);

/**
*   @brief Procura sequencialmente pela postagem pelo seu identificador e preenche um objeto com suas informações
*   @param identificador: ID da postagem
*   @param postagem: conterá as informações atuais do registro, deve vir alocado
*   @return Retorna o próximo nrr ou fim de lista
*/
EXT_PPC int recupera_postagem(char *identificador, Postagem *postagem);

/**
*   @brief Procura sequencialmente pelo comentário pelo seu identificador e preenche um objeto com suas informações
*   @param identificador: ID do comentário
*   @param comentario: conterá as informações atuais do registro, deve vir alocado
*   @return Retorna o próximo nrr ou fim de lista
*/
EXT_PPC int recupera_comentario(char *identificador, Comentario *comentario);

/**
*   @brief Procura sequencialmente pela postagem pelo seu nrr e preenche um objeto com suas informações
*   @param nrr: posição do registro no arquivo
*   @param postagem: conterá as informações atuais do registro, deve vir alocado
*   @return Retorna o próximo nrr ou fim de lista
*/
EXT_PPC int recupera_postagem_nrr(int nrr, Postagem *postagem);

/**
*   @brief Procura sequencialmente pelo comentário pelo seu nrr e preenche um objeto com suas informações
*   @param nrr: posição do registro no arquivo
*   @param comentario: conterá as informações atuais do registro, deve vir alocado
*   @return Retorna o próximo nrr ou fim de lista
*/
EXT_PPC int recupera_comentario_nrr(int nrr, Comentario *comentario);

#endif /* PERSISTENCIA_PC_H */
