#include "private.h"
#include <stdio.h>

void readline_sig_handler(int sig) {
	printf("received %d\n", sig);
	fflush(stdout);
}

static int signal_from_idx(int i) {
	if (i < 0 || i >= 7)
		return -1;
	int sigs[7] = {SIGINT, SIGWINCH, SIGTSTP, SIGCONT, SIGTERM, SIGHUP, SIGQUIT};
	return sigs[i];
}

int readline_install_sig() {
	for (int i = 0; i < 7; i++) {
		int sig = signal_from_idx(i);
		struct sigaction act;
	
		act.sa_handler = &readline_sig_handler
		sigemptyset(&act.sa_mask);
		act.sa_flags = 0;
		if (sigaction(sig, &act, &readline_info.old_act[i]))
			return 1;
	}
	return 0;
}
