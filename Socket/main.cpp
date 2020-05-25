#include <iostream>
#include <WinSock2.h>
//#include <Windows.h>
#include <WS2tcpip.h>

#pragma comment(lib, "Ws2_32.lib")

//struct in_addr {
//    union {
//        struct {
//            uint8_t s_b1, s_b2, s_b3, s_b4;
//        } S_un_b;
//        struct {
//            uint16_t s_w1, s_w2;
//        } S_un_w;
//        uint32_t S_addr;
//    } S_un;
//};
//
//struct sockaddr_in {
//    short sin_family;
//    uint16_t sin_port;
//    struct in_addr sin_addr;
//    char sin_zero[8];
//};

// Creating socket address, representing port 80
// and IP-address 65.254.248.180
int main()
{
    //WSADATA WSAData;
    //WSAStartup(MAKEWORD(2, 2), &WSAData);

    sockaddr_in myAddr;

    //// «аполн€ем siz_zero нул€ми, чтобы привести размер sockaddr_in
    //// в соотсветствие с размером sockaddr
    memset(myAddr.sin_zero, 0, sizeof(myAddr.sin_zero));
    myAddr.sin_family = AF_INET;

    //// “.к. 80 - это многобайтное число, оно должно преобразовыватьс€
    //// из аппаратного пор€дка следовани€ байтов, используемого на
    //// данном компьютере, в сетевой
    myAddr.sin_port = htons(80);
    myAddr.sin_addr.S_un.S_un_b.s_b1 = 65;
    myAddr.sin_addr.S_un.S_un_b.s_b2 = 254;
    myAddr.sin_addr.S_un.S_un_b.s_b3 = 248;
    myAddr.sin_addr.S_un.S_un_b.s_b4 = 180;

    //WSACleanup();

    std::cout << "Hello World!\n";
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
