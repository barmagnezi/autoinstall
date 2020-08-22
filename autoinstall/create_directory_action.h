#pragma once
#include "install_action.h"
#include "windows_exception.h"


/**
 * Exception represent that CreateDirAction failed with some windows error.
 * This class only override prefix_message function from prefix_message;
*/
class CreateDirException : public WindowsException
{
	std::string prefix_message() const override;
};

/**
 * Exception represent that CreateDirAction failed to create because directory already exists.
*/
class DirAlreadyExists : public std::exception {};

/**
 * Implementation of create directory for installation.
 * The class create directory on constructor and delete it automatically if installation failed (read more about InstallAction object)
*/
class CreateDirAction : public InstallAction
{
private:
	const std::wstring directory_;
public:
	CreateDirAction(const std::wstring& directory, 
		const LPSECURITY_ATTRIBUTES& lp_security_attributes=NULL);
	~CreateDirAction();
};
