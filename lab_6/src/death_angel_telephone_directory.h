#ifndef DEATH_ANGEL_TELEPHONE_DIRECTORY_H

#define DEATH_ANGEL_TELEPHONE_DIRECTORY_H

#define MAX_LENGTH_TELEPHONE_NUMBER 11

struct Information_Abonent
{
	char telephone_number[MAX_LENGTH_TELEPHONE_NUMBER];
	char* surname;
	char* name;
	int size_surname;
	int size_name;
};

struct Telephone_Directory
{
	struct Information_Abonent data_abonent;
	struct Telephone_Directory* next_abonent;
};

typedef struct Telephone_Directory telephone_directory;
typedef struct Information_Abonent information_abonent;

int Free_List_Abonent(telephone_directory** list_abonent);
int Add_Note_In_Telephone_Directory(telephone_directory** list_abonent);

#endif