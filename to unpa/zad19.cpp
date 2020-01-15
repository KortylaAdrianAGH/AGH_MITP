#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main (int argc, char *argv[]){
  if (argc != 2){
      cout << "$zad19" << endl;
      cout << "usage: zad19 file" << endl;
    return 0;
    }
      fstream plik;
      plik.open (argv[1], ios::in);
      if (plik.good () == false){
          cout << "Plik nie istnieje" << endl;
          exit (0);
        }
      string wiersz;
      int nr_wiersza = 0;
      while (getline (plik, wiersz)){
          if (wiersz != "\0"){
              nr_wiersza++;
            }
        }
      plik.close ();
      cout << "file: ";
      cout << argv[1];
      cout << " zawiera ";
      cout << nr_wiersza;
      cout << " wierszy" << endl;
      return 0;
}





