//Task 5:multiprocessing (shared memory)

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

    // get the identifier of the shared memory in shmid
    int shmid = shmget(key, sizeof(int), 0666 | IPC_CREAT); 
    if (shmid < 0)
    {
        cerr << "Can't get shared memory" << endl;
        return 1;
    }

    // attach the shared memory segment
    int *sharedMemory = (int*)shmat(shmid, NULL, 0);
    if (sharedMemory == (int*)(-1))
    {
        cerr << "ERor attaching shared memory" << endl;
        return 1;
    }         

    // send data to server   
    *sharedMemory = 20;  

sleep(7);
    // REad the modified value from server:    
    cout << "Modified value from server: " << *sharedMemory << endl;     
   
    //modify the value client
    *sharedMemory += 4;
    cout << "Modified value received from server in client: " <<  *sharedMemory << endl;    
            
    //print the modified value in an output file  
    ofstream outputFile("outputClient.txt"); 
    // check if the file was opened successfully
    if (outputFile.is_open()) 
    { 
        // write the modified value the file
        outputFile <<  *sharedMemory; 
        // close the file when done
        outputFile.close(); 
        cout << "Data was written to outputClient.txt" << endl;
    }
    else 
    {
        cerr << "Error opening file" << endl;
    }

    // detach the sharedMemory
    shmdt(sharedMemory);
        
    return 0; 
}