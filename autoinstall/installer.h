#pragma once
#include <list>
#include <tuple>
#include <string>
#include <memory>
#include "install_action.h"

typedef std::tuple<std::wstring, std::wstring> src_dst;

class Installer {
	std::wstring install_dir_;
	std::list<src_dst> src_dst_files_;

public:
	Installer(std::wstring install_dir, std::list<src_dst> files);
	bool install();
};