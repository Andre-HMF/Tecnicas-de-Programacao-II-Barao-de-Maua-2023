/*

unsigned int refat(unsigned int n);



//--------------

//Fatorial Recursivo (Alto uso de memoria em alta escala)
unsigned int refat(unsigned int n)
{
    if(n==0)
    {
        return 1;
    }
    else
    {
        return (n * refat(n-1));
    }
}

//str.erase
//str.insert
//str.length
//str.assign(str,strat,N);
//str.at
//str.append
//string str1("Cat");
//string str2 = "Cat";
//str.substr
//str.swap
//x=x+y
//y=x-y
//x=x-y


*/