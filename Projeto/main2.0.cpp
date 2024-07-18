#include <iostream>
#include <string>
#include <list>
#include <cmath>

using namespace std;

int MAX_CIDADES = 100;
int INFINITO = 9999999;

struct pokemon {
    string nome;
    string tipo;
    int local[2];  // Localização agora tem 2 elementos para x e y
    int codigo;
};

struct treenode {
    pokemon new_pokemon;
    treenode *left;
    treenode *right;
};

struct Aresta {
    int destino;
    int peso;
};

struct Cidade {
    int codigo;
    string nome;
    bool CentroPokemon;
    list<Aresta> adj; // Lista de adjacências usando a estrutura Aresta
};

typedef treenode *treenodeptr;

void insert_nome(treenodeptr &arvore, pokemon new_pokemon) {
    if (arvore == NULL) {
        arvore = new treenode;
        arvore->new_pokemon = new_pokemon;
        arvore->left = NULL;
        arvore->right = NULL;
    } else if (arvore->new_pokemon.nome > new_pokemon.nome) {
        insert_nome(arvore->left, new_pokemon);
    } else {
        insert_nome(arvore->right, new_pokemon);
    }
}

void insert_tipo(treenodeptr &arvore, pokemon new_pokemon) {
    if (arvore == NULL) {
        arvore = new treenode;
        arvore->new_pokemon = new_pokemon;
        arvore->left = NULL;
        arvore->right = NULL;
    } else if (arvore->new_pokemon.tipo > new_pokemon.tipo) {
        insert_tipo(arvore->left, new_pokemon);
    } else {
        insert_tipo(arvore->right, new_pokemon);
    }
}

void mostraInfo(treenodeptr &arvore) {
    cout << "Nome: " << arvore->new_pokemon.nome << endl;
    cout << "Tipo: " << arvore->new_pokemon.tipo << endl;
    cout << "Codigo: " << arvore->new_pokemon.codigo << endl;
    cout << "Localização: x = " << arvore->new_pokemon.local[0] << " y = " << arvore->new_pokemon.local[1] << endl;
}

void exibir(treenodeptr &arvore) {
    if (arvore != NULL) {
        exibir(arvore->left);
        mostraInfo(arvore);
        exibir(arvore->right);
    }
}

void tdestruir(treenodeptr &arvore) {
    if (arvore != NULL) {
        tdestruir(arvore->left);
        tdestruir(arvore->right);
        delete arvore;
    }
    arvore = NULL;
}

void menu() {
    setlocale(LC_ALL, "Portuguese");
    cout << "------------------------Selecione uma opção-----------------------" << endl;
    cout << "1 - Inserir Pokemon" << endl;
    cout << "2 - Encontrar Pokemon por nome" << endl;
    cout << "3 - Exibir Pokemons por nomes" << endl;
    cout << "4 - Exibir Pokemons por tipo" << endl;
    cout << "5 - Exibir quantos Pokemons tem de cada tipo" << endl;
    cout << "6 - Cadastrar cidades" << endl;
    cout << "7 - Menor Caminho até um centro Pokemon" << endl;
    cout << "8 - Quantidade de Pokemons em um raio de 100 metros da Pokedex" << endl;
    cout << "0 - Sair" << endl;
    cout << "--------------------------------------------------------------------" << endl;
}

treenodeptr search(treenodeptr arvore, const string &pokemon_nome) {
    if (arvore == NULL)
        return NULL;
    else if (arvore->new_pokemon.nome == pokemon_nome)
        return arvore;
    else if (arvore->new_pokemon.nome > pokemon_nome)
        return search(arvore->left, pokemon_nome);
    else
        return search(arvore->right, pokemon_nome);
}

void adicionarCidade(Cidade cidades[], int &numCidades, int codigo, 
                                const string &nome, bool CentroPokemon) {
    if (numCidades < MAX_CIDADES) {
        cidades[numCidades++] = {codigo, nome, CentroPokemon};
    } else {
        cout << "Número máximo de cidades atingido." << endl;
    }
}

void adicionarAresta(Cidade cidades[], int numCidades, int deCodigo,
                                 int paraCodigo, int peso) {
    for (int i = 0; i < numCidades; ++i) {
        if (cidades[i].codigo == deCodigo) {
            cidades[i].adj.push_back({paraCodigo, peso});
            break;
        }
    }
}

