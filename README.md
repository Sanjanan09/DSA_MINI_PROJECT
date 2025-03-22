Phone Directory Application

Description

The Phone Directory Application is a simple C program that allows users to store, search, edit, delete, and display contact information using a doubly linked list.

Features

Add a new contact (Name and Phone Number)

Display all saved contacts

Search for a contact by name

Delete a contact by name

Edit contact details

Exit the program

Prerequisites

A C compiler such as GCC

A terminal or command prompt to run the program

Compilation and Execution

To compile the program, use the following command:

gcc phone_directory.c -o phone_directory

To run the program, use:

./phone_directory

Usage

Run the program.

Select an option from the menu:

1 to add a new contact.

2 to display all contacts.

3 to search for a contact by name.

4 to delete a contact by name.

5 to edit an existing contact.

6 to exit the application.

Follow the on-screen prompts to enter names and phone numbers.

The program will continue running until the user chooses option 6 to exit.

Example Interaction

Phone Directory Application

1. Add Contact
2. Display Contacts
3. Search Contact
4. Delete Contact
5. Edit Contact
6. Exit
   Enter your choice: 1
   Enter contact name: John
   Enter phone number: 1234567890
   Contact added successfully.

Memory Management

The program dynamically allocates memory for each contact.

Before exiting, all allocated memory is freed to prevent memory leaks.

Limitations

Contact names are case-sensitive.

Phone numbers are stored as strings but are not validated.

There is no persistence; all data is lost when the program exits.

Future Improvements

Implement file handling to save contacts persistently.

Improve input validation for phone numbers.

Allow case-insensitive searches.
