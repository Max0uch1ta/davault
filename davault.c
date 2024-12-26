#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void create_vault(char* vault_name);

int main(int argc, char *argv[]) {
	// Check that necessary directories are present
	system("[ ! -d \"~/.local/share/davault/.vaults/\" ] && mkdir -p ~/.local/share/davault/.vaults/");

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

		switch (choice) {
		
			
			// Create a new vault.
			case 0:
				break;
			case 1:
				// ask user for file name
				char vault_name[30];
				printf("\nVault name > ");
				scanf("%s", &vault_name);
				// create new file
				create_vault(vault_name);

				// Create gpg command for system() function
				char command[50];
				sprintf(command, "gpg -o ~/.local/share/davault/.vaults/%s.gpg -c %s", vault_name, vault_name);

				printf("Please provide a password\n");
				system(command);

				// remove text file
				char rm_file[35];
				sprintf(rm_file,"rm %s", vault_name);
				system(rm_file);
			case 2:
				// Get vault name
				// Look for vault
				// If vault exists, login
				// else error
			case 3:
				// if no vault open, ask what vault to open
				// open file in csv
				// ask for source, username and password
				// add line
				// close file
			case 4:
				// if no vault open, ask what vault
				// open csv and turn to hashtable
				// close file and rm 
				// ask for source
				// if multiple usernames print usernames for choice
				// print password with username
		}
	}
	return 0;

}

void create_vault(char* vault_name) {
	// create a file with vault_name
	FILE* fptr;

	fptr = fopen(vault_name, "w");

	fclose(fptr);
}
