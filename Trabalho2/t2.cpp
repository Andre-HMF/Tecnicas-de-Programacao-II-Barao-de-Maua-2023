//Tecnicas de Programação II
//ID:2164047
//Nome: André Henrique Marchetto Filho


////ios::binary

//Padrão
#include <iostream>
//Leitura e escrita de arquivo
#include <fstream>
//
#include <sstream>
#include <iomanip>
//rand
#include <cstdlib>
//timne
#include <ctime>
#include <string>
#include <cmath>

using namespace std;


//________________________________________________________________InterpretadorGlobal________________________________________________________________________//

struct _datas_
{
    bool * bp = new bool[0];//1
    char * cp = new char[0];//1
    int * ip = new int[0];//4
    float * fp = new float[0];//4
    double * dp = new double[0];//8
    string * sp = new string[0];//
    int grup=0;
    int tamanho[6]={0,0,0,0,0,0};
};

struct pontomédio
{
    float x=0,y=0;
};

void InterpretadorGlobal();
//Funções_do_InterpretadorGlobal();

//Funções
//Pega um número aleatorio
int Aleatorio(int max,int aleatorizador, int save_number_randow[], int i=-1);//max->valor maximo aleatorizador->deixa mais alatorio

//Verifica se um caractere esta fora de um range retorna true caso seja verdade
bool Checker_range_char(char& c,char vetor[],int size=0);
bool Checker_char(char &c,char range1,char range2);

//Se aprofeita do verificador e analisa um arquivo e as ocorrencias de caracteres não especificados utilizando a tabela ASCII
char Pick_up_separator(string arquivo, char vetor[], int size=0);
void deallocate_data(_datas_ *des,int &qnt);
void Type_separator_save(string piece,_datas_ *des,int *padrao=nullptr);
void Read_data(_datas_ *des);

bool Check_Egual_Randow(int save_number_randow[], int tamanho);

int Cont_Line(string &arquivo);


//Redimenciona o ptr
void Resize_ptr_bool(_datas_ *ptr);
void Resize_ptr_char(_datas_ *ptr);
void Resize_ptr_int(_datas_ *ptr);
void Resize_ptr_float(_datas_ *ptr);
void Resize_ptr_double(_datas_ *ptr);
void Resize_ptr_string(_datas_ *ptr);

void Size_Reset(_datas_ &ptr);

void Cut_string_by_separator(_datas_ &data,string &linhas,char &separador,int *padrao=nullptr);

void Save_Content_Data_by_Archive(_datas_ &data,string &arquivo,char &separador,int *padrao=nullptr);

void Read_grup(_datas_ *ptr,int k);

string piece_copy(string &str,int n,int inicial=0);
//bool Ifverifypadrao(_datas_ &ptr,int save[]);
void Save_Content_Data_by_Archive_Range(_datas_ &data,string &arquivo,char &separador,int sgetr=0,int egetr=0,int *padrao=nullptr);
void Check_pattern(string &arquivo,char &separador,int *stamanho,int tamanho);

bool Check_Number_Egual_Vetor(int n1,int nv[], int tamanho);
bool Check_Number_Egual(int n1, int n2);

void Selecting_member_numbers(_datas_ *lideres, int &k, _datas_ *membros, int &total_de_membros);
void Updating_Leaders(_datas_ *lideres, int &k, _datas_ *membros, int &total_de_membros);
//void generate_a_new_file(_datas_ *lideres, int &k, _datas_ *membros, int &total_de_membros);

void Create_a_new_file(string &str,_datas_ *data, int &k);
void Rewriting_a_file(string &str,_datas_ *data, int &k);

//___________________________________________________________________________________________________________________________________________________________//

                                                                                                                                                        
//________________________________________________________________InterpretadorFlor_________________________________________________________________________//

struct Flor
{
    long double f1,f2;
    string tipo;
    int grupo;
};


void InterpretadorFlor();

int Contar_Linhas(string str);

int Gerador_de_Numero_Aleatorio(int max,int j,int Salvar_Aleatorio[]);

void Lerconteudo(Flor data[],int &quantidade);

void Atualizando_grupos_dos_membros(Flor * Lideres,int &k, Flor * Membros, int &qntmembros);

void Atualizando_valor_dos_Lideres(Flor * Lideres,int &k, Flor * Membros, int &qntmembros);

//___________________________________________________________________________________________________________________________________________________________//

