/********************************************************\
File Name: discount_product.h
Author: Liri (17/4/2020)
Purpose: This header file contain the declaration of function that
		 discount the price of each product in product vector according
		 to the biggest discount category it belongs to
\********************************************************/

#pragma once

#include "product.h"

#include <iostream>
#include <map>
using namespace std;

const char* const PRINT_COST = " costs ";
const char* const DOLLAR = "$";
const unsigned int HUNDRED = 100;

void discount_product(std::vector<Product> &products_vector,
						std::map<CATEGORY, double> discount_category_map);
/**
* @brief  discount each product according to the category that has
the biggest discount that the product belongs to
* @param  INOUT std::vector<Product> &products_vector - the vector
*		  of products
*		  IN std::map<CATEGORY, double> discount_category_map - the map of
*		  the discount that corresponding to the categorys
* @notes  the vector of products changed such that each price of product
*		  discount according to its category
* @return this function has no return value
* @author  Liri
*/

double biggest_discount_of_product(std::vector<CATEGORY> categories_vector,
									std::map<CATEGORY, double> discount_category_map);
/**
* @brief  find the biggest discount of product according to the catefories
*		  it belongs to
* @param  IN std::vector<CATEGORY> categories_vector - the vector of categories
*		  of the product
*		  IN std::map<CATEGORY, double> discount_category_map - the map of
*		  the discount that corresponding to the categories
*		  OUT double biggest discount of product
* @return the biggest discount of products
* @author  Liri
*/
