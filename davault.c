#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void create_vault(char* vault_name);

int main(int argc, char *argv[]) {

	printf("Welcome to DaVault\n");
	printf("What would you like to do?\n");
	
	// Print list of possible actions 
	printf("1) Create a new vault\n");
	printf("2) Sign in to vault\n");
	printf("3) Add a password\n");
	printf("4) Get a password\n");
	printf("Press q to quit.\n");

	// Prompt user input for choice
	int choice;
	scanf("Input: %d \n", &choice);

	// Create a new vault.
	if (choice == 1) {
		// ask user for file name
		char vault_name[30];
		scanf("Vault name: %s\n", &vault_name);
		// create new file
		create_vault(vault_name);

		// Create gpg command for system() function
		char command[50];
		sprintf(command, "gpg -c %s", vault_name);

		printf("Please provide a password\n");
		system(command);

		// remove text file
		char rm_file[35];
		sprintf(rm_file,"rm %s", vault_name);
		system(rm_file);
	} else if (choice == 2) {
		// Get vault name
		// Look for vault
		// If vault exists, login
		// else error
	}


	return 0;

}

void create_vault(char* vault_name) {
	// create a file with vault_name
	FILE* fptr;

	fopen(vault_name, "w");

	fclose(fptr);
}
