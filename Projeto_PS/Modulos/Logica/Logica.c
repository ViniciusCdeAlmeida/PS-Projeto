

/* Includes ok */


#define LOGICA_SERV
#include "Logica.h"
#include "..\Persistencia\Persistencia_Produtos.h"
#include "..\Persistencia\Persistencia_Usuario.h"
//Funções de Manipulação de lista
Listagens* cria_lista(){
    return NULL;
}

Listagens* insere_lista(Listagens* lista, char* info){
    Listagens* novo=(Listagens*)malloc(sizeof(Listagens));
    novo->informacao=info;
    novo->proximo=lista;
    return novo;
}

void deleta_lista(Listagens* lista){
    Listagens* p=lista;
    while(p!=NULL){
        Listagens* t=p->proximo;
        free(p);
        p=t;
    }
}
//Funções de procura
Usuario* procura_usuario(char* ID){
    int temp;
    Usuario* user;
    temp=recupera_usuario(ID,user);
    if(temp==INX_USUARIO) return NULL;
    return user;
}

Postagem* procura_postagem(char* ID){
    int temp;
    Postagem* post;
    temp=recupera_postagem(ID,post);
    if(temp==INX_POSTAGEM) return NULL;
    return post;
}

Comentario* procura_comentario(char* ID){
    int temp;
    Comentario* coment;
    temp=recupera_comentario(ID,coment);
    if(temp==INX_COMENTARIO) return NULL;
    return coment;
}

int descadastro(char* ID){

}

int elimina_usuario(char* ID){

}

int atualiza(char* novoUser, char* novaSenha, char* ID){
    Usuario *user=(Usuario*)malloc(sizeof(Usuario));
    user=procura_usuario(ID);
    if(user==NULL) return FRACASSO_LN;
    else preenche_usuario(novoUser,ID,novaSenha);//como enviar o byteoffset??
}

int preenche_usuario(char* name, char* ID, char* senha){
    Usuario *user=(Usuario *)malloc(sizeof(Usuario));
    user=procura_usuario(ID);
    if(user!=NULL){
        strcpy(user->nome,name);
        strcpy(user->identificador,ID);
        strcpy(user->senha,senha);
        if(armazena_usuario(user)){
            free(user);
            return SUCESSO_LN;
        }else{
            free(user);
            return FRACASSO_LN;
        }
    }
    free(user);
    return FRACASSO_LN;
}

int preenche_postagem(char* ID_User,char* Titulo,char* texto,char* Identificador,char validacao){
    Postagem *post=(Postagem *)malloc(sizeof(Postagem));
    Usuario *user=(Usuario *)malloc(sizeof(Usuario));
    user=procura_usuario(ID_User);
    post=procura_postagem(Identificador);
    if(user!=NULL){
        if(post!=NULL){
            strcpy(post->idUsuario,ID_User);
            strcpy(post->titulo,Titulo);
            strcpy(post->identificador,Identificador);
            strcpy(post->conteudo,texto);
            post->avaliacaoSoma=0;
            post->avaliacaoQuantidade=0;
            post->permissaoComentario=validacao;
            if(user->primPostagem==NULL) user->primPostagem=post->identificador;
            if(armazena_postagem(post)){
                free(post);
                return SUCESSO_LN;
            }else{
                printf("Houve uma falha no armazenamento\n");
                free(post);
                return FRACASSO_LN;
            }
        }else{
            printf("Identificador de postagem jah existente!\n");
        }
        free(post);
        return FRACASSO_LN;
    }else{
        printf("Usuario nao encontrado!\n");
        return FRACASSO_LN;
    }
}

int valida_comentario(char* ID_Postagem){
    Postagem* post;
    post=procura_postagem(ID_Postagem);
    if(post!=NULL){
        if(post->permissaoComentario=='S') return SUCESSO_LN;
    }
    return FRACASSO_LN;
}

/*int preenche_comentario(char* id_user,char* texto, char* ID, char* id_post){
    Comentario *coment=(Comentario *)malloc(sizeof(Comentario));
    Usuario *user=(Usuario *)malloc(sizeof(Usuario));
    user=procura_usuario(id_user);
    coment=procura_comentario(ID);
    if(user!=NULL){
        if(coment!=NULL){
            strcpy(coment->idUsuario,id_user);
            strcpy(coment->identificadorPost,id_post);
            strcpy(coment->identificador,ID);
            strcpy(coment->conteudo,texto);
            if(user->primComentario==NULL) 
                user->primComentario = coment->identificador;
            if(armazena_comentario(coment)){
                free(coment);
                return SUCESSO_LN;
            }else{
                free(coment);
                //Ocorreu um erro ao tentar armazenar o comentario
                return FRACASSO_LN;
            }
        }else{
            //Identificador de comentario jah existente
            free(coment);
            return FRACASSO_LN;
        }
    }else{
        //Usuario nao encontrado
        return FRACASSO_LN;
    }
}
*/
Listagens* preenche_listagens_usuario(){//ainda incompleta
    int i=1, temp;
    Usuario* user;
    Listagens* lista=cria_lista();
    do{
        temp=recupera_usuario_nrr(i,user);
        lista=insere_lista(lista,user->identificador);
        i++;
    }while(temp!=INX_USUARIO);
    return lista;
}
/*
Listagens* preenche_listagens_postagem(char* ID){
    Listagens* lista=cria_lista();
    Usuario *user=(Usuario *)malloc(sizeof(Usuario));
    Postagem *post=(Postagem *)malloc(sizeof(Postagem));
    char* id_postagem;
    user=procura_usuario(ID);
    id_postagem=user->primPostagem;
    insere_lista(lista,id_postagem);
    if(id_postagem!=NULL){
        do{
            recupera_postagem(id_postagem,post);
            id_postagem = post->proxRelativoUsuario;
            insere_lista(lista,id_postagem);
        }while(id_postagem==NULL);
    }else printf("O usuario nao possui postagens!\n");
    return lista;
}
*/
Listagens* preenche_listagens_comentario(char *ID_Post){
    Listagens* lista=cria_lista();
    Postagem *post=(Postagem *)malloc(sizeof(Postagem));
    Comentario *coment=(Comentario *)malloc(sizeof(Comentario));
    post=procura_postagem(ID_Post);
    char* id_comentario;
    id_comentario=post->primComentario;
    insere_lista(lista,id_comentario);
    if(id_comentario!=NULL){
        do{
            recupera_postagem(id_comentario,post);
            id_comentario=coment->proxRelativoPostagem;
            insere_lista(lista,id_comentario);
        }while(id_comentario==NULL);
    }else printf("O usuario nao possui postagens!\n");
    return lista;
}

int remove_comentario_usuario(char* ID_User,char* ID_Post,char* ID_Coment){

}

int atribui_avaliacao_postagem(int nota, char* ID_Post){
    Postagem *post=(Postagem *)malloc(sizeof(Postagem));
    post=procura_postagem(ID_Post);
    post->avaliacaoQuantidade++;
    post->avaliacaoSoma+=nota;
    armazena_postagem(post);
    return SUCESSO_LN;
}
