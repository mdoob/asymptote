/*****
 * settings.h
 * Andy Hammerlindl 2004/05/10
 *
 * Declares a list of global variables that act as settings in the system.
 *****/

#ifndef SETTINGS_H
#define SETTINGS_H

#include <fstream>
#include <sys/stat.h>

#include "common.h"
#include "pair.h"
#include "item.h"

namespace types {
class record;
}

namespace camp {
void glrenderWrapper();
}

namespace gl {
extern bool glthread;
extern bool initialize;

#ifdef HAVE_PTHREAD
extern pthread_t mainthread;
extern pthread_cond_t initSignal;
extern pthread_mutex_t initLock;
extern pthread_cond_t readySignal;
extern pthread_mutex_t readyLock;
void wait(pthread_cond_t& signal, pthread_mutex_t& lock);
void endwait(pthread_cond_t& signal, pthread_mutex_t& lock);
#endif
}

namespace settings {
extern char *argv0;

void Warn(const string& s);
void noWarn(const string& s);
bool warn(const string& s);
extern string systemDir;
extern string docdir;
extern const string dirsep;

extern bool safe;

bool globalread();
bool globalwrite();

extern const string suffix;
extern const string guisuffix;
extern const string standardprefix;

extern string historyname;

void SetPageDimensions();

types::record *getSettingsModule();

vm::item& Setting(string name);

template <typename T>
inline T getSetting(string name)
{
  return vm::get<T>(Setting(name));
}

// Global settings accessible as variables

extern Int verbose;
extern bool debug;
extern bool xasy;
extern bool keys;
extern bool compact;
extern bool gray;
extern bool bw;
extern bool rgb;
extern bool cmyk;

bool view();
bool trap();
string outname();

void setOptions(int argc, char *argv[]);

// Access the arguments once options have been parsed.
int numArgs();
char *getArg(int n);

Int getScroll();

#if !defined(_MSC_VER)
extern mode_t mask;
#endif

bool xe(const string& texengine);
bool lua(const string& texengine);
bool pdf(const string& texengine);
bool latex(const string& texengine);
bool context(const string& texengine);

string nativeformat();
string defaultformat();

const char *newpage(const string& texengine);
const char *beginlabel(const string& texengine);
const char *endlabel(const string& texengine);
const char *rawpostscript(const string& texengine);
const char *beginpicture(const string& texengine);
const char *endpicture(const string& texengine);
const char *beginspecial(const string& texengine);
const char *endspecial();

string texcommand();
string texprogram();

const double inches=72.0;
const double cm=inches/2.54;
const double tex2ps=72.0/72.27;
const double ps2tex=1.0/tex2ps;

const string AsyGL="webgl/asygl.js";
const string WebGLheader="webgl/WebGLheader.html";
const string WebGLfooter="webgl/WebGLfooter.html";
}

extern const char *REVISION;
extern const char *AsyGLVersion;

#endif
