/**
* @file interface_impl.c
* @brief Faz operações de output e input. Trabalhando diretamente com a Lógica de Negócio.
* @author Charles Cardoso de Oliveira
* @version 1.4
* @date Criação: 28/12/2012
* @date Modificação 1: 02/01/2013
* @date Modificação 2: 08/01/2013
* @date Modificação 3: 15/01/2013
* @date Modificação 4: 03/02/2013
*/

/* Includes */
#include "Apresentacao.h"

/*
 Função responsável por imprimir as funcionalidades do BLOG para o Usuário.
*/
void menu_inicial(int *estadoUsuario){

    printf("**************************************************************\n");
    printf("******************** SISTEMA DE PRODUTOS *********************\n");
    printf("**************************************************************\n");
    if (*estadoUsuario == USUARIO_LOGADO) {
    printf("VOCE ESTA LOGADO.\n");
    }
	printf("01 - LOGIN PARA LIDER DE PROJETO.\n");
	printf("02 - LOGIN DESENVOLVEDOR.\n");
	printf("03 - CADASTRAR DESENVOLVEDOR.\n");
    printf("04 - ALTERAR CADASTRO.\n");
    printf("05 - CADASTRAR UM PRODUTO.\n");
	printf("06 - ALTERAR UM PRODUTO.\n");
    printf("07 - CADASTRAR DEFEITO.\n");
    printf("08 - FECHAR UM PRODUTO.\n");
    printf("09 - LISTAR PRODUTOS.\n");
    //printf("10 - ENCERRAR SECAO (LOGOFF)\n");
    printf("10 - SAIR DO SISTEMA.\n");
    printf("**************************************************************\n");
}

/*
 Função responsável por invocar as diversas funções do BLOG dependendo da escolha do usuário.
*/
void opcao_usuario(int *estadoUsuario){
/* Declarações */
int opcaoUsuario;

    do{
    printf ("POR FAVOR ESCOLHA UMA OPCAO: ");
    scanf ("%d", &opcaoUsuario);
        switch(opcaoUsuario){
            case 1:
                system("CLS");
                login_liderProjeto();
                system("PAUSE");
                system("CLS");
                menu_inicial(estadoUsuario);
                break;
			case 2:
                system("CLS");
                login_desenvolvedor();
                system("PAUSE");
                system("CLS");
                menu_inicial(estadoUsuario);
                break;
			case 3:
                system("CLS");
                cadastro_desenvolvedor();
                system("PAUSE");
                system("CLS");
                menu_inicial(estadoUsuario);
                break;
            case 4:
                system("CLS");
                altera_desenvolvedor(estadoUsuario);
                system("PAUSE");
                system("CLS");
                menu_inicial(estadoUsuario);
                break;
            /*case 3:
                system("CLS");
                descadastro_usuario(estadoUsuario);
                system("PAUSE");
                system("CLS");
                menu_inicial(estadoUsuario);
                break;
            */
			case 5:
                system("CLS");
                cadastra_produto(estadoUsuario);
                system("PAUSE");
                system("CLS");
                menu_inicial(estadoUsuario);
                break;
            case 6:
                system("CLS");
                altera_produto(estadoUsuario);
                system("PAUSE");
                system("CLS");
                menu_inicial(estadoUsuario);
                break;
            case 7:
                system("CLS");
                cadastra_defeito();
                system("PAUSE");
                system("CLS");
                menu_inicial(estadoUsuario);
                break;
            case 8:
                system("CLS");
                fecha_produto();
                system("PAUSE");
                system("CLS");
                menu_inicial(estadoUsuario);
                break;
            case 9:
                system("CLS");
                lista_produtos();
                system("PAUSE");
                system("CLS");
                menu_inicial(estadoUsuario);
                break;
            /*case 10:
                system("CLS");
                lista_comentario();
                system("PAUSE");
                system("CLS");
                menu_inicial(estadoUsuario);
                break;*/
           /* case 10:
                system("CLS");
                deleta_comentario(estadoUsuario);
                system("PAUSE");
                system("CLS");
                menu_inicial(estadoUsuario);
                break;
            case 11:
                system("CLS");
                avalia_postagem(estadoUsuario);
                system("PAUSE");
                system("CLS");
                menu_inicial(estadoUsuario);
                break;
            case 12:
                system("CLS");
                valida_usuario(estadoUsuario);
                system("PAUSE");
                system("CLS");
                menu_inicial(estadoUsuario);
                break;
            case 13:
                system("CLS");
                break;*/
            case 10:
                system("CLS");
                printf("O SISTEMA FOI FECHADO COM SUCESSO.\n");
                system("PAUSE");
                break;
            default:
                system("CLS");
                printf("ERRO: OPCAO ESCOLHIDA NAO EXISTE.\n");
                system("PAUSE");
                system("CLS");
                menu_inicial(estadoUsuario);
                break;
        }
    }while(opcaoUsuario!=11);
}



