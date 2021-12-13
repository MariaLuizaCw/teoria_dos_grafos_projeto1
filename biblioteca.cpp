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
            if(matriz = 1){
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
            fprintf(arq,"Número de Vértices: %d \nNúmeros de Arestas: %d \n", numVertices, numArestas);
            fprintf(arq,"Grau Mínimo: %d \nGrau Máximo: %d \nGrau Médio: %f \nMediana de Grau: %d \n", min, max, medio,  mediano);
            fclose(arq);
        };
        

        int GerarArquivoBusca(vector<int> &pai, vector<int> &nivel){
            FILE *arq;
            int i;
            int result;
            // clrscr();
            arq = fopen("resultado_busca.txt", "wt");
            for (i = 0; i < numVertices; i++)
            {
                result = fprintf(arq,"Vértice %d: pai = %d e nivel = %d \n", i+1, pai[i] + 1, nivel[i]);  					  
                if (result == EOF)		    
                printf("Erro na Gravacao\n");
            }
            fclose(arq);
        };
        int bfs(int ini, int fim){
            ini--;
            fim--;
            vector<int>dist(numVertices, -1);
            vector<int>pai(numVertices, -1);
            vector<int>nivel(numVertices, -1);
            queue<int>q;
            q.push(ini);
            dist[ini] = 0;
            nivel[ini] = 0;
            while (!q.empty()){
                int f = q.front();
                q.pop();
                if(f == fim){
                    GerarArquivoBusca(pai, nivel);
                    return dist[fim];
                }
                
                for(int vizinho:grafo[f]){
                    if(dist[vizinho] != -1) continue;
                    dist[vizinho] = dist[f] + 1;
                    pai[vizinho] = f;
                    nivel[vizinho] = nivel[f] + 1;
                    q.push(vizinho);
                }
            }
        };

    int Distancia(int ini, int fim){
        return bfs(ini, fim);
    }

    int Diametro(){
        int max = -1;
        for(int i = 1; i <= numVertices; i++){
            for(int j = 1; j <= numVertices; j++){
                if(j != i){
                    int d = bfs(i, j);
                    if(d > max){
                        max = d;
                    }
                }
            }
        }
        return max;
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
    biblioteca teste(numVertices, 1);
    teste.InsertGrafo();
    // cout << teste.NumVertices() << " " << teste.NumArestas() << "\n";
    //cin >> u >> v;
    teste.bfs(1, 3);
    //cout << teste.Distancia(1,3)<< " " << teste.Diametro() << "\n";
    return 0;
}
