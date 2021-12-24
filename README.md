# Projeto 1 de Teoria dos Grafos
### Maria Luiza Cantanhede e Yasmin Forestti 

A bibliotaca de grafos criada pela dupla se encontra no arquivo "biblioteca.cpp". Essa biblioteca foi feita utilizando princípios de orientação a objetos.

## Como utilizar a bibliotaca

O primeiro passo é criar uma instância da classe com dois parâmetros: o número de vértices do grafo e o tipo de representação que será utilizada (1 para matriz e 0 para lista de adjacências).

```
biblioteca grafo(numVertices, 1);
```

### Métodos implementados:

- Inserção do grafo: este método não recebe parâmetros; ao ser executado, realiza a leitura das arestas do grafo no arquivo de entrada até a condição de EOF e gera um arquivo de texto (saida.txt) contendo número de vértices, números de arestas, grau mínimo, grau máximo, grau médio e mediana de grau: 12 

 ```
grafo.InsertGrafo();
```

- Busca em largura: este método executa uma busca em largura a partir do vértice inicial que é passado como parâmetro, retorna o vetor de níveis em que cada posição representa o nível do vértice de índice i na árvore geradora do vértice inicial e gera um arquivo de texto  (resultado_busca.txt) com essa árvore geradora.
```
grafo.bfs(2);
```
- Busca em Profundidade: este método executa uma busca em profundidade a partir do vértice inicial que é passado como parâmetro, retorna o vetor vértices marcados durante a busca em que cada posição indica se o vértice de índice i foi explorado pelo algorítmo e gera um arquivo de texto (resultado_busca.txt) com a árvore geradora da dfs.

```
grafo.dfs(2);
```
- Diâmetro: este método retorna o diâmetro do grafo e gera um arquivo de arquivo de texto (Diametro.txt) com esses valor.
```
grafo.Diametro();
```
- Distância: este método recebe dois vértices como parâmetro, retorna a distância entre eles e gera uma arquivo de texto (Distancia.txt) com essa informação.
```
grafo.Distancia(2, 3);
```
- Diâmetro aproximado: este método retorna o diâmetro aproximado do grafo e gera um arquivo de arquivo de texto (Diametro_aproximado.txt) com esses valor.
```
grafo.DiametroAproximativo();
```
- Verificação de componentes conexos: este método gera um arquivo de texto (Conexao.txt) contendo o número do componentes conexo e seus vértices integrantes.
```
grafo.Conexao();
```
