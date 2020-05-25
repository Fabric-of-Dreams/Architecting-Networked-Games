// Unions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

struct S {
    union
    {
        int32_t n;     // occupies 4 bytes
        uint16_t a[2]; // occupies 4 bytes
        uint8_t c;     // occupies 1 byte
    };                 // the whole union occupies 4 bytes
};

struct S2 {
    union
    {
        int32_t n;     // occupies 4 bytes
        uint16_t a[2]; // occupies 4 bytes
        uint8_t c;     // occupies 1 byte
        struct {
            uint8_t s_b1, s_b2, s_b3, s_b4;
        } S_un_b;
    };                 
};

struct in_addr {
    union {
        struct {
            uint8_t s_b1, s_b2, s_b3, s_b4;
        } S_un_b;
    };
};

int main()
{
    S2 s = { 0x12345678 }; // hexadecimal integer
    // initializes the first member, s.n is now the active member
    // at this point, reding from s.s or s.c is undefined behavior
    cout << hex << "s.n = " << s.n << endl;
    s.a[0] = 0x0011; // s.a is now the active member
    // at this point, reading from n or c is UB but most compilers dfine it
    cout << "s.c = " << +s.c << endl; // 11 or 00, depending on platforms
    cout << "s.n = " << s.n << endl; //12340011 or 00115678
    s.S_un_b.s_b1 = { 0xff };

    in_addr i = { 0x12345678 };
    cout << "i.size = " << sizeof(i) << endl;
    cout << "i.S_un_b.s_b1 = " << +i.S_un_b.s_b1 << endl;
    cout << "i.S_un_b.s_b2 = " << +i.S_un_b.s_b2 << endl;
    cout << "i.S_un_b.s_b3 = " << +i.S_un_b.s_b3 << endl;
    cout << "i.S_un_b.s_b4 = " << +i.S_un_b.s_b4 << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
