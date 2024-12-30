#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

#define VAULT_PATH "/.local/share/davault/.vaults/"
#define MAX_CMD_LEN 100 
#define MAX_FILE_LEN 30


void create_vault(char* vault_name);
char * get_vaults(char* path, char* file, bool encrypted);
void open_vault(char* vault_name);
void get_creds(char* line);


int main(int argc, char *argv[]) {
	// Check that necessary directories are present
	system("[ ! -d \"~/.local/share/davault/.vaults/\" ] && mkdir -p ~/.local/share/davault/.vaults/");
	FILE* current_vault;
	char* vault_name;
	bool vault_open = false;

	printf("Welcome to DaVault\n");
	printf("What would you like to do?\n");
	
	while (1) {
		// Print list of possible actions
		printf("1) Create a new vault\n");
		printf("2) Sign in to vault\n");
		printf("3) Add a password\n");
		printf("4) Get a password\n");
		printf("Press 0 to quit.\n");
		printf("Your choice > ");

		// Prompt user input for choice
		int choice;
		scanf("%d", &choice);
		if (choice == 0) {break;}

		switch (choice) {
		
			
			// Create a new vault.
			case 1:
				// ask user for file name
				printf("\nVault name > ");
				scanf("%ms", &vault_name);
				// create new vault
				create_vault(vault_name);
				break;
			// Open a vault
			case 2:
				open_vault(vault_name);
				break;

			case 3:
				// if no vault open, ask what vault to open
				if (vault_name == NULL) {
					open_vault(vault_name);
				}
				// open file 
				current_vault = fopen("vault", "a");
				if (current_vault == NULL) {
					printf("Could not open file.\n");
				}
				// Get credentials dor stdin
				char line[100];
				get_creds(line);
				
				// write credential to file.
				if (fprintf(current_vault, "%s", line) < 0) { printf("Error writing to file");} 

				fclose(current_vault); // close the file
				break;
			case 4:
				// if no vault open, ask what vault
				// open csv and turn to hashtable
				// close file and rm 
				// ask for source
				// if multiple usernames print usernames for choice
				// print password with username
				break;
		}
	}
	return 0;

}

void create_vault(char* vault_name) {
	// create a file with vault_name
	FILE* fptr;

	fptr = fopen(vault_name, "w");
	fprintf(fptr, "site, username, password\n");

	fclose(fptr);


	// Create gpg command for system() function
	char command[MAX_CMD_LEN];
	sprintf(command, "gpg -o ~/.local/share/davault/.vaults/%s.gpg -c %s", vault_name, vault_name);

	printf("Please provide a password\n");
	system(command);

	// remove text file
	char rm_file[MAX_CMD_LEN];
	sprintf(rm_file,"rm %s", vault_name);
	system(rm_file);
}


char * get_vaults(char* path, char* file, bool encrypted) {
	
	const char* home = getenv("HOME");

	// if looking for encrypted vault add .gpg to path
	char *fullpath;
	if (encrypted) {
		fullpath = malloc(snprintf(NULL, 0, "%s%s%s.gpg", home, path, file));
		sprintf(fullpath, "%s%s%s.gpg", home, path, file);

	} else {
		fullpath = malloc(snprintf(NULL, 0, "%s%s%s", home, path, file));
		sprintf(fullpath, "%s%s%s", home, path, file);
	}

	return fullpath;
}

void open_vault(char* vault_name) {
	bool closed = true;
	while (closed) {
		char *tmp;
		// Get vault name
		printf("What vault do you want to open? (0 to return)\n> ");
		if (scanf("%ms", &tmp) != 1) {
			printf("An error occured");
		}
		// Exit if 0
		if (strcmp(tmp, "0") == 0) {
			break;
		}
		// Test if vault exists
		char* path = get_vaults(VAULT_PATH, tmp, true);

		if(!access(path, F_OK )){
			printf("The File %s\t was Found\n",path);
			// if it exists open and login
			char cmd[MAX_CMD_LEN];
			sprintf(cmd,"gpg -o vault --decrypt %s", path);
			system(cmd);
			strcpy(vault_name, tmp);
			closed = true;
		}else{
			printf("The File %s\t not Found\n",path);
		}
		free(tmp);
		free(path);
	}
}


// ask for source, username and password
void get_creds(char* line) {
	// Must add verifivation for ; 
	char source[25];
	char username[25];
	char password[50];
	printf("What is the source of the pwd\n>");
	if (fgets(source, 25, stdin) == NULL) { printf("Error getting source");}
	if (fgets(username, 25, stdin) == NULL) { printf("Error getting source");}
	if (fgets(password, 55, stdin) == NULL) { printf("Error getting source");}

	snprintf(line, 100, "%s;%s;%s", source,username,password);
}
