/********************************************************\
File Name: product.h
Author: Liri (15/4/2020)
Purpose: This file contain the structure of the producet, 
		 and the enum structure of categories of products
\********************************************************/

#pragma once

#include <vector>

/*enum structute of categories of products*/
typedef enum {
	BREAD,
	DRINK,
	VEGETABLES,
	FRUITS,
	MEAT
}CATEGORY;

/*structure that contain the product features (name, categories, price)*/
typedef struct product {
	const char* name;
	std::vector<CATEGORY> categories_vector;
	double price;
}Product;
