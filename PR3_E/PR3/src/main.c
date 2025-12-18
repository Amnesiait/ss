#include <stdio.h>
#include "inventory.h"

int main(int argc, char **argv)
{
	char fileName[MAX_FILE_NAME];
	tCompany company;
	tDepartmentType srcDepartment;
	tDepartmentType dstDepartment;
	tEquipmentType typeEquipment;
	int amount;
	bool isRead;
	int i;
	bool ok;
	
	/* load data from file */ 
    printf("LOAD DATA FROM FILE. ENTER FILE NAME >>\n");
    scanf("%s", fileName);
	
    loadCompanyFromFile(fileName, &company, &isRead);
	
	if (isRead) { /* Data successfully loaded */
	
		/* List the equipment inventory of each department */
		/* Exercise 1 */
		/* ... */
		
		/* Exercise 3 */
		/* Select source department */
		printf("SOURCE DEPARTMENT (1=IT, 2=HR, 3=SALES)\n");
		scanf("%u", &srcDepartment);
		getchar();
		/* ... */
		
		/* Transfer equipment */
		/* ... */
		
		/* Exercise 5 */
		if (ok) {
			/* ... */	
		}
		
	}
	else {
		/* Failed to load data */
		printf("UNABLE TO LOAD COMPANY DATA\n");	
	}
	
	return 0;
}
