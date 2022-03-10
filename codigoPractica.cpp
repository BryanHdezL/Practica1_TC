/********************************************************************************************************
    Descripcion:
        Creacion de un programa que realiza operaciones basicas con cadenas binarias, como concatenar,
        potencia, inversa, prefijos, sufijos y subcadenas.
    Autores:
        Hernandez Lopez Bryan
        Martinez Islas Armando Samir
    Fecha de creacion:
        10/03/2022
    Version: 1.0
********************************************************************************************************/

//Librerias
#include<bits/stdc++.h> //Libreria de cabecera.
using namespace std;

//Prototipos de funciones
void menu(string, string);
void opciones(int ,string ,string );
void concatenacion(string, string);
void potencia(string, int);
void inverso(string);
void presuf(string);
void subcadena(string, string);
int verificar(string);

//Funcion Principal.
int main(){
    string cadena1, cadena2;    //Declaracion de las cadenas con las que trabajara el programa.
        system("cls");
        cout<<"\n  - Captura una cadena con 0 y/o 1 (cadena 1): ";  //Solicitamos cadenas al usuario.
        cin >> cadena1;
        cout<<"  - Captura otra cadena con 0 y/o 1 (cadena 2): ";
        cin>>cadena2;
        
        while(verificar(cadena1) || verificar(cadena2)){ //Verificamos que en verdad la cadena sea binaria, invocando a la funcion de la linea 200.
            cout<<"\n    Se usaron caracteres que no estan en el alfabeto. \n"; //Mensaje que indica que no es una cadena binaria.
            cout<<"\n  - Captura una cadena con 0 y/o 1 (cadena 1): ";  //Volvemos a solicitar las cadenas al usuario.
            cin >> cadena1;
            cout<<"  - Captura otra cadena con 0 y/o 1 (cadena 2): ";
            cin>>cadena2;
        }
        menu(cadena1,cadena2);  //Invocamos a la funcion menu con las 6 opciones disponibles.
    return 0;   //Fin del programa.
}

//Funcion menu
void menu(string cadena1,string cadena2){
    int opcion=0;   //Variable que almacena opcion del menu que elige el usuario.
		cout << "\n\t+-------------------------------+\n";
		cout << "\t|\t MENU PRINCIPAL \t|";
		cout << "\n\t+-------------------------------+";
		cout << "\n\t|     1) Concatenacion.  \t|";
        cout << "\n\t|     2) Potencia.  \t\t|";
        cout << "\n\t|     3) Inverso.  \t\t|";
		cout << "\n\t|     4) Prefijo / Sufijos. \t|";
		cout << "\n\t|     5) Subcadena.\t\t|";
		cout << "\n\t|     6) Salir del programa. \t|";
		cout << "\n\t+-------------------------------+\n";

		cout << "\n Digite la opcion que desea realizar: "; 
        cin >> opcion;	
        opciones(opcion,cadena1,cadena2);   //Invoxamos a la funcion que realizara la operacion indicada por el usuario.
}

//Funcion de las opciones.
void opciones(int opcion,string cadena1,string cadena2){
    string subca;   //Variable que almacena la subcadena de la opcion 5 del menu.
    int cad, po;    //cad almacena el numero de cadena captura al incio con la que se trabajara y po almacena el valor de potencia a trabajar en la opcion 2 del menu.
    switch(opcion){
            case 1:
                concatenacion(cadena1, cadena2);    //Invocamos a la funcion que concatenara de 2 formas las cadenas, la cual se encuentra en la linea 133.
                menu(cadena1,cadena2);  //Volvemos a mostrar el menu al usuario hasta que capture la opcion de salir.
            break;
            case 2:
                cout<<" \n   - Potencia: "; //Solicitamos el valor de la potencia de la cadena
                cin>>po;
                cout<<"   - Que cadena quiere utilizar 1 o 2? : ";  //El usuario selecciona la cadena con la que se va a trabajar.
                cin>>cad;
                if(cad==1){ //Dependiendo la cadena seleccioada son los parametros que se ele envian a la funcion dedicada a la operacion.
                    potencia(cadena1, po);
                }else if(cad==2){
                    potencia(cadena2, po);
                }else if(cad<1 || cad>2){   //Comprobacion de que se capturaron valores validos, como el numero de cadena adecuado.
                    cout << "\n Valores no validos, intente de nuevo.\n";
                }menu(cadena1,cadena2); //Volvemos a mostrar el menu al usuario hasta que capture la opcion de salir.
            break;
            case 3:
                cout<<"\n   - Que cadena quiere utilizar 1 o 2? : ";    //El usuario selecciona la cadena con la que se va a trabajar.
                cin>>cad;
                if(cad==1){ //Dependiendo la cadena seleccioada son los parametros que se ele envian a la funcion dedicada a la operacion.
                    inverso(cadena1);
                }else if(cad==2){
                    inverso(cadena2);
                }else{
                    cout << "\n Valores no validos, intente de nuevo.\n"; 
                }menu(cadena1,cadena2); //Volvemos a mostrar el menu al usuario hasta que capture la opcion de salir.
            break;
            case 4:
                cout<<"\n   - Que cadena quiere utilizar 1 o 2? : ";    //El usuario selecciona la cadena con la que se va a trabajar.
                cin>>cad;
                if(cad==1){ //Dependiendo la cadena seleccioada son los parametros que se ele envian a la funcion dedicada a la operacion.
                    presuf(cadena1);
                }else if(cad==2){
                    presuf(cadena2);
                }else{
                    cout << "\n Valores no validos, intente de nuevo.\n";
                }menu(cadena1,cadena2); //Volvemos a mostrar el menu al usuario hasta que capture la opcion de salir.
            break;
            case 5:
                cout<<"\n   - Subcadena a evaluar: ";   //Solicitamos la subcadena a buscar.
                cin>>subca;
                cout<<"   - Que cadena quiere utilizar 1 o 2? : ";  //El usuario selecciona la cadena con la que se va a trabajar.
                cin>>cad;
                if(cad==1){ //Dependiendo la cadena seleccioada son los parametros que se ele envian a la funcion dedicada a la operacion.
                    subcadena(cadena1, subca);
                }else if(cad==2){
                    subcadena(cadena2, subca);
                }else{
                    cout << "\n Valores no validos, intente de nuevo.\n";
                }menu(cadena1,cadena2); //Volvemos a mostrar el menu al usuario hasta que capture la opcion de salir.
            break;
            case 6:
                cout<<"\n   Hasta pronto!\n"<<endl; //Mensaje de despedida y finalizacion de la ejecucion del programa.
            break;
            default:
                cout << "\n Opcion no valida, intente de nuevo.\n";
		        menu(cadena1,cadena2);  //Volvemos a mostrar el menu al usuario hasta que capture la opcion de salir.
            break;
        }
}

