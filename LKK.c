#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * LAU-KATA-KATI
 * Mariano Oconitrilo Vega - 2021080289
 * Para jugar solo compile y ejecute este archivo
 */





/**
 * Estructura de los nodos que se usan para formar el tablero
 */
struct node {
    int position;
    int player;
    struct node *up;
    struct node *down;
    struct node *left;
    struct node *right;
    struct node *left_up;
    struct node *left_center;
    struct node *left_down;
    struct node *right_up;
    struct node *right_center;
    struct node *right_down;
};

/**
 * Funcion que inicializa y crea el nodo central del tablero
 * @return retorna un puntero a una estructura de nodo que va a ser el centro del tablero
 */
struct node *new_board() {

    struct node *new_node = NULL;
    new_node = calloc(1, sizeof(struct node));
    new_node->position = 1;
    new_node->player = 0;
    new_node->left_up = NULL;
    new_node->left_center = NULL;
    new_node->left_down = NULL;
    new_node->right_up = NULL;
    new_node->right_center = NULL;
    new_node->right_down = NULL;

    return new_node;
}

/**
 * Funcion que inicializa y creo los nodos del tablero
 * @param pos - Numero entero que va a ser la posicion del nodo en el tablero
 * @return - retorna un puntero a una estructura de nodo
 */
struct node *new_node(int pos) {

    struct node *new_node = NULL;
    new_node = calloc(1, sizeof(struct node));
    new_node->position = pos;
    new_node->player = 0;
    new_node->up = NULL;
    new_node->down = NULL;
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->left_up = NULL;
    new_node->left_center = NULL;
    new_node->left_down = NULL;
    new_node->right_up = NULL;
    new_node->right_center = NULL;
    new_node->right_down = NULL;

    return new_node;
}

/**
 * Funcion que inserta una columna del tablero a la izquierda
 * @param board - puntero a una estructura de nodo que es el centro del tablero
 * @param player - la ficha del jugador que se va a insetar
 */
void insertL_end(struct node *board, int player) {

    if (board == NULL) {
        return;
    } else {
        struct node *current = board->left_up;
        while (current != NULL) {
            if (current->left == NULL) {
                struct node *temp = current->down;
                struct node *temp2 = current->down->down;

                int pos = (temp2->position) + 1;
                struct node *new_node1 = new_node(pos++);
                new_node1->player = player;
                struct node *new_node2 = new_node(pos++);
                new_node2->player = player;
                struct node *new_node3 = new_node(pos++);
                new_node3->player = player;

                current->left = new_node1;
                temp->left = new_node2;
                temp2->left = new_node3;

                new_node1->right = current;
                new_node1->down = new_node2;

                new_node2->right = temp;
                new_node2->up = new_node1;
                new_node2->down = new_node3;

                new_node3->right = temp2;
                new_node3->up = new_node2;
                return;
            }
            current = current->left;
        }
    }
}

/**
 * Funcion que crea el lado izquierdo del tablero
 * @param board - puntero a una estructura de nodo que es el centro del tablero
 * @param depth - un numero entero que es la profundidad del tablero
 */
void leftSide(struct node *board, int depth) {

    int flag = depth - 3;
    int pos = 2;

    for (int i = 0; i < depth; i++) {

        if (i < flag && i == 0) {

            struct node *new_node1 = new_node(pos);
            pos++;
            struct node *new_node2 = new_node(pos);
            pos++;
            struct node *new_node3 = new_node(pos);

            board->left_up = new_node1;
            board->left_center = new_node2;
            board->left_down = new_node3;

            new_node1->right = board;
            new_node1->down = new_node2;

            new_node2->right = board;
            new_node2->up = new_node1;
            new_node2->down = new_node3;

            new_node3->right = board;
            new_node3->up = new_node2;
        } else if (i >= flag && i == 0) {

            struct node *new_node1 = new_node(pos);
            new_node1->player = 1;
            pos++;
            struct node *new_node2 = new_node(pos);
            new_node2->player = 1;
            pos++;
            struct node *new_node3 = new_node(pos);
            new_node3->player = 1;

            board->left_up = new_node1;
            board->left_center = new_node2;
            board->left_down = new_node3;

            new_node1->right = board;
            new_node1->down = new_node2;

            new_node2->right = board;
            new_node2->up = new_node1;
            new_node2->down = new_node3;

            new_node3->right = board;
            new_node3->up = new_node2;
        } else if (i < flag) {

            insertL_end(board, 0);
        } else {

            insertL_end(board, 1);
        }
    }
}

