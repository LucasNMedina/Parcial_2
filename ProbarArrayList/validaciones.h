/** \brief La funcion menu() imprime un mensaje y obtiene un caracter como respuesta ya validado.
 *
 * \param message char* es el mensaje a ser mostrado.
 * \param minChar char es el minimo caracter valido.
 * \param maxChar char es el maximo caracter valido.
 * \return char el caracter validado.
 *
 */
char menu(char* message,char minChar, char maxChar);

/** \brief la funcion esNumerico recorre la cadena para verificar si hay numeros
 *
 * \param str char* la cadena a ser verificada
 * \return int 1 si es numero - 0 si no son solo numeros.
 *
 */
int esNumerico(char* str);

/** \brief verificarLargo toma una cadena de string y verifica que este en un rango de letras.
 *
 * \param str char* la cadena a verificar.
 * \param largoCadena int el mayor numero de letras que puede contener.
 * \return int 1 SI esta en rango - 0 si NO esta en rango.
 *
 */
int verificarLargo(char* str,int largoCadena);

/** \brief verificarLargoDNI toma una cadena de numeros y verifica que contenga 8 numeros.
 *
 * \param str char* la cadena a ser verificada.
 * \return int 1 SI esta en Rango - 0 si NO lo esta.
 *
 */
int verificarLargoDNI(char* str);

/** \brief validarDNI verifica que la cadena ingresada sea un DNI.
 *
 * \param str char* la cadena a ser verificada.
 * \return int 1 si lo es - 0 no lo es.
 *
 */
int validarDNI(char* str);

/** \brief la funcion esSoloLetras recorre la cadena para verificar si hay letras.
 *
 * \param str char* la cadena a ser verificada.
 * \return int 1 si es solo letras - 0 si no son solo letras.
 *
 */
int esSoloLetras(char* str);

/** \brief validarNombre verifica que lo ingresado sea un nombre.
 *
 * \param str char* la cadena a verificar.
 * \param largo int la cantidad de elementos que puede tener ese array.
 * \return int 1 si es nombre - 0 no lo es.
 *
 */
int validarNombre(char* str,int largo);

/** \brief validarEdad verifica que lo ingresado sea una edad.
 *
 * \param str char* la cadena a ser verificada.
 * \return int 1 si es edad - 0 no lo es.
 *
 */
int validarEdad(char* str);

/** \brief estiloNombres toma los nombre y los acomoda en un estilo determinado.
 *
 * \param str char* el nombre a acomodar.
 * \return void
 *
 */
void estiloNombres(char* str);

