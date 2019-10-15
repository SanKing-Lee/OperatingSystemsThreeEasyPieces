# Mechanism: Limited Direct Execution
0. **time sharing CPU**
   1. performance
   2. control
1. **Limited Direct Execution**
   1. direct execution
      1. make sure do what we want
      2. switch processes
2. restricted operation
   1. user mode
   2. kernel mode
   3. trap: system call
   4. trap table: 当系统调用发生时应该跳转到哪些代码
3. switch between processes
   1. regain control
      1. cooperative approach
         1. wait for a system call
         2. illegal operation-> trap
      2. non-cooperative approach
         1. timer interrupt
         2. 启动时初始化计时中断需要执行的代码和启动计时器
      3. saving and restoring context
         1. scheduler
         2. context switch
         3. 内核栈中存有当前运行进程的寄存器等，在进程切换时，将当前进程的内核栈内容存储到另外的结构体，并从其它进程的状态结构体中加载相应的寄存器等内容到内核态栈中，执行相应切换后的进程。
4. concurrency
   1. disable interrupts during interrupt processing
   2. lock schemes to protect concurrent access to internal data structures