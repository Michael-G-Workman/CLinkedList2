// CLinkedList2.c
//
// By Michael G. Workman
//
// A simple C program demonstrating a Linked List using a Struct for a Zoo Animal
// In this second version of this console app, we use a doubly linked list to emulate
// animals in a zoo, and we create a function to search the list for certain animal types,
// and also a delete operation that will delete a specific node, but keep the list intact
//
// This example freely distributable under terms of MIT open source license
// https://opensource.org/licenses/MIT

#include <stdio.h>
#include <stdlib.h>

// our animal types
enum AnimalType {
	Lion,
	Giraffe,
	Zebra,
	Pangolin
};

// our animal sex
enum AnimalSex {
	Male,
	Female
};

// data type to be used for each animal (node) in the linked list
struct zooAnimal {
	enum AnimalType type;
	int weight;
	int age;
	enum AnimalSex sex;
	struct zooAnimal* next;
	struct zooAnimal* previous;
};

// function to return the string name of Animal Type Enum
const char* getEnumNameAnimalType(enum AnimalType animalType) {
	switch (animalType)
	{
		case Lion: return "Lion";
		case Giraffe: return "Giraffe";
		case Zebra: return "Zebra";
		case Pangolin: return "Pangolin";
	}
}

// function to return the string name of Animal Sex Enum
const char* getEnumNameAnimalSex(enum AnimalSex animalSex) {
	switch (animalSex)
	{
		case Male: return "Male";
		case Female: return "Female";
	}
}

// function to search the list of animals to find a specific animal
// print out matching animals
void searchAnimals(enum AnimalType animalType, struct zooAnimal* animalList)
{
	// loop through list, finding matching animals
	while (animalList != NULL)
	{
		if (animalList->type == animalType) {

			printf("%d year old, %d pound %s %s\n\n",
				animalList->age,
				animalList->weight,
				getEnumNameAnimalSex(animalList->sex),
				getEnumNameAnimalType(animalList->type));
		}
		
		animalList = animalList->next;
	}
}

int main()
{
	// we will have a zoo keeper var to point at specific animals in the list
	// starting with the first animal in the list
	struct zooAnimal* zooKeeper = NULL;

	// create a 3 year old 300 pound male lion, make start node of list
	struct zooAnimal* lion1 = (struct zooAnimal*)malloc(sizeof(struct zooAnimal));
	if (NULL == lion1)
	{
		printf("\n Lion creation failed \n");
		return 1;
	}
	lion1->type = Lion;
	lion1->sex = Male;
	lion1->age = 3;
	lion1->weight = 300;
	lion1->next = NULL;
	
	// since this is the first animal (node) in the list, there is no previous animal
	lion1->previous = NULL;

	// have the zoo keeper point to this first animal (node) in the list
	zooKeeper = lion1;

	// create a 1 year old 50 pound female lion cub then make next node in the list
	// make the first lion the previous animal in the list
	struct zooAnimal* lion2 = (struct zooAnimal*)malloc(sizeof(struct zooAnimal));
	if (NULL == lion2)
	{
		printf("\n Lion creation failed \n");
		return 1;
	}
	lion2->type = Lion;
	lion2->sex = Female;
	lion2->age = 1;
	lion2->weight = 50;
	lion2->next = NULL;

	// add this lion to be the next animal (node) in the list
	lion1->next = lion2;

	// make the first lion the previous animal in the list
	lion2->previous = lion1;

	// create a 3 year old 10 pound adult male pangolin then make next node in the list
	// make the second lion the previous animal in the list
	struct zooAnimal* pangolin1 = (struct zooAnimal*)malloc(sizeof(struct zooAnimal));
	if (NULL == pangolin1)
	{
		printf("\n Pangolin creation failed \n");
		return 1;
	}
	pangolin1->type = Pangolin;
	pangolin1->sex = Male;
	pangolin1->age = 3;
	pangolin1->weight = 10;
	pangolin1->next = NULL;

	// add this pangolin to be the next animal (node) in the list
	lion2->next = pangolin1;

	// make the second lion the previous animal in the list
	pangolin1->previous = lion2;

	// create a 5 year old 400 pound adult male giraffe then make next node in the list
	// make the pangolin the previous animal in the list
	struct zooAnimal* giraffe1 = (struct zooAnimal*)malloc(sizeof(struct zooAnimal));
	if (NULL == giraffe1)
	{
		printf("\n Giraffe creation failed \n");
		return 1;
	}
	giraffe1->type = Giraffe;
	giraffe1->sex = Male;
	giraffe1->age = 5;
	giraffe1->weight = 400;
	giraffe1->next = NULL;

	// add this giraffe to be the next animal (node) in the list
	pangolin1->next = giraffe1;

	// make the pangolin the previous animal in the list
	giraffe1->previous = pangolin1;

	// create a 2 year old 250 pound adult female zebra then make next node in the list
	struct zooAnimal* zebra1 = (struct zooAnimal*)malloc(sizeof(struct zooAnimal));
	if (NULL == zebra1)
	{
		printf("\n Zebra creation failed \n");
		return 1;
	}
	zebra1->type = Zebra;
	zebra1->sex = Female;
	zebra1->age = 2;
	zebra1->weight = 250;
	zebra1->next = NULL;

	// add this zebra to be the next animal (node) in the list
	giraffe1->next = zebra1;

	// make the giraffe the previous animal in the list
	zebra1->previous = giraffe1;

	printf("Search Results\n=================\n\n");

	// search for specific animal type
	searchAnimals(Lion, zooKeeper);

	printf("Traversing Animal List Forward!!\n=================================\n\n");

	// traverse the linked list moving forward
	while (zooKeeper != NULL) {

		printf("%d year old, %d pound %s %s\n\n",
			zooKeeper->age,
			zooKeeper->weight,
			getEnumNameAnimalSex(zooKeeper->sex),
			getEnumNameAnimalType(zooKeeper->type));

		zooKeeper = zooKeeper->next;
	}

	// set the zookeeper to the last animal (node) in the list, the Zebra
	zooKeeper = zebra1;

	printf("Traversing Animal List Backwards!!\n==================================\n\n");

	// traverse the linked list moving backwards
	while (zooKeeper != NULL) {

		printf("%d year old, %d pound %s %s\n\n",
			zooKeeper->age,
			zooKeeper->weight,
			getEnumNameAnimalSex(zooKeeper->sex),
			getEnumNameAnimalType(zooKeeper->type));

		zooKeeper = zooKeeper->previous;
	}

	// delete the pangolin from the list, and keep the list intact after delete

	// set the previous animal (node) to pangolin next field to the pangolin next field
	pangolin1->previous->next = pangolin1->next;

	// set the next animal (node) to pangolin previous field to the pangolin previous field
	pangolin1->next->previous = pangolin1->previous;

	// delete the pangolin from the list
	free(pangolin1);

	// display the list after the delete operation
	printf("List After Deletion of Pangolin!!\n=================================\n\n");

	// reset zooKeeper to first element in the list, the first lion
	zooKeeper = lion1;

	// traverse the linked list moving forward after delete operation
	while (zooKeeper != NULL) {

		printf("%d year old, %d pound %s %s\n\n",
			zooKeeper->age,
			zooKeeper->weight,
			getEnumNameAnimalSex(zooKeeper->sex),
			getEnumNameAnimalType(zooKeeper->type));

		zooKeeper = zooKeeper->next;
	}

	// free the allocated memory for the zoo animals (nodes)	
	free(lion1);
	free(lion2);
	free(giraffe1);
	free(zebra1);
	free(zooKeeper);

	return 0;
}
