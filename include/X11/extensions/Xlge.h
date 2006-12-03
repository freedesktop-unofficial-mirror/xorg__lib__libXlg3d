/*
 * $XFree86: xc/lib/Xlg3d/Xlge.h,v 1.1 2002/11/30 06:21:45 deronj Exp $

Copyright (c) 2004, Sun Microsystems, Inc. 

Permission to use, copy, modify, distribute, and sell this software and its
documentation for any purpose is hereby granted without fee, provided that
the above copyright notice appear in all copies and that both that
copyright notice and this permission notice appear in supporting
documentation.

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
OPEN GROUP BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN
AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

Except as contained in this notice, the name of The Open Group shall not be
used in advertising or otherwise to promote the sale, use or other dealings
in this Software without prior written authorization from The Open Group.

 */

#ifndef _XLGE_H_
#define _XLGE_H_

#include <X11/extensions/lgewire.h>

#include <X11/Xfuncproto.h>

/*
 * This revision number also appears in configure.ac, they have
 * to be manually synchronized
 */
#define LG3D_REVISION	0
#define LG3D_VERSION	((LG3D_MAJOR * 10000) + (LG3D_MINOR * 100) + (LG3D_REVISION))

_XFUNCPROTOBEGIN

extern Bool XLgeQueryExtension (
    Display*   /* display */,
    int*       /* event_basep */,
    int*       /* error_basep */
);

extern Status XLgeQueryVersion (
    Display*    /* display */,
    int*        /* major_versionp */, 
    int*        /* minor_versionp */,
    int*        /* implementationp */
);


extern Status XlgeRegisterClient (
    Display*    /* display */,
    int         /* clientType */
);


extern Status XLgeRegisterScreen (
    Display*    /* display */,
    Window      /* prw */
);

extern Status XlgeControlLgMode (
    Display*    /* display */,
    Bool        /* enable */
);

extern Status XlgeSendEvent(
    Display*    /* dpy */, 
    XEvent*     /* event */
);

_XFUNCPROTOEND

#endif /* _XLGE_H_ */