int main()
{
    int select;
    while (select!=0)
    {
        cout << endl << "Selecione seu codigo: ";
        cin >> select;

        if (select==1)
        {
            InterpretadorGlobal();       
        }
        else if (select==2)
        {
            InterpretadorFlor();
        }
        
        
    }

    return 0;
}

void InterpretadorFlor()
{
    string str="iris_petalas.csv",str2="iris_petalas2.csv";
    

    // //inserção de dados
    // cout << "Digite o arquivo a ser lido: ";
    // getline(cin, str);

    //Definir total de grupos

    int nlines=Contar_Linhas(str);
    int extra = 1;//Consertar detector
    cout << "Numero de linhas detectada no arquivo: "<<nlines<<endl;
    nlines=nlines-extra;

    int k=0;
    while (k<=1||k>nlines)
    {
        cout << "Definir total de grupos: ";
        cin >> k;
        if (k<=1)
        {
            cout << "Numero de grupos tem que ser maiores que 1!" << endl;
        }
        else if (k>nlines)
        {
            cout << "Numero de grupos ("<< nlines <<") excedido!" << endl;
        }
        
    }

    int runs=0;
    while (runs<1)
    {
        cout << "Definir total de reagrupamento de grupos com base no ponto medio resultante dos membros: ";
        cin >> runs;
        if (runs<1)
        {
            cout << "Numero de vezes tem que ser maiores que 0!" << endl;
        }
    }

    int qntmembros = nlines-k;
    Flor Lideres[k],Membros[qntmembros];
    int Salvar_Aleatorio[k];

    //Zerando os valores
    for (size_t i = 0; i < k; i++)
    {
        Salvar_Aleatorio[i] = Gerador_de_Numero_Aleatorio(nlines,i,Salvar_Aleatorio);
    }

    //for (size_t i = 0; i < k; i++)
    //{
    //    cout << Salvar_Aleatorio[i] << ' ';
    //}
    

    ifstream infile(str,ios::in);

    string linhas;

    int cont=0,grupo=1;
    char separador;
    while (getline(infile,linhas))
    {
        for (size_t i = 0; i < k; i++)
        {
            if (cont==Salvar_Aleatorio[i])
            {
                istringstream instring(linhas);
                instring >> Lideres[grupo-1].f1 >> separador >> Lideres[grupo-1].f2 >> separador >> Lideres[grupo-1].tipo;
                Lideres[grupo-1].grupo = grupo;
                grupo++;
            }
        }
        cont++;
    }

    //cout << "\nLideres: "<< endl;
    //Lerconteudo(Lideres,k);

    infile.clear();
    infile.seekg(0,ios::beg);
    
    cont=0,grupo=0;//grupo está sendo reutilizado como contador de membros
    while (getline(infile,linhas))
    {
        bool b=true;
        for (size_t i = 0; i < k; i++)
        {
            if (cont==Salvar_Aleatorio[i])
            {
                b=false;
            }
        }

        if (b&&cont!=0)
        {
            istringstream instring(linhas);
            instring >> Membros[grupo].f1 >> separador >> Membros[grupo].f2 >> separador >> Membros[grupo].tipo;
            Membros[grupo].grupo = 0;
            grupo++;
        }
        cont++;
    }

    infile.close();

    //cout << "\nMembros: "<< endl;
    //Lerconteudo(Membros,qntmembros);

    for (size_t i = 0; i < runs; i++)
    {
        Atualizando_grupos_dos_membros(Lideres,k,Membros,qntmembros);
        Atualizando_valor_dos_Lideres(Lideres,k,Membros,qntmembros);
        
        //cout << "\nLideres: "<< endl;
        //Lerconteudo(Lideres,k);
    }

    ofstream outfile(str2, ios::out);

    for (size_t i = 0; i < k; i++)
    {
        outfile << fixed << setprecision(1) << Lideres[i].f1 << ',' << Lideres[i].f2 << ',' << Lideres[i].tipo << ',' << Lideres[i].grupo << endl;
    }

    for (size_t i = 0; i < qntmembros; i++)
    {
        outfile << Membros[i].f1 << ',' << Membros[i].f2 << ',' << Membros[i].tipo << ',' << Membros[i].grupo << endl;
    }
    
    outfile.clear();
    outfile.close();


}

//________________________________________________________________InterpretadorFlor_________________________________________________________________________//

int Contar_Linhas(string str)
{
    ifstream infile(str,ios::in);

    int i = 0;
    
    while (getline(infile, str))
    {
        i++;
    }

    infile.clear();
    infile.close();
    return i;
}

