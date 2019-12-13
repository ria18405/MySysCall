**Writing Your Own System Call**

Created own system call in C, called sh_task_info(), which takes argument as PID. It would need to search out the task struct() corresponding to the PID and print out all the fields corresponding to it and also save it in a file. The file name also needs to be supplied as an argument to the system call.

Handled errors in user inputs, such as incorrect arguments, through appropriate errno and function return values (e.g. 0 signaling correct input, while 1 signaling incorrect input).

Run the `make` command, and run use.c by `./use`. Here use.c is the code in the userspace i.e can be edited by the user and pid (process id ) values can be changed accordingly. The system call returns 0 in case of successfull compilation. 
