/********************************************************\
File Name: list_of_products.cpp
Author: Liri (15/4/2020)
Purpose: This file contain the funcions that add node to list of products,
		 discount the price of the products and print the products
\********************************************************/

#include "list_of_products.h"

Product_List* add_new_product_to_end_of_list(Product_List** list_of_products,
												Product new_product) {
	Product_List* new_node;
	Product_List* current_node;

	new_node = (Product_List*)malloc(sizeof(Product_List));
	if (NULL == new_node) {
		printf(ERROR_MEMORY_ALLOCATION_FAILED);
		return NULL;
	}

	new_node->product = new_product;
	new_node->next = NULL;

	if (NULL == *list_of_products)
	{
		return new_node;
	}

	else
	{
		/*add the new node in the end of the list*/
		current_node = *list_of_products;
		while (NULL != current_node->next)
		{
			current_node = current_node->next;
		}
		current_node->next = new_node;
	}
	return *list_of_products;
}

Product_List* discount_products(Product_List** list_of_products,
								std::map<CATEGORY, double> discount_category) {

	Product_List* current_node;
	double discount = 0;

	current_node = *list_of_products;

	while (NULL != current_node) {
		/*reduce the product price according to the discount*/
		discount = (HUNDRED - discount_category[current_node->product.category]) / HUNDRED;
		current_node->product.price *= discount;
		current_node = current_node->next;
	}
	return *list_of_products;
}

void free_product_list(Product_List* list_of_products) {
	Product_List* tmp;

	while (NULL != list_of_products)
	{
		tmp = list_of_products;
		list_of_products = list_of_products->next;
		free(tmp);
	}
}

void print_list_of_products(Product_List* list_of_products) {

	Product_List* current_node;
	current_node = list_of_products;
	while (NULL != current_node) {
		std::cout << current_node->product.name
			<< PRINT_COST
			<< current_node->product.price
			<< DOLLAR
			<< std::endl;
		current_node = current_node->next;
	}
}