int Gerador_de_Numero_Aleatorio(int max,int j,int Salvar_Aleatorio[])
{
    srand((time(0)*j));
    bool b=true;
    int randow;
    while (b)
    {
        randow = (rand() % (max))+1;
        b = false;
        for (size_t i = 0; i < j; i++)
        {
            if (randow==Salvar_Aleatorio[i])
            {
                b = b + true;
            }
        }
    }
    return randow;
}

void Lerconteudo(Flor data[],int &quantidade)
{
    for (size_t i = 0; i < quantidade; i++)
    {
        cout << "Conteudo: " << endl;
        cout << data[i].f1 << ' ' << data[i].f2 << ' ' << data[i].tipo << ' ' << data[i].grupo << endl;
    }
}

void Atualizando_grupos_dos_membros(Flor * Lideres,int &k, Flor * Membros, int &qntmembros)
{
    for (size_t i = 0; i < qntmembros; i++)
    {
        long double r=0;
        for (size_t j = 0; j < k; j++)
        {
            if (j==0)
            {
                r=sqrt(pow(Lideres[j].f1-Membros[i].f1,2)+pow(Lideres[j].f2-Membros[i].f2,2));
                Membros[i].grupo = Lideres[j].grupo;
            }
            else if (r>sqrt(pow(Lideres[j].f1-Membros[i].f1,2)+pow(Lideres[j].f2-Membros[i].f2,2)))
            {
                r=sqrt(pow(Lideres[j].f1-Membros[i].f1,2)+pow(Lideres[j].f2-Membros[i].f2,2));
                Membros[i].grupo = Lideres[j].grupo;
            }
        }
    }
}

void Atualizando_valor_dos_Lideres(Flor * Lideres,int &k, Flor * Membros, int &qntmembros)
{
    for (size_t i = 0; i < k; i++)
    {
        Lideres[i].f1 = 0;
        Lideres[i].f2 = 0;
        int cont = 0;
        for (size_t j = 0; j < qntmembros; j++)
        {
            if (Lideres[i].grupo==Membros[j].grupo)
            {
                Lideres[i].f1=Lideres[i].f1+Membros[j].f1;
                Lideres[i].f2=Lideres[i].f2+Membros[j].f2;
                cont++;
            }
        }
        Lideres[i].f1=Lideres[i].f1/cont;
        Lideres[i].f2=Lideres[i].f2/cont;
    }
}


//___________________________________________________________________________________________________________________________________________________________//


//________________________________________________________________InterpretadorGlobal________________________________________________________________________//

void InterpretadorGlobal()
{
    string str="iris_petalas.csv",str2="iris_petalas2.csv";
    
    //inserção de dados
    /*
    cout << "Arquivo a ser lido: ";
    getline(cin, str);
    */

    //Definir total de grupos

    int nlines=Cont_Line(str)-1;//Consertar problema da detecção de sequencia incorreta
    cout << "Numero: "<<nlines<<endl;
    
    int k=0;
    while (k<=1||k>nlines)
    {
        cout << "Definir total de grupos: ";
        cin >> k;
        if (k<=1)
        {
            cout << "Numero de grupos tem que ser maiores que 1!" << endl;
        }
        else if (k>=nlines)
        {
            cout << "Numero de grupos ("<< nlines <<") excedido!" << endl;
        }
        
    }

    int runs=0;
    while (runs<1)
    {
        cout << "Definir total de reagrupamento de grupos com base no ponto medio resultante dos membros: ";
        cin >> runs;
        if (runs<1)
        {
            cout << "Numero de vezes tem que ser maiores que 0!" << endl;
        }
    }

    //Terminio da inserção de dados.

    //Valores de distância da tabela ASCII
    char v[] = {'a','z','A','Z','0','9','.','.','"','"'};

    //Identifica o separador
    char separador = Pick_up_separator(str,v,10);

    //Indetifica o padrão da coluna
    int Pattern[6];
    Check_pattern(str,separador,Pattern,6);

    cout << "\nPadrao: ";
    for (size_t i = 0; i < 6; i++)
    {
        cout << Pattern[i] << ' ';
    }
    cout << endl;
    
    _datas_ lideres[k];
    int save_number_randow[k];

    cout << "\n__________Selecionando_Lideres___________";
    for (size_t i = 0; i < k; i++)
    {
        Save_Content_Data_by_Archive_Range(lideres[i],str,separador,Aleatorio(nlines,i,save_number_randow,i),0,Pattern);
        lideres[i].grup=i+1;
    }
    cout << "\n_____________________________________________";

    cout << "\n__________Lendo_Lideres___________";
    for (size_t i = 0; i < k; i++)
    {
        Read_data(&lideres[i]);
    }
    cout << "\n_____________________________________________";
    //pow(144)
    Read_grup(lideres,k);

    cout << "Verifique os numeros sortiados: ";
    for (size_t i = 0; i < k; i++)
    {
        cout << save_number_randow[i] << " ";
    }
    cout << endl;

    int total_de_membros=nlines-k;
    int nmembros[total_de_membros];
    _datas_ membros[total_de_membros];

    int i = 0, conter=0;
    while (i<total_de_membros)
    {
        if (!Check_Number_Egual_Vetor(conter+1,save_number_randow,k))
        {
            Save_Content_Data_by_Archive_Range(membros[i],str,separador,i+1,0,Pattern);//(+2)->Erro de indentificação do primeiro registro "0"
            i++;
        }
        conter++;
    }

    cout << "\n__________Lendo_Membros___________";
    for (size_t i = 0; i < total_de_membros; i++)
    {
        cout << "\nMembro ("<<i+1<<") :";
        Read_data(&membros[i]);
    }
    cout << "\n_____________________________________________";

    for (size_t i = 0; i < runs; i++)
    {
        Selecting_member_numbers(lideres,k,membros,total_de_membros);
        Updating_Leaders(lideres,k,membros,total_de_membros);
        Read_grup(membros,total_de_membros);
        Read_grup(lideres,k);
    }

    Create_a_new_file(str2,lideres,k);
    Rewriting_a_file(str2,membros,total_de_membros);

    deallocate_data(lideres,k);
    deallocate_data(membros,total_de_membros);
}

