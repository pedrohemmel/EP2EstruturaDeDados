// C program to insert a node in AVL tree
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h> 
#include <string.h>

/*STRUCTS*/

typedef struct node {
  int key;
  float height;

  struct node *left;
  struct node *right;
} Node;

typedef Node* nwNode;




/*FUNÇÕES*/ 

//Função que verifica qual lado é maior e retorna o memso
int maiorEntre(int esq, int dir) { return (esq > dir)? esq : dir; }






float height(nwNode nwNd) {
  if(nwNd == NULL) { return 0; }

  //retornar 1 + a função que vai checar qual lado será maior e retornar o tamanho(height) do mesmo
  return 1 + maiorEntre(height(nwNd->left), height(nwNd->right));
}





//Função que cria a árvore pela primeira vez caso ela seja nula
nwNode newNode(int key) {
  nwNode nwNd = (Node *)malloc(sizeof(Node *));

  nwNd->key = key;
  nwNd->left = NULL;
  nwNd->right = NULL;
  nwNd->height = 0;
  return nwNd;
}




//Função que insere dados em uma árvore BST
nwNode createSamplesBST(nwNode nwNd, int key) {
  
  if(nwNd == NULL) {
    nwNd = newNode(key);
  } else if(nwNd->key > key) {
    nwNd->left = createSamplesBST(nwNd->left, key);
  } else if(nwNd->key < key) {
    nwNd->right = createSamplesBST(nwNd->right, key);
  } else {
    printf("\nInserção não realizada! O elemento %d já existe!\n", key);
  }

  //recalcula a altura de todos os nós entre a raiz e o novo nó inserido
  nwNd->height = height(nwNd);
  
  return nwNd;
}






//Função que vai fazer a rotação RR da arvore
  nwNode rotateRR(nwNode nwNd) {
    //variaveis auxiliares para fazer a rotacao

    nwNode esqRaiz = nwNd->left;
    nwNode tRR = esqRaiz->right;

    //Rotação sendo feita
    esqRaiz->right = nwNd;
    nwNd->left = tRR;

    esqRaiz->height = height(esqRaiz);

    return esqRaiz;
  }






  nwNode rotateLL(nwNode nwNd) {
    //variaveis auxiliares para fazer a rotacao

    nwNode dirRaiz = nwNd->right;
    nwNode tLL = dirRaiz->left;

    //Rotação sendo feita
    dirRaiz->left = nwNd;
    nwNd->right = tLL;

    dirRaiz->height = height(dirRaiz);

    return dirRaiz;
  }






  //Função que pega o fator de balanceamento da arvore
  int getBalanceFactor(nwNode nwNd) {
    if(nwNd == NULL) {
      return 0;
    }
    return height(nwNd->left) - height(nwNd->right);
  }





  //Função que insere dados em uma árvore BST com AVL
  nwNode createSamplesAVL(nwNode nwNd, int key) {
    
    if(nwNd == NULL) {
      nwNd = newNode(key);
    } else if(nwNd->key > key) {
      nwNd->left = createSamplesAVL(nwNd->left, key);
    } else if(nwNd->key < key) {
      nwNd->right = createSamplesAVL(nwNd->right, key);
    } else {
      printf("\nInserção não realizada! O elemento %d já existe!\n", key);
    }
  
    //recalcula a altura de todos os nós entre a raiz e o novo nó inserido
    nwNd->height = height(nwNd);
    
    //Pegando o valor do fator de balanceamento para efetuar as rotações dentro das
    int balance = getBalanceFactor(nwNd);
  
    //Estrutura condicional para fazer a rotação da arvore
  
    //Caso RR
    if(balance > 1 && key < nwNd->left->key) {
      return rotateRR(nwNd);
    }
  
    //Caso LL
    if(balance < -1 && key > nwNd->right->key) {
      return rotateLL(nwNd);
    }
  
    //Caso RL
    if(balance < -1 && key < nwNd->right->key) {
      nwNd->right = rotateRR(nwNd->right);
      return rotateLL(nwNd);
    }
  
    if(balance > 1 && key > nwNd->left->key) {
      nwNd->left = rotateLL(nwNd->left);
      return rotateRR(nwNd);
    }
    
    return nwNd;
  }






//Função que irá imprimir as arvores em pré ordem
void preOrder(nwNode nwNd) {

  if(nwNd != NULL) {
    printf("| %d", nwNd->key);
    preOrder(nwNd->left);
    preOrder(nwNd->right);
  }
}





