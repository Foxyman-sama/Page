#ifndef DLLINTERFACE_HPP
#define DLLINTERFACE_HPP

#ifdef  Scrap_EXPORTS
#define SCRAP_API __declspec(dllexport)
#else
#define SCRAP_API __declspec(dllimport)
#endif					  

#endif 