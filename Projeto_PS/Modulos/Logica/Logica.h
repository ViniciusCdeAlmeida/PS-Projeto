/**
*   @file logica_def.h
*   @brief Arquivo de defini��o da camada de L�gica de Neg�cio
*          M�dulo de L�gica de Neg�cio
*   @author Victor Quezado
*   @version 1.0
*   @date Cria��o: 28/12/2012
*   @date �ltima Modifica��o: 05/02/2013
*/

#ifndef LOGICA_H
#define LOGICA_H
#ifdef LOGICA_SERV
#define EXT_LOG
#else
#define EXT_LOG extern
#endif

/* Includes */
#include "..\..\Padroes.h"

/* Constantes de tamanho */
#define TAM_TITULO 11
#define TAM_NOME 11
#define TAM_SENHA 7
#define TAM_ID 6
#define TAM_POST 31
#define TAM_COMENT 21

/* Estruturas utilizadas */

/**
*   @brief Estrutura que define uma lista de strings
*/
/* Estruturas utilizadas */

/**
*   @brief Estrutura que define uma lista de strings
*/
typedef struct listagens{
    char *informacao;
    struct listagens *proximo;
} Listagens;

/**
*   @brief Estrutura que define um coment�rio
*/
typedef struct comentario {
    char idUsuario[TAM_ID],
         conteudo[TAM_COMENT],
         identificador[TAM_ID],
         identificadorPost[TAM_ID];
    int byteOffset;
    char* proxRelativoPostagem, proxRelativoUsuario;
} Comentario;

/**
*   @brief Estrutura que define uma postagem
*/
typedef struct postagem {
    char idUsuario[TAM_ID],
         titulo[TAM_TITULO],
         conteudo[TAM_POST],
         identificador[TAM_ID],
         permissaoComentario;
    int avaliacaoSoma, avaliacaoQuantidade;
    int dia, mes, ano;
    int quantidadeComentarios;
    int byteOffset;
    char* primComentario, proxRelativoUsuario;
} Postagem;

/**
*   @brief Estrutura que define um usu�rio
*/
typedef struct usuario {
    char nome[TAM_NOME],
         senha[TAM_SENHA],
         identificador[TAM_ID];
    int byteOffset;
    char* primPostagem, primComentario;
} Usuario;

/**Fun��es de manipula��o da lista*/
//lembrando que n estao completas nos prototipos e tem de haver uma revis�o da l�gica destes prototipos
/**
*   @brief cria uma estrutura de dados do tipo "lista" vazia
*   @param <nada>
*   @return retorna uma lista vazia
*/
EXT_LOG Listagens* cria_lista();//OK

/**
*   @brief insere elementos do tipo string dentro da lista
*   @param lista:estrutura de dados do tipo lista(vazia ou n�o)
*   @param info: uma string contendo a informa��o que se quer armazenar
*   @return retorna a lista inicial mais o elemento(info)
*/
EXT_LOG Listagens* insere_lista(Listagens* lista, char* info);//OK

/**
*   @brief deleta da mem�ria a lista desejada
*   @param lista: estrutura de dados do tipo lista
*   @return <nada>
*/
EXT_LOG void deleta_lista(Listagens* lista);//OK


/**Fun��es de requisitos funcionais*/

/**
*   @brief fornece os dados de usu�rio, devidamente encaixados dentro da estrutura, para a persist�ncia
*   @param name:nome do usu�rio
*   @param ID:identificador do usu�rio
*   @param senha:senha de acesso do usu�rio
*   @return retorna se foi bem sucedido ou n�o
*/
EXT_LOG int preenche_usuario(char* name,char* ID,char* senha);//OK?

/**
*   @brief procura o usu�rio desejado
*   @param ID: identificador do usu�rio a ser pesquisado
*   @return retorna uma estrutura de dados do tipo usu�rio com as informa��es do usu�rio
*/
EXT_LOG Usuario* procura_usuario(char* ID);//OK, ajuste no retorno da fun��o recupera

