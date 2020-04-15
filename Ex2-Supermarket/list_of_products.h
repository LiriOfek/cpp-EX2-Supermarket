/********************************************************\
File Name: list_of_products.h
Author: Liri (15/4/2020)
Purpose: This file contain the structure of list of products,
	     and declaration of functions that add node to list of
		 products, discount the price of the products and print
		 the products
\********************************************************/

#pragma once

#include "product.h"
#include <iostream>
#include <string>
#include <map>

const char* const ERROR_MEMORY_ALLOCATION_FAILED = "Error! memory allocation failed.\n";
const unsigned int HUNDRED = 100;

/*structure that contain node in list of products*/
typedef struct list {
	Product product;
	list* next;
}Product_List;

Product_List* add_new_product_to_end_of_list(Product_List** list_of_products,
	Product new_product);
/**
* @brief  add new product to the end of the list
* @param  IN Product_List** list_of_products - pointer to pointer to the
*		  list of the products
*		  IN Product new_product - the new product
*		  OUT Product_List* list_of_products - pointer to the list of
*		  products
* @return pointer to the list of products after add new product in the
*		  end of the list, if there was an error of memory allocation
*		  than return NULL
* @note   the function allocate memory for the new products
* @author  Liri
*/

Product_List* discount_product(Product_List** list_of_products,
	std::map<CATEGORY,
	double> discount_category);
/**
* @brief  discount each product price according to the discount of
*		  product category
* @param  IN Product_List** list_of_products - pointer to pointer to the
*		  list of the products
*		  IN std::map<CATEGORY,double> discount_category - the discount of
*		  each category
*		  OUT Product_List* list_of_products - pointer to the list of
*		  products
* @return pointer to the list of products after discount each product in
*		  the list according to the discount in the discount_category
* @author  Liri
*/