//Funções_do_InterpretadorGlobal();

void Create_a_new_file(string &str,_datas_ *data, int &k)
{
    ofstream outfile(str,ios::out);

    string text;
    for (size_t i = 0; i < k; i++)
    {
        ostringstream outstring;
        outstring << data[i].fp[0] << ',' << data[i].fp[1] << ',' << data[i].sp[0] << ',' << data[i].grup;
        outfile << outstring.str() << endl;
        text = "";
    }
    outfile.clear();
    outfile.close();
}

void Rewriting_a_file(string &str,_datas_ *data, int &k)
{
    ofstream outfile(str,ios::app);

    string text;
    for (size_t i = 0; i < k; i++)
    {
        ostringstream outstring;
        outstring << data[i].fp[0] << ',' << data[i].fp[1] << ',' << data[i].sp[0] << ',' << data[i].grup;
        outfile << outstring.str() << endl;
        text = "";
    }
    outfile.clear();
    outfile.close();
}


void Updating_Leaders(_datas_ *lideres, int &k, _datas_ *membros, int &total_de_membros)
{
    //Atualizar os lideres
    for (size_t i = 0; i < k; i++)
    {
        pontomédio pm;
        int cont = 0;
        for (size_t j = 0; j < total_de_membros; j++)
        {
            //cout << "Comparador de " << lideres[i].grup << " para "<< membros[j].grup << endl;
            if (lideres[i].grup==membros[j].grup)
            {
                pm.x=pm.x+membros[j].fp[0];
                pm.y=pm.y+membros[j].fp[1];
                cont++;
                cout << "\nValor pm(x) (" << pm.x << ") e pm(y) (" << pm.y << ") e cont (" << cont << ')' << endl;
            }
        }
        cout << "\nLider do grupo ["<< lideres[i].grup <<"] Atualizou valor da largura (" << lideres[i].fp[0] << ") e altura (" << lideres[i].fp[1] << ") ";
        lideres[i].fp[0]=pm.x/cont;
        lideres[i].fp[1]=pm.y/cont;
        cout << "para: largura (" << lideres[i].fp[0] << ") e altura (" << lideres[i].fp[1] << ") "<< endl;
        cont=0;
        pm.x=0;
        pm.y=0;
    }
}

void Selecting_member_numbers(_datas_ *lideres, int &k, _datas_ *membros, int &total_de_membros)
{
    //Selecionando grupo dos membros
    for (size_t i = 0; i < total_de_membros; i++)
    {
        long double r,save;
        int Save_Nearest_Leader;
        for (size_t j = 0; j < k; j++)
        {
            r = sqrt(pow(lideres[j].fp[0]-membros[i].fp[0],2)+pow(lideres[j].fp[1]-membros[i].fp[1],2));

            if (j==0)
            {
                Save_Nearest_Leader = j;
                save = r;   
            }
            else if (r<save)
            {
                Save_Nearest_Leader = j;
                save = r;
            }
        }
        membros[i].grup=Save_Nearest_Leader+1;//Número está sendo representado 1 acima nos lideres, o número zero é utilizado para dizer que não tem ninguem
    }
}