/**
 * Funcion que inserta una fila al final del lado derecho del tablero
 * @param board - puntero a una estructura de nodo que es el centro del tablero
 * @param player - numero entero que es la ficha del jugador que va en esa fila
 */
void insertR_end(struct node *board, int player) {

    if (board == NULL) {
        return;
    } else {
        struct node *current = board->right_up;
        while (current != NULL) {
            if (current->right == NULL) {

                struct node *temp = current->down;
                struct node *temp2 = current->down->down;

                int pos = (temp2->position) + 1;
                struct node *new_node1 = new_node(pos++);
                new_node1->player = player;
                struct node *new_node2 = new_node(pos++);
                new_node2->player = player;
                struct node *new_node3 = new_node(pos++);
                new_node3->player = player;

                current->right = new_node1;
                temp->right = new_node2;
                temp2->right = new_node3;

                new_node1->left = current;
                new_node1->down = new_node2;

                new_node2->left = temp;
                new_node2->up = new_node1;
                new_node2->down = new_node3;

                new_node3->left = temp2;
                new_node3->up = new_node2;
                return;
            }
            current = current->right;
        }
    }
}

/**
 * Funcion que crea el lado derecho del tablero
 * @param board - puntero a una estructura de nodo que es el centro del tablero
 * @param depth - numero entero que es la profundidad del tablero
 */
void rightSide(struct node *board, int depth) {
    int flag = depth - 3;
    int pos = (depth * 3) + 2;

    for (int i = 0; i < depth; i++) {

        if (i < flag && i == 0) {

            struct node *new_node1 = new_node(pos);
            pos++;
            struct node *new_node2 = new_node(pos);
            pos++;
            struct node *new_node3 = new_node(pos);

            board->right_up = new_node1;
            board->right_center = new_node2;
            board->right_down = new_node3;

            new_node1->left = board;
            new_node1->down = new_node2;

            new_node2->left = board;
            new_node2->up = new_node1;
            new_node2->down = new_node3;

            new_node3->left = board;
            new_node3->up = new_node2;
        } else if (i >= flag && i == 0) {

            struct node *new_node1 = new_node(pos);
            new_node1->player = 2;
            pos++;
            struct node *new_node2 = new_node(pos);
            new_node2->player = 2;
            pos++;
            struct node *new_node3 = new_node(pos);
            new_node3->player = 2;

            board->right_up = new_node1;
            board->right_center = new_node2;
            board->right_down = new_node3;

            new_node1->left = board;
            new_node1->down = new_node2;

            new_node2->left = board;
            new_node2->up = new_node1;
            new_node2->down = new_node3;

            new_node3->left = board;
            new_node3->up = new_node2;
        } else if (i < flag) {

            insertR_end(board, 0);
        } else {

            insertR_end(board, 2);
        }
    }
}

/**
 * Funcion que crea un nuevo juego, creando el tablero completo con sus fichas ya puestas y con n de profundidad
 * @param board - puntero a una estructura nodo que es el centro del tablero
 * @param depth - numero entero que es la profundidad del tablero
 * @return retorna 0 si se creo correctamente el tablero
 */
int new_game(struct node *board, int depth) {

    if (board == NULL) {
        return -1;
    } else {
        leftSide(board, depth);
        rightSide(board, depth);
    }

    return 0;
}

/**
 * Funcion que imprime tableros
 * @param board - un puntero a una estructura de nodo que es el centro del tablero
 */
