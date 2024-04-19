#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

struct InfoFlores {
    double largura_petala;
    double altura_petala;
    string especie;
};

const int MAX_FLORES = 150;

// Função para ler os dados do arquivo CSV
int ler_dados(const string& nome_arquivo, InfoFlores* flores) {
    ifstream arquivo(nome_arquivo);

    if (!arquivo) {
        cerr << "Erro ao abrir o arquivo de dados." << endl;
        return 0;
    }

    string linha;
    getline(arquivo, linha); 

    int num_flores = 0;
    while (getline(arquivo, linha)) {
        stringstream ss(linha);
        string valor;

        getline(ss, valor, ',');
        flores[num_flores].largura_petala = stod(valor);

        getline(ss, valor, ',');
        flores[num_flores].altura_petala = stod(valor);

        getline(ss, valor, ',');
        flores[num_flores].especie = valor;

        num_flores++;
    }

    arquivo.close();
    return num_flores;
}

// Função para calcular a distância euclidiana entre duas flores
double calcular_distancia(const InfoFlores& flor1, const InfoFlores& flor2) {
    double diff_largura = flor1.largura_petala - flor2.largura_petala;
    double diff_altura = flor1.altura_petala - flor2.altura_petala;
    return sqrt(diff_largura * diff_largura + diff_altura * diff_altura);
}

// Função para encontrar o grupo mais próximo de uma flor
int encontrar_grupo_proximo(const InfoFlores& flor, const InfoFlores* representantes, int num_grupos) {
    int grupo_proximo = 0;
    double distancia_minima = calcular_distancia(flor, representantes[0]);

    for (int i = 1; i < num_grupos; i++) {
        double distancia = calcular_distancia(flor, representantes[i]);
        if (distancia < distancia_minima) {
            distancia_minima = distancia;
            grupo_proximo = i;
        }
    }

    return grupo_proximo;
}

// Função para atualizar os representantes de cada grupo
void atualizar_representantes(const InfoFlores* flores, const int* grupos, int num_flores, InfoFlores* representantes, int num_grupos) {
    int* contagem = new int[num_grupos](); // Inicializa todos os elementos com 0

    for (int i = 0; i < num_flores; i++) {
        int grupo = grupos[i];
        contagem[grupo]++;
        //Acho que o número da larg e alt prescisa ser zerado
        representantes[grupo].largura_petala += flores[i].largura_petala;
        representantes[grupo].altura_petala += flores[i].altura_petala;
    }

    for (int i = 0; i < num_grupos; i++) {
        if (contagem[i] != 0) {
            representantes[i].largura_petala /= contagem[i];
            representantes[i].altura_petala /= contagem[i];
        }
    }

    delete[] contagem;
}

// Função para gerar um novo arquivo CSV com os dados e grupos correspondentes
void gerar_arquivo_grupos(const InfoFlores* flores, const int* grupos, int num_flores, const string& nome_arquivo) {
    ofstream arquivo(nome_arquivo);

    if (!arquivo) {
        cerr << "Erro ao criar o arquivo de dados." << endl;
        return;
    }

    arquivo << "\"petal_length\",\"petal_width\",\"variety\",\"grupo\"" << endl;

    for (int i = 0; i < num_flores; i++) {
        arquivo << flores[i].largura_petala << "," << flores[i].altura_petala << "," << flores[i].especie << "," << grupos[i] << endl;
    }

    arquivo.close();
    cout << "O arquivo '" << nome_arquivo << "' foi criado com sucesso." << endl;
}

int main() {
    const string nome_arquivo_entrada = "iris_petalas.csv";
    const string nome_arquivo_saida = "flores_grupos.csv";

    InfoFlores flores[MAX_FLORES];
    int num_flores = ler_dados(nome_arquivo_entrada, flores);
    int grupos[MAX_FLORES] = {0}; // Inicializa todos os elementos com 0

    int k;
    cout << "Digite o valor de k (número de grupos): ";
    cin >> k;

    // Escolher aleatoriamente k flores como representantes iniciais dos grupos
    srand(static_cast<unsigned>(time(0)));
    InfoFlores representantes[k];
    for (int i = 0; i < k; i++) {
        int indice_aleatorio = rand() % num_flores;
        representantes[i] = flores[indice_aleatorio];
    }

    int num_iteracoes;
    cout << "Digite o número de iterações: ";
    cin >> num_iteracoes;

    for (int iteracao = 0; iteracao < num_iteracoes; iteracao++) {
        for (int i = 0; i < num_flores; i++) {
            grupos[i] = encontrar_grupo_proximo(flores[i], representantes, k);
        }

        atualizar_representantes(flores, grupos, num_flores, representantes, k);
    }

    gerar_arquivo_grupos(flores, grupos, num_flores, nome_arquivo_saida);

    return 0;
}