//VERICA A IGUALDADE DE NÚMEROS

bool Check_Number_Egual_Vetor(int n1,int nv[], int tamanho)
{
    bool b = false;
    for (size_t i = 0; i < tamanho; i++)
    {
        b = b + Check_Number_Egual(n1,nv[i]);
    }
    return b;
}

bool Check_Number_Egual(int n1, int n2)
{
    if (n1==n2)
    {
        return true;
    }
    return false;
}


//CONTA TOTAL DE LINHAS

int Cont_Line(string &arquivo)
{
    ifstream inpetalas(arquivo,ios::in);
    _datas_ data;
    string linhas;
    int cont=0;
    while (getline(inpetalas,linhas))
    {
        cont++;
    }
    cout << "Cont: " << cont << endl;
    int qnt=1;
    deallocate_data(&data,qnt);
    inpetalas.close();
    return cont;
}


//IDENTIFICA O PADRAO DA COLUNA
//stamanho = vetor que será decorado o padrão
//ele só indentifica o conteudo do arquivo de forma "contagórica" e não sequencil! Não é atoa que o vetor de padrão é int.
void Check_pattern(string &arquivo,char &separador,int *stamanho,int tamanho)
{
    cout << "\n__________Indentificando_Padrao___________";
    _datas_ data;
    ifstream inpetalas(arquivo,ios::in);
    string linhas;

    for (size_t i = 0; i < tamanho; i++)
    {
        *(stamanho+i)=0;
    }
    
    bool check = true;
    while (getline(inpetalas,linhas))
    {
        Cut_string_by_separator(data,linhas,separador);
        
        for (size_t i = 0; i < tamanho; i++)
        {
            if (*(stamanho+i)!=data.tamanho[i])
            {
                check = check * false; 
            }
            
            *(stamanho+i)=data.tamanho[i];
            data.tamanho[i]=0;
        }
        
        if (check)
        {
            break;
        }
        check = true;
    }
    inpetalas.clear();
    inpetalas.close();
    Read_data(&data);
    cout << "\n_____________________________________________";
}


//SALVA CONTEUDO _DATA_ DO ARQUIVO LIDO

void Save_Content_Data_by_Archive(_datas_ &data,string &arquivo,char &separador,int *padrao)
{
    ifstream inpetalas(arquivo,ios::in);
    string linhas;
    
    cout << "teste:"<<separador;
    while (getline(inpetalas,linhas))
    {
        Cut_string_by_separator(data,linhas,separador,padrao);
    }
    inpetalas.close();
    Read_data(&data);
}

void Save_Content_Data_by_Archive_Range(_datas_ &data,string &arquivo,char &separador,int sgetr,int egetr,int *padrao)
{
    ifstream inpetalas(arquivo,ios::in);
    string linhas;

    cout << " Separador: " << separador << " Range1: " << sgetr << " Range2: " << egetr << endl;


    int cont=0;
    while (getline(inpetalas,linhas))
    {
        if(((sgetr<=cont&&cont<=egetr)&&(sgetr!=0&&egetr!=0))||((sgetr==cont)&&(sgetr!=0)))
        {
            Cut_string_by_separator(data,linhas,separador,padrao);
        }

        cont++;
    }
    inpetalas.close();
    Read_data(&data);
}

void Cut_string_by_separator(_datas_ &data,string &linhas,char &separador,int *padrao)//padrao "impede de aconteça erros"
{
    cout << "\n\nLinha: " << linhas << endl;
    while (linhas.find(separador)<18446744073709)
    {
        string piece;
        //piece = str.substr(inicial, n);
        piece = piece_copy(linhas,linhas.find(separador),0);

        //interpretar o pedaço para seu valor-------------
        linhas = piece_copy(linhas,linhas.length(),linhas.find(separador)+1);

        cout << "Piece: " << piece << " Modificacao: " << linhas << endl;

        Type_separator_save(piece,&data,padrao); 
    }
    Type_separator_save(linhas,&data,padrao);
    //Save completo em todos dados 
}


//SEPARADORES

