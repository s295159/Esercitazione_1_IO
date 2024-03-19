//Write a program which reads the values from a file of name data.csv
//1. The file contains a list with N values in [1, 5].
//2. Write a function that maps points in the interval [−1, 2].
//3. For each i = 1, . . . , N, compute the mean of the first i mapped values.
// Finally, print the result in a file result.csv of the following format:

#include <iostream>
#include <fstream>
#include <iomanip> // serve per setprecision e scientific
using namespace std;

//2. Write a function that maps points in the interval [−1, 2]
double mapsPoints(double x)
{
    // Devo traslare i punti dall'intervallo di partenza [1,5]
    // al nuovo intervallo [-1,2] ottenendo quindi
    // xNuovo = (3/4)*x - 7/4
    double xNuovo = 0.75*x-1.75;
    return xNuovo;

}

int main(void)
{
    string fileName = "data.csv"; // file name
    ifstream ifstr(fileName);

    if(ifstr.fail())
    {
        cerr << "File does not exist" << endl;
        return 1;
    }
    else
    {
        // se invece il file esiste procedo nella eventale creazione del nuovo
        // file output, questo volta non in modalità lettura ma in modalità scrittura
        string fileName2 = "result.csv";
        ofstream ofs(fileName2);

        // inizio scrivendo l'Header
        ofs << "# Name" << endl;

        double valore; // il mio valore in input
        double somma = 0; // somma dei valori
        int unsigned i = 1; // indice che ni servirà per la media

        while( ifstr >> valore ) // leggo tutto il file : data.csv
        {
            // Per ogni i = 1, . . . , N, calcola
            // la media dei primi valori i mappati
            double xMappato = mapsPoints(valore) ; // valore assume il ruolo di x all'interno della funzione
            somma += xMappato ; // somma dei valori traslati
            double media = somma/i;
            // quindi lo scrivo sul file result.csv
            // in particolare stampare in questo formato
            // 1 1.5205631514641289e+00 ( indice poi media )
            ofs << i << "  "<< scientific << setprecision(16) << media << endl;
            // scientific mi da il numero in notazione scientifica
            // setprecision(16) ho 16 cifre significative dopo la virgola
            i++; //incremento l'indice
        }
        ofs.close();
        ifstr.close();



    }
    return 0;
}
