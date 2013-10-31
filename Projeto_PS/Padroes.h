
#ifndef PADROES_H
#define PADROES_H


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

/* Sucesso */
#define SUC_OPERACAO 0
#define SUC_FUNCAO 0
#define SUCESSO_LN 1
#define FRACASSO_LN 0

/* Erros de arquivo */
#define ERRO_ARQUIVO -5

/* Erros de existência */
#define INX_USUARIO -10
#define INX_POSTAGEM -11
#define INX_COMENTARIO -12

#define FIM_LISTA -9999
#define REG_ENABLE "00000"

#define DB_USUARIO "database_usuarios.txt"
#define DB_POSTCOM "database_postcom.txt"

#define TAM_REGUSUARIO 42

#define CTE_CABECALHO 6

/* Status de Usuario */
#define USUARIO_LOGADO 1
#define USUARIO_DESLOGADO 0

#endif /* CONVENCOES_H */
