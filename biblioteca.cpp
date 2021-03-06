#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

class biblioteca{
    int numVertices;
    int numArestas = 0;
    int matriz;
    
    vector<vector<int>>grafo;
    public:
        biblioteca(int, int);
        // Insere Grafo
        void InsertGrafo(){
            int min = -1, max = -1, mediano = -1;
            float medio = 0;
            vector<int>graus(numVertices);
            int v,u;
            if(matriz == 1){
                vector<vector<int>>arestasMatriz(numVertices , vector<int>(numVertices ));
                while(cin >> v >> u){
                    numArestas += 1;
                    u--;
                    v--;
                    graus[u]++;
                    graus[v]++;
                    arestasMatriz[v][u] = 1;
                    arestasMatriz[u][v] = 1;
                }
                grafo = arestasMatriz;
            } else {
                vector<vector<int>>arestasLista(numVertices);
                while(cin >> v >> u){
                    numArestas += 1;
                    u--;
                    v--;
                    graus[u]++;
                    graus[v]++;
                    arestasLista[v].push_back(u);
                    arestasLista[u].push_back(v);
                }
                grafo = arestasLista;
                // int totalBytes = 0;
                // for(int v = 0; v < numVertices; v++){
                //     totalBytes += graus[v]*12;
                // }
                // cout << totalBytes << '\n';
            }
            sort(graus.begin(), graus.end());
            for(int g:graus){
                medio += g;
            }
            medio /= numVertices;
            max = graus[numVertices - 1];
            min = graus[0];
            int mid = numVertices/2;
            if(mid % 2 == 0){
                mediano = (graus[mid] +  graus[mid + 1])/2;
            } else {
                mediano =  graus[mid + 1];
            }
            FILE *arq;
            arq = fopen("saida.txt", "wt");
            fprintf(arq,"N??mero de V??rtices: %d \nN??meros de Arestas: %d \n", numVertices, numArestas);
            fprintf(arq,"Grau M??nimo: %d \nGrau M??ximo: %d \nGrau M??dio: %f \nMediana de Grau: %d \n", min, max, medio,  mediano);
            fclose(arq);

        };
        

        void GerarArquivoBusca(vector<int> &pai, vector<int> &nivel){
            FILE *arq;
            int i;
            int result;
         
            arq = fopen("resultado_busca.txt", "wt");
            for (i = 0; i < numVertices; i++)
            {
                result = fprintf(arq,"V??rtice %d: pai = %d e nivel = %d \n", i+1, pai[i] + 1, nivel[i]);  					  
                if (result == EOF)		    
                printf("Erro na Gravacao\n");
            }
            fclose(arq);
        };
        vector<int> dfs(int ini){
            ini--;
            vector<int>pai(numVertices, -1);
            vector<int>nivel(numVertices, -1);
            vector<int>marcado(numVertices, -1);
            stack<int>s;
            s.push(ini);
            nivel[ini] = 0;
            if(matriz == 0){
                while (!s.empty()){
                    int f = s.top();
                    s.pop();        
                    if(marcado[f] != -1) continue;    
                    marcado[f] = 1;
                    for(int vizinho:grafo[f]){
                        s.push(vizinho);
                        if(marcado[vizinho] == 1) continue;
                        pai[vizinho] = f;
                        nivel[vizinho] = nivel[f] + 1;
                        
                    }
                }
            }else{
                while (!s.empty()){
                    int f = s.top();
                    s.pop();
                    if(marcado[f] != -1) continue;  
                    marcado[f] = 1;
                    for(int i=0; i< numVertices; i++){
                        if(grafo[f][i] == 1){
                            s.push(i);
                            if(marcado[i] == 1) continue;
                            pai[i] = f;
                            nivel[i] = nivel[f] + 1;
                        }    
                    }
                }
               
            }
            GerarArquivoBusca(pai, nivel);
            return marcado;
        };
        
        void componentesConexos(int ini, vector<int> &componentes, vector<vector<int>> &vertices,int atualComponente){
            vector<int>marcado(numVertices, -1);
            stack<int>s;
            s.push(ini);

            if(matriz == 0){
                while (!s.empty()){
                    int f = s.top();
                    s.pop();        
                    if(marcado[f] != -1) continue;    
                    marcado[f] = 1;
                    componentes[f] = atualComponente;
                    vertices[atualComponente].push_back(f);
                    for(int vizinho:grafo[f]){
                        s.push(vizinho);
                    }
                }
            }else{
                while (!s.empty()){
                    int f = s.top();
                    s.pop();
                    if(marcado[f] != -1) continue;  
                    marcado[f] = 1;
                    componentes[f] = atualComponente;
                    vertices[atualComponente].push_back(f);
                    for(int i=0; i< numVertices; i++){
                        if(grafo[f][i] == 1){
                            s.push(i);
                        }    
                    }
                }
               
            }

        };       

