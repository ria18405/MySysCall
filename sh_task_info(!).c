#include<linux/sched.h>
#include<linux/init.h>
#include<linux/kernel.h>
#include<linux/syscalls.h>
// #include <linux/errno.h>
#include <linux/fcntl.h>
#include <linux/fs.h>
#include<linux/file.h>
#include<linux/module.h>
#include<linux/proc_fs.h>
#include <asm/segment.h>
#include <asm/uaccess.h>
#include <linux/buffer_head.h>


// #include<string.h>
// #include<stdlib.h>
// sys_define2(sys_sh_task_info,int,char*, )

asmlinkage long sys_sh_task_info(int mypid,char *filename){

	int nbytes;
	int fd;
	// int ret;
	// int err=0;
	loff_t pos=0;
	struct file *file ;
	printk("yay! Successful compilation!!");
	struct task_struct *task;

	printk(KERN_ALERT "The process id: %d\n", mypid);

	task= pid_task(find_vpid(mypid),PIDTYPE_PID);
	printk(KERN_ALERT "The common pid found: %d name: %s\n", task->pid, task->comm);
	printk(KERN_ALERT " Priority: %d State : %d \n", task->prio, task->state);

	mm_segment_t oldfs; 
	oldfs = get_fs();
    set_fs(get_ds());		

	// char current_wd[500];
	// getcwd(current_wd, sizeof(current_wd));
	// strcat(current_wd,"/");
	// strcat(current_wd,filename);
	fd= sys_open(filename,O_WRONLY | O_CREAT,0777);
	// filp = sys_open("/home/riagupta/abc.txt",O_WRONLY | O_CREAT,0777);
	// if(IS_ERR(filp)){
	// 	err=PTR_ERR(filp);
	// 	return 0;
	// }
// struct file *fd=


	// set_fs(oldfs);
	// if (fd <0) 
	//     { 
	//     	printk("Error Number % d\n", );  
	//         perror("Error : ");                  
	//     }
//rewrite contents



if(fd>=0){
	char string [1024];
	sprintf(string,"The process id: %d\n name: %s\n Priority: %d\n State : %d \n",mypid,task->comm,task->prio,task->state );
	printk("please note this printing");
	printk("%s",string);
	nbytes=strlen(string);

    // ret = vfs_write(fd, string, nbytes, &offset);
	file->f_op->write(file, string, nbytes, &file->f_offset);
    sys_close(fd);

	}

else{
	printk("Unable to open file\n");
} 
    set_fs(oldfs);
	return 0;
}

	
