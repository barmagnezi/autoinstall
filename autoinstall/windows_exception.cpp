#include "windows_exception.h"
#include <iostream>

std::string WindowsException::prefix_message() const{
	return "Generic windows error with code:";
}

void WindowsException::print_error_code_message() const
{
	std::cout << prefix_message() << windows_error_code_ << std::endl;
}

WindowsException::WindowsException()
{
	windows_error_code_ = GetLastError();
}