        void Conexao(){
            int atualComponente;
            vector<vector<int>>vertices(numVertices);
            vector<int>componentes(numVertices, -1);
            atualComponente = 0;
            for(int i =0 ; i< numVertices; i++){
                if(componentes[i] == -1){
                    componentesConexos(i, componentes, vertices, atualComponente);
                    atualComponente += 1;
                }
            }

    
            FILE *arq;
            arq = fopen("Conexao.txt", "wt");
            int lenMaiorComp = -1;
            int lenMenorComp = numVertices + 1;
            sort(vertices.begin(), vertices.end(), [](vector<int> & a, vector<int> & b){ return b.size() < a.size(); });
            for(int i= 0; i < numVertices; i++){
                if(vertices[i].size() != 0){
                    fprintf(arq,"Componente conexo %d: ", i);
                    for(int v: vertices[i]){
                        fprintf(arq,"%d ", v+1);
                    }
                }

                fprintf(arq,"\n");
            }
            
            // cout << lenMaiorComp << '\n';
            // cout << lenMenorComp << '\n';
            fclose(arq);

        };


        vector<int> bfs(int ini){
            ini--;
            if(matriz == 0){
                vector<int>pai(numVertices, -1);
                vector<int>nivel(numVertices, -1);
                queue<int>q;
                q.push(ini);
                nivel[ini] = 0;
                while (!q.empty()){
                    int f = q.front();
      
                    q.pop();            
                    for(int vizinho:grafo[f]){
                        if(nivel[vizinho] != -1) continue;
                        pai[vizinho] = f;
                        nivel[vizinho] = nivel[f] + 1;
                        q.push(vizinho);
                    }
                }
                GerarArquivoBusca(pai, nivel);
                return nivel;
            }else{
                vector<int>pai(numVertices, -1);
                vector<int>nivel(numVertices, -1);
                queue<int>q;
                q.push(ini);
                nivel[ini] = 0;
                while (!q.empty()){
                    int f = q.front();
                    q.pop();
                    for(int i=0; i< numVertices; i++){
                        if(grafo[f][i] == 1){
                            if(nivel[i] != -1) continue;
                            pai[i] = f;
                            nivel[i] = nivel[f] + 1;
                            q.push(i);
                        }    
                    }
                }
                GerarArquivoBusca(pai, nivel);
                return nivel;
            }
                
    };

    int Distancia(int ini, int fim){
        vector<int> niveis = bfs(ini);
        FILE *arq;
        arq = fopen("Distancia.txt", "wt");
        fprintf(arq,"Dist??ncia entre %d e %d: %d\n",ini,fim, niveis[fim-1]);
        fclose(arq);
        return niveis[fim-1];
    }

    int Diametro(){
        int max = -1;
        for(int i = 1; i <= numVertices; i++){
            vector<int>niveis = bfs(i);
            for(int j = 1; j <= numVertices; j++){
                if(j != i){
                    int d = niveis[j-1];
                    if(d > max){
                        max = d;
                    }
                }
            }
        }
        FILE *arq;
        arq = fopen("Diametro.txt", "wt");
        fprintf(arq,"Diametro: %d\n",max);
        fclose(arq);
        return max;
    };
    int DiametroAproximativo(){
            
        int numAmostras = log2(numVertices);
        int diametro = -1;
        for (int i = 0; i < numAmostras; i++){
            srand(i);
            int verticeAleatorio =  (rand() % numVertices) + 1;
            vector<int>niveis = bfs(verticeAleatorio);
            for(int j = 0; j < numVertices; j++){
                diametro = max(niveis[j], diametro);
            }

        }
        FILE *arq;
        arq = fopen("Diametro_aproximado.txt", "wt");
        fprintf(arq,"Diametro Aproximado: %d\n",diametro);
        fclose(arq);
        return diametro;
    }
    void Tempo(){
        int segTotal;
        clock_t  inicio, fim;
        inicio = clock();
        for(int i = 0; i< 1000; i++){
            srand(i);
            int verticeAleatorio =  (rand() % numVertices) + 1;
            vector<int>niveis = dfs(verticeAleatorio);
        }

        fim = clock();
        segTotal = fim - inicio;
        cout << (segTotal)/1000 << "\n";

    };
};


biblioteca::biblioteca(int n, int m){
    numVertices = n;
    numArestas = numArestas;
    matriz = m;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int numVertices,u,v;
    cin >> numVertices;
    biblioteca grafo(numVertices, 0);
    grafo.InsertGrafo();
    grafo.bfs(2);
    grafo.dfs(2);
    grafo.Diametro();
    grafo.Distancia(2, 3);
    grafo.Diametro();
    grafo.DiametroAproximativo();
    grafo.Conexao();
    return 0;
}
