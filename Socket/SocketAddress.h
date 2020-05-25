#pragma once
#include <iostream>
#include <WinSock2.h>
#include <WS2tcpip.h>

#pragma comment(lib, "Ws2_32.lib")

using namespace std;

class SocketAddress
{
public:
	SocketAddress(uint32_t inAddress, std::uint16_t inPort);
	SocketAddress(const sockaddr& inSockAddr);
	size_t GetSize() const;

private:
	sockaddr mSockAddr;
	sockaddr_in* GetAsSockAddrIn();
};

