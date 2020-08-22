#pragma once
#include "install_action.h"

#include <list>
#include <tuple>


typedef std::tuple<std::wstring, std::wstring> src_dst;

class Installer {
	std::wstring install_dir_;
	std::list<src_dst> src_dst_files_;

public:
	Installer(std::wstring install_dir, std::list<src_dst> files);
	bool install();
};