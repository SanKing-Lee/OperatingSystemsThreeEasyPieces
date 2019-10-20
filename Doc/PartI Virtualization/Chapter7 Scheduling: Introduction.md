## Chapter7 Scheduling: Introduction
1. **workload assumption**
   1. same amount of time
   2. arrives at the same time
   3. only CPU, no I/O
   4. known run-time
2. **metric**
   1. turnaround = completoin - arrival
   2. response = firstrun - arrival
   3. performance and fairness
3. **FIFO(FCFS)**
   1. simple 
   2. convoy effect
4. **SJF**
   1. non-preemptive
   2. 从同时到达的进程中选取一个最短时间的执行
   3. 耗时长的进程先达到仍然有可能导致护航效应
5. **STCF**
   1. preemtive
   2. fairless
6. **RR**
   1. time slice

   时间片太短|时间片太长
   -|-
   进程切换开销大|退化为FCFS
   2. fair
7. **Incorporating I/O**
   1. 在其中一个执行I/O时，执行另外的进程
   2. 抢占式 

调度算法|响应时间|周转时间
-|-|-
FCFS|0|0
SJF|0|1
STCF|0|1
RR|1|0
