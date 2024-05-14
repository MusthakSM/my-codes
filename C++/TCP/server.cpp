#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <tchar.h>
#include <cstring>
using namespace std;

int main()
{
    // Initialize Winsock
    WSADATA wsaData;
    int wsaerr;
    WORD wVersionRequested = MAKEWORD(2, 2);
    wsaerr = WSAStartup(wVersionRequested, &wsaData);
    if (wsaerr != 0)
    {
        cout << "WSAStartup failed with error: " << wsaerr << endl;
        return 1;
    }
    else
    {
        cout << "WSAStartup successful" << endl;
        cout << "Winsock status: " << wsaData.szSystemStatus << endl;
    }

    // Create socket
    SOCKET serverSocket;
    serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (serverSocket == INVALID_SOCKET)
    {
        cout << "Error creating socket: " << WSAGetLastError() << endl;
        WSACleanup();
        return 1;
    }

    // Bind socket
    sockaddr_in service;
    service.sin_family = AF_INET;
    service.sin_addr.s_addr = inet_addr("127.0.0.1");
    service.sin_port = htons(32000);
    if (bind(serverSocket, (SOCKADDR *)&service, sizeof(service)) == SOCKET_ERROR)
    {
        cout << "Bind failed with error: " << WSAGetLastError() << endl;
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    // Listen for incoming connections
    if (listen(serverSocket, SOMAXCONN) == SOCKET_ERROR)
    {
        cout << "Listen failed with error: " << WSAGetLastError() << endl;
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    cout << "Server is listening for incoming connections..." << endl;

    // Accept connections and handle data
    while (true)
    {
        SOCKET acceptSocket;
        acceptSocket = accept(serverSocket, NULL, NULL);
        if (acceptSocket == INVALID_SOCKET)
        {
            cout << "Accept failed with error: " << WSAGetLastError() << endl;
            closesocket(serverSocket);
            WSACleanup();
            return 1;
        }

        cout << "Client connected" << endl;

        while (true)
        {
            // Receive data from client
            char receiveBuffer[200];
            int rbyteCount = recv(acceptSocket, receiveBuffer, sizeof(receiveBuffer), 0);
            if (rbyteCount <= 0)
            {
                cout << "Receive failed with error: " << WSAGetLastError() << endl;
                closesocket(acceptSocket);
                continue; // Move to the next iteration of the loop
            }

            receiveBuffer[rbyteCount] = '\0'; // Null-terminate the received string
            cout << "Received data: " << receiveBuffer << endl;

            // Check if the received message is "QUIT"
            if (strcmp(receiveBuffer, "QUIT") == 0)
            {
                cout << "Client requested to terminate the server. Closing server..." << endl;
                closesocket(acceptSocket);
                break; // Exit the loop to terminate the server
            }

            // Send response back to client
            char buffer[200];
            cout << "Enter the message to send back: ";
            cin.getline(buffer, 200);
            int sbyteCount = send(acceptSocket, buffer, strlen(buffer), 0);
            if (sbyteCount == SOCKET_ERROR)
            {
                cout << "Send failed with error: " << WSAGetLastError() << endl;
                closesocket(acceptSocket);
                continue; // Move to the next iteration of the loop
            }
            cout << "Server sent " << sbyteCount << " bytes" << endl;

        }

        break;
    }

    // Close the server socket
    closesocket(serverSocket);
    WSACleanup();

    return 0;
}
