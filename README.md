#### Problema

Implemente a inserção em uma árvore B de ordem d armazenada em disco. A chave da árvore é o código do cliente. A inserção é sempre feita em uma folha e, se a folha estiver cheia, ela deve ser particionada. O particionamento pode se propagar para os nós ancestrais e, se a raiz for particionada, uma nova raiz deve ser criada.

A lógica é a mesma da inserção em árvore B em memória principal vista anteriormente (funções posicao, busca, insere, particiona e insere\_folha). A diferença é que os nós estão gravados em arquivo e, portanto, precisam ser lidos do arquivo, modificados em memória e gravados de volta no arquivo.

A árvore é armazenada em dois arquivos:

- **Arquivo de metadados** (metadados.dat): contém a ordem d da árvore, o ponteiro para a raiz (pont\_raiz) e o ponteiro para a próxima posição livre do arquivo de dados (pont\_prox\_no\_livre). Uma árvore vazia tem pont\_raiz igual a -1.
- **Arquivo de dados** (clientes.dat): contém os nós da árvore. Cada nó guarda a quantidade de chaves (m), o ponteiro para o nó pai (pont\_pai), os ponteiros para os filhos (p) e os clientes. Ponteiros nulos valem -1.

Todos os ponteiros são posições (em bytes) dentro do arquivo de dados. Novos nós são sempre gravados no final do arquivo, na posição indicada por pont\_prox\_no\_livre.

O arquivo arvore\_b.c fornecido já contém as seguintes funções prontas:

- le\_no\_pos e salva\_no\_pos: leem e gravam um nó numa posição do arquivo de dados
- aloca\_no: reserva a posição de um novo nó no final do arquivo de dados e atualiza pont\_prox\_no\_livre
- atualiza\_pai: atualiza o ponteiro para o pai de um nó gravado no arquivo
- posicao: busca binária da posição em que a chave deveria estar dentro do nó
- busca: retorna a posição do nó onde a chave está, ou onde ela deveria estar

Vocês devem implementar as funções:

- void insere\_no(FILE \*arq, TMetadados \*md, int d, int ptNo, TNo \*no, int pos, TCliente \*cli, int pt): insere o cliente cli e o ponteiro da direita pt no nó no (gravado na posição ptNo). Se o nó estiver cheio, chama particiona. Ao final, o nó deve estar gravado no arquivo
- void particiona(FILE \*arq, TMetadados \*md, int d, int ptP, TNo \*P, int pos, TCliente \*cli, int pt): particiona o nó P, criando o nó Q no final do arquivo e, se P for a raiz, criando também a nova raiz W. A chave do meio sobe para o pai
- int insere(int cod\_cli, char \*nome\_cli, char \*nome\_arquivo\_metadados, char \*nome\_arquivo\_dados, int d): insere o cliente na árvore. Deve retornar a posição da raiz da árvore após a inserção, ou -1 se a chave já existir na árvore (nesse caso, nada é inserido). Ao final, o arquivo de metadados deve estar atualizado

Use o arquivo arvore\_b.c fornecido nesse exercício, pois ele já contém o tratamento de entrada e saída.

#### Entrada:
- Código do cliente a ser inserido
- Nome do cliente a ser inserido (sem espaços)
- Os arquivos metadados.dat e clientes.dat com a árvore inicial, que devem estar no diretório onde o programa é executado (eles não são lidos do teclado). Cada caso de teste fornece esses dois arquivos

#### Saída:
- A linha "PONT " seguida do valor retornado pela função insere
- A linha "ARQUIVO DE METADADOS:" seguida do conteúdo do arquivo de metadados após a inserção (d, pont\_raiz, pont\_prox\_no\_livre)
- A linha "ARQUIVO DE DADOS:" seguida de todos os nós do arquivo de dados após a inserção, na ordem em que estão gravados no arquivo. Cada nó é impresso como "NO: m, pont\_pai, (p0, p1, ..., p2d)", seguido dos seus clientes

## Exemplos:

Em todos os exemplos, d = 2 e cada nó ocupa 444 bytes no arquivo de dados. A coluna "Arquivos iniciais" mostra o conteúdo dos arquivos antes da inserção, no mesmo formato da saída.

### Exemplo 1

Caso de teste: [casos-teste/1](casos-teste/1)

Árvore vazia: a inserção cria a raiz.

|Arquivos iniciais|Entrada|Saída|
|---|---|---|
|ARQUIVO DE METADADOS:<BR/>2, -1, 0<BR/>ARQUIVO DE DADOS:|7<BR/>Bia|PONT 0<BR/>ARQUIVO DE METADADOS:<BR/>2, 0, 444<BR/>ARQUIVO DE DADOS:<BR/>NO: 1, -1, (-1, -1, -1, -1, -1) <BR/>&emsp;7, Bia|

