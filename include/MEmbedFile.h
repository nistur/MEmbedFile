#ifndef __M_EMBED_FILE_H__
#define __M_EMBED_FILE_H__

#include <MEngine.h>
#include <MResource.h>

#include <MCore.h>

class MEmbedFileRef;

class MEmbedFile : public MResource
{
public:
	virtual void set(const char* name, const char* data, int size) = 0;

	virtual MEmbedFileRef* getRef() = 0;
};

#define MEmbedFileGetNew(file, filename, data, size) \
{\
    file = (MEmbedFile*)MResource::getNew("MEmbedFile"); \
    if(file) \
      file->set(filename, data, size); \
}

#endif/*__M_EMBED_FILE_H__*/