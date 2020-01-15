#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <stdio.h>

#define WIN 1
#define UNI 0

using namespace std;

bool getFileType(string path) {
    ifstream is(path.c_str(), ifstream::binary);
    char byte[1];
    while(!is.eof()) {
        is.read(byte, 1);
        if(byte[0] == '\r') {
            is.close();
            return WIN;
        }
        if(byte[0] == '\n') {
            is.close();
            return UNI;
        }
    }
    is.close();
    return(0);
}

bool winToUnix(string path) {
    ifstream is(path.c_str(), ifstream::in | ifstream::binary);
    ofstream os("buf.bin", ofstream::out | ifstream::binary);
    char byte[1];
    while(!is.eof()) {
        is.read(byte, 1);
        if(byte[0] != '\r') {
            os.write(byte, 1);
        }
        else
            continue;
    }
    if(byte[0] != '\n')
        os.write("\n", 1);
    os.close();
    is.close();
    return(0);
}

bool unixToWin(string path) {
    ifstream is(path.c_str(), ifstream::in | ifstream::binary);
    ofstream os("buf.bin", ofstream::out | ifstream::binary);
    char byte[1];
    while(!is.eof()) {
        is.read(byte, 1);
        if(byte[0] == '\n')
            os.write("\r\n", 2);
        else
            os.write(byte, 1);
    }
   if(byte[0] != '\n')
        os.write("\r\n", 2);
    os.close();
    is.close();
    return(0);
}

int main(int argc, char** argv) {
    if(argc == 1 || argc>3) {
        cout << "usage: zad20 [-unix|-win] file AAA" << endl;
        return 0;
    }
    if(argc == 2) {
        cout << "file: " << argv[1] << " is a ";
        if(getFileType(argv[1]) == WIN) {
            cout << "windows file" << endl;
            return 0;
        } else {
            cout << "unix file" << endl;
            return 0;
        }
    }
    if(argc == 3) {
        // 1 - type
        // 2 - filename
        if(strcmp(argv[1], "-unix") == 0) {
            if(getFileType(argv[2]) == UNI) {
                cout << "file: " << argv[2] << " is a unix file - not converted" << endl;
                return 0;
            }
          winToUnix(argv[2]);
            remove(argv[2]);
            rename("buf.bin", argv[2]);
        } else if(strcmp(argv[1], "-win") == 0) {
            if(getFileType(argv[2]) == WIN) {
                cout << "file: " << argv[2] << " is a windows file - not converted" << endl;
                return 0;
            }
            unixToWin(argv[2]);
            remove(argv[2]);
            rename("buf.bin", argv[2]);
        } else {
            cout << "usage: zad20 [-unix|-win] file" << endl;
            return 0;
        }
    }
}

