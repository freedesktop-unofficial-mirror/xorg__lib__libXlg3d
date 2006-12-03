# 
#  $Id: Makefile.am,v 1.4 2005/07/16 06:33:36 daniels Exp $
# 
# Copyright (c) 2004, Sun Microsystems, Inc. 
# 
# Permission to use, copy, modify, distribute, and sell this software and its
# documentation for any purpose is hereby granted without fee, provided that
# the above copyright notice appear in all copies and that both that
# copyright notice and this permission notice appear in supporting
# documentation.
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL 
# SUN MICROSYSTEMS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN
# AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
# CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
#
# Except as contained in this notice, the name of Sun Microsystems shall not be
# used in advertising or otherwise to promote the sale, use or other dealings
# in this Software without prior written authorization from Sun Microsystems.

AM_CFLAGS = $(XLG3D_CFLAGS) $(XLG3D_CFLAGS) $(X_CFLAGS) -I$(top_srcdir)/include

lib_LTLIBRARIES = libXlg3d.la

libXlg3d_la_SOURCES = \
	Xlge.c

libXlg3d_la_LIBADD = $(XLG3D_LIBS) $(X_LIBS) $(XLG3D_LIBS)

libXlg3d_la_LDFLAGS = -version-number 1:0:0 -no-undefined

libXlg3dincludedir = $(includedir)/X11/extensions
libXlg3dinclude_HEADERS = $(top_srcdir)/include/X11/extensions/Xlge.h 
