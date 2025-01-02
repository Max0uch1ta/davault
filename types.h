#ifndef __TYPES_H__
#define __TYPES_H__


#define VAULT_PATH "/.local/share/davault/.vaults/"
#define MAX_CMD_LEN 100 
#define MAX_FILE_LEN 30
#define MAX_LEN 50

typedef struct pwd_entry {
	char source[MAX_LEN];
	char user[MAX_LEN];
	char pwd[MAX_LEN];
	struct pwd_entry* left;
	struct pwd_entry* right;
} pwd_entry;




#endif // __TYPES_H__