string piece_copy(string &str,int n,int inicial)
{
    //cout << str;
    string newword = "";
    for (int i = inicial; i < n; i++)
    {
        //cout << "Letra da nova palavra: " << str[i] << endl;
        newword = newword + str[i];
    }
    //cout << "Newword: " << newword << endl;
    return newword;
}

void Type_separator_save(string piece,_datas_ *des,int *padrao)
{
    cout << "Alocando conteudo: (" << piece <<')'<< endl;
    int tipos[5]={0,0,0,0,0};
    for (int i = 0; i < piece.length(); i++)
    {
        if (Checker_char(piece[i],'0','9'))
        {
            tipos[0]++;
            //cout << "0-9 " << tipos[0] << " de " << piece[i] << " Tipo0 atualizado:" << tipos[0] << endl;
        }
        else if (Checker_char(piece[i],'.','.'))
        {
            tipos[1]++;
            //cout << ".-. " << tipos[1] << " de " << piece[i] << " Tipo1 atualizado:" << tipos[1] << endl;
        }
        else if (Checker_char(piece[i],'a','z'))
        {
            tipos[2]++;
            //cout << "a-b " << tipos[2] << " de " << piece[i] << " Tipo2 atualizado:" << tipos[2] << endl;
        }
        else if (Checker_char(piece[i],'A','Z'))
        {
            tipos[3]++;
            //cout << "A-B " << tipos[3] << " de " << piece[i] << " Tipo3 atualizado:" << tipos[3] << endl;
        }
        else
        {
            tipos[4]++;
            //cout << "? " << tipos[4] << " de " << piece[i] << " Tipo4 atualizado:" << tipos[4] << endl;
        }
    }
    //char - somente 1 digito(qualquer caractere)
    //string - {'a','z','A','Z','0','9','.','.','"','"'};(qualquer caractere)
    //int - '0','9'
    //float - '0','9','.','.'
    //double - '0','9','.','.' muito digito para direita.

    cout << "Conteudo de tipos [" << tipos[0];
    for (size_t i = 1; i < 5; i++)
    {
        cout <<", "<< tipos[i];
    }
    cout << ']' << endl;
    

    if ((piece.length()==1&&(piece=="1"||piece=="0"||piece=="true"||piece=="false")&&padrao==nullptr)||(piece.length()==1&&(piece=="1"||piece=="0"||piece=="true"||piece=="false")&& *(padrao+0)!=0 && padrao != nullptr))
    {
        cout <<"Caminho bool"<<endl;
        //bool
        Resize_ptr_bool(des);
        des->bp[des->tamanho[0] - 1] = (piece == "1" || piece == "true");
    }
    else if (((piece.length()==1&&(tipos[0]>0 && tipos[1]>0 && tipos[2]>0 && tipos[3]>0 && tipos[4]>0))&&padrao==nullptr)||(piece.length()==1&&(tipos[0]>0 && tipos[1]>0 && tipos[2]>0 && tipos[3]>0 && tipos[4]>0)&&*(padrao+1)!=0 && padrao != nullptr))
    {
        cout << "Caminho char"<<endl;
        //char
        Resize_ptr_char(des);
        istringstream(piece) >> des->cp[des->tamanho[1] - 1];
    }
    else if ((tipos[0]>0 && tipos[1]==0 && tipos[2]==0 && tipos[3]==0 && tipos[4]==0 && padrao == nullptr)||(tipos[0]>0 && tipos[1]==0 && tipos[2]==0 && tipos[3]==0 && tipos[4]==0 &&*(padrao+2)!=0 && padrao != nullptr))
    {
        cout <<"Caminho int"<<endl;
        //int
        Resize_ptr_int(des);
        istringstream(piece) >> des->ip[des->tamanho[2] - 1];
    }
    else if ((tipos[0]>0 && tipos[1]>=0 && tipos[2]==0 && tipos[3]==0 && tipos[4]==0 && padrao == nullptr)||(tipos[0]>0 && tipos[1]>=0 && tipos[2]==0 && tipos[3]==0 && tipos[4]==0 &&*(padrao+3)!=0 && padrao != nullptr))
    {
        cout <<"Caminho float"<<endl;
        //float
        Resize_ptr_float(des);
        istringstream(piece) >> *(des->fp + (des->tamanho[3] - 1));
    }
    else
    {
        cout << des->tamanho[5] << " Caminho string"<<endl;
        //string
        Resize_ptr_string(des);
        des->sp[des->tamanho[5] - 1] = piece;
    }
}


//LEITORES DO CONTEUDO

