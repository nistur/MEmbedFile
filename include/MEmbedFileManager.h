#ifndef __M_EMBED_FILE_MANAGER_H__
#define __M_EMBED_FILE_MANAGER_H__

#include <MEngine.h>
#include <MFile.h>

#include "MEmbedFile.h"

#include <map>
#include <string>

class MEmbedFileManager : public MFileOpenHook
{
public:
	MEmbedFileManager();
	~MEmbedFileManager();

public:
	MFile * open(const char * path, const char * mode);

	static void add(MEmbedFile* file, const char* filename);
	static void remove(MEmbedFile* file, const char* filename);

private:
	static MEmbedFileManager* s_instance;

	typedef std::map<std::string, MEmbedFile*> files;
	typedef files::iterator                    filesIter;
	files                                      m_files;

	MFileOpenHook*                             m_standardFileOpenHook;
};

#endif/*__M_EMBED_FILE_MANAGER_H__*/