/**
*   @brief procura a postagem desejada
*   @param ID:identificador da postagem
*   @param post:estrutura de dados que aramzenar� as informa��es da postagem
*   @return retorna uma estrutura de dados do tipo postagem com as informa��es da postagem
*/
EXT_LOG Postagem* procura_postagem(char* ID);//OK?

/**
*   @brief procura o comentario desejado
*   @param ID:identificador do coment�rio
*   @param coment:estrutura de dados que armazenar� as informa��es do coment�rio
*   @return retorna uma estrutura de dados do tipo coment�rio com as informa��es do coment�rio
*/
EXT_LOG Comentario* procura_comentario(char* ID);//OK?

/**
*   @brief descadastra o usu�rio
*   @param ID:identificador do usu�rio que queira se descadastrar
*   @return retorna se foi bem sucedido ou n�o
*/
EXT_LOG int descadastro(char* ID);

/**
*   @brief fornece as novas informa��es do usu�rio a serem atualidas na persist�ncia
*   @param novoUser: novo nome de usu�rio
*   @param novaSenha: nova senha de acesso do usu�rio
*   @param ID:identificador do usu�rio(fixo, portanto n�o ser� alterado)
*   @return retorna se foi bem sucedido ou n�o
*/
EXT_LOG int atualiza(char* novoUser, char* novaSenha, char* ID);//incompleto

/**
*   @brief elimina usuario
*   @param ID:identificador do usu�rio a ser eliminado
*   @return retorna se foi bem sucedido ou n�o
*/
EXT_LOG int elimina_usuario(char* ID);

/**
*   @brief armazena as informa��es dentro da estrutura Postagem e envia para a persist�ncia
*   @param ID_User: identificador do usu�rio
*   @param Titulo: t�tulo da postagem
*   @param Texto: conte�do da postagem
*   @param identificador: identificador da postagem
*   @param validacao: permiss�o de haver coment�rio
*   @return retorna se houve sucesso ou n�o
*/
EXT_LOG int preenche_postagem(char* ID_User,char* Titulo,char* Texto,char* identificador,char validacao);

/**
*   @brief verifica se pode haver um comentario na postagem
*   @param ID_Postagem: identificador da postagem
*   @return retorna se houve sucesso ou n�o
*/
EXT_LOG int valida_comentario(char* ID_Postagem);

/**
*   @brief aramzena as informa��es dentro da estrutura Comentarios
*   @param id_user: identificador do usu�rio que realizar� o coment�rio
*   @param conteudo: texto do coment�rio
*   @param ID: identificador do coment�rio
*   @param id_post: identificador da postagem onde ser� feito o coment�rio
*   @return retorna se foi sucesso ou n�o
*/
EXT_LOG int preenche_comentario(char* id_user,char* conteudo, char* ID, char* id_post);

/**
*   @brief cria uma lista contendo todos os identificadores dos usu�rios cadastrados
*   @param <nada>
*   @return lista contendo os identificadores
*/
EXT_LOG Listagens* preenche_listagens_usuario();

/**
*   @brief cria uma lista com todas as postagens daquele usu�rio
*   @param ID:identificador do usu�rio a ser pesquisado
*   @return lista contendo os identificadore das postagens
*/
EXT_LOG Listagens* preenche_listagens_postagem(char* ID);

/**
*   @brief cria uma lista de todos os coment�rios relacionados a uma certa postagem
*   @param ID_Post:identificador da postagem
*   @return lista contendo os identificadores
*/
EXT_LOG Listagens* preenche_listagens_comentario(char * ID_Post);

/**
*   @brief remove um certo comentario
*   @param ID_User:identificador de usu�rio
*   @param ID_Post:identificador da postagem
*   @param ID_Coment:identificador do coment�rio
*   @return retorna se houve sucesso ou n�o
*/
EXT_LOG int remove_comentario_usuario(char* ID_User,char* ID_Post,char* ID_Coment);

/**
*   @brief calcula a m�dia da avalia��o de uma certa postagem
*   @param nota: nova nota atribu�da �quela postagem
*   @param ID_Post:identificador da postagem
*   @return retorna se houve secesso ou n�o
*/
EXT_LOG int atribui_avaliacao_postagem(int nota, char* ID_Post);

#endif /* LOGICA_H */
