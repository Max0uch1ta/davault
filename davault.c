#include <stdio.h>
#include <string.h>

void create_vault(char* vault_name);

int main(int argc, char *argv[]) {

	printf("Welcome to DaVault\n");
	printf("What would you like to do?\n");
	
	// Print list of possible actions 
	printf("1) create a new vault\n");

	// Prompt user input for choice
	int choice;
	scanf("Input: %d \n", &choice);

	if (choice == 1) {
		// ask user for file name
		char vault_name[30];
		scanf("Vault name: %s\n", &vault_name);
		// create new file
		create_vault(vault_name	);

		printf("Please provide a password\n");


		// ask for password
		// verify password
		// add password to file
	}

	return 0;

}

void create_vault(char* vault_name) {
		FILE* fptr;

		fopen(vault_name, "w");

		fclose(fptr);
}
