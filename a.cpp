#include <bits/stdc++.h>  
#define nl '\n'         
#define ll long long       
using namespace std;

struct Node{
    int value;     
    Node *left;   
    Node *right;  
};

// puntero global a la raíz del arbol
Node *mainRoot;

void insert(Node *&root, int value){
    // si el puntero current esta vacio, aqui debemos crear un nuevo nodo
    if (root == NULL){
        root = new Node;      // se reserva memoria para un nuevo nodo
        root->value = value;  // se asigna el valor
        // preguntar de esto 
        root->left = NULL;    // no tiene son izquiedo todavia
        root->right = NULL;   // no tiene son derecho todavia
    }
    // si el valor es menor que el del nodo actuak se va a la izquierda
    else if (value < root->value)
        insert(root->left, value);   // llamada recursiva sobre el son izquiedo
    // si el valor es mayor que el del nodo current, se va a la derecha
    else if (value > root->value)
        insert(root->right, value);  // llamada recursiva sobre el son derecho
        // si es igual, se ignora (no se permiten duplicados)
}

void print(Node *root)
{
    cout << "\n\t[" << root << "] Value: " << root->value << nl;
    if(root->left != NULL)
        cout << "L: [" << root->left << "] Value: " << root->left->value << nl;
    if(root->right != NULL)
        cout << "\t\tR: [" << root->right << "] Value: " << root->right->value << nl;
}

bool preOrderSearch(Node *root, Node *padre, int valbusc, int it)
{
    if (root != NULL)
    {
        if (root->value == valbusc)
        {
            cout << "nodo encontrado: " << root->value << nl;
            cout << "[" << root << "]" << nl;
            
            if (padre == NULL)
                cout << "  NO TIENE (es la raiz)" << nl; 
            else
                cout << " Padre: " << padre->value << " [" << padre << "]" << nl;
            
            if (root->left != NULL)
                cout << " son izquiedo: " << root->left->value << nl;
            else
                cout << " NO TIENE" << nl;
            
            if (root->right != NULL)
                cout << " son derecho: " << root->right->value << nl;
            else
                cout << " NO TIENE" << nl;
            
            cout << " it para llegar: " << it << nl;
            cout << "-----------------------------------------" << nl;
            return true;
        }
        if (preOrderSearch(root->left, root, valbusc, it + 1))
            return true;
        if (preOrderSearch(root->right, root, valbusc, it + 1))
            return true;
    }
    return false;
}

bool inOrderSearch(Node *root, Node *padre, int valbusc, int it)
{
    if (root != NULL)
    {
        if (inOrderSearch(root->left, root, valbusc, it + 1))
            return true;
        
        if (root->value == valbusc)
        {
            cout << "nodo encontrado: " << root->value << nl;
            cout << "[" << root << "]" << nl;
            
            if (padre == NULL)
                cout << "  NO TIENE (es la raiz)" << nl; 
            else
                cout << " Padre: " << padre->value << " [" << padre << "]" << nl;
            
            if (root->left != NULL)
                cout << " son izquiedo: " << root->left->value << nl;
            else
                cout << "  NO TIENE" << nl;
            
            if (root->right != NULL)
                cout << " son derecho: " << root->right->value << nl;
            else
                cout << "  NO TIENE" << nl;
            
            cout << " it para llegar: " << it << nl;
            cout << "-----------------------------------------" << nl;
            return true;
        }
        
        if (inOrderSearch(root->right, root, valbusc, it + 1))
            return true;
    }
    return false;
}

bool postOrderSearch(Node *root, Node *padre, int valbusc, int it)
{
    if (root != NULL)
    {
        if (postOrderSearch(root->left, root, valbusc, it + 1))
            return true;
        if (postOrderSearch(root->right, root, valbusc, it + 1))
            return true;
        
        if (root->value == valbusc)
        {
            cout << "nodo encontrado: " << root->value << nl;
            cout << "[" << root << "]" << nl;
            
            if (padre == NULL)
                cout << " Padre: NO TIENE (es la raiz)" << nl; 
            else
                cout << " Padre: " << padre->value << " [" << padre << "]" << nl;
            
            if (root->left != NULL)
                cout << " son izquiedo: " << root->left->value << nl;
            else
                cout << " son izquiedo: NO TIENE" << nl;
            
            if (root->right != NULL)
                cout << " son derecho: " << root->right->value << nl;
            else
                cout << " son derecho: NO TIENE" << nl;
            
            cout << " it para llegar: " << it << nl;
            cout << "-----------------------------------------" << nl;
            return true;
        }
    }
    return false;
}

int main()
{
    srand(time(NULL));
    int op, value, n, objetivo;
    
    cout << "ingrese el valor de la raiz: ";
    mainRoot = new Node;
    mainRoot->left = NULL;
    mainRoot->right = NULL;
    cin >> mainRoot->value;

    cout << "numero de valores aleatorios a insertar: "; cin >> n; 
    for (int i = 0; i < n; i++)
    {
        value = rand() % 100;
        cout << value << " "; 
        insert(mainRoot, value);
    }
    cout << nl << "--------------------------" << nl;

    do {
        cout << "1. PRE-ORDER (Raiz-Izq-Der)" << nl;
        cout << "2.  IN-ORDER (Izq-Raiz-Der)" << nl;
        cout << "3. POST-ORDER (Izq-Der-Raiz)" << nl;
        cout << "0. salir" << nl;
        cin >> op;
        cout << nl;

        switch (op)
        {
            case 1:
                cout << "ingrese el valor a buscar: ";
                cin >> objetivo;
                if (!preOrderSearch(mainRoot, NULL, objetivo, 1))
                    cout << "el valor " << objetivo << " no esta" << nl;
                break;
            case 2:
                cout << "ingrese el valor a buscar: ";
                cin >> objetivo;
                if (!inOrderSearch(mainRoot, NULL, objetivo, 1))
                    cout << "el valor " << objetivo << " no esta" << nl;
                break;
            case 3:
                cout << "ingrese el valor a buscar: ";
                cin >> objetivo;
                if (!postOrderSearch(mainRoot, NULL, objetivo, 1))
                    cout << "no existe en el arbol" << nl;
                break;
            case 0:
                cout << "adios crack!" << nl;
                break;
            default:
                cout << "op invalida. Intente de nuevo" << nl;
        }

    } while (op != 0); 

    return 0; 
}
