#ifndef __M_EMBED_FILE_PLUGIN_H__
#define __M_EMBED_FILE_PLUGIN_H__

#ifdef WIN32
# include <windows.h>
# ifdef M_EMBED_FILE_BUILD
#  define EXPORT __declspec(dllexport)
# else
#  define EXPORT __declspec(dllimport)
# endif
#else
# define EXPORT
#endif

#ifdef  MPluginStart
# undef MPluginStart
#endif/*MPluginStart*/

#ifdef  MPluginEnd
# undef MPluginEnd
#endif/*MPluginEnd*/

#ifdef  M_EMBED_FILE_STATIC

#define MPluginStart(x) \
x##Start()

#define MPluginEnd(x)  \
x##End()

#else/*!M_EMBED_FILE_STATIC*/

#define MPluginStart(x) \
StartPlugin()

#define MPluginEnd(x)  \
EndPlugin()

#endif/*M_EMBED_FILE_STATIC*/

extern "C"
{

EXPORT void MPluginStart(MEmbedFile);
EXPORT void MPluginEnd  (MEmbedFile);

}
#endif/*__M_EMBED_FILE_PLUGIN_H__*/