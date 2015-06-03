#include "../KECS.h"

#include <iostream>
#include <fstream>

using namespace std;

namespace KECS{

	void OgldevFileError(const char* pFileName, uint line, const char* pFileError)
	{
		#ifdef WIN32
			char msg[1000];
			_snprintf_s(msg, sizeof(msg), "%s:%d: unable to open file `%s`", pFileName, line, pFileError);
			MessageBoxA(NULL, msg, NULL, 0);
		#else
			fprintf(stderr, "%s:%d: unable to open file `%s`\n", pFileName, line, pFileError);
		#endif    
	}

	bool Common::ReadFile(const char* pFileName, string& outFile)
	{
		ifstream f(pFileName);
		
		bool ret = false;
		
		if (f.is_open()) {
			string line;
			while (getline(f, line)) {
				outFile.append(line);
				outFile.append("\n");
			}
			
			f.close();
			
			ret = true;
		}
		else {
			OGLDEV_FILE_ERROR(pFileName);
		}
		
		return ret;
	}
}
