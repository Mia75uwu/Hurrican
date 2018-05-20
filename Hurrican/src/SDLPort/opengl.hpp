#ifndef _OPENGL_H_
#define _OPENGL_H_

#include <epoxy/gl.h>
#ifdef _WIN32
#include <epoxy/wgl.h>
#else
#include <epoxy/glx.h>
#endif
#if 0
#include "SDL.h"

// Do some sanity checks
#if !defined(USE_GL1) && !defined(USE_GL2) && !defined(USE_GL3)
#error "ERROR USE_GL1/2/3 are not defined. At least one must be defined."
#elif defined(USE_GL1) && (defined(USE_GL2) || defined(USE_GL3))
#error "ERROR USE_GL1 and USE_GL2/3 are defined. Only one must be defined."
#elif defined(USE_GL2) && defined(USE_GL3)
#error "ERROR USE_GL2 and USE_GL3 are defined. Only one must be defined."
#elif defined(USE_GL1) && (defined(USE_GLES2) || defined(USE_GLES3))
#error "ERROR USE_GL1 and USE_GLES2 are defined. Replace USE_GLES2 or 3 for USE_GLES1"
#elif defined(USE_GL2) && defined(USE_GLES1)
#error "ERROR USE_GL2 and USE_GLES1 are defined. Replace USE_GLES1 for USE_GLES2"
#endif

#if SDL_VERSION_ATLEAST(2, 0, 0)

#if !defined(USE_GLES1) && !defined(USE_GLES2) && defined(USE_GLFULL)
#include "SDL_opengl.h"
#elif !defined(USE_GLES1) && defined(USE_GLES2) && !defined(USE_GLFULL)
#include "SDL_opengles2.h"
#elif !defined(USE_GLES1) && defined(USE_GLES3) && !defined(USE_GLFULL)
#include "SDL_opengles2.h"
#elif defined(USE_GLES1) && !defined(USE_GLES2) && !defined(USE_GLFULL)
#include "SDL_opengles.h"
#else
#error Invalid OpenGL Config
#endif

#else /* SDL 1.2 */

#if defined(USE_GLES1) || defined(USE_GLES2) || defined(USE_GLES3)
/* OpenGL-ES Profiles */
#if defined(USE_GLES2)
#include "gl2.h"
#include "gl2ext.h"
#elif defined(USE_GLES3)
#include "gl2.h"
#include "gl2ext.h"
#else
#include "gl.h"
#include "glext.h"
#endif

#else /* Full OpenGL Profile */
//#include "SDL_opengl.h"
#endif

#endif

#if defined(USE_GLES1) || defined(USE_GLES2) || defined(USE_GLES3)
#define glClearDepth glClearDepthf
#endif

#endif
#endif /* _OPENGL_H_ */
