#include <iostream>
#include <string>
#include <limits>
#include <clocale>
using namespace std;

/*		INTEGRANTES DO GRUPO
Tobias Bueno Pereira - 418 - GES
Rodrigo Armengol de Oliveira - 294 - GES
Igor de Araújo Fonseca - 479 - GES
Thiago Damas Ferreira Silva - 214 - GEC
André Rocha de Mesquita - 2017 - GEC
*/

#define quantidade 1000
string cidades[70];
int num_city;

struct Pokemon
{
    string pokebola;
    string local;
    string tipo;
    string name;
    int num;
};

Pokemon cadastro_poke() // função para o cadastro dos pokemons
{
	setlocale(LC_ALL, "Portugese");
    Pokemon novo;
    cout << "------------------------Menu de cadastro----------------------------" << endl;
    cout << "Insira o nome do Pokemon: ";
    do
    {
        getline(cin >> ws, novo.name);
        if (novo.name.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ ") != string::npos)
        {
            cout << "Nome inválido. Use apenas letras." << endl;
            novo.name = ""; // Reinicia o nome para tentar novamente
        }
    } while (novo.name.empty());

    cout << "Insira o tipo do Pokemon " << novo.name << ": ";
    do
    {
        getline(cin >> ws, novo.tipo);
        if (novo.tipo.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ ") != string::npos)
        {
            cout << "Tipo inválido. Use apenas letras." << endl;
            novo.tipo = ""; // Reinicia o tipo para tentar novamente
        }
    } while (novo.tipo.empty());

    cout << "Insira o número do Pokemon: ";
    while (!(cin >> novo.num) || novo.num <= 0)
    {
        cout << "Número inválido. Insira um número positivo: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Insira a localização do pokemon: ";
    do
    {
        getline(cin >> ws, novo.local);
    } while (novo.local.empty());

    cout << "Insira a pokebola que o pokemon foi capturado: ";
    getline(cin >> ws, novo.pokebola);

    cout << "------------------------------------------------------------------" << endl;

    return novo;
}

void cadastro_city() // cadastro de cidades
{
	setlocale(LC_ALL, "Portugese");
    cout << "----------------------Cadastro de cidades--------------------------" << endl;
    cout << "Quantas cidades gostaria de cadastrar? :";

    while (!(cin >> num_city))
    {
        cout << "Insira apenas números!" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // limpa buffer de entrada
    }
    cin.ignore(); // para limpar o buffer de entrada

    for (int i = 0; i < num_city; i++)
    {
        cout << "Digite o nome da cidade " << i + 1 << ": ";
        do
        {
            getline(cin >> ws, cidades[i]);
        } while (cidades[i].empty());
    }
    cout << "-------------------------------------------------------------------" << endl;
}

void exibir_menu()
{
	setlocale(LC_ALL, "Portugese");
    cout << "------------------------Selecione uma opção-----------------------" << endl;
    cout << "1 - Inserir Pokemon\n2 - Inserir cidades\n3 - Mostrar informações do pokemon\n4 - Exibir cidades\n5 - Sair" << endl;
    cout << "------------------------------------------------------------------" << endl;
}

void exibir_pokemon(Pokemon registro) // função para mostrar os pokemons
{
	setlocale(LC_ALL, "Portugese");
    cout << "----------------------Informações do Pokemon-----------------------" << endl;
    cout << "Quem é esse Pokemon? " << registro.name << endl;
    cout << "Tipo: " << registro.tipo << endl;
    cout << "Pokebola utilizada: " << registro.pokebola << endl;
    cout << "Número do Pokemon: " << registro.num << endl;
    cout << "Localização do Pokemon: " << registro.local << endl;
    cout << "-------------------------------------------------------------------" << endl;
}

void exibir_city() // exibe a cidade
{
	setlocale(LC_ALL, "Portugese");
    cout << "----------------------Cidades Cadastradas--------------------------" << endl;
    for (int i = 0; i < num_city; i++)
    {
        cout << i + 1 << ". " << cidades[i] << endl;
    }
    cout << "-------------------------------------------------------------------" << endl;
}

void choose() // menu de opções
{
	setlocale(LC_ALL, "Portugese");
    int option;
    Pokemon registro;
    bool pokemon_cadastrado = false;

    do
    {
        exibir_menu();
        cout << "Opção: ";
        while (!(cin >> option) || option < 1 || option > 5)
        {
            cout << "Opção inválida. Apenas números entre 1 e 5." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Opção: ";
        }

        switch (option)
        {
        case 1:
            registro = cadastro_poke();
            pokemon_cadastrado = true;
            break;
        case 2:
            cadastro_city();
            break;
        case 3:
            if (pokemon_cadastrado)
                exibir_pokemon(registro);
            else
                cout << "Nenhum Pokemon cadastrado ainda." << endl;
            break;
        case 4:
            exibir_city();
            break;
        default:
            cout << "Opção inválida. Tente novamente." << endl;
            break;
        }

    } while (option != 5);

    cout << "-------------------------------------------------------------------" << endl;
    cout << "Programa finalizado com sucesso!!" << endl;
}

int main()
{
    choose();

    return 0;
}

/*
Tobias Bueno Pereira - 418 - ges
Rodrigo armengol de Oliveira - 294 - ges
Igor de Araújo Fonseca - 479 - ges
Thiago damas Ferreira Silva - 214 - gec
André Rocha mesquita - 2017 - gec
*/