### Exemplo 2

Caso de teste: [casos-teste/2](casos-teste/2)

Inserção em folha que não está cheia (nesse caso, a raiz).

|Arquivos iniciais|Entrada|Saída|
|---|---|---|
|ARQUIVO DE METADADOS:<BR/>2, 0, 444<BR/>ARQUIVO DE DADOS:<BR/>NO: 3, -1, (-1, -1, -1, -1, -1) <BR/>&emsp;10, Joao<BR/>&emsp;11, Vanessa<BR/>&emsp;13, Maria|12<BR/>Ana|PONT 0<BR/>ARQUIVO DE METADADOS:<BR/>2, 0, 444<BR/>ARQUIVO DE DADOS:<BR/>NO: 4, -1, (-1, -1, -1, -1, -1) <BR/>&emsp;10, Joao<BR/>&emsp;11, Vanessa<BR/>&emsp;12, Ana<BR/>&emsp;13, Maria|

### Exemplo 3

Caso de teste: [casos-teste/3](casos-teste/3)

A chave já existe na árvore: nada é inserido.

|Arquivos iniciais|Entrada|Saída|
|---|---|---|
|ARQUIVO DE METADADOS:<BR/>2, 0, 444<BR/>ARQUIVO DE DADOS:<BR/>NO: 3, -1, (-1, -1, -1, -1, -1) <BR/>&emsp;10, Joao<BR/>&emsp;11, Vanessa<BR/>&emsp;13, Maria|11<BR/>Ana|PONT -1<BR/>ARQUIVO DE METADADOS:<BR/>2, 0, 444<BR/>ARQUIVO DE DADOS:<BR/>NO: 3, -1, (-1, -1, -1, -1, -1) <BR/>&emsp;10, Joao<BR/>&emsp;11, Vanessa<BR/>&emsp;13, Maria|

### Exemplo 4

Caso de teste: [casos-teste/4](casos-teste/4)

A raiz está cheia: ela é particionada e uma nova raiz é criada.

|Arquivos iniciais|Entrada|Saída|
|---|---|---|
|ARQUIVO DE METADADOS:<BR/>2, 0, 444<BR/>ARQUIVO DE DADOS:<BR/>NO: 4, -1, (-1, -1, -1, -1, -1) <BR/>&emsp;10, Joao<BR/>&emsp;11, Vanessa<BR/>&emsp;12, Ana<BR/>&emsp;13, Maria|5<BR/>Bruno|PONT 888<BR/>ARQUIVO DE METADADOS:<BR/>2, 888, 1332<BR/>ARQUIVO DE DADOS:<BR/>NO: 2, 888, (-1, -1, -1, -1, -1) <BR/>&emsp;5, Bruno<BR/>&emsp;10, Joao<BR/>NO: 2, 888, (-1, -1, -1, -1, -1) <BR/>&emsp;12, Ana<BR/>&emsp;13, Maria<BR/>NO: 1, -1, (0, 444, -1, -1, -1) <BR/>&emsp;11, Vanessa|

### Exemplo 5

Caso de teste: [casos-teste/6](casos-teste/6)

A folha está cheia: ela é particionada e a chave do meio sobe para o pai.

|Arquivos iniciais|Entrada|Saída|
|---|---|---|
|ARQUIVO DE METADADOS:<BR/>2, 888, 1776<BR/>ARQUIVO DE DADOS:<BR/>NO: 4, 888, (-1, -1, -1, -1, -1) <BR/>&emsp;10, Ana<BR/>&emsp;15, Paulo<BR/>&emsp;20, Bia<BR/>&emsp;25, Rui<BR/>NO: 2, 888, (-1, -1, -1, -1, -1) <BR/>&emsp;40, Davi<BR/>&emsp;50, Eva<BR/>NO: 2, -1, (0, 444, 1332, -1, -1) <BR/>&emsp;30, Caio<BR/>&emsp;60, Fabio<BR/>NO: 2, 888, (-1, -1, -1, -1, -1) <BR/>&emsp;70, Gil<BR/>&emsp;80, Hugo|5<BR/>Bruno|PONT 888<BR/>ARQUIVO DE METADADOS:<BR/>2, 888, 2220<BR/>ARQUIVO DE DADOS:<BR/>NO: 2, 888, (-1, -1, -1, -1, -1) <BR/>&emsp;5, Bruno<BR/>&emsp;10, Ana<BR/>NO: 2, 888, (-1, -1, -1, -1, -1) <BR/>&emsp;40, Davi<BR/>&emsp;50, Eva<BR/>NO: 3, -1, (0, 1776, 444, 1332, -1) <BR/>&emsp;15, Paulo<BR/>&emsp;30, Caio<BR/>&emsp;60, Fabio<BR/>NO: 2, 888, (-1, -1, -1, -1, -1) <BR/>&emsp;70, Gil<BR/>&emsp;80, Hugo<BR/>NO: 2, 888, (-1, -1, -1, -1, -1) <BR/>&emsp;20, Bia<BR/>&emsp;25, Rui|

