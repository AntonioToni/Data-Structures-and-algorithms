#include "hash.h"
#include <malloc.h>
#include <stdio.h>
#include <string.h>

#define HCONST 3567892

HashTable *NewTable(int size)
{
	HashTable *new = (HashTable*)malloc(sizeof(HashTable));
	new -> size = size;
	new -> load = 0;
	new -> table = (Bin**)malloc(new->size * sizeof(Bin*));
	int i;
	for (i = 0; i < new -> size; i++)
	{
		new ->table[i] = NULL;
	}
	return new;
}

unsigned int hash(char *word)
{
	// od kljuca generira hash kod
	unsigned int key = 0;
	while(*word != '\0')
	{
		key = key*HCONST + *word;
		word++;
	}
	return key;
}

void Insert(HashTable *ht, char *word)
{
	// dodaje novu rijec u listu na odgovarajucem pretincu
	unsigned int key = hash(word);
	int index = key % ht -> size;
	if (ht -> table[index] != NULL)
	{
		Bin* head = ht->table[index];
		dodaj_glavu(&head, word);
		ht->table[index] = head;
		ht->load++;
	}
	else
	{
		ht->table[index] = malloc(sizeof(Bin*));
		Bin* head = NULL;
		dodaj_glavu(&head, word);
		ht->table[index] = head;
		ht->load++;
	}
}

int Get(HashTable *ht, char *word)
{
	int i;
	for (int i = 0; i < ht->size; i++)
	{
		if (ht->table[i] == NULL)
			return 0;
		else if (strcmp(ht->table[i]->word,word)==0)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	return 0;
}

void DeleteTable(HashTable *ht)
{
	// brise cijelu hash tablicu (liste na svim pretincima (rijec i element liste), pretince ...)
	free(ht->table);
	free(ht);
}