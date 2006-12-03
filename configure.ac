dnl 
dnl  $Id: configure.ac,v 1.10 2005/12/03 05:49:43 kem Exp $
dnl 
dnl Copyright (c) 2004, Sun Microsystems, Inc. 
dnl 
dnl Permission to use, copy, modify, distribute, and sell this software and its
dnl documentation for any purpose is hereby granted without fee, provided that
dnl the above copyright notice appear in all copies and that both that
dnl copyright notice and this permission notice appear in supporting
dnl documentation.
dnl
dnl The above copyright notice and this permission notice shall be included in
dnl all copies or substantial portions of the Software.
dnl
dnl THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
dnl IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
dnl FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL 
dnl SUN MICROSYSTEMS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN
dnl AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
dnl CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
dnl
dnl Except as contained in this notice, the name of Sun Microsystems shall not be
dnl used in advertising or otherwise to promote the sale, use or other dealings
dnl in this Software without prior written authorization from Sun Microsystems.
dnl
dnl Process this file with autoconf to create configure.

AC_PREREQ([2.57])

dnl
dnl Version should match the current Xlg3d version. Xlg3dQueryVersion
dnl returns the version from lgewire.h, NOT the version we set here. But we
dnl try to keep these the same.  Note that the library has an extra
dnl digit in the version number to track changes which don't affect the
dnl protocol, so Xlg3d version l.n.m corresponds to protocol version l.n
dnl that 'revision' number appears in Xlg3d.h and has to be manually
dnl synchronized.
dnl
AC_INIT(libXlg3d, 5.0, [https://bugs.freedesktop.org/enter_bug.cgi?product=xorg], libXlg3d)
AM_INIT_AUTOMAKE([dist-bzip2])
AM_MAINTAINER_MODE

AM_CONFIG_HEADER(config.h)

# Check for progs
AC_PROG_CC
AC_PROG_LIBTOOL

# Check lgext configuration, strip extra digits from package version to
# find the required protocol version

if test "$VERSION" = "" ; then
       VERSION=$PACKAGE_VERSION;
fi
LGEXT_VERSION=[`echo $VERSION | sed 's/^\([0-9][0-9]*\.[0-9][0-9]*\).*$/\1/'`]
AC_SUBST(LGEXT_VERSION)
PKG_CHECK_MODULES(XLG3D, [lg3dproto >= $LGEXT_VERSION] x11 xfixes xext fixesproto)
AC_SUBST(XLG3D_CFLAGS)
AC_SUBST(XLG3D_LIBS)

XORG_RELEASE_VERSION

AC_OUTPUT([Makefile
	   src/Makefile
           xlg3d.pc])