int encontrarIndiceCidade(Cidade cidades[], int numCidades, int codigo) {
    for (int i = 0; i < numCidades; ++i) {
        if (cidades[i].codigo == codigo)
            return i;
    }
    return -1; // cidade não encontrada
}

void caminhoMaisCurtoDijkstra(Cidade cidades[], int numCidades, int codigoInicial) {
    int vertices = numCidades;
    bool intree[MAX_CIDADES] = {false};
    int distancia[MAX_CIDADES];
    int pai[MAX_CIDADES];

    for (int i = 0; i < MAX_CIDADES; ++i) {
        distancia[i] = INFINITO;
        pai[i] = -1;
    }

    int indiceInicial = encontrarIndiceCidade(cidades, numCidades, codigoInicial);
    if (indiceInicial == -1) {
        cout << "Cidade não encontrada" << endl;
        return;
    }

    distancia[indiceInicial] = 0;
    int v = indiceInicial;

    while (!intree[v]) {
        intree[v] = true;
        list<Aresta>::iterator it;
        for (it = cidades[v].adj.begin(); it != cidades[v].adj.end(); ++it) {
            int indiceDestino = encontrarIndiceCidade(cidades, numCidades, it->destino);
            if (indiceDestino != -1 && distancia[indiceDestino] > distancia[v] + it->peso) {
                distancia[indiceDestino] = distancia[v] + it->peso;
                pai[indiceDestino] = v;
            }
        }

        v = -1;
        int dist = INFINITO;
        for (int u = 0; u < vertices; ++u) {
            if (!intree[u] && distancia[u] < dist) {
                dist = distancia[u];
                v = u;
            }
        }
        if (v == -1) break; // não há mais nós para processar
    }

    int dist_CPokemon = INFINITO;
    int indice_CPokemon = -1;
    for (int u = 0; u < vertices; ++u) {
        if (cidades[u].CentroPokemon && distancia[u] < dist_CPokemon) {
            dist_CPokemon = distancia[u];
            indice_CPokemon = u;
        }
    }

    if (indice_CPokemon != -1) {
        if (dist_CPokemon == 0)
        {
            cout << "Na cidade em que você está tem um centro Pokemon" << endl;
        }else
            cout << "O Centro Pokémon mais próximo está em " << cidades[indice_CPokemon].nome
                 << " com uma distância de " << dist_CPokemon << "Km" << endl;
    } else {
        cout << "Nenhum Centro Pokémon é alcançável." << endl;
    }
}

