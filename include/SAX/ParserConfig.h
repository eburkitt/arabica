#ifndef ARABICA_PARSERCONFIG_H
#define ARABICA_PARSERCONFIG_H

#ifdef USE_LIBXML2
#include <SAX/wrappers/saxlibxml2.h>
#undef DEF_SAX_P
#define DEF_SAX_P libxml2_wrapper
#ifdef _MSC_VER
#pragma message("Including libxml2")
#pragma commentcomment(lib, "libxml2.lib")
#endif
#endif

#ifdef USE_MSXML
#ifndef _MSC_VER
#error "Can only use MSXML on Windows"
#endif
#pragma message("Including MSXML")
#include <SAX/wrappers/saxmsxml2.h>
#undef DEF_SAX_P
#define DEF_SAX_P msxml2_wrapper
#endif 

#ifdef USE_XERCES
#include <SAX/wrappers/saxxerces.h>
#undef DEF_SAX_P
#define DEF_SAX_P xerces_wrapper
#ifdef _MSC_VER
#pragma message("Including Xerces")
#pragma comment(lib, "xerces-c_2.lib")
#endif
#endif

#ifdef USE_GARDEN
#ifdef _MSC_VER
#pragma message("Including Garden")
#endif
#include <SAX/parsers/saxgarden.h>
#undef DEF_SAX_P
#define DEF_SAX_P Garden
#endif

#ifdef USE_EXPAT
#include <SAX/wrappers/saxexpat.h>
#undef DEF_SAX_P
#define DEF_SAX_P expat_wrapper
#ifdef _MSC_VER
#pragma message("Including Expat")
#pragma comment(lib, "libexpat.lib")
#endif
#endif

#ifdef _MSC_VER
#pragma comment(lib, "wsock32.lib")
#endif


#ifndef NO_DEFAULT_PARSER
#ifdef DEF_SAX_P
namespace SAX
{
#ifdef HAVE_BOOST
  template<class string_type, class T0 = Arabica::nil_t, class T1 = Arabica::nil_t>
#else
  template<class string_type, class T0 = Arabica::default_string_adaptor<string_type>, class T1 = Arabica::nil_t>
#endif
  class XMLReader : public DEF_SAX_P<string_type, T0, T1> { };
} // namespace SAX
#else
#error "No default parser defined."
#endif
#endif

#undef DEF_P

#endif 

