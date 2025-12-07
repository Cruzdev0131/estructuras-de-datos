#include <bits/stdc++.h>
#define nl endl
#define ll long long
using namespace std;

// 1. EL NODO (La cajita con punteros)
struct Nodo {
    string palabra;
    Nodo *izquierda; // Puntero al hijo izquierdo
    Nodo *derecha;   // Puntero al hijo derecho
};

// Variable Global para guardar las sugerencias que encontremos
vector<string> listaDeOpciones;

// --- FUNCIÓN 1: Crear un nodo nuevo ---
// (Ayuda a no escribir tanto 'new' y 'NULL' a cada rato)
Nodo* crearNodo(string texto) {
    Nodo *nuevo = new Nodo();
    nuevo->palabra = texto;
    nuevo->izquierda = NULL;
    nuevo->derecha = NULL;
    return nuevo;
}

// --- FUNCIÓN 2: Insertar en el árbol (Recursiva fácil) ---
void insertar(Nodo *&raiz, string texto) {
    // Caso base: Si llegamos a un hueco vacio (NULL), ahí va la palabra
    if (raiz == NULL) {
        raiz = crearNodo(texto);
        return;
    }

    // Si la palabra es menor, nos vamos a la izquierda
    if (texto < raiz->palabra) {
        insertar(raiz->izquierda, texto);
    }
    // Si es mayor, a la derecha
    else {
        insertar(raiz->derecha, texto);
    }
}

// --- FUNCIÓN 3: Revisar si coincide (Lógica manual) ---
// Revisa si 'palabra' empieza con las letras de 'loQueEscribi'
bool coincide(string palabra, string loQueEscribi) {
    // Si escribí más letras que la palabra misma, no puede ser
    if (loQueEscribi.length() > palabra.length()) {
        return false;
    }

    // Revisamos letra por letra
    for (int i = 0; i < loQueEscribi.length(); i++) {
        // Si una letra es diferente, ya no coinciden
        if (palabra[i] != loQueEscribi[i]) {
            return false;
        }
    }
    return true; // Pasó todas las pruebas
}

// --- FUNCIÓN 4: Buscar en el árbol (Recorrido In-Order) ---
void buscarOpciones(Nodo *raiz, string busqueda) {
    if (raiz == NULL) return;

    // 1. Ir a la izquierda primero (para que salgan en orden alfabetico)
    buscarOpciones(raiz->izquierda, busqueda);

    // 2. Revisar el nodo current
    if (coincide(raiz->palabra, busqueda)) {
        listaDeOpciones.push_back(raiz->palabra);
    }

    // 3. Ir a la derecha
    buscarOpciones(raiz->derecha, busqueda);
}

// --- FUNCIÓN 5: Cargar las 50 palabras ---
void cargarDiccionario(Nodo *&raiz) {
    // Un arreglo simple de strings
    string datos[] = {
        "arbol", "abeja", "avion", "amigo", "alto",
        "bueno", "barco", "buscar", "banco", "balon",
        "casa", "carro", "camino", "cielo", "computadora",
        "dedo", "dato", "dia", "diente", "doctor",
        "elefante", "escuela", "estado", "ejemplo", "energia",
        "fuego", "fiesta", "familia", "flor", "fruta",
        "gato", "gente", "guitarra", "gol", "ganar",
        "hielo", "hola", "huevo", "hora", "hotel",
        "iglesia", "imagen", "isla", "idea", "internet",
        "juego", "jirafa", "jardin", "joven", "jugo"
    };

    // Insertamos una por una
    for(int i = 0; i < 50; i++) {
        insertar(raiz, datos[i]);
    }
}

int main() {
    Nodo *raizDelArbol = NULL; // Importante: Inicializar en NULL
    cargarDiccionario(raizDelArbol);

    string fraseFinal = "";
    string entradaUsuario;

    cout << "--- AUTOCOMPLETADO SUPER FACIL ---" << nl;
    cout << "Escribe 'salir' para terminar." << nl;

    while (true) {
        cout << "\nTu frase: " << fraseFinal << nl;
        cout << "Escribe (minimo 3 letras): ";
        cin >> entradaUsuario;

        if (entradaUsuario == "salir") break;

        if (entradaUsuario.length() < 3) {
            // Si es muy corta, la agregamos directo
            fraseFinal = fraseFinal + entradaUsuario + " ";
        } 
        else {
            // Limpiamos la lista global antes de buscar
            listaDeOpciones.clear();
            
            // Buscamos
            buscarOpciones(raizDelArbol, entradaUsuario);

            if (listaDeOpciones.empty()) {
                cout << "-> No encontre nada. Agregando palabra." << nl;
                fraseFinal = fraseFinal + entradaUsuario + " ";
            } 
            else {
                cout << "--- Sugerencias ---" << nl;
                cout << "0. " << entradaUsuario << " (Usar lo que escribi)" << nl;
                
                // Mostrar opciones
                for (int i = 0; i < listaDeOpciones.size(); i++) {
                    cout << (i + 1) << ". " << listaDeOpciones[i] << nl;
                }

                int opcion;
                cout << "Elige numero: ";
                cin >> opcion;

                if (opcion > 0 && opcion <= listaDeOpciones.size()) {
                    // El usuario eligió una sugerencia
                    // Restamos 1 porque el arreglo empieza en 0
                    fraseFinal = fraseFinal + listaDeOpciones[opcion - 1] + " ";
                } else {
                    // El usuario eligió 0 o numero invalido
                    fraseFinal = fraseFinal + entradaUsuario + " ";
                }
            }
        }
    }

    cout << "\nFrase Terminada: " << fraseFinal << nl;
    return 0;
}