# K-Means in Parallel
This is an implementation of the well known clustering algorithm K-Means. The implementation was done in `C++ 17` using `OpenMP 4.0`. The IDE used for the project was `Visual Studio 2019` and the compiler was `Intel Compiler 19.1`. The *Effective Logical Core Utiliation* percentage was 96.1 %. 

![Effective Logical Core Utilization Percentage](performance.PNG "Effective Logical Core Utilization Percentage")

There are 2 scritps that detect system logical core number:
  * For Linux (Tested on Ubuntu 20.04)         : Bash Script       `disp_system_thread_count-ubu20`
  * For Windows (Tested on Windows 10 x64 20H2): Powershell Script `disp_system_thread_count-win64`
The program was also tested with different number of available threads, and the scaling is pictured below.

![Thread Parallelism Convergence](convergence.png "Thread Parallelism Convergence")

There is a [PDF project report](parallel-programming-lab-2.pdf) in Greek.

![Demo](kmeans.gif)