//Funcion para concatenar cadenas.
void concatenacion(string a, string b){
    cout<<"\n   -> Opcion 1: ";
    cout<<a<<b; //Se concatena la cadena 1 y despues la cadena 2
    cout<<"\n   -> Opcion 2: ";
    cout<<b<<a<<endl;   //Se concatena la cadena 2 y despues la cadena 1
}

//Funcion para concatenar cadenas dependiendo la potencia.
void potencia(string a, int po){
    if(po<0){   //Comprovacion si la potencia es negativa
        reverse(a.begin(), a.end());    //Primero invertimos la cadena (carcateristica de las potencias negativas).
        po *= -1;   //Volvemos positivo el valor de la potencia
    }
    cout<<"\n   -> Cadena creada: ";
    for(int i=0; i<po; i++){    // Imprimimos en pantalla N veces la cadena, donde N es el valor de la potencia.
        cout<<a;
    }
    cout<<"\n";
}

//Funcion para invertir las cadenas.
void inverso(string a){
    cout<<"\n   -> El inverso de la cadena "<<a<<" es: ";
    reverse(a.begin(), a.end());    //Mediante la funcion reverse del lenguaje C++ mostramos en pantalla la cadena invertida.
    cout<<a<<endl;
}

//Funcion para obtener prefijos y sufijos.
void presuf(string a){
    char e=156; //Caracter del simbolo de Euro, simulando ser epsilon.
    cout<<"\n   -> Resultados: "<<endl;
    cout<<"\t Prefijos:"<<endl; //Mostramos los prefijos.
    cout<<"\t\t"<<e<<"\t\t";    //El primer prefijo de una cadena es epsilon, por lo cual lo imprimimos antes del bucle.
    for (int i = 0; i < a.length(); i++){   //Recorremos la cadena, imprimiendo caracter por caracter en cada iteracion de izquierda a derecha.
        cout<<"\n\t\t"<<e;  //Imprimimos epsilon al inicio de cada prefijo.
        for (int j = 0; j <= i; j++){
            cout<<a[j];
        }
    }
    cout<<"\n\n\t Sufijos:"<<endl;  //Mostramos los sufijos.
    cout<<"\t\t"<<e<<"\n\t\t";  //El primer sufijo de una cadena es epsilon, por lo cual lo imprimimos antes del bucle.
    for (int i = a.length()-1; i >= 0; i--){    //Recorremos la cadena, imprimiendo caracater por caracter en cada iteracion de derecha a izquierda.
        for (int j = i; j < a.length(); j++){
            cout<<a[j];
        }
        cout<<e<<"\n\t\t";  //Imprimimos epsilon al final de cada prefijo.
    }
}

//Funcion para encontrar las subcadenas.
void subcadena(string a, string b){
    for (int i = 0; i < a.length(); i++){   //Recorremos la cadena caracterer por caracter buscando el primer elemento de la subcadena.
        if(a[i]==b[0]){ //Si se encuentra el elemento, se sigue recorriendo la cadena incial, comprobando si el resto de elemetnos siguen la misma secuencia.
            int temp=i;
            for (int j = 0; j < b.length(); j++){
                if(a[temp]!=b[j]){
                    break;
                }
                if(j==b.length()-1){
                    cout<<"\n   -> Si es subcadena."<<endl; //Mensaje en caso de haber encontrado la subcadena que tiene como parametro la funcion.
                    return;
                }
                temp++;
            }
        }
    }
    cout<<"\n   -> No es subcadena."<<endl; //Mensaje en caso de no haber encontrado la subcadena que tiene como parametro la funcion.
}

//Funcion verificar
int verificar(string a){
    for (int i = 0; i < a.length(); i++){   //Recorremos la cadena de izqueirda a derecha.
        if(a[i]!='0' and a[i]!='1'){    //Comprueba si el elemento que se encuentra en el bucle es 1 o 0.
            return 1;
        }
    }
    return 0;
}
