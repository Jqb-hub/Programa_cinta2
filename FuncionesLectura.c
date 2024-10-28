#include <stdlib.h>
#include <stdio.h>

char LeerVel(void);

const char LecturaVelocidad[]="01 03 14 27 00 02 71 F0";
const char LecturaCorriente[]="01 03 14 4F 00 02 F0 2C";
const char LecturaPar[]="01 03 14 59 00 01 11 E8";
const char LecturaPotencia[]="01 03 14 63 00 02 31 E5";
const char LecturaTension[]="01 03 14 77 00 01 71 E1";
const char LecturaTemperatura[]="01 03 14 F9 00 01 11 CA";


int main (void){
    int velocidad, corriente, par, potencia, tension, temperatura;
    velocidad = LeerParam(LecturaVelocidad);
    corriente = LeerParam(LecturaCorriente);
    par = LeerParam(LecturaPar);
    potencia = LeerParam(LecturaPotencia);
    tension = LeerParam(LecturaTension);
    temperatura = LeerParam(LecturaTemperatura);
    printf(velocidad,"\n",corriente,"\n",par,"\n",potencia,"\n",tension,"\n",temperatura);
}

int LeerParam(char param_lectura[]){ 
    int respuesta;
    char resp_edit;
    //Comando de lectura a enviar
    //Enviar Comando de lectura de alguna forma
    //Recibir respuesta con valor leido
    char resp_RAW[]=""; //Valor que deberia llegar
    resp_edit = RecortarString(resp_RAW);
    respuesta = strtol(resp_edit,NULL,16) * 0.001;    //Convertir valor HEX a DEC con factor aplicado
    return respuesta;
}

char RecortarString(char string_recortar[]){
    char string_sin_espacio[50];
    char string_final[20];
    int j = 0, t= 0, string_stop;
    for (int i = 0; string_recortar[i]; i++){               //Eliminar ceros de la respuesta
        if(string_recortar[i] != ' ')
            string_sin_espacio[j++] = string_recortar[i];
    }
    switch (string_sin_espacio[5]){                         //Tamaño de datos de respuesta
    case 3:
        string_stop = 3;
        break;
    case 4:
        string_stop = 7;
        break;
    case 5:
        string_stop = 3;
        break;
    case 6:
        string_stop = 3;
        break;
    case 7:
        string_stop = 7;
        break;
    case 9:
        break;
    default:
        break;
    }
    for (int k = 6; string_sin_espacio[6+string_stop]; k++){ //Extraer datos respuesta
        string_final[t++] = string_sin_espacio[k];
    }
    return string_final;    
}