#include <iostream>
#include <curl/curl.h>
#include "../include/ProgressBar.hpp"

int main()
{
	ProgressBar bar('.', '=', 30);

	std::cout << "Downloading onedark.vim from https://raw.githubusercontent.com/joshdick/onedark.vim/master/colors/onedark.vim" << std::endl;

	CURL *downloader = curl_easy_init();
	FILE *file = fopen("onedark.vim", "w");
	CURLcode result;
	std::string url = "https://raw.githubusercontent.com/joshdick/onedark.vim/master/colors/onedark.vim";
	const char *URL = url.c_str();
	curl_easy_setopt(downloader, CURLOPT_URL, URL);
	bar.setPercentage(10);
	bar.displayPercentage();	
	curl_easy_setopt(downloader, CURLOPT_WRITEDATA, file);
	bar.setPercentage(20);	
	bar.displayPercentage();
	result = curl_easy_perform(downloader);
	fclose(file);
	bar.setPercentage(30);	
	bar.displayPercentage();
	curl_easy_cleanup(downloader);

	bar.end();
	std::cout << "Done" << std::endl;

	return 0;
}
