// Task 13.1. - Enhance Core and Grad ctors to identify ctor and its arguments.
//              Provide app to verify every ctor.

#include "misc.hpp"

int main() {
	static_cast<void>(misc::Core());
	static_cast<void>(misc::Grad());
	static_cast<void>(misc::Core(std::cin));
	static_cast<void>(misc::Grad(std::cin));

	return 0;
}
