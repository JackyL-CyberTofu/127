#include "intarr.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>

int intarr_save_json( intarr_t* ia, const char* filename )
{
    if ( ia==NULL || ia->data==NULL )
    {
        return 1;
    }
    if (filename==NULL)
    {
        return 1;
    }
    FILE *new=fopen(filename,"w+");
    int i=0;
    fprintf(new,"[");
    for (i=0;i<ia->len;i++)
    {
        fprintf(new," %d",ia->data[i]);
        if (i!=ia->len-1)
        {
            //Don't print comma on last # in array
            fprintf(new,",");
        }
    }
    fprintf(new," ]");
    fclose(new);
    return 0;
}

intarr_t* intarr_load_json( const char* filename )
{
    if (filename == NULL)
    {
        return NULL;
    }
    FILE * file;
    file = fopen (filename, "r+");
    if (file==NULL)
    {
        return NULL;
    }
    int count=0;
    char ch;
    int k,i=0;
    intarr_t *new=malloc(sizeof(intarr_t));
    
    while (!feof(file))
    {
        ch = getc(file);
        if (ch == ','){
            count ++;
        }
    }
    fseek(file,0,SEEK_SET);
    if (count==0)
    {
        new->len = 0;
        new->data = NULL;
        return new;
    }
    new->len=count+1;  //Last "," is not counted
    new->data=malloc(sizeof(int)*new->len);
    
    while(i<new->len)
    {
        while (fscanf(file, "%d",&k)!=1)
        {
            fseek(file, 1, SEEK_CUR);
            //Does not iterate because only 1 left
        }
        new->data[i]=k;
        i++;
    }
    fseek(file,0,SEEK_END);
    fclose(file);
    
    return new;
}


