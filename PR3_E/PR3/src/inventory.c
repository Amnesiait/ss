#include <stdlib.h>
#include <string.h>
#include "inventory.h"

/* Auxiliary action to load company data (departments and equipment) from file */
void loadCompanyFromFile(char* filename, tCompany* company, bool* isRead) {
    FILE* fin = NULL;
    char line[MAX_LINE];
	tDepartment department;
    tEquipment newItem;
    tEquipmentModel modelTmp;

    int deptType;
    int intToBool;
	int i;
	int nDepartments;

    /* Try to open the file */
    if ((fin = fopen(filename, "r")) != NULL) {

		nDepartments = 0;
		
        /* Read while there are departments and space available */
        while (!feof(fin)) {
			/* Remove any content from the line */
            line[0] = '\0';
			/* Read one line (maximum MAX_LINE chars) and store it in "line" variable */
            fgets(line, MAX_LINE - 1, fin);
			/* Ensure that the string is ended by 0 */
            line[MAX_LINE - 1] = '\0';

            if (strlen(line) > 0) {
                /* Read department header: <departmentType> <nItems> */
                sscanf(line, "%d %d", &deptType, &department.inventoryTable.nItems);				
				department.type = getDepartmentType(deptType);				
				
				/* Read all items of this department */
				for (i = 0; i < department.inventoryTable.nItems; i++) {
					/* Remove any content from the line */
					line[0] = '\0';
					/* Read one line (maximum MAX_LINE chars) and store it in "line" variable */
					fgets(line, MAX_LINE - 1, fin);
					/* Ensure that the string is ended by 0 */
					line[MAX_LINE - 1] = '\0';
					
					if (strlen(line) > 0) {
						/* Parse equipment line: ID isAssigned type brand name */
						sscanf(line, "%d %d %u %s %s", &newItem.id, &intToBool, &modelTmp.type, modelTmp.brand, modelTmp.name);
						newItem.isAssigned = (bool)intToBool;
						newItem.model = modelTmp;
						
						/* Add item to inventory vector */
						department.inventoryTable.inventory[i] = newItem;
					}					
				}
				/* Add new department to departments vector */
				company->departments[nDepartments] = department;
				nDepartments++;
            }
        }

        fclose(fin);
        *isRead = true;
    } else {
        *isRead = false;
    }
}

/* Auxiliary function that return the name for an equipment type */
char* getEquipmentTypeName(tEquipmentType type) {
    char *result;
	
	switch (type) {
		case DESKTOP:
			result = "DESKTOP";
			break;
		case LAPTOP:
			result = "LAPTOP";
			break;
		case PRINTER:
			result = "PRINTER";
			break;
		case MONITOR:
			result = "MONITOR";
			break;
		case KEYBOARD:
			result = "KEYBOARD";
			break;
		case MOUSE:
			 result = "MOUSE";
			 break;
	}
    return result;
}

/* Auxiliary function that returns the equipment type according to its numeric value */
tEquipmentType getEquipmenType(int value) {
    tEquipmentType equipType;

    switch (value) {
		case 1:
			equipType = DESKTOP;
			break;
		case 2:
			equipType = LAPTOP;
			break;
		case 3:
			equipType = PRINTER;
			break;
		case 4:
			equipType = MONITOR;
			break;
		case 5:
			equipType = KEYBOARD;
			break;
		case 6:
			equipType = MOUSE;
			break;
	}
    return equipType;
}

/*Auxiliary function that return the name for a department */
char* getDepartmentName(tDepartmentType deptType){
    char *result;
	
	switch (deptType) {
		case IT:
			result = "IT";
			break;
		case HR:
			result = "HR";
			break;
		case SALES:
			result = "SALES";
			break;
	}
    return result;
}

/* Auxiliary function that return the index a department */
int getDepartmentIndex(tDepartmentType deptType) {
    int index = 0;

    switch (deptType) {
		case IT:
			index = 0;
			break;
		case HR:
			index = 1;
			break;
		case SALES:
			index = 2;
			break;
	}
    return index;
}

/* Auxiliary function that returns the department type according to its numeric value */
tDepartmentType getDepartmentType(int value) {
    tDepartmentType depType;

    switch (value) {
		case 1:
			depType = IT;
			break;
		case 2:
			depType = HR;
			break;
		case 3:
			depType = SALES;
			break;
       }
       return depType;
}

/* Acction that prints the inventory information for a specific department. */
void writeDepartmentInventory(tDepartmentType deptType, tCompany company) {
    int j;
	int deptIndex;
    int count, available;
	tEquipmentType equipType;

	/* Get the index of the department in the company's department array */
    deptIndex = getDepartmentIndex(deptType);
	
    // Print the department header
    printf("DEPARTMENT: %s\n", getDepartmentName(deptType));
    printf("TYPE - COUNT - AVAILABLE\n");
    printf("========================\n");

    // Loop through all equipment types and print their count and availability
    for (j = 0; j < MAX_EQUIP_TYPES; j++) {
		
		/* Get the equipment type based on the numeric value */
		equipType = getEquipmenType(j + 1);
		
		/* Exercise 1.1 */
        /* ... */

        /* Print equipment type name, count, and available items */
        printf("%s - %d - %d\n", getEquipmentTypeName(equipType), count, available);
    }
	/* Print a blank line */
	printf("\n");
}

/* Exercise 2 */
/* ... */

/* Exercise 4.1 */
/* ... */

/* Exercise 4.2 */
/* ... */

/* Exercise 4 */
/* ... */





