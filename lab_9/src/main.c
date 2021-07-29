#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>

#define VALUE_PID_FOR_CHILD_PROCESS 0

void Print_Identifier_Parent_And_Child_Process()
{
	pid_t temp_pid = getpid();
	pid_t temp_ppid = getppid();
	printf("PPID == %d PID == %d\n", temp_ppid, temp_pid);
}

int main()
{
	pid_t pid_two;
	pid_t pid_three;
	pid_t pid_four;
	pid_t pid_five;
	pid_t pid_six;
	Print_Identifier_Parent_And_Child_Process();
	pid_two = fork();
	if(VALUE_PID_FOR_CHILD_PROCESS == pid_two)
	{
		Print_Identifier_Parent_And_Child_Process();
		pid_four = fork();
		if(VALUE_PID_FOR_CHILD_PROCESS == pid_four)
		{
			Print_Identifier_Parent_And_Child_Process();
		}
		else
		{
			waitpid(pid_four, NULL, 0);
			pid_five = fork();
			if(VALUE_PID_FOR_CHILD_PROCESS == pid_five)
			{
				Print_Identifier_Parent_And_Child_Process();
			}
			else
			{
				waitpid(pid_five, NULL, 0);
			}
		}
	}
	else
	{
		waitpid(pid_two, NULL, 0);
		pid_three = fork();
		if(VALUE_PID_FOR_CHILD_PROCESS == pid_three)
		{
			Print_Identifier_Parent_And_Child_Process();
			pid_six = fork();
			if(VALUE_PID_FOR_CHILD_PROCESS == pid_six)
			{
				Print_Identifier_Parent_And_Child_Process();
			}
			else
			{
				waitpid(pid_six, NULL, 0);
			}
		}
		else
		{
			waitpid(pid_three, NULL, 0);
		}
	}
	return 0;
}