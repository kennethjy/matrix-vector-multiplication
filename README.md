# matrix-vector-multiplication


1. To compile the library, run:
  ```sh
    gcc -o mylib.o -c mylib/mylib.c
  ```
 
 
 
2. After that, to compile the main test code, run:
  ```sh
    gcc -o main.o -c main_test.c
  ```
  
Alternatively, to compile the benchmark files, run:
   
  ```sh
      gcc -o main.o -c main_b_time.c
  ```   
or
   
  ```sh
      gcc -o main.o -c main_b_space.c
  ```


note: To benchmark the memory space taken, open task manager (windows) or system monitor (linux) after running the main.out file. Don't forget to terminate the program by pressing ctrl + c in the command line or just end task the program in task manager.


3. Finally, to compile the code to get the main.out (for linux), run:
  ```sh
       gcc -Wall -O0 -o main.out main.o mylib.o
  ```

   For windows, skip all the above steps and just run 
    ```
      run.bat
    ```
   after changing main_test in line 1 to the file you want to compile

# Documentation
Test:

![image](https://user-images.githubusercontent.com/114073455/206437207-e8ad1c6f-b511-4497-8c93-f0363adf5fda.png)
![image](https://user-images.githubusercontent.com/114073455/206437330-aa39b414-8654-4a3a-b52b-e3d80baaf99b.png)


Time comparison:

![image](https://user-images.githubusercontent.com/114073455/206435753-e5def1db-6fab-4913-acd0-fe3d1ef1b8d8.png)


This graph is generated from the data written in the file 
    ```
      file.txt
    ```
   made by compiling and running 
    ```
      main_b_time.c
    ```
   20 times.


Space comparison:

![image](https://user-images.githubusercontent.com/114073455/206436614-69894690-d1d4-45c4-bde4-acd589aea452.png)


