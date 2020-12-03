# K-Means in Parallel
This is an implementation of the well known clustering algorithm K-Means. The implementation was done in `C++ 17` using `OpenMP 4.0`. The IDE used for the project was `Visual Studio 2019` and the compiler was `Intel Compiler 19.1`. The *Effective Logical Core Utiliation* percentage was 96.1 %. 

To test the code in Linux, execute the commands:
 1. **git** *clone https://github.com/andreasceid/k-means-parallel.git*
 2. **cd** *k-means-parallel*
 3. **chmod u+x** *disp_system_thread_count-ubu20.sh*
 4. **./disp_system_thread_count-ubu20.sh**
   > Write down the number on the output. We will use it later
 5. **cd** *k-means-parallel*
   > Edit `Common.h`, at line 27, and set variable `NUM_THR` equal to the number we noted in step 5
 6. **make**
 7. **./kmeans**

![Effective Logical Core Utilization Percentage](performance.PNG "Effective Logical Core Utilization Percentage")

There are 2 scritps that detect system logical core number:
  * For Linux (Tested on Ubuntu 20.04 64 bit): Bash Script `disp_system_thread_count-ubu20.sh`
  * For Windows (Tested on Windows 10 Version 20H2 64 bit): Powershell Script `disp_system_thread_count-win64.ps1`
  
The program was also tested with different number of available threads, and the scaling is pictured below.

![Thread Parallelism Convergence](convergence.png "Thread Parallelism Convergence")

There is a [PDF project report](parallel-programming-lab-2.pdf) in Greek.

![Demo](kmeans.gif)
