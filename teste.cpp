#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <bits/stdc++.h>
using namespace std;




int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int numVertices = 10;
    vector<vector<int>>arestasMatriz(numVertices);
    for(int i = 0; i < numVertices; i++){

        arestasMatriz[i] = (vector<int>(i+1));
    }
    cout << arestasMatriz[4][4] << '\n';

    return 0;
}
