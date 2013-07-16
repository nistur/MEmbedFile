#ifndef __M_EMBED_FILE_IMPL_H__
#define __M_EMBED_FILE_IMPL_H__

#include "MEmbedFile.h"
#include <string>

class MEmbedFileImpl : public MEmbedFile
{
public:
	~MEmbedFileImpl();

public:
	void set(const char* name, const char* data, int size);
	void destroy();

	MEmbedFileRef* getRef();

	static MResource* getNew();

private:
	std::string m_filename;
	const char* m_data;
	int         m_size;
};

#endif/*__M_EMBED_FILE_H__*/