### Exemplo 6

Caso de teste: [casos-teste/7](casos-teste/7)

A folha e a raiz estão cheias: o particionamento se propaga até a raiz e uma nova raiz é criada.

|Arquivos iniciais|Entrada|Saída|
|---|---|---|
|ARQUIVO DE METADADOS:<BR/>2, 888, 2664<BR/>ARQUIVO DE DADOS:<BR/>NO: 4, 888, (-1, -1, -1, -1, -1) <BR/>&emsp;10, Ana<BR/>&emsp;15, Paulo<BR/>&emsp;20, Bia<BR/>&emsp;25, Rui<BR/>NO: 3, 888, (-1, -1, -1, -1, -1) <BR/>&emsp;35, Sara<BR/>&emsp;40, Davi<BR/>&emsp;50, Eva<BR/>NO: 4, -1, (0, 444, 1332, 1776, 2220) <BR/>&emsp;30, Caio<BR/>&emsp;60, Fabio<BR/>&emsp;90, Ivo<BR/>&emsp;120, Malu<BR/>NO: 2, 888, (-1, -1, -1, -1, -1) <BR/>&emsp;70, Gil<BR/>&emsp;80, Hugo<BR/>NO: 2, 888, (-1, -1, -1, -1, -1) <BR/>&emsp;100, Joao<BR/>&emsp;110, Lia<BR/>NO: 2, 888, (-1, -1, -1, -1, -1) <BR/>&emsp;130, Nina<BR/>&emsp;140, Otto|5<BR/>Bruno|PONT 3552<BR/>ARQUIVO DE METADADOS:<BR/>2, 3552, 3996<BR/>ARQUIVO DE DADOS:<BR/>NO: 2, 888, (-1, -1, -1, -1, -1) <BR/>&emsp;5, Bruno<BR/>&emsp;10, Ana<BR/>NO: 3, 888, (-1, -1, -1, -1, -1) <BR/>&emsp;35, Sara<BR/>&emsp;40, Davi<BR/>&emsp;50, Eva<BR/>NO: 2, 3552, (0, 2664, 444, -1, -1) <BR/>&emsp;15, Paulo<BR/>&emsp;30, Caio<BR/>NO: 2, 3108, (-1, -1, -1, -1, -1) <BR/>&emsp;70, Gil<BR/>&emsp;80, Hugo<BR/>NO: 2, 3108, (-1, -1, -1, -1, -1) <BR/>&emsp;100, Joao<BR/>&emsp;110, Lia<BR/>NO: 2, 3108, (-1, -1, -1, -1, -1) <BR/>&emsp;130, Nina<BR/>&emsp;140, Otto<BR/>NO: 2, 888, (-1, -1, -1, -1, -1) <BR/>&emsp;20, Bia<BR/>&emsp;25, Rui<BR/>NO: 2, 3552, (1332, 1776, 2220, -1, -1) <BR/>&emsp;90, Ivo<BR/>&emsp;120, Malu<BR/>NO: 1, -1, (888, 3108, -1, -1, -1) <BR/>&emsp;60, Fabio|

## Casos de teste:

Os casos de teste estão na pasta [casos-teste](casos-teste). Cada caso tem 4 arquivos:

- entrada.txt: o que deve ser digitado no teclado (código e nome do cliente)
- metadados.dat e clientes.dat: a árvore antes da inserção (arquivos binários)
- saida.txt: a saída esperada do programa

