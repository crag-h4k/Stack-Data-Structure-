#ifndef _STACKTEMP_H_
#define _STACKTEMP_H_
#include <cstdlib> // Provides NULL and size_t
#include "node.h" // Node template class
#include <fstream>

namespace main_savitch_7B {
	template <class T>
	class stack
	{
		public:
		// TYPEDEFS
			typedef std::size_t size_type;
			typedef T value_type;
			// CONSTRUCTORS and DESTRUCTOR
			stack( ) {
				top_ptr = NULL;
			}
			stack(const stack& source);
			~stack( ) {
				main_savitch_7B::list_clear(top_ptr);
			} // MODIFICATION MEMBER FUNCTIONS
			void push(const T& entry);
			void pop( );
			void operator = (const stack& source);
			// CONSTANT MEMBER FUNCTIONS
			size_type size( ) const {
				return main_savitch_7B::list_length(top_ptr);
			}
			bool empty( ) const {
				return (top_ptr == NULL);
			}
			T top( ) const;
		private:
			main_savitch_7B::node<T> *top_ptr; // Points to top of stack
	};
}

#include "stack.cpp"
#endif
