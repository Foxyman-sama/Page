#ifndef DLLINTERFACE_HPP
#define DLLINTERFACE_HPP

#ifdef  Scrap_EXPORTS
#define SCRAP_API __declspec(dllexport)
#else
#define SCRAP_API __declspec(dllimport)
#endif					  

constexpr std::string_view USER_AGENT {
    "Mozilla/5.0 (Windows NT 10.0; Win64; x64) "
    "AppleWebKit/537.36 (KHTML, like Gecko) "
    "Chrome/108.0.0.0 Safari/537.36"
};

#endif 