// C++ program to illustrate the client application in the 
// socket programming 
#include <cstring> 
#include <iostream> 
#include <netinet/in.h> 
#include <sys/socket.h> 
#include <unistd.h> 
#include <fstream>

using namespace std; 
  
int main() 
{ 
    // creating socket 
    int clientSocket = socket(AF_INET, SOCK_STREAM, 0); 
  
    // specifying address 
    sockaddr_in serverAddress; 
    serverAddress.sin_family = AF_INET; 
    serverAddress.sin_port = htons(8080); 
    serverAddress.sin_addr.s_addr = INADDR_ANY; 
  
    // sending connection request 
    connect(clientSocket, (struct sockaddr*)&serverAddress, 
            sizeof(serverAddress)); 
  
    // sending data 
    //const char* message = "Hello, server!"; 
    int serverValue = 20;
    //send(clientSocket, message, strlen(message), 0); 
    send(clientSocket, &serverValue, sizeof(serverValue), 0); 
   
    //REceive the modified value from server
    int modValue;
    recv(clientSocket, &modValue, sizeof(int), 0); 
    cout << "Modified value from server: " << modValue << endl;  

     //MOdify the value from server
    int modValue1 = modValue + 4;
    cout << "Modified value in client: " << modValue1 << endl; 
   

    //print the modified value in an output file  
    ofstream outputFile("outputClient.txt"); 
    // check if the file was opened successfully
    if (outputFile.is_open()) 
    { 
        // write the modified value the file
        outputFile << modValue1; 
        // close the file when done
        outputFile.close(); 
        cout << "Data was written to outputClient.txt" << endl;
    }
    else 
    {
        cerr << "Error opening file" << endl;
    }

    // closing socket 
    close(clientSocket); 
        
    return 0; 
}