#include <bits/stdc++.h>
#define nl endl
#define ll long long
using namespace std;

struct Nodo {
    string pregunta;
    string ans;
    Nodo* si;
    Nodo* no;
    
    Nodo(string p, string r = "") {
        pregunta = p;
        ans = r;
        si = NULL;
        no = NULL;
    }
};

Nodo* raiz;

Nodo* preg() {
    Nodo* raiz = new Nodo("¿Es un personaje?");
    
    // Rama SI - Personajes
    raiz->si = new Nodo("¿Tiene poderes magicos o sobrenaturales?");
    
    // Personajes con poderes
    raiz->si->si = new Nodo("¿Viene de un videojuego?");
    raiz->si->si->si = new Nodo("¿Es Mario?", "Mario Bros");
    raiz->si->si->si->si = new Nodo("¿Es Link?", "Zelda");
    raiz->si->si->si->no = new Nodo("¿Es Link?", "Zelda");
    raiz->si->si->no = new Nodo("¿Tiene cabello naranja?");
    raiz->si->si->no->si = new Nodo("¿Busca poder absoluto?", "DragonBall");
    raiz->si->si->no->no = new Nodo("¿Aparece en anime?", "Arcane");
    
    // Personajes sin poderes
    raiz->si->no = new Nodo("¿Es de una serie de TV?");
    raiz->si->no->si = new Nodo("¿Es mexicano?");
    raiz->si->no->si->si = new Nodo("¿Vive en una vecindad?", "El Chavo del 8");
    raiz->si->no->si->no = new Nodo("¿Es estudiante?", "Arcane");
    raiz->si->no->no = new Nodo("¿Es una esponja?", "Bob Esponja");
    
    // Rama NO - No es personaje
    raiz->no = new Nodo("¿Es un lugar imaginario?");
    raiz->no->si = new Nodo("¿Tiene castillos?", "Zelda");
    raiz->no->no = new Nodo("¿Es una serie de TV?", "Arcane");
    
    return raiz;
}

void jugar(Nodo* current) {
    if (current == NULL) return;
    
    if (current->si == NULL && current->no == NULL) {
        cout << "\npienso que es: "<< current->ans << nl;
        char ansconf;
        cout << "es o no es? (s/n): ";
        cin>>ansconf;
        if (ansconf == 's') cout << "adivinado!"<< nl;
         else cout << "imposible" << nl;
        
        return;
    }
    
    cout << current->pregunta << " (s/n): ";
    char ans;
    cin >> ans;
    
    if (ans == 's' || ans == 'S') {
        jugar(current->si);
    } else {
        jugar(current->no);
    }
}

int main() {

    raiz = preg();
    char conti = 's';
    
    while (conti == 's'){
        cout << "=== AKINATOR by cruzdev ===" << nl;
       // cout << "piensa en un personaje de: Zelda, Arcane, DragonBall, El Chavo del 8, Bob Esponja, Mario Bros o Malcolm." << nl;
        cout << "escribe s (si), n (no)\n" << nl;
        jugar(raiz);
        cout << "quieres jugar de nuevo?: ";
        cin >> conti;
    }

    
    
    return 0;



}