/*
Recebe da lógica de Negócio um ponteiro de Postagem contendo todos as informações relacionadas a postagem.
E se a lista não for vazia, imprime todos essas informações (texto, nota, identificador, etc.).
*/
void lista_produtos(){
 /*Postagem *postagem;
 char identificadorPostagem[TAM_ID];

    printf("Digite o ID da postagem: ");
    scanf("%s", identificadorPostagem);
    postagem = preenche_texto_postagem(identificadorPostagem);
    if(postagem == NULL){
    printf("POSTAGEM NAO EXISTE.\n");
    }
    else{
    printf("TITULO: %s\t", postagem->titulo);
    printf("IDENTIFICADOR POSTAGEM: %s\n\n", postagem->identificador);
    printf("%s\n\n", postagem->conteudo);
    printf("IDENTIFICADOR USUARIO: %s\n", postagem->id_usuario);
    printf("MEDIA AVALIACAO POSTAGEM: %d\n", postagem->avaliacao);
    }
 */
}

/* Recebe da Lógica de Negócio um ponteiro do tipo Listagens contendo as informações de comentarios relacionados a uma postagem.
Se a lista não for vazia, imprime todas os comentários.
*/
void lista_comentario(){
 /*Listagens *listagens, *p;
 char identificadorPostagem[TAM_ID];

    printf("Digite o ID da postagem: ");
    scanf("%s", identificadorPostagem);
    listagens = preenche_listagens_comentario(identificadorPostagem);
    if (listagens == NULL){
    printf("NAO EXISTE NENHUM COMENTARIO RELACIONADO A ESTA POSTAGEM.\n");
    }
    else{
        for(p=listagens;p!=NULL;p=p->proximo){
        printf("%s\n\n", p->informacao);
        }
    }*/
}

/*Verifica se o usuario esta logado.
Se estiver logado recebe do identificador de postagem e de comentário e manda para a lógica de negócio.
Retorna resultado da operação.
*/
void fecha_produto(int *estadoUsuario){
/*int respostaLogica;
char identificadorPostagem[TAM_ID], identificadorComentario[TAM_ID];
    if(*estadoUsuario == USUARIO_DESLOGADO){
    printf("VOCE PRECISA ESTAR LOGADO PARA EXECUTAR ESSA ACAO.\n");
    }
    else{
    printf("Digite o identificador da postagem: ");
    scanf("%s", identificadorPostagem);
    printf("Digite o identificador do comentario: ");
    scanf("%s", identificadorComentario);
    respostaLogica = remove_comentario_usuario (identificadorUsuario, identificadorPostagem, identificadorComentario);
        if (respostaLogica == OP_SUCESSO){
        printf("O COMENTARIO FOI DELETADO COM SUCESSO.\n");
        }
        else{
        printf("IDENTIFICADOR DE POSTAGEM OU COMENTARIO INFORMADOS NAO EXISTE.\n");
        }
    }*/
}

