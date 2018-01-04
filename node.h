#ifndef _NODETEMP_H_
#define _NODETEMP_H_
#include <cstdlib> // Provides NULL and size_t
#include <iterator>
#include <fstream>

namespace main_savitch_7B {
	template <class T> class node
	{
		public:
			// TYPEDEF
			typedef T value_type;
			// CONSTRUCTOR
			node(const T& init_data=T( ), node* init_link=NULL) {
				data_field = init_data;
				link_field = init_link;
			} // MODIFICATION MEMBER FUNCTIONS
			T& data( ) {
				return data_field;
			}
			node* link( ) {
				return link_field;
			}
			void set_data(const T& new_data) {
				data_field = new_data;
			}
			void set_link(node* new_link) {
				link_field = new_link;
			}
			// CONST MEMBER FUNCTIONS
			const T& data( ) const {
				return data_field;
			}
			const node* link( ) const {
				return link_field;
			}
		private:
		    T data_field;
		    node *link_field;
	};

	// FUNCTIONS to manipulate a linked list:
	template <class T>
	void list_clear(node<T>*& head_ptr);

	template <class T>
	void list_copy
	(const node<T>* source_ptr, node<T>*& head_ptr, node<T>*& tail_ptr);

	template <class T>
	void list_head_insert(node<T>*& head_ptr, const T& entry);

	template <class T>
	void list_head_remove(node<T>*& head_ptr);

	template <class T>
	void list_insert(node<T>* previous_ptr, const T& entry);

	template <class T>
	std::size_t list_length(const node<T>* head_ptr);

	template <class NodePtr, class SizeType>
	NodePtr list_locate(NodePtr head_ptr, SizeType position);

	template <class T>
	void list_remove(node<T>* previous_ptr);

	template <class NodePtr, class T>
	NodePtr list_search(NodePtr head_ptr, const T& target);
}

#include "node.cpp"
#endif