void print_board(struct node *board) {

    struct node *temp = board->left_up;

    while (temp->left != NULL) {

        temp = temp->left;
    }

    struct node *temp2 = temp->down;
    struct node *temp3 = temp->down->down;

    while (temp->position != 1) {

        if (temp3->player == 1) {
            printf("\033[0;34m%d\033[0m", temp3->position);
        } else if (temp3->player == 2) {
            printf("\033[0;31m%d\033[0m", temp3->position);
        } else {
            printf("%d", temp3->position);
        }

        printf(" -- ");

        if (temp2->player == 1) {
            printf("\033[0;34m%d\033[0m", temp2->position);
        } else if (temp2->player == 2) {
            printf("\033[0;31m%d\033[0m", temp2->position);
        } else {
            printf("%d", temp2->position);
        }

        printf(" -- ");

        if (temp->player == 1) {
            printf("\033[0;34m%d\033[0m", temp->position);
        } else if (temp->player == 2) {
            printf("\033[0;31m%d\033[0m", temp->position);
        } else {
            printf("%d", temp->position);
        }

        printf("\n");
        if (temp->right->position == 1) {
            printf("\\    |    /\n");

            if (board->player == 1) {
                printf("     \033[0;34m%d\033[0m     \n", board->position);
            } else if (board->player == 2) {
                printf("     \033[0;31m%d\033[0m     \n", board->position);
            } else
                printf("     %d     \n", board->position);

            temp = temp->right;
            temp2 = temp2->right;
            temp3 = temp3->right;
        } else {
            printf("|     |    |\n");
            temp = temp->right;
            temp2 = temp2->right;
            temp3 = temp3->right;
        }
    }

    printf("/    |    \\\n");

    temp = board->right_up;
    temp2 = board->right_center;
    temp3 = board->right_down;

    while (temp != NULL) {

        if (temp3->player == 1) {
            printf("\033[0;34m%d\033[0m", temp3->position);
        } else if (temp3->player == 2) {
            printf("\033[0;31m%d\033[0m", temp3->position);
        } else {
            printf("%d", temp3->position);
        }

        printf(" -- ");

        if (temp2->player == 1) {
            printf("\033[0;34m%d\033[0m", temp2->position);
        } else if (temp2->player == 2) {
            printf("\033[0;31m%d\033[0m", temp2->position);
        } else {
            printf("%d", temp2->position);
        }

        printf(" -- ");

        if (temp->player == 1) {
            printf("\033[0;34m%d\033[0m", temp->position);
        } else if (temp->player == 2) {
            printf("\033[0;31m%d\033[0m", temp->position);
        } else {
            printf("%d", temp->position);
        }

        printf("\n");
        if (temp->right == NULL) {

            temp = temp->right;
            temp2 = temp2->right;
            temp3 = temp3->right;
        } else {
            printf("|     |     |\n");
            temp = temp->right;
            temp2 = temp2->right;
            temp3 = temp3->right;
        }
    }
}

/**
 * Funcion que busca nodos dentro del tablero
 * @param value - el valor de la posicion del nodo que se esta buscando
 * @param board - puntero a una estructura de nodo que es el centro del tablero
 * @param depth - la profundidad del tablero
 * @return retorna el puntero hacia el nodo con la posicion buscada si se encontro y si no NULL
 */
struct node *find_node(int value, struct node *board, int depth) {

    if (board == NULL) {
        return NULL;
    } else if (value == 1) {

        return board;
    } else if (value <= (depth * 3) + 1) {

        struct node *temp1 = board->left_up;
        struct node *temp2 = board->left_center;
        struct node *temp3 = board->left_down;

        while (temp1 != NULL) {
            if (temp1->position == value)
                return temp1;
            else if (temp2->position == value)
                return temp2;
            else if (temp3->position == value)
                return temp3;
            else {
                temp1 = temp1->left;
                temp2 = temp2->left;
                temp3 = temp3->left;
            }
        }

        return NULL;
    } else if (value > (depth * 3) + 1) {
        struct node *temp1 = board->right_up;
        struct node *temp2 = board->right_center;
        struct node *temp3 = board->right_down;

        while (temp1 != NULL) {
            if (temp1->position == value)
                return temp1;
            else if (temp2->position == value)
                return temp2;
            else if (temp3->position == value)
                return temp3;
            else {
                temp1 = temp1->right;
                temp2 = temp2->right;
                temp3 = temp3->right;
            }
        }

        return NULL;
    }
}

