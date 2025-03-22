#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Structure to represent a contact
typedef struct Contact {
char name[50];
char phoneNumber[15];
struct Contact* next;
struct Contact* prev;
} Contact;
// Function to create a new contact
Contact* createContact(const char* name, const char* phoneNumber) {
Contact* newContact = (Contact*)malloc(sizeof(Contact));
if (newContact != NULL) {
strcpy(newContact->name, name);
strcpy(newContact->phoneNumber, phoneNumber);
newContact->next = NULL;
newContact->prev = NULL;
}
return newContact;
}
// Function to insert a contact into the phone directory
void insertContact(Contact** head, const char* name, const char* phoneNumber) {
Contact* newContact = createContact(name, phoneNumber);
if (newContact == NULL) {
printf("Memory allocation failed.\n");
return;
}
if (*head == NULL) {
// List is empty
*head = newContact;
} else {
// Insert at the end
Contact* temp = *head;
while (temp->next != NULL) {
temp = temp->next;
}
temp->next = newContact;
newContact->prev = temp;
}
printf("Contact added successfully.\n");
}
// Function to display all contacts in the phone directory
void displayContacts(Contact* head) {
printf("\nPhone Directory:\n");
if (head == NULL) {
printf("No contacts to display.\n");
return;
}
while (head != NULL) {
printf("Name: %s, Phone Number: %s\n", head->name, head->phoneNumber);
head = head->next;
}
printf("\n");
}
// Function to search for a contact by name
Contact* searchContact(Contact* head, const char* name) {
while (head != NULL) {
if (strcmp(head->name, name) == 0) {
return head; // Contact found
}
head = head->next;
}
return NULL; // Contact not found
}
// Function to delete a contact by name
void deleteContact(Contact** head, const char* name) {
Contact* current = *head;
while (current != NULL) {
if (strcmp(current->name, name) == 0) {
if (current->prev != NULL) {
current->prev->next = current->next;
} else {
// Deleting the first node
*head = current->next;
}
if (current->next != NULL) {
current->next->prev = current->prev;
}
free(current);
printf("Contact deleted successfully.\n");
return;
}
current = current->next;
}
printf("Contact not found.\n");
}
// Function to edit contact information
void editContact(Contact* contact) {
printf("Enter new name: ");
scanf("%s", contact->name);
printf("Enter new phone number: ");
scanf("%s", contact->phoneNumber);
printf("Contact information updated successfully.\n");
}
// Main function
int main() {
Contact* phoneDirectory = NULL;
// Menu-driven phone directory application
int choice;
char name[50];
char phoneNumber[15];
do {
printf("\nPhone Directory Application\n");
printf("1. Add Contact\n");
printf("2. Display Contacts\n");
printf("3. Search Contact\n");
printf("4. Delete Contact\n");
printf("5. Edit Contact\n");
printf("6. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice) {
case 1:
printf("Enter contact name: ");
scanf("%s", name);
printf("Enter phone number: ");
scanf("%s", phoneNumber);
insertContact(&phoneDirectory, name, phoneNumber);
break;
case 2:
displayContacts(phoneDirectory);
break;
case 3:
printf("Enter the name to search: ");
scanf("%s", name);
{
Contact* result = searchContact(phoneDirectory, name);
if (result != NULL) {
printf("Contact found - Name: %s, Phone Number: %s\n", result->name, result->phoneNumber);
} else {
printf("Contact not found.\n");
}
}
break;
case 4:
printf("Enter the name to delete: ");
scanf("%s", name);
deleteContact(&phoneDirectory, name);
break;
case 5:
printf("Enter the name to edit: ");
scanf("%s", name);
{
    Contact* editResult = searchContact(phoneDirectory, name);
if (editResult != NULL) {
editContact(editResult);
} else {
printf("Contact not found.\n");
}
}
break;
case 6:
// Exit the program
break;
default:
printf("Invalid choice. Please enter a valid option.\n");
}
} while (choice != 6);
// Free allocated memory before exiting
while (phoneDirectory != NULL) {
Contact* temp = phoneDirectory;
phoneDirectory = phoneDirectory->next;
free(temp);
}
printf("Exiting Phone Directory Application.\n");
return 0;
}