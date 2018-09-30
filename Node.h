/*
 * Node.h
 *
 *  Created on: Dec 10, 2015
 *      Author: Nazanin
 */

#ifndef NODE_H_
#define NODE_H_
template<class type>
class Node {

public:
	
	type data;
	Node *next;
	Node *prev;
};

#endif /* NODE_H_ */

