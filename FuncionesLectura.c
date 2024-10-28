#include <stdlib.h>

char LeerVel(void);

int main (void){
    char velocidad;
    velocidad = LeerVel();

}

char LeerVel(void){
    int respuesta_vel;
    char resp_vel_edit;
    char com_vel[] = ""; //Comando de lectura a enviar
    //Enviar Comando de lectura de alguna forma
    //Recibir respuesta con valor leido
    char resp_vel_RAW[]=""; //Valor que deberia llegar
    resp_vel_edit = RecortarString(resp_vel_RAW);
    respuesta_vel = strtol(resp_vel_edit,NULL,16) * 0.001;    //Convertir valor HEX a DEC con factor aplicado
}
char LeerAmps(void){
    int respuesta_par;
    char resp_amps_edit;
    char com_amps[] = ""; //Comando de lectura a enviar
    //Enviar Comando de lectura de alguna forma
    //Recibir respuesta con valor leido
    char resp_amps_RAW[]=""; //Valor que deberia llegar
    resp_amps_edit = RecortarString(resp_amps_RAW);
    respuesta_par = strtol(resp_amps_edit,NULL,16) * 0.001;    //Convertir valor HEX a DEC con factor aplicado
}
char LeerPar(void){
    int respuesta_par;
    char resp_par_edit;
    char rom_par[] = "01 03 14 27 00 02 71 F0"; //Comando de lectura a enviar
    //Enviar Comando de lectura de alguna forma
    //Recibir respuesta con valor leido
    char resp_par_RAW[]="01 03 04 00 00 27 0E 60 07"; //Valor que deberia llegar
    resp_par_edit = RecortarString(resp_par_RAW);
    respuesta_par = strtol(resp_par_edit,NULL,16) * 0.001;    //Convertir valor HEX a DEC con factor aplicado
}
char LeerPot(void){
    int respuesta_pot;
    char resp_pot_edit;
    char rom_pot[] = "01 03 14 27 00 02 71 F0"; //Comando de lectura a enviar
    //Enviar Comando de lectura de alguna forma
    //Recibir respuesta con valor leido
    char resp_pot_RAW[]="01 03 04 00 00 27 0E 60 07"; //Valor que deberia llegar
    resp_pot_edit = RecortarString(resp_pot_RAW);
    respuesta_pot = strtol(resp_pot_edit,NULL,16) * 0.001;    //Convertir valor HEX a DEC con factor aplicado
}
char LeerTens(void){
    int respuesta_tens;
    char resp_tens_edit;
    char rom_tens[] = "01 03 14 27 00 02 71 F0"; //Comando de lectura a enviar
    //Enviar Comando de lectura de alguna forma
    //Recibir respuesta con valor leido
    char resp_tens_RAW[]="01 03 04 00 00 27 0E 60 07"; //Valor que deberia llegar
    resp_tens_edit = RecortarString(resp_tens_RAW);
    respuesta_tens = strtol(resp_tens_edit,NULL,16) * 0.001;    //Convertir valor HEX a DEC con factor aplicado
}
char LeerTemp(void){
    int respuesta_temp;
    char resp_temp_edit;
    char rom_temp[] = "01 03 14 27 00 02 71 F0"; //Comando de lectura a enviar
    //Enviar Comando de lectura de alguna forma
    //Recibir respuesta con valor leido
    char resp_temp_RAW[]="01 03 04 00 00 27 0E 60 07"; //Valor que deberia llegar
    resp_temp_edit = RecortarString(resp_temp_RAW);
    respuesta_temp = strtol(resp_temp_edit,NULL,16) * 0.001;    //Convertir valor HEX a DEC con factor aplicado
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