|Caso|Descrição|Entrada|Metadados|Dados|Saída esperada|
|---|---|---|---|---|---|
|[1](casos-teste/1)|Árvore vazia: a inserção cria a raiz|[entrada.txt](casos-teste/1/entrada.txt)|[metadados.dat](casos-teste/1/metadados.dat)|[clientes.dat](casos-teste/1/clientes.dat)|[saida.txt](casos-teste/1/saida.txt)|
|[2](casos-teste/2)|Inserção na raiz, que não está cheia|[entrada.txt](casos-teste/2/entrada.txt)|[metadados.dat](casos-teste/2/metadados.dat)|[clientes.dat](casos-teste/2/clientes.dat)|[saida.txt](casos-teste/2/saida.txt)|
|[3](casos-teste/3)|Chave já existe numa folha: nada é inserido|[entrada.txt](casos-teste/3/entrada.txt)|[metadados.dat](casos-teste/3/metadados.dat)|[clientes.dat](casos-teste/3/clientes.dat)|[saida.txt](casos-teste/3/saida.txt)|
|[4](casos-teste/4)|Raiz cheia: a raiz é particionada e uma nova raiz é criada|[entrada.txt](casos-teste/4/entrada.txt)|[metadados.dat](casos-teste/4/metadados.dat)|[clientes.dat](casos-teste/4/clientes.dat)|[saida.txt](casos-teste/4/saida.txt)|
|[5](casos-teste/5)|Inserção numa folha que não está cheia, numa árvore com 2 níveis|[entrada.txt](casos-teste/5/entrada.txt)|[metadados.dat](casos-teste/5/metadados.dat)|[clientes.dat](casos-teste/5/clientes.dat)|[saida.txt](casos-teste/5/saida.txt)|
|[6](casos-teste/6)|Folha cheia: a folha é particionada e a chave do meio sobe para o pai|[entrada.txt](casos-teste/6/entrada.txt)|[metadados.dat](casos-teste/6/metadados.dat)|[clientes.dat](casos-teste/6/clientes.dat)|[saida.txt](casos-teste/6/saida.txt)|
|[7](casos-teste/7)|Folha e raiz cheias: o particionamento se propaga até a raiz (inserção à esquerda)|[entrada.txt](casos-teste/7/entrada.txt)|[metadados.dat](casos-teste/7/metadados.dat)|[clientes.dat](casos-teste/7/clientes.dat)|[saida.txt](casos-teste/7/saida.txt)|
|[8](casos-teste/8)|Chave já existe num nó interno: nada é inserido|[entrada.txt](casos-teste/8/entrada.txt)|[metadados.dat](casos-teste/8/metadados.dat)|[clientes.dat](casos-teste/8/clientes.dat)|[saida.txt](casos-teste/8/saida.txt)|
|[9](casos-teste/9)|Folha e raiz cheias: o particionamento se propaga até a raiz (inserção à direita)|[entrada.txt](casos-teste/9/entrada.txt)|[metadados.dat](casos-teste/9/metadados.dat)|[clientes.dat](casos-teste/9/clientes.dat)|[saida.txt](casos-teste/9/saida.txt)|

### Como compilar e rodar os testes

O projeto tem um Makefile. Abra a pasta do projeto no VSCode e use o terminal integrado (menu Terminal > New Terminal). Os comandos abaixo devem ser executados na pasta do projeto:

|Comando|O que faz|
|---|---|
|`make`|Compila o programa, gerando o executável arvore\_b|
|`make test`|Roda todos os casos de teste e mostra quais passaram e quais falharam|
|`make caso N=4`|Roda apenas o caso 4 e mostra as diferenças entre a sua saída e a saída esperada|
|`make clean`|Apaga o executável e a pasta execucao|

No `make caso`, as linhas marcadas com < são da sua saída e as linhas marcadas com > são da saída esperada. A saída do seu programa fica gravada em execucao/saida\_obtida.txt.

Para usar o make é preciso ter o gcc e o make instalados. No Linux e no macOS eles normalmente já estão disponíveis (no macOS, instale as ferramentas de linha de comando com `xcode-select --install`, se necessário). No Windows, use o WSL ou o MSYS2.

**Atenção:** o programa lê e **altera** os arquivos metadados.dat e clientes.dat do diretório onde é executado. Os comandos `make test` e `make caso` copiam os arquivos .dat do caso para a pasta execucao antes de rodar o programa, então os arquivos da pasta casos-teste nunca são alterados. Se for rodar o programa manualmente (por exemplo, `./arvore_b` e digitar a entrada), copie antes os arquivos .dat do caso para o diretório de execução, e copie de novo antes de cada execução, senão o teste vai partir de uma árvore já modificada.

## Dicas Importantes:

- A entrada e a saída já são tratadas no arquivo fornecido para ler e imprimir os dados no formato esperado pela questão. Vocês devem APENAS implementar as funções solicitadas no problema
- Os arquivos metadados.c, no.c, cliente.c e lista\_nos.c (e seus respectivos .h) já contêm as funções para ler e gravar metadados, nós e clientes. Não é preciso alterá-los. As funções de arvore\_b.c estão declaradas em arvore\_b.h
- Abra o arquivo de dados no modo "rb+" para poder ler e gravar no mesmo arquivo. Se o arquivo ainda não existir (árvore vazia), abra no modo "wb+"
- Sempre que um nó mudar de pai (por exemplo, os filhos que passam de P para Q no particionamento), o ponteiro para o pai gravado no arquivo precisa ser atualizado (use atualiza\_pai)
- Grave P e Q no arquivo antes de inserir a chave que sobe no pai: se o pai também for particionado, os ponteiros para o pai de P e de Q serão atualizados diretamente no arquivo
- Ao particionar, coloque -1 nos ponteiros de P que deixaram de ser usados, pois todos os ponteiros do nó aparecem na saída
- Na saída, os clientes de cada nó aparecem precedidos de um caractere de tabulação, pois é assim que a função imprime\_cliente os imprime
