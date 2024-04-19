#include <iostream>
using namespace std;

int main(){
    float notas[4][3];

    for (int i=0;i<4;i++)
    {
        for (int j=0;j<3;j++)
        {
            cout << "Salve seu numero de " << i << " x " << j << endl;
            cin >> notas[i][j];
        }
    }

    for (int i=0;i<4;i++)
    {
        for (int j=0;j<3;j++)
        {
            cout << notas[i][j];
        }
        cout << endl;
    }
}