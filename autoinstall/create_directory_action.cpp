#include "create_directory_action.h"
#include <iostream>


std::string CreateDirException::prefix_message() const {
	return "Create directory failed with error code:";
}

/**
 * Constructor will create directory at directory.
 * If directory already exists DirAlreadyExists exception will be raised.
 * If there is some "windows" problem to create directory CreateDirException exception will be raised.
*/
CreateDirAction::CreateDirAction(const std::wstring& directory, //path to directory
	const LPSECURITY_ATTRIBUTES& lp_security_attributes // security attributes object for CreateDirectory WINAPI
) : directory_(directory)
{
	if (CreateDirectory(directory_.c_str(), lp_security_attributes))
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

/**
* Destructor will delete directory if installation failed.
* If there is some "windows" problem to delete directory, the function will write log and continue.
*/
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