/**
 * Funcion que verifica si dos nodos son adyacentes en el tablero
 * @param node1 - un puntero a una estructura nodo
 * @param node2 - un punteroi a una estrucutra nodo
 * @return retorna 1 si los nodos son adyacenter y 1 si no lo son
 */
int isAdyacent(struct node *node1, struct node *node2) {

    if (node1->position == 1)
        return node1->left_up == node2 || node1->left_center == node2 || node1->left_down == node2 ||
               node1->right_up == node2 || node1->right_center == node2 || node1->right_down == node2;
    else return node1->left == node2 || node1->right == node2 || node1->up == node2 || node1->down == node2;
}

/**
 * Funcion que verifica si se puede comer una ficha en un movimiento
 * @param position1 - un puntero a una estructura de nodo
 * @param position2 - un puntero a una estructura de nodo
 * @param depth - numero entero que es la profundidad del tablero
 * @param player - numero entero que el judaor que efectuo el movimiento
 * @return retorna 1 si el jugador se puede comer la ficha del contrario y 0 si no
 */
int eat_token(struct node *position1, struct node *position2, int depth, int player) {

    int pos1 = position1->position;
    int pos2 = position2->position;

    //Si la posicion 1 es igual al centro del tablero
    if (pos1 == 1) {

        //Si la posicion 2 es al lado derecho del tablero
        if (pos2 > (depth * 3) + 1) {
            if (position2->left->player != player && position2->left->player != 0 &&
                position2->left->left == position1) {
                position1->player = 0;
                position2->left->player = 0;
                position2->player = player;
                return 1;
            }
            return 0;
        }
        //Si la posicion 2 es al lado izquierdo del tablero
        else if (pos2 <= (depth * 3) + 1) {
            if (position2->right->player != player && position2->right->player != 0 &&
                position2->right->right == position1) {
                position1->player = 0;
                position2->right->player = 0;
                position2->player = player;
                return 1;
            }
            return 0;
        }
        return 0;
    }

    //Si se va a comer una ficha y la posicion 2 es el centro
    else if (pos2 == 1) {

        //Lado derecho
        if (pos1 > (depth * 3) + 1) {
            if (position1->left->player != player && position1->left->player != 0 &&
                position1->left->left == position2) {
                position1->player = 0;
                position1->left->player = 0;
                position2->player = player;
                return 1;
            }
            return 0;
        }
        //Lado izquierdo
        if (pos1 <= (depth * 3) + 1) {
            if (position1->right->player != player && position1->right->player != 0 &&
                position1->right->right == position2) {
                position1->player = 0;
                position1->right->player = 0;
                position2->player = player;
                return 1;
            }
            return 0;
        }
        return 0;

    }
    // Si se come una ficha de un lado al otro, osea que pase por el centro, en este caso de izquieda a derecha
    else if (pos1 <= (depth * 3) + 1 && pos2 > (depth * 3) + 1) {

        if (pos1 == 2 && (depth * 3) + 4 == pos2) {
            if (position1->right->player != player && position1->right->player != 0) {
                position1->player = 0;
                position1->right->player = 0;
                position2->player = player;
                return 1;
            }
            return 0;
        } else if (pos1 == 3 && (depth * 3) + 3 == pos2) {
            if (position1->right->player != player && position1->right->player != 0) {
                position1->player = 0;
                position1->right->player = 0;
                position2->player = player;
                return 1;
            }
            return 0;
        } else if (pos1 == 4 && (depth * 3) + 2 == pos2) {
            if (position1->right->player != player && position1->right->player != 0) {
                position1->player = 0;
                position1->right->player = 0;
                position2->player = player;
                return 1;
            }
            return 0;
        }
        return 0;
    }
    // Se come una ficha de derecha a izquierda
    else if (pos1 > (depth * 3) + 1 && pos2 <= (depth * 3) + 1) {

        if (pos1 == (depth * 3) + 4 && pos2 == 2) {
            if (position1->left->player != player && position1->left->player != 0) {
                position1->player = 0;
                position1->left->player = 0;
                position2->player = player;
                return 1;
            }
            return 0;
        } else if (pos1 == (depth * 3) + 3 && pos2 == 3) {
            if (position1->left->player != player && position1->left->player != 0) {
                position1->player = 0;
                position1->left->player = 0;
                position2->player = player;
                return 1;
            }
            return 0;
        } else if (pos1 == (depth * 3) + 2 && pos2 == 4) {
            if (position1->left->player != player && position1->left->player != 0) {
                position1->player = 0;
                position1->left->player = 0;
                position2->player = player;
                return 1;
            }
            return 0;
        }
        return 0;
    }
    // Casos donde se puede comer al lado izquierdo
    else if (pos1 <= (depth * 3) + 1) {

        //Casos donde se come una ficha de izquierda a derecha o de abajo hacia arriba
        if (pos1 - pos2 > 0) {

            //Caso si se come en horizontal
            if (abs(pos1 - pos2) == 6) {
                if (position1->right->player != 0 && position1->right->player != player) {

                    position1->player = 0;
                    position1->right->player = 0;
                    position2->player = player;
                    return 1;
                }
                return 0;
            }

            //Caso donde se come en vertical
            else if (abs(pos1 - pos2) == 2) {

                if (position1->up->player != 0 && position1->up->player != player && position1->up->up != NULL) {
                    position1->player = 0;
                    position1->up->player = 0;
                    position2->player = player;
                    return 1;
                }
                return 0;

            }
            return 0;
        }

        //Casos donde se come una ficha de derecha a izquierda y de arriba hacia abajo
        else if (pos1 - pos2 < 0) {

            //Caso si se come en horizontal
            if (abs(pos1 - pos2) == 6) {
                if (position1->left->player != 0 && position1->left->player != player) {

                    position1->player = 0;
                    position1->left->player = 0;
                    position2->player = player;
                    return 1;
                }
                return 0;
            }

            //Caso si se come en vertical
            if (abs(pos1 - pos2) == 2) {

                if (position1->down->player != 0 && position1->down->player != player &&
                    position1->down->down != NULL) {
                    position1->player = 0;
                    position1->down->player = 0;
                    position2->player = player;
                    return 1;
                }
                return 0;


            }
            return 0;
        }
        return 0;
    }
    // Casos donde se puede comer al lado derecho
    else if (pos1 > (depth * 3) + 1) {

        // Casos donde se puede comer de derecha a izquierda y de abajo hacia arriba
        if (pos1 - pos2 > 0) {

            //Caso donde se come en horizontal
            if (abs(pos1 - pos2) == 6) {
                if (position1->left->player != 0 && position1->left->player != player) {

                    position1->player = 0;
                    position1->left->player = 0;
                    position2->player = player;
                    return 1;
                }
                return 0;
            }

            //Caso donde come en vertical
            if (abs(pos1 - pos2) == 2) {

                if (position1->up->player != 0 && position1->up->player != player && position1->up->up != NULL) {
                    position1->player = 0;
                    position1->up->player = 0;
                    position2->player = player;
                    return 1;
                }
                return 0;

            }
            return 0;
        }

        //Casos donde se puede comer de izquierda a derecha y de arriba hacia abajo
        else if (pos1 - pos2 < 0) {

            //Caso donde come en horizontal
            if (abs(pos1 - pos2) == 6) {
                if (position1->right->player != 0 && position1->right->player != player) {

                    position1->player = 0;
                    position1->right->player = 0;
                    position2->player = player;
                    return 1;
                }
                return 0;
            }

            //Caso donde se come en vertical
            if (abs(pos1 - pos2) == 2) {

                if (position1->down->player != 0 && position1->down->player != player &&
                    position1->down->down != NULL) {
                    position1->player = 0;
                    position1->down->player = 0;
                    position2->player = player;
                    return 1;
                }
                return 0;


            }
            return 0;
        }
        return 0;
    }
    return 0;
}


