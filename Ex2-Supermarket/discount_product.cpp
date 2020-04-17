/********************************************************\
File Name: discount_product.cpp
Author: Liri (17/4/2020)
Purpose: This file discount each product according to the biggest dicount
		 category it belongs to
\********************************************************/

#include "discount_product.h"

void discount_product(std::vector<Product> &products_vector,
						std::map<CATEGORY, double> discount_category_map) {
	double relative_part_of_price = 0;
	double biggest_discount;
	for (int index = 0; index < (int)products_vector.size(); ++index) {
		biggest_discount = biggest_discount_of_product(
			products_vector[index].categories_vector,
			discount_category_map);
		relative_part_of_price = (HUNDRED - biggest_discount) / HUNDRED;
		/*update the price after discount*/
		products_vector[index].price *= relative_part_of_price;
	}
}

double biggest_discount_of_product(std::vector<CATEGORY> categories_vector,
									std::map<CATEGORY, double> discount_category_map) {
	double biggest_discount = 0;
	double current_discount = 0;
	for (int i = 0; i < (int)categories_vector.size(); ++i) {
		current_discount = discount_category_map[categories_vector[i]];
		if (current_discount > biggest_discount) {
			biggest_discount = current_discount;
		}
	}
	return biggest_discount;
}