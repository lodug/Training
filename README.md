# Training
Training tasks

=======================================================================================================================================================================================
Task1: implementati o ierarhie de clase (fiecare clasa cu fisierul ei sursa) care sa includa:

o clasa abstracta care sa contina toate elementele necesare unui obiect de tip automobil(care sa contina minim informatii legate de:

combustibil, caroserie, tractiune, putere, echipare, VIN number as a pointer)

si diferite tipuri derivate de automobil in functie de caracteristicile fiecaruia

     Subtasks:               1. Exemplificati in main ordinea apelarii constructorilor si destructorilor pentru clasele de baza si derivate               2. Limitati numarul de obiecte ce pot fi create la 1 obiect pentru una dintre clase               3. Implementati "Rule of three" si "Rule of five" pentru clasele derivate               4. Implementati o clasa utilitara ale carei functii sa poata fi apelate fara a folosi un obiect (functii de printare custom, de calcul al mediei etc)

     
=======================================================================================================================================================================================
Task2: smart pointers: shared vs unique, weak what is good for? Replace raw pointers with smart ones and explain during a demo why is good one or an other.

=======================================================================================================================================================================================
Task3: design patterns: Subtask1: implement an (Abstract) Factory. Subtask2: implement a Safe Singleton

=======================================================================================================================================================================================
Task4: multithreading: implement a task that treats the value of an extern variable that is read, modified and printed by 2 threads in parallel in a safe way.

=======================================================================================================================================================================================
Task5:  multiprocessing: exchange info between a server and a client process and print the modified values in each process in different files. (use sockets and advance to shared memory as a second step).

- created 2 feature branches: one for the subtask1: sockets and one for shared memory

=======================================================================================================================================================================================
Task 6: de introdus un observer in implementarea din unul dintre taskurile precedente

 - I implemented it in the Task 3: subtask 2 - safe singleton

=======================================================================================================================================================================================
Task7: sa se implementeze un bash script care la start-up sa porneasca serverul si clientul implementate in taskul 5 . Scriptul trebuie apelat in mod automat la start-up de sistemul de operare.

- I did it for the task with sockets (task 5:subtask1)
- one script that I run by myself
- one script that is run automatically

=======================================================================================================================================================================================
Task 8: Unit Testing using Boost framework for one implemented task

=======================================================================================================================================================================================
Task 9: Abstract Factory Pattern to implement and demo

=======================================================================================================================================================================================
Task 10: sa porteze partea de build catre cmake pentru unul din taskurile implementate anterior (taskul cu cele mai multe fisiere).


