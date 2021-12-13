#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int>teste{4, 2, 1, 3};
    sort(teste.begin(), teste.end());
    for(int t: teste){
        cout << t << '\n';
    }
    int u = 7/2;
    cout << u << '\n';
    return 0;
}
