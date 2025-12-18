#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/*Constants for file reading */
#define MAX_FILE_NAME 100+1
#define MAX_LINE 514

#define MAX_NAME_LENGTH 50
#define MAX_EQUIPMENT   100   /* Max. number of equipment per warehouse */
#define NUM_DEPARTMENTS 3     /* Number of departments */
#define MAX_EQUIP_TYPES  6    /* Max number of different equipment types */

/* Enum to represent different types of IT equipment */
typedef enum {
    DESKTOP = 1,
    LAPTOP,
    PRINTER,
    MONITOR,
    KEYBOARD,
    MOUSE
} tEquipmentType;

/* Enum to represent company departments */
typedef enum {
    IT = 1,   /* IT Department */
    HR,       /* Human Resources */
    SALES     /* Sales */
} tDepartmentType;

/* Structure to represent an IT equipment model */
typedef struct {
    char brand[MAX_NAME_LENGTH]; /* Brand of the model */
    char name[MAX_NAME_LENGTH];  /* Name of the model */
    tEquipmentType type;         /* Type of equipment */
} tEquipmentModel;

/* Structure to represent an IT equipment unit */
typedef struct {
    int id;                 /* Unique identifier for the equipment */
    bool isAssigned;        /* true if the equipment is assigned, false if available */
    tEquipmentModel model;  /* Model details */
} tEquipment;


/* Table that represents a inventory of IT equipment */
typedef struct {
    tEquipment inventory[MAX_EQUIPMENT]; /* List of equipment in inventory */
    int nItems;                          /* Number of equipment items in inventory */
} tInventoryTable;

/* Structure to represent a department */
typedef struct {
    tDepartmentType type; /* Department type */
    tInventoryTable inventoryTable; /* IT equipment inventory specific to the department */
} tDepartment;

/* Structure that represents the company where a company is composed of several departments */
typedef struct {
    tDepartment departments[NUM_DEPARTMENTS]; /* Departments */
} tCompany;

/* Auxiliary action to load company data (departments and equipment) from file */
void loadCompanyFromFile(char* filename, tCompany* company, bool* isRead);
/* Auxiliary function that return the name for an equipment type */
char* getEquipmentTypeName(tEquipmentType type);
/* Auxiliary function that returns the equipment type according to its numeric value */
tEquipmentType getEquipmenType(int value);
/* Auxiliary function that return the name for an department */
char* getDepartmentName(tDepartmentType depto);
/* Auxiliary function that return the index a department */
int getDepartmentIndex(tDepartmentType deptType);
/* Auxiliary function that returns the department type according to its numeric value */
tDepartmentType getDepartmentType(int value);

/* Action that prints the inventory information for a specific department. */
void writeDepartmentInventory(tDepartmentType deptType, tCompany company);

/* Exercise 2 */
/* ... */

/* Exercise 4.1 */
/* ... */

/* Exercise 4.2 */
/* ... */

/* Exercise 4 */
/* ... */



