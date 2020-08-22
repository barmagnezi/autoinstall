#include "create_directory_action.h"
#include <iostream>


std::string CreateDirException::prefix_message() {
	return "Create directory failed with error code:";
}

CreateDirAction::CreateDirAction(std::wstring directory, LPSECURITY_ATTRIBUTES lpSecurityAttributes) : directory_(directory)
{
	if (CreateDirectory(directory_.c_str(
), lpSecurityAttributes))
	{
		std::wcout << L"Create " << directory_ << L"." << std::endl;
	}
	else if (ERROR_ALREADY_EXISTS == GetLastError())
	{
		throw DirAlreadyExists();
	}
	else
	{
		//throw CreateDirException(GetLastError());
		throw CreateDirException();
	}	
}

CreateDirAction::~CreateDirAction()
{
	if (!is_install_success())
	{
		if (!RemoveDirectory(directory_.c_str()))
		{
			std::wcout << L"Error deleting directory " << directory_ << L", continue (" << GetLastError() << ")" <<std::endl;
		}
		else
		{
			std::wcout << L"Directory " << directory_ << L" deleted." << std::endl;
		}
	}
}