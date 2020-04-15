/********************************************************\
File Name: main.cpp
Author: Liri (15/4/2020)
Purpose: This file test functions in list_of_products.cpp,
		 make a list of products, discount their price, and print the
		 results
\********************************************************/

const unsigned int NUMBER_OF_PRODUCTS = 6;
const unsigned int NUMBER_OF_CATEGORIES = 5;

enum {
	SUCCESS,
	FAIL
};

#include "list_of_products.h"

#include "list_of_products.h"

int test_discount(Product products[],
	const char *products_name[],
	CATEGORY products_category[],
	double products_price[],
	double discount_categories[]) {
	/**
	* @brief  fill the list with products, discount each product with the
	*		  corresponding discount, and print the results
	* @param  IN Product products[] - array of the products
	*		  IN const char *products_name[] - array of products names
	*		  IN CATEGORY products_category[] - array of products catagories
	*		  IN double products_price[] - array of products prices
	*		  IN double discount_categories[] - array of discount corresponding
	*		  to each category
	*		  OUT FAIL if there was an error of memory allocation,
	*		  otherwise returb SUCCESS
	* @return FAIL if there was an error of memory allocation,
	*		  otherwise return SUCCESS
	* @note   call add_new_product_to_end_of_list() that allocate memory for
	*		  the list, and call free_product_list() that free the allocated
	*		  memory for the list
	* @author  Liri
	*/
	Product_List* list_of_products = NULL;

	/*fill list with products*/
	for (int index = 0; index < NUMBER_OF_PRODUCTS; ++index) {
		products[index] = { products_name[index],
			products_category[index],
			products_price[index] };
		list_of_products = add_new_product_to_end_of_list(&list_of_products,
			products[index]);
	}

	if (NULL == list_of_products) {
		return FAIL;
	}

	/*add the disount of each category*/
	std::map<CATEGORY, double> discount_category;
	for (int index = 0; index < NUMBER_OF_CATEGORIES; ++index) {
		discount_category.insert(std::make_pair((CATEGORY)index,
			discount_categories[index]));
	}

	/*discount the products*/
	list_of_products = discount_product(&list_of_products,
		discount_category);

	/*print the products*/
	print_list_of_products(list_of_products);

	free_product_list(list_of_products);

	return SUCCESS;
}