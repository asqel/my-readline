#include "readline.h"
#include <unistd.h>
int main() {
	write(1, readline_init() ? "NON\n" : "OUI\n", 4);
	readline();
	return 0;
}
