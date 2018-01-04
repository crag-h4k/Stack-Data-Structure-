#include <cassert> // Provides assert
#include "stack.h"

namespace main_savitch_7B {

	template <class T>
	stack<T>::stack(const stack<T>& source)
	// Library facilities used: node2.h
	{
		main_savitch_7B::node<T> *tail_ptr; // Needed for argument of list_copy main_savitch_6B::list_copy(source.top_ptr, top_ptr, tail_ptr);

	 	main_savitch_7B::list_copy(source.top_ptr, top_ptr, tail_ptr);
	}

	template <class T>
	void stack<T>::push(const T& entry)
	// Library facilities used: node.h
	{
		main_savitch_7B::list_head_insert(top_ptr, entry);
	}

	template <class T>
	void stack<T>::pop( )
	// Library facilities used: cassert, node2.h
	{
	    assert(!empty( ));
		main_savitch_7B::list_head_remove(top_ptr);
	}

	template <class T>
	void stack<T>::operator =(const stack<T>& source)
	// Library facilities used: node2.h
	{
		main_savitch_7B::node<T> *tail_ptr; // Needed for argument of list_copy

		if (this == &source) // Handle self-assignment
			return;

		main_savitch_7B::list_clear(top_ptr);
		main_savitch_7B::list_copy(source.top_ptr, top_ptr, tail_ptr);
	 }

	template <class T>
	T stack<T>::top( ) const
	{
	    assert(!empty( ));
		return top_ptr->data( );
	}
}
