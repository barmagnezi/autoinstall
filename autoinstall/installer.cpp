#include <iostream>
#include <filesystem>
#include "installer.h"
#include "windows_exception.h"
#include "create_file_action.h"
#include "create_directory_action.h"

#define SRC_FILE_INDEX 0
#define DST_FILE_INDEX 1

Installer::Installer(std::wstring install_dir, std::list<src_dst> files): install_dir_(install_dir), src_dst_files_(files) {}

bool Installer::install()
{
	std::list<std::unique_ptr<InstallAction>> installations_actions; // List for all installation changes
	
	try{
		// Creating dest directory if requried
		try {
			installations_actions.push_front(std::make_unique<CreateDirAction>(install_dir_));
		}
		catch (DirAlreadyExists)
		{
			std::wcout << L"Directory  " << install_dir_ << L" already exists, skip." << std::endl;
		}

		// copy all files to dest folder
		for (auto& src_dst : src_dst_files_)
		{
			
			installations_actions.push_front(std::make_unique<CreateFileAction>(
				std::get<SRC_FILE_INDEX>(src_dst),
				install_dir_ + L"\\" + std::get<DST_FILE_INDEX>(src_dst) // Get full path to destination file
				));
		}
	}
	catch (WindowsException& e)
	{
		std::cout << "Got installation exception." << std::endl << "Exception message: ";
		e.print_error_code_message();
		return false;
	}
	for (auto& action : installations_actions) { action->update_install_success(); }
	std::cout << "Installation success!" << std::endl;
	return true;
}
