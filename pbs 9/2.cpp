#include <iostream>
#include <cctype>

using namespace std;

int main()
{
    enum State {
        H,
        A,
        AB,
        AC,
        ABC,
        AS,
        ABS,
        ACS,
        ABCS,
        ERR
    };

    int c;
    State st = H;

    while ((c = cin.get()) >= 0) {
        switch (st) {
            case H:
            if (c == '0') {
                st = A;
            } else if (c == '1') {
                st = AB;
            } else if (isspace(c)) {
            } else {
                cout << '0' << endl;
                st = ERR;
            }
            break;
            case A:
            if (c == '0') {
                st = A;
            } else if (c == '1') {
                st = AB;
            } else if (isspace(c)) {
                cout << '0' << endl;
                st = H;
            } else {
                cout << '0' << endl;
                st = ERR;
            }
            break;
            case AS:
            if (c == '0') {
                st = A;
            } else if (c == '1') {
                st = AB;
            } else if (isspace(c)) {
                cout << '1' << endl;
                st = H;
            } else {
                cout << '0' << endl;
                st = ERR;
            }
            break;
            case AB:
            if (c == '0') {
                st = AC;
            } else if (c == '1') {
                st = ABC;
            } else if (isspace(c)) {
                cout << '0' << endl;
                st = H;
            } else {
                cout << '0' << endl;
                st = ERR;
            }
            break;
            case ABS:
            if (c == '0') {
                st = AC;
            } else if (c == '1') {
                st = ABC;
            } else if (isspace(c)) {
                cout << '1' << endl;
                st = H;
            } else {
                cout << '0' << endl;
                st = ERR;
            }
            break;
            case AC:
            if (c == '0') {
                st = AS;
            } else if (c == '1') {
                st = ABS;
            } else if (isspace(c)) {
                cout << '0' << endl;
                st = H;
            } else {
                cout << '0' << endl;
                st = ERR;
            }
            break;
            case ACS:
            if (c == '0') {
                st = AS;
            } else if (c == '1') {
                st = ABS;
            } else if (isspace(c)) {
                cout << '1' << endl;
                st = H;
            } else {
                cout << '0' << endl;
                st = ERR;
            }
            break;
            case ABC:
            if (c == '0') {
                st = ACS;
            } else if (c == '1') {
                st = ABCS;
            } else if (isspace(c)) {
                cout << '0' << endl;
                st = H;
            } else {
                cout << '0' << endl;
                st = ERR;
            }
            break;
            case ABCS:
            if (c == '0') {
                st = ACS;
            } else if (c == '1') {
                st = ABCS;
            } else if (isspace(c)) {
                cout << '1' << endl;
                st = H;
            } else {
                cout << '0' << endl;
                st = ERR;
            }
            break;
            case ERR:
            if (isspace(c)) {
                st = H;
            }
            break;
        }
    }
    switch (st) {
        case ERR:
        case H:
        break;
        case AS:
        case ABS:
        case ACS:
        case ABCS:
        cout << '1' << endl;
        break;
        case A:
        case AB:
        case AC:
        case ABC:
        cout << '0' << endl;
        break;
    }

    return 0;
}