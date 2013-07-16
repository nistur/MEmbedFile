#ifndef __M_EMBED_FILE_REF_H__
#define __M_EMBED_FILE_REF_H__

#include <MEngine.h>
#include <MFile.h>

#include <string>

class MEmbedFileRef : public MFile
{
public:
	MEmbedFileRef(const char* filename, const char* data, int size);
public:
	virtual void	open(const char * path, const char * mode);
	virtual int		close();
	virtual size_t	read(void * dest, size_t size, size_t count);
	virtual size_t	write(const void * str, size_t size, size_t count){ return 0; };
	virtual int		print(const char * format, ...){ return 0; };
	virtual int		print(const char * format, va_list args){ return 0; };
	virtual int		seek(long offset, int whence);
	virtual long	tell();
	virtual void	rewind();
	
	virtual bool 	isOpen();
	virtual void	destroy();

private:
	bool        m_open;
	std::string m_filename;
	const char* m_data;
	int         m_size;

	const char* m_ptr;
};

#endif/*__M_EMBED_FILE_REF_H__*/