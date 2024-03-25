//Task 5: multiprocessing

// C++ program to show the example of server application in 
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
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0); 
  
    // specifying the address 
    sockaddr_in serverAddress; 
    serverAddress.sin_family = AF_INET; 
    serverAddress.sin_port = htons(8080); 
    serverAddress.sin_addr.s_addr = INADDR_ANY; 
  
    // binding socket. 
    bind(serverSocket, (struct sockaddr*)&serverAddress, 
         sizeof(serverAddress)); 
  
    // listening to the assigned socket 
    listen(serverSocket, 5); 
  
    // accepting connection request 
    int clientSocket 
        = accept(serverSocket, nullptr, nullptr); 
  
    // receiving data 
    //char buffer[1024] = { 0 }; 
    int clientValue;
    // recv(clientSocket, buffer, sizeof(buffer), 0); 
    // cout << "Message from client: " << buffer << endl; 
    recv(clientSocket, &clientValue, sizeof(clientValue), 0); 
    cout << "Value from client: " << clientValue << endl;     

    //MOdify the value from client
    int modValue = clientValue + 5;
    cout << "Modified value in server: " << modValue << endl; 

    //send the modified value back to client
    send(clientSocket, &modValue, sizeof(modValue), 0);     

    //print the modified value in an output file
    ofstream outputFile("outputServer.txt"); 
    // check if the file was opened successfully
    if (outputFile.is_open()) 
    { 
        // write the modified value the file
        outputFile << modValue; 
        // close the file when done
        outputFile.close();         
        cout << "Data was written to outputServer.txt" << endl;
    }
    else 
    {
        cerr << "Error opening file" << endl;
    }     

    // closing the sockets. 
    close(serverSocket); 
    close(clientSocket); 
     
    return 0; 
}