* 测试system call overheads
使用read 0 bytes实现

* 测试context switch overheads
使用两个pipe进行父进程和子进程的通信，使用sched_setaffinity()绑定进程和cpu，通过pipe1父进程写子进程读，pipe2子进程写父进程读，write()和read()都是0byte来产生context switch。

* 参考资料
[lmbench](http://www.bitmover.com/lmbench/)


