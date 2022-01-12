#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	float sel[12]; //0-2 normale, 3-5 x, 6-8 y, 9-11 z
	unsigned short col;
}trokut;

typedef struct 
{
	trokut *niz;
	unsigned int n;
}objekt3d;

objekt3d *read()
{
	int i, j;
	FILE *prstl = fopen("primjerbin.stl", "rb");
	objekt3d *new = (objekt3d*)malloc(sizeof(objekt3d));
	fseek(prstl, 80, SEEK_SET);
	fread(&new -> n, 4, 1, prstl);
	new -> niz = (trokut*)malloc(sizeof(trokut) * (new->n));
	for (i = 0; i < (new -> n); i++)
	{
		for (j = 0; j < 12; j++)
		{
			printf("%f",fread(&new->niz[i].sel[j],4,1,prstl));
			fread(&new -> niz[i].sel[j], 4, 1, prstl);
		}
		fread(&new -> niz[i].col, 2, 1, prstl);
	}
	fclose(prstl);
	return new;
}

void writebin(objekt3d *new)
{
	FILE *bin = fopen("bin.stl", "wb");
	int i, j;
	char buffer[80] = { 0 };
	fwrite(buffer, sizeof(char), 80, bin);
	fwrite(&new -> n, 4, 1, bin);
	for (i = 0; i < new -> n; i++)
	{
		for (j = 0; j < 12; j++)
		{
			fwrite(&new -> niz[i].sel[j], 4, 1, bin);
		}
		fwrite(&new -> niz[i].col, 2, 1, bin);
	}
	fclose(bin);
}

void writetxt(objekt3d *new)
{
	FILE *txt = fopen("txt.stl", "wt");
	int i, j;
	fprintf(txt, "solid \n");
	for (i = 0; i < new -> n; i++)
	{
		fprintf(txt, "facet normal %f %f %f\n", &new -> niz[i].sel[0], &new -> niz[i].sel[1], &new -> niz[i].sel[2]);
		fprintf(txt, "outer loop\n");
		for(j = 3; j < 12; j += 3)
		{
			fprintf(txt, "vertex %f %f %f\n", new -> niz[i].sel[j], new -> niz[i].sel[(j+1)], new -> niz[i].sel[(j+2)]);
		}
		fprintf(txt, "endfacet\n");
	}
	fclose(txt);
}

void del(objekt3d *new)
{
	free(new);
    free(new -> niz);
}

int main()
{
	objekt3d *new = read();
	writebin(new);
	writetxt(new);
	del(new);
	return 0;
}