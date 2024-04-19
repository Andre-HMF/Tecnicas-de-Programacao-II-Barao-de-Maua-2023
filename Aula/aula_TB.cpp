#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct registro
{
    int x;
    double d;
};
typedef struct registro registro;


int main()
{

    ofstream fw("saida.txt");
    fw<<"guardando alguma coisa no arquivo" <<endl;
    fw.close();

    ifstream fr("saida.txt");
    string buf;
    getline(fr,buf);
    cout << buf << endl;
    fr.close();
    //seekp()=>put=>escrita
    //seekg()=>get=>leitura
    //      ^->(qtd bytes, referencial:beg,end,cur)

    ifstream fr2("saida.txt");

    char c;
    fr2.seekg(4,ios::beg);
    fr2.get(c);
    cout<<c<<endl;

    fr2.seekg(-7,ios::end);
    fr2.get(c);
    cout<<c<<endl;
    //eof()->conta como carctere
    //\n->conta como carctere

    //fr2.seekg(10,ios::beg)
    //fr2.get(fr2,buf)
    //cout << fr2<< endl;
    fr2.close();

    fstream f("saida.txt",ios::in|ios::out);
    f.seekp(10,ios::beg);
    f.put('A');
    f.seekp(6,ios::cur);
    f.put('C');
    f.seekg(0,ios::beg);
    getline(f,buf);
    cout<<buf<<endl;
    f.close();
    //seekp e seekg são o mesmo ponteiro!

    const int tam = 3;
    registro registros[tam]={{1,1.1},{2,2.2},{3,3.3}};

    fstream fb("registros.dat",ios::out | ios::binary);
    fb.write(reinterpret_cast<char *>(registros),tam*sizeof(registro));
    fb.close();
    fb.open("registro.dat",ios::in | ios::binary);
    f.seekg(1*sizeof(registro),ios::beg);

    registro temp;
    fb.read(reinterpret_cast<char *>(&temp),sizeof(registro));
    cout << temp.x<<","<<temp.d<<endl;
    fb.close();

    temp.x=4;
    tem.d=4.4;

    fb.open("registros.dat",ios::in | ios::out | ios::binary);

    fb.seekp(1*sizeof(registro),ios::beg);
    fb.write(reinterpret_cast<char*>(&temp),sizeof(registro));
    fb.seekg(0,ios::beg);

    registro registro_1[3];
    fb.read(reinterpret_cast<char*>(&registro_1),3*sizeof(registro));

    for (int i = 0; i < 3; i++)
    {
        cout <<registro_1[i].x<<","<<registro_1[i].d<<endl;
    }
    

    return 0;
}