int findByKey(nwNode nwNd, int key) {
  if(nwNd != NULL) {
    if(nwNd->key == key) {
      return 1;
    }
    return 0 + findByKey(nwNd->left, key) + findByKey(nwNd->right, key);
  }

  return 0;
}




 
/* Driver program to test above function*/
int main(void)
{
  
  int decisao = 1;
  int numAmostras, numNos, swap;

  srand(time(NULL));

  printf("Menu 1) Nova simulação ou 2) Sair\n");
  scanf("%d", &decisao);

  while(decisao != 1 && decisao != 2) {
    printf("\nNúmero digitado inválido.\n");

    usleep(500000);

    printf("\nMenu 1) Nova simulação ou 2) Sair\n");
    scanf("%d", &decisao);
  }

  while(decisao == 1) {

    printf("\nBem vindo! Aqui você poderá criar quantas amostras de árvores BSTs e AVLs quiser!\n");

    sleep(1);
  
    printf("\nPrimeiramente digite a quantidade de amostras você quer: (Lembrando que cada amostra vai gerar uma árvore BST e uma AVL)\n");
    scanf("%d", &numAmostras);

    printf("\nBeleza.. Agora digite a quantidade de nós que cada amostra terá: ");
    scanf("%d", &numNos);

    
    //Setando a quantidade de indices da listRandomKey;
    int listRandomKey[numNos];

    //Setei um valor estritamente crescente na array listRandomKey para que possa ser feito o swap(troca) com os indices randomizados
    for(int i = 0; i < numNos; i++) {
      listRandomKey[i] = i + 1;
    }
    

    for(int i = 1; i <= numAmostras; i++) {
      //Criando as duas arvores (BST e BST AVL)
      nwNode nodeBST = NULL;
      nwNode nodeAVL = NULL;

      //Laço de repetição utilizado para trocar os números de forma aleatória
      for(int j = 0; j < numNos; j++) {

        //Gerando número aleatório que será utilizado como indice da array
        int randomNum = (rand() % numNos) + 1;

        //Realizando o swap do valor dos indices
        swap = listRandomKey[i];
        listRandomKey[i] = listRandomKey[randomNum];
        listRandomKey[randomNum] = swap;
      }

      printf("\n\n");

      //Criando variaveis que armazenaram o tempo de execução
      float tempoBST = 0.0; 
      float tempoAVL = 0.0; 
      float tempoMedioArvores = 0.0;

      //Laço de repetição que vai criar e tratar as árvores BST e AVL
      //Registrando o tempo que comecou e o tempo que terminou
      clock_t startBST = clock();
      for(int j = 0; j < numNos; j++) {      
        nodeBST = createSamplesBST(nodeBST, listRandomKey[j]);
      }
      clock_t endBST = clock(); 

      //Registrando o tempo que comecou e o tempo que terminou
      clock_t startAVL = clock();
      for(int j = 0; j < numNos; j++) {      
        nodeAVL = createSamplesAVL(nodeAVL, listRandomKey[j]);
      }
      clock_t endAVL = clock(); 

      //Calculando o tempo de execução das árvores
      tempoBST += (float)(endBST - startBST) / CLOCKS_PER_SEC;
      tempoAVL += (float)(endAVL - startAVL) / CLOCKS_PER_SEC;
      tempoMedioArvores += (tempoBST + tempoAVL)/2;

      printf("AMOSTRA %d || Nós: %d \n\n", i, numNos);

      sleep(1);
      
      printf("Binary Serach Tree\n\n");

      usleep(500000);
      
      preOrder(nodeBST);
      printf(" |");

      usleep(500000);

      printf("\n\n------------------------------\n\n");

      sleep(1);
      
      printf("Height Balancing Binary Search Tree\n\n");

      usleep(500000);
      
      preOrder(nodeAVL);
      printf(" |");

      usleep(500000);

      printf("\n\n------------------------------\n\n");

      usleep(500000);

      //Calculando media da altura das árvores
      double mediaAltura = (nodeBST->height + nodeAVL->height)/2;

      printf("Altura árvore BST: %f\n", nodeBST->height);
      printf("Tempo médio de construção da BST: %f\n", tempoBST);

      usleep(500000);
      
      printf("\nAltura árvore BST com AVL implementado: %f\n", nodeAVL->height);
      printf("Tempo médio de construção da AVL: %f\n", tempoAVL);

      usleep(500000);
      
      printf("\nAltura média das árvores: %f\n", mediaAltura);
      printf("Tempo médio de construção das duas árvores: %f", tempoMedioArvores);
      
      sleep(2);

      printf("\n\n\n");

    }


    printf("\nMenu 1) Nova simulação ou 2) Sair\n");
    scanf("%d", &decisao);



    while(decisao != 1 && decisao != 2) {
      printf("\nNúmero digitado inválido.\n");
  
      usleep(500000);
  
      printf("\nMenu 1) Nova simulação ou 2) Sair\n");
      scanf("%d", &decisao);
    }
    
    
  }

  printf("Obrigado e volte sempre!");
  
  
  
 
  return 0;
}