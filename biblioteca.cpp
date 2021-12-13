#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

class biblioteca{
    int numVertices;
    int numArestas = 0;
    vector<vector<int>>VetorAdj;
    vector<vector<int>>MatrizAdj;

    public:
        biblioteca(int);

        void InsertGrafo(){
            vector<vector<int>>arestasGrafo(numVertices);
            vector<vector<int>>arestasMatriz(numVertices , vector<int>(numVertices ));
            
            int v,u;
            while(cin >> v >> u){
                numArestas += 1;
                u--;
                v--;

                arestasMatriz[v][u] = 1;
                arestasMatriz[u][v] = 1;

                arestasGrafo[v].push_back(u);
                arestasGrafo[u].push_back(v);

            }
            MatrizAdj = arestasMatriz;  
            VetorAdj = arestasGrafo;
        };
        
        int ImprimeMatrizAdj(){
            for(int i =0; i< numVertices; i++){
                for (int j = 0; j < numVertices; j++){
                    cout << MatrizAdj[i][j] << " ";
                }
                cout << "\n";
            }
        };

        int ImprimeVetorAdj(){
            for(int i = 0; i < numVertices; i++){
                cout << i << "->";
                for(int j: VetorAdj[i]){
                     cout << j << ", ";
                }
                cout << "\n";
            }
        };

        int NumArestas(){
            return numArestas;
        };

        int NumVertices(){
            return numVertices;
        };

        int bfs(int ini, int fim){

            vector<int>dist(numVertices, -1);
    
            // memset(dist, -1, numVertices);
            queue<int>q;
            q.push(ini);
            dist[ini] = 0;
            while (!q.empty()){
                int f = q.front();
                q.pop();
                if(f == fim){
                    return dist[fim];
                }
                
                for(int vizinho:VetorAdj[f]){
                    if(dist[vizinho] != -1) continue;
                    dist[vizinho] = dist[f] + 1;
                    q.push(vizinho);
                }
            }
        };

    int Distancia(int ini, int fim){
        ini--;
        fim--;
        return bfs(ini, fim);
    }

    int Diametro(){
        int max = -1;
        for(int i = 0; i < numVertices; i++){
            for(int j = 0; j < numVertices; j++){
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

biblioteca::biblioteca(int n){
    numVertices = n;
    numArestas = numArestas;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int numVertices,u,v;
    cin >> numVertices;
    biblioteca teste(numVertices);
    teste.InsertGrafo();
    cout << teste.NumVertices() << " " << teste.NumArestas() << "\n";
    teste.ImprimeMatrizAdj();
    teste.ImprimeVetorAdj();
    //cin >> u >> v;
    cout << teste.Diametro() << '\n';
    //cout << teste.Distancia(1,3)<< " " << teste.Diametro() << "\n";
    return 0;
}
