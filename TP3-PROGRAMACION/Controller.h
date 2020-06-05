int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
int controller_addEmployee(LinkedList* pArrayListEmployee);					///PUNTO3
int controller_editEmployee(LinkedList* pArrayListEmployee);				///PUNTO4
int controller_removeEmployee(LinkedList* pArrayListEmployee);				///PUNTO5
int controller_ListEmployee(LinkedList* pArrayListEmployee);				///PUNTO6
int controller_sortEmployee(LinkedList* pArrayListEmployee);				///PUNTO7
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);		///PUNTO8
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);	///PUNTO9
/*************************************************************************
 * ***********************************************************************
 */
int controller_idmaximo(LinkedList* pArrayListEmployee);

