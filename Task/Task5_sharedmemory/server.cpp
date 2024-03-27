//Task 5: multiprocessing(shared memory)

#include <cstring> 
#include <iostream> 
#include <netinet/in.h> 
#include <sys/socket.h> 
#include <unistd.h> 
#include <fstream>
#include <sys/ipc.h>
#include <sys/shm.h>
  
using namespace std; 
  
int main() 
{ 
    // ftok to generate unique key
    key_t key = ftok("shmfile", 65);

    // creating shared memory segment
    int shmid = shmget(key, sizeof(int),IPC_CREAT | 0666); 
    if (shmid < 0)
    {
        cerr << "Can't create shared memory" << endl;
        return 1;
    }

    // attach the shared memory segment
    int* sharedMemory = (int*)shmat(shmid, NULL, 0);
    if (sharedMemory == (int*)(-1))
    {
        cerr << "ERor attaching shared memory" << endl;
        return 1;
    }         

    sleep(5); 
    // receiving data from client         
    cout << "Value from client: " << *sharedMemory << endl;     

    //MOdify the value from client
    *sharedMemory += 5;
    cout << "Modified value in server: " << *sharedMemory << endl;      

    //print the modified value in an output file
    ofstream outputFile("outputServer.txt"); 
    // check if the file was opened successfully
    if (outputFile.is_open()) 
    { 
        // write the modified value the file
        outputFile << *sharedMemory; 
        // close the file when done
        outputFile.close();         
        cout << "Data was written to outputServer.txt" << endl;
    }
    else 
    {
        cerr << "Error opening file" << endl;
    }     

    // detach from shared memory 
   shmdt(sharedMemory);   
     
    return 0; 
}