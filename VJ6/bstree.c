#include <stdio.h>
#include <malloc.h>
#include "bstree.h"

BSTree NewBSTree()
{
	// Novo prazno stablo
	Node* tr = NULL;
	return tr;
}

void AddNode(BSTree *bst, char *word)
{
	// Rekurzivno se tra�i mjesto za novi �vor u stablu. Ako rije� postoji u stablu, ne dodaje se.
	// bst parametar je dvostruki pokaziva�.
	if (*bst == NULL)
	{
		(*bst) = (Node*) malloc(sizeof(Node));
		(*bst)->word = word;
		(*bst)->left = NULL;
		(*bst)->right = NULL;
	}
	else
	{
		if (strcmp(word, (*bst)->word) < 0)
		{
			AddNode((&(*bst)->left), word);
		}
		else if (strcmp(word, (*bst)->word) > 0)
		{
			AddNode((&(*bst)->right),word);
		}
		else
		{
			free(word);
		}
	}
}

int BSTHeight(BSTree bst)
{
	int lijevo = 0, desno = 0;
	if (bst == NULL)
	{
		return 0;
	}
	lijevo = BSTHeight(bst->left);
	desno = BSTHeight(bst->right);
	if (lijevo < desno)
	{
		return 1 + desno;
	}
	else
	{
		return 1 + lijevo;
	}
}

void PrintBSTree(BSTree bst)
{
	// Ispisuje rije�i u stablu na ekran po abecednom redu.
	// In-order �etnja po stablu (lijevo dijete, �vor, desno dijete)
	if (bst == NULL)
	{
		return;
	}
	PrintBSTree(bst->left);
	printf("%s\n", bst->word);
	PrintBSTree(bst->right);
}

void SaveBSTree(BSTree bst, FILE *fd)
{
	// Snima rije� po rije� iz stabla u tekstualnu datoteku. Rije�i su odvojene razmakom.
	// Pre-order �etnja po stablu (ttenutni �vor pa djeca)
	if (bst == NULL)
	{
		return;
	}
	fprintf(fd, "%s ", bst->word);
	SaveBSTree(bst->left, fd);
	SaveBSTree(bst->right, fd);
}

void DeleteBSTree(BSTree bst)
{
	// Bri�e stablo (string word i sam �vor) iz memorije.
	// Post-order �etnja po stablu (prvo djeca pa trenutni �vor)
	if (bst == NULL)
	{
		return;
	}
	DeleteBSTree(bst->left);
	DeleteBSTree(bst->right);
	free(bst->word);
	free(bst);
}

BSTree LoadBSTree(FILE *fd)
{
	// U�itava rije� po rije� iz tekstualne datoteke i dodaje ih u stablo preko AddNode() funkcije.
	// Rije� duplicirati sa strdup().
	char rijec[1024];
	Node* bst = NewBSTree();
	while (fscanf(fd, "%s ", rijec) != EOF)
	{
		AddNode(&bst, strdup(rijec));
	}
	return bst;
}

int Rijeci(BSTree bst)
{
	if (bst == NULL)
	{
		return 0;
	}
	else if (strlen(bst->word) > 5)
	{
		return Rijeci(bst->right) + Rijeci(bst->left) + 1;
	}
	else if (strlen(bst->word) <= 5)
	{
		return Rijeci(bst->right) + Rijeci(bst->left);
	}
}