void Read_data(_datas_ *des)
{
    cout << endl << "Read: ";
    if (des->tamanho[0]!=0)
    {
        cout << endl << "Conteudo bool: ";
        for (size_t i = 0; i < des->tamanho[0]; i++)
        {
            cout << des->bp[i] << ' ';
        }
    }

    if (des->tamanho[1]!=0)
    {
        cout << endl << "Conteudo char: ";
        for (size_t i = 0; i < des->tamanho[1]; i++)
        {
            cout << des->cp[i] << ' ';
        }
    }
    if (des->tamanho[2]!=0)
    {
        cout << endl << "Conteudo int: ";
        for (size_t i = 0; i < des->tamanho[2]; i++)
        {
            cout << des->ip[i] << ' ';
        }
    }
    if (des->tamanho[3]!=0)
    {
        cout << endl <<"Conteudo float: ";
        for (size_t i = 0; i < des->tamanho[3]; i++)
        {
            cout << des->fp[i] << ' ';
        }
    }
    if (des->tamanho[4]!=0)
    {
        cout << endl << "Conteudo double: ";
        for (size_t i = 0; i < des->tamanho[4]; i++)
        {
            cout << des->dp[i] << ' ';
        }
    }
    if (des->tamanho[5]!=0)
    {
        cout << endl << "Conteudo string: ";
        for (size_t i = 0; i < des->tamanho[5]; i++)
        {
            cout << des->sp[i] << ' ';
        }
    }
    cout << endl;
}

void Read_grup(_datas_ *ptr,int k)
{
    cout << endl << "Read grup: ";
    if (ptr!=nullptr)
    {
        for (size_t i = 0; i < k; i++)
        {
            cout << (ptr+i)->grup << ' ';
        }
    }
    cout << endl;
}


//MODIFICADOR DO TAMANHO DA STRUCT _DATA_

void Resize_ptr_bool(_datas_ *ptr)
{
    bool * b = new bool [ptr->tamanho[0]+1];
    for (size_t i = 0; i < ptr->tamanho[0]; i++)
    {
        b[i] = ptr->bp[i];
    }
    ptr->tamanho[0] = ptr->tamanho[0] + 1;
    delete [] ptr->bp;
    ptr->bp = b;
}
void Resize_ptr_char(_datas_ *ptr)
{
    char * c = new char [ptr->tamanho[1]+1];
    for (size_t i = 0; i < ptr->tamanho[1]; i++)
    {
        c[i] = ptr->cp[i];
    }
    ptr->tamanho[1] = ptr->tamanho[1] + 1;
    delete [] ptr->cp;
    ptr->cp = c;
}
void Resize_ptr_int(_datas_ *ptr)
{
    int * in = new int [ptr->tamanho[2]+1];
    for (size_t i = 0; i < ptr->tamanho[2]; i++)
    {
        in[i] = ptr->ip[i];
    }
    ptr->tamanho[2] = ptr->tamanho[2] + 1;
    delete [] ptr->ip;
    ptr->ip = in;
}
void Resize_ptr_float(_datas_ *ptr)
{
    float * f = new float [ptr->tamanho[3]+1];
    for (size_t i = 0; i < ptr->tamanho[3]; i++)
    {
        f[i] = ptr->fp[i];
    }
    ptr->tamanho[3] = ptr->tamanho[3] + 1;
    delete [] ptr->fp;
    ptr->fp = f;
}
void Resize_ptr_double(_datas_ *ptr)
{
    double * d = new double [ptr->tamanho[4]+1];
    for (size_t i = 0; i < ptr->tamanho[4]; i++)
    {
        d[i] = ptr->dp[i];
    }
    delete [] ptr->dp;
    ptr->tamanho[4] = ptr->tamanho[4] + 1;
    ptr->dp = d;
}

void Resize_ptr_string(_datas_ *ptr)
{
    string * s = new string [ptr->tamanho[5]+1];
    for (size_t i = 0; i < ptr->tamanho[5]; i++)
    {
        s[i] = ptr->sp[i];
    }
    ptr->tamanho[5] = ptr->tamanho[5] + 1;
    delete [] ptr->sp;
    ptr->sp = s;
}

void deallocate_data(_datas_ *des,int &qnt)
{
    for (size_t i = 0; i < qnt; i++)
    {
        delete[]des[i].bp;
        delete[]des[i].cp;
        delete[]des[i].ip;
        delete[]des[i].fp;
        delete[]des[i].dp;
        delete[]des[i].sp;
    }
    cout << "Conteudo Data Eliminado" << endl;
}