int main_cidade(Cidade cidades[]) {
    int numCidades = 0;

    int numCidadesInput;
    cout << "Digite o número de cidades: ";
    cin >> numCidadesInput;

    for (int i = 0; i < numCidadesInput; ++i) {
        int codigo;
        string nome;
        bool CentroPokemon;

        cout << "Digite o código da cidade: ";
        cin >> codigo;
        cin.ignore(); // Limpa o buffer de entrada
        cout << "Digite o nome da cidade: ";
        getline(cin, nome);
        cout << "A cidade tem um Centro Pokémon? (1 para sim, 0 para não): ";
        cin >> CentroPokemon;

        adicionarCidade(cidades, numCidades, codigo, nome, CentroPokemon);
    }

    int numArestas;
    cout << "Digite o número de caminhos entre as cidades: ";
    cin >> numArestas;

    for (int i = 0; i < numArestas; ++i) {
        int deCodigo, paraCodigo, peso;

        cout << "Digite o código da cidade de origem: ";
        cin >> deCodigo;
        cout << "Digite o código da cidade de destino: ";
        cin >> paraCodigo;
        cout << "Digite a distância: ";
        cin >> peso;

        adicionarAresta(cidades, numCidades, deCodigo, paraCodigo, peso);
    }

    return numCidades;
}
// Função para calcular a distância Euclidiana entre dois pontos
int calcularDistancia(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

// Função para contar quantos Pokemons estão dentro de um raio de 100 metros
int contarPokemonNoRaioRecursivo(treenodeptr arvore, int x_pokedex, 
                                            int y_pokedex, int raio) {
    if (arvore == NULL) {
        return 0;
    }

    int distancia = calcularDistancia(x_pokedex, y_pokedex, 
                            arvore->new_pokemon.local[0], arvore->new_pokemon.local[1]);
    int count = 0;

    if (distancia <= raio) {
        count = 1;
    }

    count += contarPokemonNoRaioRecursivo(arvore->left, x_pokedex, y_pokedex, raio);
    count += contarPokemonNoRaioRecursivo(arvore->right, x_pokedex, y_pokedex, raio);

    return count;
}

// Função principal para contar Pokemons dentro de um raio de 100 metros
int contarPokemonNoRaio(treenodeptr arvore, int x_pokedex, int y_pokedex) {
    if (arvore == NULL) {
        return 0;
    }

    int raio = 100;
    return contarPokemonNoRaioRecursivo(arvore, x_pokedex, y_pokedex, raio);
}

// Função principal e demais partes do código permanecem inalteradas...

int main() {
    Cidade cidades[MAX_CIDADES];
    treenodeptr ar_nome = NULL;
    treenodeptr ar_tipo = NULL;
    treenodeptr res = NULL;
    int numCidades;
    int opcao = -1;
    int terra = 0;
    int agua = 0;
    int fogo = 0;
    int planta = 0;
    int outros = 0;

    while (opcao != 0) {
        menu();
        cout << "Opção: ";
        cin >> opcao;
        cout << endl;

        switch (opcao) {
        case 0:
            cout << "Programa finalizado!" << endl;
            break;
        case 1: {
            pokemon new_pokemon;
            cout << "Digite o nome do Pokemon: ";
            cin.ignore(); // Limpa o buffer de entrada
            getline(cin, new_pokemon.nome);
            cout << "Digite o tipo do Pokemon (Terra/Fogo/Agua/Planta): ";
            getline(cin, new_pokemon.tipo);
            cout << "Digite a localização do Pokemon x: ";
            cin >> new_pokemon.local[0];
            cout << "Digite a localização do Pokemon y: ";
            cin >> new_pokemon.local[1];
            cout << "Digite o número do Pokemon: ";
            cin >> new_pokemon.codigo;

            if (new_pokemon.tipo == "Terra")
                terra++;
            else if(new_pokemon.tipo == "Agua")
                agua++;
            else if(new_pokemon.tipo == "Fogo")
                fogo++;
            else if(new_pokemon.tipo == "Planta")
                planta++;
            else
                outros++;

            insert_nome(ar_nome, new_pokemon);
            insert_tipo(ar_tipo, new_pokemon);
            break;
        }
        case 2: {
            string pokemon_nome;
            cout << "Digite o nome do Pokemon que deseja encontrar: ";
            cin.ignore(); // Limpa o buffer de entrada
            getline(cin, pokemon_nome);
            cout << endl;
            res = search(ar_nome, pokemon_nome);

            if (res == NULL)
                cout << "Pokemon não encontrado!" << endl;
            else
                cout << "Pokemon encontrado!" << endl;
            break;
        }
        case 3:
            cout << "------------------ Pokemons Cadastrados por nomes ------------------" << endl;
            exibir(ar_nome);
            break;
        case 4:
            cout << "------------------ Pokemons Cadastrados por tipos ------------------" << endl;
            exibir(ar_tipo);
            break;
        case 5:
            cout << "---------------- Quantidade de Pokemons de cada tipo ---------------" << endl;
            cout << "Fogo: " << fogo << endl;
            cout << "Agua: " << agua << endl;
            cout << "Terra: " << terra << endl;
            cout << "Planta: " << planta << endl;
            cout << "Outros: " << outros << endl;
            break;
        case 6:
            cout << "----------------------- Cadastrar cidades --------------------------" << endl;
            numCidades = main_cidade(cidades);
            break;
        case 7:
            cout << "------------- Menor caminho até um centro Pokemon ------------------" << endl;
            int codigoInicial;
            cout << "Digite o código da cidade atual: ";
            cin >> codigoInicial;
            caminhoMaisCurtoDijkstra(cidades, numCidades, codigoInicial);
            break;
        case 8: {
            cout << "---------- Quantidade de Pokemons em um raio de 100 metros ----------" << endl;
            int x_pokedex, y_pokedex;
            cout << "Digite a coordenada x da Pokedex: ";
            cin >> x_pokedex;
            cout << "Digite a coordenada y da Pokedex: ";
            cin >> y_pokedex;

            int numPokemons = contarPokemonNoRaio(ar_nome, x_pokedex, y_pokedex);
            cout << "Número de Pokemons dentro do raio de 100 metros: " << numPokemons << endl;
            break;
        }
        default:
            cout << "Opção Inválida!" << endl;
            break;
        }
    }

    tdestruir(ar_nome);
    tdestruir(ar_tipo);

    return 0;
}