#include "private.h"

//void rdl_update_event() {
//	char c = '\0';
//	int ret = read(1, &c, 1);
//	if (ret <= 0 || !c)
//		return ;
//	buffer_append(&readline_info.stash, c);
//}
//
//static char **key_events = NULL;
//size_t key_events_len = 0;
//
//int rdl_register_key(char *code) {
//	char **tmp = realloc(key_events, sizeof(char *) * (key_events_len + 1));
//	if (!tmp)
//		return 1;
//	key_events = tmp;
//	char *code_dup = strdup(code);
//	if (!code_dup)
//		return 1;
//	key_events[key_events_len++] = code_dup;
//	return 0;
//}
//
//char *rdl_get_event() {
//	if (!readline_info.stash)
//		return NULL;
//	char c = readline_info.stash[0];
//	if (' ' <= c && c <= '~') {
//		char *res = malloc(2);
//		if (!res)
//			return NULL;
//		res[0] = c;
//		res[1] = '\0';
//		return res;
//	}
//	return NULL;
////	if (c >> 3 == 0b11110 && ) {
////	}
//}