void Size_Reset(_datas_ &ptr)
{
    for (size_t i = 0; i < 6; i++)
    {
        ptr.tamanho[i] = 0;
    }
}


//ALEATORIO

//Verifica a igualdade de um número de um vetor do próprio vetor com base no número solicitado ele verifica o todas posições anteriores em comparação com a atual
bool Check_Egual_Randow(int save_number_randow[], int tamanho)
{
    bool b = false;
    for (size_t i = 0; i < tamanho; i++)
    {
        if (save_number_randow[i]==save_number_randow[tamanho])
        {
            cout << "Numero igual: " << save_number_randow[i] << "=" << save_number_randow[tamanho] << endl;
            b = true;  
        }
    }
    return b;
}

//Gera um número aleatório, se o usuario inserir um vetor eo i, o número será salvo no exato valor que o ultimo parametro representa
//aleatorizador só deixa o número mais aleatório
int Aleatorio(int max,int aleatorizador, int save_number_randow[], int i)
{
    srand((time(0)*aleatorizador));
    if (i != -1)
    {
        save_number_randow[i] = (rand() % (max))+1;
        while (Check_Egual_Randow(save_number_randow,i))
        {
            save_number_randow[i] = (rand() % (max-1))+1;
        }
        cout << "Numero Encontrado: " << save_number_randow[i] << endl;
        return save_number_randow[i];
    }
    else
    {
        return (rand() % (max))+1;
    }
}


//SEPARADOR

//Verificar se o char é igual(true se for igual, false para desigual)
bool Checker_char(char &c,char range1,char range2)
{
    bool r = false;
    for (size_t j = (size_t) range1; j <= (size_t) range2; j++)
    {  
        if ((size_t) c == (size_t) j)
        {
            r = true;
        } 
    }
    return r;
}

//Verifica a igualdade de um caracter para um vetor de caracter e se tiver algum = retorna true caso contrario false
bool Checker_range_char(char& c,char vetor[],int size)
{
    //Verificador
    bool r = false;
    //Tabela ASCII
    //size tem que ser par
    if ((size != 0) && (size % 2 == 0) && (size > 0))
    {
        size = (size / 2);
        for (int i = 0; i < size; i++)
        {
            r = r + Checker_char(c,vetor[0+(i*2)],vetor[1+(i*2)]);//Envia em par
        }
    }
    else
    {
        cout << "Erro de incoerencia!";
    }
    return r;
}

//Analisa o total de caracteres não especificados eos conta e retorna o com maior frequência
char Pick_up_separator(string arquivo, char vetor[], int size)
{
    cout << "\n__________Indentificando_Separador___________";
    ifstream inpetalas(arquivo,ios::in);

    int cont=0;
    char *ptrchar = (char*) malloc(sizeof(char)*cont);
    int *ptrint = (int*) malloc(sizeof(int)*cont);

    int ondeexiste = -1;
    char separador = ' ';
    string linhas;
    cout << "\nCaracter analizado: ";
    while (getline(inpetalas,linhas))
    {
        for (int i = 0; i < linhas.length(); i++)
        {
            char c = linhas[i];
            //"Ondeexiste" basicamente serve como localizador e contador para ptrint
            if (!Checker_range_char(c,vetor,size))
            {
                for (int i = 0; i < cont; i++)
                {
                    if (c == *(ptrchar+i))
                    {
                        ondeexiste = i;
                    }
                }

                if (ondeexiste>-1)
                {
                    *(ptrint+ondeexiste)=*(ptrint+ondeexiste) + 1;
                }
                else
                {
                    cont++;
                    ptrchar = (char*) realloc(ptrchar,sizeof(char)*cont);
                    ptrint = (int*) realloc(ptrint,sizeof(int)*cont);
                    *(ptrchar+cont-1) = c;
                    *(ptrint+cont-1) = 1;
                }
                ondeexiste = -1;
                cout << "'" << c << "' ";
            } 
        }
    }
    cout << endl;

    int maior=0;
    for (int i = 0; i < cont; i++)
    {
        cout << "Simbolo: '"<< *(ptrchar+i) << "' Repeticao: " << *(ptrint+i) << endl;
        if (*(ptrint+i)>maior)
        {
            separador = *(ptrchar+i);
        }   
    }
    
    free(ptrchar);
    free(ptrint);
    inpetalas.close();
    cout << "\n_____________________________________________";
    return separador;
}

//___________________________________________________________________________________________________________________________________________________________//