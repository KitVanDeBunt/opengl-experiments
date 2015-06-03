#ifndef UTILS_ENGINE_COMMON_H
#define UTILS_ENGINE_COMMON_H

#include "..\KECS.h"
#include <iostream>

using namespace std;

#define PI 3.14159265

namespace KECS{

	typedef unsigned int uint;

	void OgldevFileError(const char* pFileName, uint line, const char* pFileError);

	#define OGLDEV_FILE_ERROR(FileError) OgldevFileError(__FILE__, __LINE__, FileError);



	class Common
	{
	public:
		static float ToRadian(float x){
			return (x * PI / 180.0f);
		};
		static bool ReadFile(const char* pFileName, string& outFile);
	};
}

#endif	/* UTILS_ENGINE_COMMON_H */