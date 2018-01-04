#include <cassert> // Provides assert 
#include <cstdlib> // Provides NULL and size_t
#include "node.h"

namespace main_savitch_7B {
	template <class T>
	void list_clear(node<T>*& head_ptr)
	{
		while (head_ptr != NULL) list_head_remove(head_ptr);
	}

	template <class T> void list_copy
	(const node<T>* source_ptr, node<T>*& head_ptr, node<T>*& tail_ptr)
	{
        head_ptr = NULL;
        tail_ptr = NULL;
		// Handle the case of the empty list. if (source_ptr == NULL)
		return;
		// Make the head node for the newly created list, and put data in it. list_head_insert(head_ptr, source_ptr->data( )); tail_ptr = head_ptr;
		// Copy the rest of the nodes one at a time, adding at the tail of new list. source_ptr = source_ptr->link( );
		while (source_ptr != NULL)
		{
			list_insert(tail_ptr, source_ptr->data( ));
			tail_ptr = tail_ptr->link( );
			source_ptr = source_ptr->link( );
		}
	}

	template <class T>
	void list_head_insert(node<T>*& head_ptr, const T& entry)
	{
		head_ptr = new node<T>(entry, head_ptr);
	}

	template <class T>
	void list_head_remove(node<T>*& head_ptr)
	{
		node<T> *remove_ptr;
		remove_ptr = head_ptr;
		head_ptr = head_ptr->link( );
		delete remove_ptr;
	}

	template <class T>
	void list_insert(node<T>* previous_ptr, const T& entry)
	{
		node<T> *insert_ptr;
		insert_ptr = new node<T>(entry, previous_ptr->link( ));
		previous_ptr->set_link(insert_ptr);
	}

	template <class T>
	std::size_t list_length(const node<T>* head_ptr)
	{
		const node<T> *cursor;
		std::size_t answer;
		answer = 0;
		for (cursor = head_ptr; cursor != NULL; cursor = cursor->link( )) {
			++answer;
		}
		return answer;
	}

	template <class NodePtr, class SizeType>
	NodePtr list_locate(NodePtr head_ptr, SizeType position)
	{
	    NodePtr cursor;
	    std::size_t i;
		assert(0 < position);
		cursor = head_ptr;
		for (i = 1; (i < position) && (cursor != NULL); ++i) {
			cursor = cursor->link( );
		}
	 	return cursor;
	}

	template <class T>
	void list_remove(node<T>* previous_ptr)
	{
		node<T> *remove_ptr;
		remove_ptr = previous_ptr->link( );
		previous_ptr->set_link(remove_ptr->link( ));
		delete remove_ptr;
	}

	template <class NodePtr, class T>
	NodePtr list_search(NodePtr head_ptr, const T& target)
	{
		NodePtr cursor;
		for (cursor = head_ptr; cursor != NULL; cursor = cursor->link( )) {
			if (target == cursor->data( )) {
				return cursor;
			}
		}
		return NULL;
	}
}
