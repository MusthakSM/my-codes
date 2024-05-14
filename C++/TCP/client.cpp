#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>
using namespace std;

int main()
{
    // WSAStartup
    WSADATA wsaData;
    int wserr;
    WORD wVersionRequested = MAKEWORD(2, 2);
    wserr = WSAStartup(wVersionRequested, &wsaData);
    if (wserr != 0)
    {
        cout << "The winsock dll not found" << endl;
        return 0;
    }
    else
    {
        cout << "The Winsock dll found" << endl;
        cout << "The status: " << wsaData.szSystemStatus << endl;
    }

    // Socket creation
    SOCKET clientSocket;
    clientSocket = INVALID_SOCKET;
    clientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (clientSocket == INVALID_SOCKET)
    {
        cout << "Error at socket(): " << WSAGetLastError() << endl;
        WSACleanup();
        return 0;
    }
    else
    {
        cout << "Socket is OK!" << endl;
    }

    // Connection to server
    sockaddr_in clientService;
    clientService.sin_family = AF_INET;
    clientService.sin_addr.s_addr = inet_addr("127.0.0.1");
    clientService.sin_port = htons(32000);
    if (connect(clientSocket, (SOCKADDR *)&clientService, sizeof(clientService)) == SOCKET_ERROR)
    {
        cout << "Client: connect() - Failed to connect: " << WSAGetLastError() << endl;
        closesocket(clientSocket);
        WSACleanup();
        return 0;
    }
    else
    {
        cout << "Client: Connect() is OK!" << endl;
        cout << "Client: Can start sending and receiving data..." << endl;
    }

    // Sending and receiving loop
    while (true)
    {
        // Sending data
        char sendBuffer[200];
        cout << "Enter the message to send: ";
        cin.getline(sendBuffer, 200);
        int sbyteCount = send(clientSocket, sendBuffer, strlen(sendBuffer), 0);
        if (sbyteCount == SOCKET_ERROR)
        {
            cout << "Server send error: " << WSAGetLastError() << endl;
            closesocket(clientSocket);
            WSACleanup();
            return -1;
        }
        else
        {
            cout << "Client: Sent " << sbyteCount << " bytes" << endl;
        }

        // Check if the received message is "QUIT"
        if (strcmp(sendBuffer, "QUIT") == 0)
        {
            cout << "Client has terminated the program..." << endl;
            closesocket(clientSocket);
            break; // Exit the loop to terminate the server
        }

        // Receive data from client
        char receiveBuffer[200];
        int rbyteCount = recv(clientSocket, receiveBuffer, sizeof(receiveBuffer), 0);
        if (rbyteCount <= 0)
        {
            cout << "Receive failed with error: " << WSAGetLastError() << endl;
            closesocket(clientSocket);
            continue; // Move to the next iteration of the loop
        }

        receiveBuffer[rbyteCount] = '\0'; // Null-terminate the received string
        cout << "Received data: " << receiveBuffer << endl;
    }

    closesocket(clientSocket);
    WSACleanup();

    return 0;
}
