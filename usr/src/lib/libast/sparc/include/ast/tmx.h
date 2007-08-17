/***********************************************************************
*                                                                      *
*               This software is part of the ast package               *
*           Copyright (c) 1985-2007 AT&T Knowledge Ventures            *
*                      and is licensed under the                       *
*                  Common Public License, Version 1.0                  *
*                      by AT&T Knowledge Ventures                      *
*                                                                      *
*                A copy of the License is available at                 *
*            http://www.opensource.org/licenses/cpl1.0.txt             *
*         (with md5 checksum 059e8cd6165cb4c31e351f2b69388fd9)         *
*                                                                      *
*              Information and Software Systems Research               *
*                            AT&T Research                             *
*                           Florham Park NJ                            *
*                                                                      *
*                 Glenn Fowler <gsf@research.att.com>                  *
*                  David Korn <dgk@research.att.com>                   *
*                   Phong Vo <kpv@research.att.com>                    *
*                                                                      *
***********************************************************************/

/* : : generated by proto : : */
/* : : generated from /home/gisburn/ksh93/ast_ksh_20070418/build_sparc_32bit/src/lib/libast/features/tmx by iffe version 2007-04-04 : : */
                  
#ifndef _TMX_H
#if !defined(__PROTO__)
#  if defined(__STDC__) || defined(__cplusplus) || defined(_proto) || defined(c_plusplus)
#    if defined(__cplusplus)
#      define __LINKAGE__	"C"
#    else
#      define __LINKAGE__
#    endif
#    define __STDARG__
#    define __PROTO__(x)	x
#    define __OTORP__(x)
#    define __PARAM__(n,o)	n
#    if !defined(__STDC__) && !defined(__cplusplus)
#      if !defined(c_plusplus)
#      	define const
#      endif
#      define signed
#      define void		int
#      define volatile
#      define __V_		char
#    else
#      define __V_		void
#    endif
#  else
#    define __PROTO__(x)	()
#    define __OTORP__(x)	x
#    define __PARAM__(n,o)	o
#    define __LINKAGE__
#    define __V_		char
#    define const
#    define signed
#    define void		int
#    define volatile
#  endif
#  define __MANGLE__	__LINKAGE__
#  if defined(__cplusplus) || defined(c_plusplus)
#    define __VARARG__	...
#  else
#    define __VARARG__
#  endif
#  if defined(__STDARG__)
#    define __VA_START__(p,a)	va_start(p,a)
#  else
#    define __VA_START__(p,a)	va_start(p)
#  endif
#  if !defined(__INLINE__)
#    if defined(__cplusplus)
#      define __INLINE__	extern __MANGLE__ inline
#    else
#      if defined(_WIN32) && !defined(__GNUC__)
#      	define __INLINE__	__inline
#      endif
#    endif
#  endif
#endif
#if !defined(__LINKAGE__)
#define __LINKAGE__		/* 2004-08-11 transition */
#endif

#define _TMX_H	1
/*
 * AT&T Research
 *
 * high resolution Time_t support
 */

#include <tm.h>
#include <tv.h>

#define TMX_MAXDATE	"2554-07-21+23:34:33.709551614 UTC"
#define TMX_MAXYEAR	2554
#define TMX_MAXSEC	((Time_t)18446744073)
#define TMX_MAXNSEC	709551614
#define TMX_RESOLUTION	1000000000

typedef uint64_t Time_t;
typedef uint64_t Tmxsec_t;
typedef uint32_t Tmxnsec_t;

#define tmxsec(t)	((Tmxsec_t)((t)/1000000000))
#define tmxnsec(t)	((Tmxnsec_t)((t)%1000000000))
#define tmxsns(s,n)	(((((Time_t)(s))*1000000000))+((Time_t)(n)))

#define TMX_NOTIME	((Time_t)(-1))
#define TMX_NOW		tmxgettime()
#define TMX_MAXTIME	tmxsns(TMX_MAXSEC,TMX_MAXNSEC)

#define tmx2tv(t,v)	((v)->tv_nsec=tmxnsec(t),(v)->tv_sec=tmxsec(t))
#define tv2tmx(v)	tmxsns((v)->tv_sec,(v)->tv_nsec)

#define tmxclock(p)	tmxsns(((p)?*(p):time(NiL)),0)

#define tmxgetatime(s)	tmxsns((s)->st_atime,ST_ATIME_NSEC_GET(s))
#define tmxgetctime(s)	tmxsns((s)->st_ctime,ST_CTIME_NSEC_GET(s))
#define tmxgetmtime(s)	tmxsns((s)->st_mtime,ST_MTIME_NSEC_GET(s))

#define tmxsetatime(s,t) ((s)->st_atime=tmxsec(t),ST_ATIME_NSEC_SET(s,tmxnsec(t)))
#define tmxsetctime(s,t) ((s)->st_ctime=tmxsec(t),ST_CTIME_NSEC_SET(s,tmxnsec(t)))
#define tmxsetmtime(s,t) ((s)->st_mtime=tmxsec(t),ST_MTIME_NSEC_SET(s,tmxnsec(t)))

#if _BLD_ast && defined(__EXPORT__)
#undef __MANGLE__
#define __MANGLE__ __LINKAGE__		__EXPORT__
#endif

extern __MANGLE__ Time_t		tmxdate __PROTO__((const char*, char**, Time_t));
extern __MANGLE__ char*		tmxfmt __PROTO__((char*, size_t, const char*, Time_t));
extern __MANGLE__ Time_t		tmxleap __PROTO__((Time_t));
extern __MANGLE__ Tm_t*		tmxmake __PROTO__((Time_t));
extern __MANGLE__ Time_t		tmxscan __PROTO__((const char*, char**, const char*, char**, Time_t, long));
extern __MANGLE__ int		tmxsleep __PROTO__((Time_t));
extern __MANGLE__ Time_t		tmxtime __PROTO__((Tm_t*, int));

extern __MANGLE__ Time_t		tmxgettime __PROTO__((void));
extern __MANGLE__ int		tmxsettime __PROTO__((Time_t));

extern __MANGLE__ int		tmxtouch __PROTO__((const char*, Time_t, Time_t, Time_t, int));

extern __MANGLE__ char*		fmttmx __PROTO__((const char*, Time_t));

#undef __MANGLE__
#define __MANGLE__ __LINKAGE__

#endif
