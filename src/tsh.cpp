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
	pid_t pid = fork();
	if(pid == 0) {
		System();
	}
	else if(pid > 0) {
		waitpid(pid);
	}
}

bool simple_shell::isQuit(char *cmd) {
	if(strcmp(cmd, "quit") == 0) return true;
  	return false;
}