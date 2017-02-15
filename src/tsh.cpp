#include "tsh.h"

using namespace std;

void simple_shell::parse_command(char* cmd, char** cmdTokens) {
	*cmdTokens = strtok(cmd, " \n");
	while(*cmdTokens != NULL) {
		cmdTokens++;
		*cmdTokens = strtok(NULL, " \n");
	}
}

void simple_shell::exec_command(char **argv) {
  // TODO: fork a child process to execute the command.
  // parent process should wait for the child process to complete and reap it
	if(argv != NULL) {
		pid_t pid = fork();
		if(pid == 0) {
			printf("EXECUTING: %s\n", *argv);
			system(*argv);
			simple_shell::exec_command(++argv);
			waitpid(pid, NULL, 0);
		}
		else if(pid > 0) signal(SIGCHLD, SIG_IGN);
	}
}

bool simple_shell::isQuit(char *cmd) {
	if(strcmp(cmd, "quit") == 0) return true;
  	return false;
}