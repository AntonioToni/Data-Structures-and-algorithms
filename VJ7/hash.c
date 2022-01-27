#include "hash.h"
#include <malloc.h>
#include <stdio.h>
#include <string.h>

#define HCONST 3567892

void dodaj_glavu(Bin** head, char *word)
{
	Bin* new = malloc(sizeof(Bin*));
	new->word = word;
	new->next = *head;
	*head = new;
}

HashTable *NewTable(int size)
{
	HashTable *new = (HashTable*)malloc(sizeof(HashTable));
	new -> size = size;
	new -> load = 0;
	new -> table = (Bin**)calloc(new->size, sizeof(Bin*));
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
	Bin* head = ht->table[index];
	dodaj_glavu(&head, word);
	ht->table[index] = head;
	ht->load++;
}

int Get(HashTable *ht, char *word)
{
	unsigned int key = hash(word);
	int index = key % ht->size;
	Bin* temp = ht->table[index];
	while (temp->next != NULL)
	{
		if (strcmp(temp->word, word) == 0)
		{
			return 1;
		}
		temp = temp->next;
	}
}

void DeleteTable(HashTable *ht)
{
	// brise cijelu hash tablicu (liste na svim pretincima (rijec i element liste), pretince ...)
	for (int i = 0; i < ht->size; i++)
	{
		Bin* temp = ht->table[i];
		while (temp != NULL)
		{
			Bin* brisi = temp;
			temp = temp->next;
			free(brisi->word);
			free(brisi);
		}
	}
	free(ht->table);
	free(ht);
}