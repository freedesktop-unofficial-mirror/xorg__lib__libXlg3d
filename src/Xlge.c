/************************************************************

$RCSfile: Xlge.c,v $

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

$Revision: 1.1.2.2.6.2.4.1 $
$Date: 2005/12/16 18:58:14 $
$State: Exp $

********************************************************/

#define NEED_EVENTS
#define NEED_REPLIES
#include <stdio.h>
#include <X11/Xlibint.h>
#include <X11/extensions/Xext.h>
#include <X11/extensions/extutil.h>
#include <X11/extensions/lgewire.h>
#include <X11/extensions/Xlge.h>

static XExtensionInfo *ext_info;
static char *ext_name = LGE_NAME;
static XExtensionHooks ext_hooks = {
    NULL,			/* create_gc */
    NULL,			/* copy_gc */
    NULL,			/* flush_gc */
    NULL,			/* free_gc */
    NULL,			/* create_font */
    NULL,			/* free_font */
    NULL,	        /* close_display */
    NULL,			/* wire_to_event */
    NULL,			/* event_to_wire */
    NULL,			/* error */
    NULL,			/* error_string */
};

static
XEXT_GENERATE_FIND_DISPLAY(find_display,
			   ext_info, ext_name, &ext_hooks,
			   0, NULL)

#define LgeCheckExtension(dpy, i, val) \
    XextCheckExtension((dpy), (i), (ext_name), (val))

#define LgeSimpleCheckExtension(dpy, i) \
    XextSimpleCheckExtension((dpy), (i), (ext_name))

/**********************************************************************/

Bool
XLgeQueryExtension (Display *dpy, int *event_basep, int *error_basep)
{
   XExtDisplayInfo *info = find_display(dpy);

    if (XextHasExtension(info)) {
	*event_basep = info->codes->first_event;
	*error_basep = info->codes->first_error;
	return True;
    } else {
	return False;
    }
}

Status
XLgeQueryVersion (Display *dpy, int *major_versionp, int *minor_versionp, int *implementationp)
{
    XExtDisplayInfo *info = find_display(dpy);
    xLgeQueryVersionReply rep;
    xLgeQueryVersionReq *req;

    LgeCheckExtension(dpy, info, 0);

    LockDisplay(dpy);
    GetReq(LgeQueryVersion, req);
    req->reqType = info->codes->major_opcode;
    req->lgeReqType = X_LgeQueryVersion;
    if (!_XReply(dpy, (xReply *) & rep, 0, xTrue)) {
	UnlockDisplay(dpy);
	SyncHandle();
	return 0;
    }
    *major_versionp = rep.majorVersion;
    *minor_versionp = rep.minorVersion;
    *implementationp = rep.implementation;
    UnlockDisplay(dpy);
    SyncHandle();
    return 1;
}

Status
XlgeRegisterClient (Display *dpy, int clientType)
{
    XExtDisplayInfo *info = find_display(dpy);
    xLgeRegisterClientReq *req;

    LockDisplay(dpy);
    GetReq(LgeRegisterClient, req);
    req->reqType = info->codes->major_opcode;
    req->lgeReqType = X_LgeRegisterClient;
    req->clientType = (CARD8) clientType;
    UnlockDisplay(dpy);
    SyncHandle();
    return True;
}


Status
XLgeRegisterScreen (Display *dpy, Window prw)
{
    XExtDisplayInfo *info = find_display(dpy);
    xLgeRegisterScreenReq *req;

    LgeCheckExtension(dpy, info, 0);

    LockDisplay(dpy);
    GetReq(LgeRegisterScreen, req);
    req->reqType = info->codes->major_opcode;
    req->lgeReqType = X_LgeRegisterScreen;
    req->prw = prw;
    UnlockDisplay(dpy);
    SyncHandle();
    return 1;
}

Status
XlgeControlLgMode (Display *dpy, Bool enable)
{
    XExtDisplayInfo *info = find_display(dpy);
    xLgeControlLgModeReq *req;

    LockDisplay(dpy);
    GetReq(LgeControlLgMode, req);
    req->reqType = info->codes->major_opcode;
    req->lgeReqType = X_LgeControlLgMode;
    req->enable = enable;
    UnlockDisplay(dpy);
    SyncHandle();
    return True;
}

Status
XlgeSendEvent(Display *dpy, XEvent *event)
{
    XExtDisplayInfo *info = find_display(dpy);
    xLgeSendEventReq *req;

    LockDisplay(dpy);
    GetReq(LgeSendEvent, req);
    req->reqType = info->codes->major_opcode;
    req->lgeReqType = X_LgeSendEvent;
    _XEventToWire(dpy, event, &req->event);
    UnlockDisplay(dpy);
    SyncHandle();
    return True;
}