/* Recebe do Usuario nome de usuario, senha e id e manda esses dados para a lógica de negócio.
Se estiverem corretos atualiza o estadoUsuario para USUARIO_LOGADO.
*/
void valida_usuario(int *estadoUsuario){
char nomeUsuario[TAM_NOME], senha[TAM_SENHA], identificador[TAM_ID];
int respostaLogica;

    printf("********** LOGIN **********\n");
    printf("Digite seu nome de usuario: ");
    scanf("%s", nomeUsuario);
    printf("Digite sua senha: ");
    scanf("%s", senha);
    printf("Digite o seu identificador: ");
    scanf("%s", identificador);
/* Manda para a Logica de Negocio */ respostaLogica = SUC_FUNCAO;

        if(respostaLogica == SUC_FUNCAO){
        *estadoUsuario = USUARIO_LOGADO;
        printf("VOCE AGORA ESTA LOGADO NO SISTEMA.\n");
        }
        else{
        printf("USUARIO OU SENHA INVALIDOS.\n");
        }
}

/*
 Função recebe os dados Nome de Usuário, Senha e Identificador do usuário.
 Passa esses dados para a lógica de negócio.
 E por fim informa ao usuário o resultado.
*/
void cadastro_desenvolvedor(){
/* Declarações */
char nomeUsuario[TAM_NOME], identificador[TAM_ID], senha[TAM_SENHA];
int respostaLogica;

    printf("********** CADASTRO DE USUARIO **********\n");
    printf("Digite seu nome de usuario (ate 10 digitos): ");
    scanf("%s", nomeUsuario);
    printf("Digite sua senha (ate 6 digitos): ");
    scanf("%s", senha);
    printf("Digite o seu identificador (ate 5 digitos): ");
    scanf("%s", identificador);
/*    respostaLogica = preenche_usuario(nomeUsuario, identificador, senha);*/
        if(respostaLogica == SUC_FUNCAO){
        printf("CADASTRO EFETUADO COM SUCESSO.\n");
        }
        else{
        printf("IDENTIFICADOR DE USUARIO JA EXISTE. POR FAVOR TENTE NOVAMENTE.\n");
        }
}

/* Verifica se o usuário está autenticado.
Se estiver logado o descadastra e altera o estadoUsuario para USUARIO_DESLOGADO.

void descadastro_usuario(int *estadoUsuario){
    if(*estadoUsuario == USUARIO_DESLOGADO){
    printf("VOCE PRECISA ESTAR LOGADO PARA EXECUTAR ESSA ACAO.\n");
    }
    else {
    /* respostaLogica = elimina_usuario(id); 
    printf ("SUA CONTA FOI DESCADASTRADA COM SUCESSO.\n");
    *estadoUsuario = USUARIO_DESLOGADO;
    }
}
*/
/* Verifica se o usuário está autenticado.
Se estiver recebe as novas informações do usuário e manda para a lógica.
Imprime resultado.
*/
void altera_desenvolvedor(int *estadoUsuario){
char novoNomeUsuario[TAM_NOME], novaSenha[TAM_SENHA];

    if(*estadoUsuario == USUARIO_DESLOGADO){
    printf("VOCE PRECISA ESTAR LOGADO PARA EXECUTAR ESSA ACAO.\n");
    }
    else{
    printf("Digite o novo nome de usuario:");
    scanf("%s", novoNomeUsuario);
    printf("Digite a nova senha:");
    scanf("%s", novaSenha);
    /* repostaLogica = atualiza_usuario(novoUsuario, id, novaSenha); */
    printf("SEUS DADOS FORAM ALTERADOS COM SUCESSO.\n");
    }
}

