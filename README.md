# EP2EstruturaDeDados

## Documentação

### Funções Utilizadas para auxiliar na criaçao da árvore

#### Height

Essa função foi criada com o intuito de retornar a altura da árvore atual. A função anda por cada nó até os extremos da árvore, verifica qual é o maior lado dos extremos e retorna o tamanho.

#### getBalanceFactor

Essa função tem como objetivo pegar o fator de balanceamento da árvore, subtraindo o lado esquerdo da árvore pelo lado direito.

#### rotateLL e rotateRR

Função utilizada para fazer a rotação da árvore caso o fator de balanceamento dela esteja maior que 1 ou menor que -1.

### Criação das árvores

Para criação das árvores BSTs, foi criado uma struct contento os seguintes atributos: 

* Key - Utilizamos para guardar o valor do nó;
* Height - Para armazenar a altura da árvore futuramente;
* Node left - Para armazenar o filho esquerdo da raiz;
* Node right - Para armazenar o filho direito da raiz;

### Quais tipos de árvores foram feitas?

Fizemos dois tipos de árvores:

* BST;
* BST com AVL implementada;

#### BST

Para criação da árvore BST, utilizamos a função nwNode *createSamplesBST(nwNode nwNd, int key)*, dois parâmetros são recebidos, uma variável do tipo node(struct da árvore) e uma do tipo inteiro que é o número que será inserido.

Quando chamado a função, será verificado se a árvore é nula(se não tem nenhum nó armazenado), se for, a função retornará outra função que tem como objetivo inicializar uma nova árvore, mas se a árvore não for nula, será feito a verificação da chave(key) com uma estrutura condicional, analisando aonde será inserido a nova chave.

#### BST com AVL implementada

Para criação da BST com AVL implementada, quando a função *createSamplesBST(nwNode nwNd, int key)* for chamada, vai ser inserido o número do mesmo jeito que é inserido na BST, mas após isso é feito o cálculo do fator de balanceamento, e logo em seguida, a rotação, seja pra direita ou para esquerda assim formando uma BST com AVL.


### Lógica dos números randômicos

Quando o usuário insere quantos nós ele vai querer, é criado uma array com o tamanho da quantidade de nós, após isso é inserido valores estritamente crescentes dentro da array (EX.: 1, 2, 3, 4, 5...).

Antes dos números serem inseridos dentro da árvores, são gerados números aleatórios para serem usados como indices da array, para cada indice aleatório criado, é feito uma troca do número desse índice para os indices na sequencia certa.
