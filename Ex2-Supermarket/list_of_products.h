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

/*structure that contain node in list of products*/
typedef struct list {
	Product product;
	list* next;
}Product_List;