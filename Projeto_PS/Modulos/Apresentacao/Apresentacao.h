/**
* @file interface_def.h
* @brief Contém Protótipos das funções de interface_impl.c, além disso possui algumas macros.
* @author Charles Cardoso de Oliveira
* @version 1.4
* @date Criação: 28/12/2012
* @date Modificação 1: 02/01/2013
* @date Modificação 2: 08/01/2013
* @date Modificação 3: 15/01/2013
* @date Modificação 4: 03/02/2013
*/

#ifndef APRESENTACAO_H
#define APRESENTACAO_H

/* Includes */
#include "..\..\Padroes.h"
#include "..\Logica\Logica.h"

/* Protótipos das funções */
/* Parametros e retornos ainda não são definitivos */
/**
* @brief Listará de uma vez os identificadores de todos os usuários.
*/
void lista_identificador_usuario();
/**
* @brief Listará de uma vez os identificadores de todas as postagens.
*/
void lista_identificador_postagem();
/**
* @brief Listará todo o conteudo relacionado a determinada postagem.
*/
void lista_texto_postagem();
/**
* @brief Função Imprime menu principal.
*/
void menu_inicial(int *);
/**
* @brief Função que invoca opção do usuário.
*/
void opcao_usuario(int *);
void lista_comentario();
void deleta_comentario(int *);
void valida_usuario(int *);
void altera_cadastro(int *);
/**
* @brief Função para cadastrar um novo usuario.
*/
void cadastro_usuario();
void descadastro_usuario(int *);
void postagem_usuario(int *);
void comenta_postagem(int *);
void avalia_postagem(int *);

#endif /* INTERFACE_H */
