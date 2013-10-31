/**
* @file interface_def.h
* @brief Cont�m Prot�tipos das fun��es de interface_impl.c, al�m disso possui algumas macros.
* @author Charles Cardoso de Oliveira
* @version 1.4
* @date Cria��o: 28/12/2012
* @date Modifica��o 1: 02/01/2013
* @date Modifica��o 2: 08/01/2013
* @date Modifica��o 3: 15/01/2013
* @date Modifica��o 4: 03/02/2013
*/

#ifndef APRESENTACAO_H
#define APRESENTACAO_H

/* Includes */
#include "..\..\Padroes.h"
#include "..\Logica\Logica.h"

/* Prot�tipos das fun��es */
/* Parametros e retornos ainda n�o s�o definitivos */
/**
* @brief Listar� de uma vez os identificadores de todos os usu�rios.
*/
void lista_identificador_usuario();
/**
* @brief Listar� de uma vez os identificadores de todas as postagens.
*/
void lista_identificador_postagem();
/**
* @brief Listar� todo o conteudo relacionado a determinada postagem.
*/
void lista_texto_postagem();
/**
* @brief Fun��o Imprime menu principal.
*/
void menu_inicial(int *);
/**
* @brief Fun��o que invoca op��o do usu�rio.
*/
void opcao_usuario(int *);
void lista_comentario();
void deleta_comentario(int *);
void valida_usuario(int *);
void altera_cadastro(int *);
/**
* @brief Fun��o para cadastrar um novo usuario.
*/
void cadastro_usuario();
void descadastro_usuario(int *);
void postagem_usuario(int *);
void comenta_postagem(int *);
void avalia_postagem(int *);

#endif /* INTERFACE_H */
