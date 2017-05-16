#include <stdio.h>
#include <stdlib.h>
#include "arquivo.h"
#include "arv.h"

int main(){
    FILE *fp;
    Registro reg;
    fp = fopen("arq", "w+");
    for(int i = 0; i < 300; i++){
        reg = insereReg(reg, i, "registro tal", rand()%307, "wildes", "2017-05-15");
        fwrite(&reg, sizeof(Registro), 1, fp);
    }
    mostrarRegistros(fp);
    fclose(fp);
    return 0;
}
