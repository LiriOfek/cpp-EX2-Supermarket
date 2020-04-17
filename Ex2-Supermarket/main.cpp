/********************************************************\
File Name: main.cpp
Author: Liri (17/4/2020)
Purpose: This file fill vector of products with products,
		 discount each product corresponding to the category it belongs,
		 and print the products that in the vector after the discount
\********************************************************/

#include "discount_product.h"


const unsigned int NUMBER_OF_PRODUCTS = 6;
const unsigned int NUMBER_OF_CATEGORIES = 5;

enum {
	SUCCESS,
	FAIL
};
void fill_products_vector(const char *products_name[],
	CATEGORY products_category[],
	double products_price[],
	std::vector<Product> &products_vector) {
	/**
	* @brief  fill the products vector with products contain name,
	*		  category and price
	* @param  IN const char *products_name[] - the array of products names
	*		  IN CATEGORY products_category[] - the array of categories that
	*		  corresponding to the names
	*		  IN double products_price[] - the array of prices that
	*		  corresponding to the names
	*		  INOUT std::vector<Product> &products_vector - the vector of
	*		  products
	* @notes  the vector of products changed such that added into it
	*		  the new products
	* @return this function has no return value
	* @author  Liri
	*/
	for (int index = 0; index < NUMBER_OF_PRODUCTS; ++index) {
		products_vector.push_back({ products_name[index],
			products_category[index],
			products_price[index] });
	}
}

void print_products(std::vector<Product> products_vector) {
	/**
	* @brief  print the products that in the vector of products
	* @param  IN std::vector<Product> products_vector - the vector of products
	* @return this function has no return value
	* @author  Liri
	*/
	for (product n : products_vector) {
		std::cout << n.name
			<< PRINT_COST
			<< n.price
			<< DOLLAR
			<< std::endl;
	}
}

int main() {
	/**
	* @brief  initiate arrays of product features and
	*		  fill the list with products, discount each product with the
	*		  corresponding discount, and print the results
	* @param  OUT FAIL if there was an error of memory allocation,
	*		  otherwise returb SUCCESS
	* @return FAIL if there was an error of memory allocation,
	*		  otherwise return SUCCESS
	* @author  Liri
	*/

	const char *products_name[] = { "white bread",
		"orange juice",
		"carrot",
		"apple",
		"banana",
		"white meat" };

	/*category corresponding to each name in products*/
	CATEGORY products_category[] = { BREAD,
		DRINK,
		VEGETABLES,
		FRUITS,
		FRUITS,
		MEAT };
	/*price of each product*/
	double products_price[] = { 30,
		13,
		6,
		7,
		10,
		100 };

	/*discount of each category, in percents*/
	double discount_categories[] = { 10,
		20,
		15,
		30,
		5 };

	std::vector<Product> products_vector;
	std::map<CATEGORY, double> discount_category_map;

	/*fill vector with product features (names, categories and prices)*/
	fill_products_vector(products_name,
		products_category,
		products_price,
		products_vector);

	/*print the product name and the price after discount*/
	print_products(products_vector);
}