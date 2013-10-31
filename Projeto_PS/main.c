/**
*   Arquivo MAIN
ok
*/

/* Includes */
#include "Modulos\Apresentacao\Apresentacao.h"
#include "Modulos\Logica\Logica.h"
#include "Modulos\Persistencia\Persistencia_Produtos.h"
#include "Modulos\Persistencia\Persistencia_Usuario.h"
#include "Padroes.h"


int main() {

    int a;
    menu_inicial(&a);
    opcao_usuario(&a);
    return 0;

}
