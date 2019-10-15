## Chapter4 The Abstraction: Process
1. **process**
   1. running program
   2. machine state
      1. program counter
      2. instruction counter
      3. stack pointer
      4. frame pointer
2. **process API**
   1. create
   2. destroy
   3. wait
   4. miscellaneous control
   5. status
3. **process creation**
   1. load code and static data from disk to memory
   2. initialize stack, heap and file descriptors(stdin, stdout, stderr)
   3. jump to main() entry
4. **process states**
   1. ready
   2. start
   3. running
   4. exit
   5. suspend
   6. blocked
5. **data structures**
   1. process lists
   2. register context
   3. process