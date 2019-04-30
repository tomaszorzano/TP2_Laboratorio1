typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
} eEmployee;


/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initEmployees(eEmployee list[], int len);
/** \brief Busca un lugar vacio para agregar un empleado nuevo.
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return Devuelve la posicion del lugar vacio.
 *
 */
int findEmpty(eEmployee list[],int len);
/** \brief Busca un empleado segun su id.
 * \param list Employee* Pointer to array of employees.
 * \param len int Array length.
 * \param id int Array identifier.
 * \return Devuelve la posicion donde se encuentra el empleado.
 *
 */
int findEmployee(eEmployee list[],int len, int id);
/** \brief Muestra los datos del empleado que se cargaron.
 * \param
 *
 */
void viewEmployee(eEmployee aEmployee);
/** \brief Muestra los datos de los empleados cargados.
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 *
 */
void viewEmployees(eEmployee list[], int len);
/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
 *
 */


int addEmployee(eEmployee list[], int len);

int funcion_opciones();
/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
 */


int removeEmployee(eEmployee* list, int len);
/** \brief Modify a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list Employee*
 * \param len int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
 */
void modifyEmployee(eEmployee list[], int len);

int funcion_opcionesModificacion();

void harcodeoEmpleados(eEmployee* list);

int sortEmployees(eEmployee list[], int len);
void reports (eEmployee list[],int len);