/* Verifica se o usuario esta autenticado.
Recebe os dados relacionados a postagem e manda para a lógica de negócio.
Imprime o resultado.
*/
void cadastra_produto(int *estadoUsuario){
char idPostagem[TAM_ID], textoPostagem[TAM_POST], tituloPostagem[TAM_TITULO];
char disponibilidade;

    if(estadoUsuario == USUARIO_DESLOGADO){
    printf("VOCE PRECISA ESTAR LOGADO PARA EXECUTAR ESSA ACAO.\n");
    }
    else{
    printf("Digite o ID da postagem: ");
    scanf("%s", idPostagem);
    printf("Digite o Titulo da postagem: ");
    scanf("%s", tituloPostagem);
    printf("Digite o texto da postagem:");
    scanf("%s", textoPostagem);
    printf("Esta postagem esta aberta a comentarios (S/N)?:");
    scanf("%c", &disponibilidade);
    /* respostaLogica = preenche_postagem(idUsuario, tituloPostagem, textoPostagem, idPostagem, toupper(disponibilidade)); */
    printf("SUA POSTAGEM FOI FEITA COM SUCESSO.\n");
    }
}

/* Verifica se o usuario está logado.
Verifica através da lógica de negócio se a postagem permite comentarios.
E se essas condições forem satisfeitas manda as informações relacionadas ao comentário para a lógica.
Imprime resultado.
*/
void comenta_postagem(int *estadoUsuario){
/*int validacaoComentario, respostaLogica;
char identificadorPostagem[TAM_ID], identificadorComentario[TAM_ID], textoPostagem[TAM_POST];

    if(estadoUsuario == USUARIO_DESLOGADO){
    printf("VOCE PRECISA ESTAR LOGADO PARA EXECUTAR ESSA ACAO.\n");
    }
    else{
    printf("Digite o indentificador da postagem: ");
    scanf("%s", identificadorPostagem);
    validacaoComentario = valida_comentario(identificadorPostagem);
        if (validacaoComentario == OP_SUCESSO){
        printf("Digite o identificador do comentario: ");
        scanf("%s", identificadorComentario);
        printf("Digite o texto do comentario: ");
        scanf("%[^\n]", textoPostagem);
        respostaLogica = preenche_comentario(identificadorUsuario, textoPostagem, identificadorComentario, identificadorPostagem);
            if (respostaLogica == OP_SUCESSO){
            printf("O SEU COMENTARIO FOI FEITO COM SUCESSO.\n");
            }
            else{
            printf("SEU COMENTARIO NAO PODE SER FEITO, TENTE OUTRA VEZ.\n");
            }
        }
        else{
        printf("A POSTAGEM QUE VOCE ESTA TENTANDO COMENTAR NAO PERMITE COMENTARIOS.\n");
        }
    }*/

}

/* Verifica se o usuario esta autenticado.
Pede o identificador da postagem.
Se essas condições forem verdadeiras manda a nota da postagem para a logica junto com outras informações.
Imprime resultado.
*/
void avalia_postagem(int *estadoUsuario){
/*int existePostagem, respostaLogica, notaPostagem;
char identificadorPostagem[TAM_ID];

    if(estadoUsuario == USUARIO_DESLOGADO){
    printf("VOCE PRECISA ESTAR LOGADO PARA EXECUTAR ESSA ACAO.\n");
    }
    else{
    printf("Digite o identificador da postagem que deseja avaliar: ");
    scanf("%s", identificadorPostagem);
    existePostagem = procura(identificadorPostagem);
        if(existePostagem == OP_SUCESSO){
        printf("Digite sua nota para essa postagem (0 a 5): ");
        scanf("%d", &notaPostagem);
        respostaLogica = atribui_avaliacao_postagem(notaPostagem, identificadorPostagem);
            if(respostaLogica == OP_SUCESSO){
            printf("SUA NOTA FOI ATRIBUIDA A POSTAGEM COM SUCESSO.\n");
            }
            else{
            printf("UM ERRO OCORREU E SUA NOTA NAO PODE SER ATRIBUIDA A POSTAGEM.\n");
            }
        }
        else{
        printf("NAO EXISTE POSTAGEM COM ESSE IDENTIFICADOR INFORMADO.\n");
        }
    }*/

}
