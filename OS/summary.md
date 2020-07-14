# Summary of Modern Operating System

## Processes and Threads

### Processes

> - process model
>   - What is process? consist of ?
> - process creation
>   - four events that cause process creation
>   - resource sharing(3 cases), execution(concurrently or not), address space
> - process termination
>   - four conditions that terminate process
>   - In what situation parent may terminate child processes.
> - process state
>   - new, running, blocked, ready, terminated
>   - diagram of process state(important)
>   - when to switch, context switch
> - implementation of process
>   - main: PCB

### Threads

> - Thread model
>
>   - what is thread? consist of? properties?
>   - what items are shared between threads, what are ***private*** to each other?
>
> - Implementing threads
>
>   - three mechanism(kernel space, user space, hybrid)
>
> - Scheduling
>
>   ![image-20200617081101526](./img/image-20200617081101526.png)
>
>   

## Deadlock

> - Definition and types of resource 
> - Deadlock 
>   - definition 定义
>   - four conditions for deadlock 
>   - strategies dealing with deadlock 
>     - esp. detection and recovery 
> - Recovery from deadlock 
>   - preemption, rollback, killing processes
> - Deadlock avoidance
>   - safe state, Banker's Algorithm
> - Deadlock prevention
>   - attacking four conditions for deadlock
> - Starvation

