/********************************************************\
File Name: discount_product.h
Author: Liri (17/4/2020)
Purpose: This header file contain the declaration of function that
discount the price of each product in product vector according
to the category it belongs to
\********************************************************/

#pragma once

#include "product.h"

#include <iostream>
#include <map>
#include <vector>

const char* const PRINT_COST = " costs ";
const char* const DOLLAR = "$";
const unsigned int HUNDRED = 100;

void discount_product(std::vector<Product> &products_vector,
						std::map<CATEGORY, double> discount_category_map);
/**
* @brief  discount each product according to the category it belongs to
* @param  INOUT std::vector<Product> &products_vector - the vector
*		  of products
*		  IN std::map<CATEGORY, double> discount_category_map - the map of
*		  the discount that corresponding to the categoryS
* @notes  the vector of products changed such that each price of product
*		  discount according to its category
* @return this function has no return value
* @author  Liri
*/