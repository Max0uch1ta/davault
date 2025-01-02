#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "types.h"

pwd_entry* create_node();
void insert_node(pwd_entry* head, pwd_entry* node);


void split_line(char* line, char* source, char* username, char* password) {
	int i = 0;
	
	// Go through line until delimiter and ads to field
	while (line[i] != ',') {
		source[i] = line[i];
		i++;
	}
	i++;
	source[i] = '\0';

	while (line[i] != ',') {
		username[i] = line[i];
		i++;
	}
	i++;
	username[i] = '\0';

	while (line[i] != '\n') {
		password[i] = line[i];
	}
	i++;
	password[i] = '\0';

}

void csv_to_tree(FILE* fpr) {
	
	pwd_entry* head = NULL;

	char source[25];
	char username[25];
	char password[50];
	
	char line[100];

	while (fgets(line, 100, fpr)) {
		split_line(line, source, username, password);
		pwd_entry* node = create_node(source, username, password);
		if (head = NULL) {
			head = node;
		} else {
			insert_node(head, node);
		}
		
	}

	
}

pwd_entry* create_node(char* source, char* username, char* password) {
	pwd_entry* entry_ptr = malloc(sizeof(pwd_entry));
	if (entry_ptr == NULL) {
		perror("Error with memory allocation with node");
		return NULL;
	}
	strncpy(entry_ptr->source, source, MAX_LEN-1);
	entry_ptr->source[MAX_LEN-1] = '\0';
	strncpy(entry_ptr->user, username, MAX_LEN-1);
	entry_ptr->user[MAX_LEN-1] = '\0';
	strncpy(entry_ptr->pwd, password, MAX_LEN-1);
	entry_ptr->pwd[MAX_LEN-1] = '\0';
	entry_ptr->left = NULL;
	entry_ptr->right = NULL;

	return entry_ptr;
}

void insert_node(pwd_entry* head, pwd_entry* node) {
	if (cmp_node(head->source, node->source) < 0) {
		if (head->left == NULL) {
			head->left = node;
		} else {
		insert_node(head->left, pwd_entry *node);
		}
	} else {
		if (head->right == NULL) {
			head->right = node;
		} else {
		insert_node(head->right, node);
		}
	}
}

int cmp_node(char* str1, char* str2) {
	// Go through each str and add value of each char.

}

