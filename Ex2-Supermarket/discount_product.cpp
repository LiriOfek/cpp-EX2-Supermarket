/********************************************************\
File Name: discount_product.cpp
Author: Liri (17/4/2020)
Purpose: This file discount each product according to the category
it belongs to
\********************************************************/

#include "discount_product.h"

void discount_product(std::vector<Product> &products_vector,
	std::map<CATEGORY, double> discount_category_map) {
	double relative_part_of_price = 0;
	for (int index = 0; index < (int)products_vector.size(); ++index) {
		relative_part_of_price = (HUNDRED - discount_category_map[products_vector[index].category]) / HUNDRED;
		/*update the price after discount*/
		products_vector[index].price *= relative_part_of_price;
	}
}