/**
 * Funcion que verifica si se puede mover una ficha
 * @param position1 - numero entero que es la posicion de la ficha del jugador que quiere mover
 * @param position2 - numero entero que es donde se quiere mover la ficha
 * @param player - numero entero que es el jugador que esta jugando actualmente
 * @param board - puntero hacia una estructura nodo que el centro del tablero
 * @param depth - numero entero que es la profundidad del tablero
 * @return 1 si no se pudo hacer el movimiento, 2 si el movimiento que se hizo fue el comer una ficha y 0 si solo se movio la ficha a un lugar adyacente
 */
int move_token(int position1, int position2, int player, struct node *board, int depth) {

    struct node *pos1 = find_node(position1, board, depth);
    struct node *pos2 = find_node(position2, board, depth);

    if (pos1->player != player) {
        printf("Movimiento invalido\n");
        return 1;
    } else if (pos2->player == 0) {
        if (isAdyacent(pos1, pos2)) {
            pos1->player = 0;
            pos2->player = player;
            return 0;
        } else if (eat_token(pos1, pos2, depth, player)) {
            return 2;
        } else return 1;
    } else {
        printf("Movimiento invalido\n");
        return 1;
    }
}

/**
 * Funcion que inicia el juego
 */
void start_game() {

    int depth;
    char input[100];
    printf("Ingrese la profundidad del tablero: ");
    fgets(input, sizeof(input), stdin);
    if (sscanf(input, "%d", &depth) != 1) {
        printf("Error: Debe ingresar un numero.\n");
        start_game();
    }

    struct node *board = new_board();
    new_game(board, depth);

    int actual_player = 0;
    printf("Que jugador va a empezar (1 o 2) ?: ");
    fgets(input, sizeof(input), stdin);
    if (sscanf(input, "%d", &actual_player) != 1) {
        printf("Error: Debe ingresar un numero.\n");
        return;
    }

    int token_p1 = 9;
    int token_p2 = 9;



    while (1) {
        printf("--------------------------\n");
        printf("\033[0;34mFichas del jugador 1: %d\033[0m  ||||  \033[0;31mFichas del jugador 2: %d\033[0m\n", token_p1, token_p2);
        print_board(board);
        printf("--------------------------\n");

        if (token_p1 == 0) {
            printf("\033[0;31mGana el jugador 2!!!!\033[0m\n");
            break;
        } else if (token_p2 == 0) {
            printf("\033[0;34mGana el jugador 1!!!!\033[0m\n");
            break;
        }

        printf("El judador acutal es el: %d\n", actual_player);
        printf("--------------------------\n");

        int x, y;
        char input[100];

        printf("Que ficha quiere mover?: ");
        fgets(input, sizeof(input), stdin);
        if (sscanf(input, "%d", &x) != 1) {
            printf("Error: Debe ingresar un numero.\n");
            continue;
        }

        printf("A que posicion la quiere mover?: ");
        fgets(input, sizeof(input), stdin);
        if (sscanf(input, "%d", &y) != 1) {
            printf("Error: Debe ingresar un numero.\n");
            continue;
        }


        if (x == y) printf("Escoga fichas diferentes\n");
        else if (x < 0 || x > (depth * 3 + 1) + (depth * 3 + 1) || y < 0 ||
                 y > (depth * 3 + 1) + (depth * 3 + 1)) {
            printf("Posiciones fuera de rango");
            continue;
        }

        int move = move_token(x, y, actual_player, board, depth);
        if (move == 1) continue;
        else if (move == 2) {
            if (actual_player == 1) token_p2--;
            else token_p1--;
            continue;
        } else {

            if (actual_player == 1) actual_player = 2;
            else actual_player = 1;
        }

    }
}


int main() {

    start_game();

    return 0;
}
