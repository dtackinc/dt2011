/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! 
  ! Copyright (C) 1998 Dtack Inc. All Rights Reserved
  ! To use this file, you must have signed a license agreement with Dtack Inc.
  ! Under no circumstances may you redistribute this file.
  ! This software is provided AS IS with no warranty expressed or implied.
  ! Dtack Inc. accepts no liability for use or misuse of this file.
  ! http://www.dtack.com  dtack@dtack.com  telephone +360.417.6700
  ! Dtack Inc, P.O. Box 3061, Port Angeles, WA USA 98362
  !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! */


/*..........................................................................
  CHANGES
  20000104 DE remove gnu/types.h
  19991217 DE split out from config.h
 *..........................................................................*/

/*..........................................................................*/ 
#define DTCONFIG_TRIPWIRE				/* we want to do tripwiring		    */

/*..........................................................................*/ 
#ifndef DTDEPEND

#ifdef DTCONFIG_LG6						/* 64-bit Linux 2.0.30 				*/
#  include <linux/posix_types.h>		/* must come before sys/types.h 	*/
#endif

#include <stdio.h>						/* files common to ALL systems	    */
#include <stdlib.h>
#include <stddef.h>
#include <stdarg.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <math.h>
#include <time.h>
#include <fcntl.h>						/* this has open in it				*/
#include <sys/types.h>					/* this has stuff for open in it	*/
#include <sys/stat.h>					/* this has stuff for creat in it	*/

/*..........................................................................*/ 
#ifdef DTCONFIG_IMPLIED_DOS32
#	define DTCONFIG_IMPLIED_DOS
#	define DTCONFIG_32BIT
#   define DTCONFIG_MALLOC_MAX (32000000L)
#   define DTCONFIG_READ_MAX DTCONFIG_MALLOC_MAX
#   define DTCONFIG_WRITE_MAX DTCONFIG_MALLOC_MAX
#endif

/*..........................................................................*/ 
#ifdef DTCONFIG_IMPLIED_DOS16
#	define DTCONFIG_IMPLIED_DOS
#	define DTCONFIG_IMPLIED_SEGMENTED	/* segment:offset pointers		    */
#	define DTCONFIG_16BIT
#	define DTCONFIG_MALLOC_MAX (63488L)	/* max multiple of 2048 < 65536   	*/
#	define DTCONFIG_READ_MAX (65534L)
#	define DTCONFIG_WRITE_MAX (65534L)
#endif

/*..........................................................................*/ 
#ifdef DTCONFIG_IMPLIED_DOS
#   include <dos.h>						/* for FP_SEG and _dos_gettime()  	*/
#	include <malloc.h>
#   define DTCONFIG_STDOUT (stdout)
#   define DTCONFIG_STDERR (stdout)
#   define DTCONFIG_STDIN  (stdin)
/*#	define DTCONFIG_WANT_STATIC_RCSID*/
#	define DTCONFIG_WANT_STATIC_F
#	define DTCONFIG_FOPEN_RBINARY "rb"
#	define DTCONFIG_FOPEN_WBINARY "wb"
#	define DTCONFIG_FOPEN_ABINARY "ab"
#	define DTCONFIG_FOPEN_RWBINARY "r+b"
#	define DTCONFIG_FOPEN_WRBINARY "w+b"
#	define DTCONFIG_FOPEN_RTEXT "rt"
#	define DTCONFIG_FOPEN_WTEXT "wt"
#	define DTCONFIG_FOPEN_ATEXT "at"
#	define DTCONFIG_FOPEN_RWTEXT "r+t"
#	define DTCONFIG_FOPEN_WRTEXT "w+t"
#   define DTCONFIG_OPEN_WTEXT \
      (O_WRONLY | \
       O_TRUNC | \
       O_CREAT | \
       O_TEXT)
#endif

/*..........................................................................*/ 
#ifdef DTCONFIG_IMPLIED_MSW16
#   define DTCONFIG_IMPLIED_MSW
#	define DTCONFIG_IMPLIED_SEGMENTED	/* segment:offset pointers		    */
#	define DTCONFIG_16BIT
#	define DTCONFIG_MALLOC_MAX (63488L)	/* max multiple of 2048 < 65536   	*/
#	define DTCONFIG_READ_MAX (65534L)
#	define DTCONFIG_WRITE_MAX (65534L)
#endif

/*..........................................................................*/ 
#ifdef DTCONFIG_IMPLIED_MSW32
#   define DTCONFIG_IMPLIED_MSW
#	define DTCONFIG_32BIT
#   define DTCONFIG_MALLOC_MAX (32000000L)
#   define DTCONFIG_READ_MAX DTCONFIG_MALLOC_MAX
#   define DTCONFIG_WRITE_MAX DTCONFIG_MALLOC_MAX
#endif

/*..........................................................................*/ 
#ifdef DTCONFIG_IMPLIED_MSW
#   include <dos.h>						/* for FP_SEG and _dos_gettime()  	*/
#	include <malloc.h>


#   define DTCONFIG_STDOUT (stdout)
#   define DTCONFIG_STDERR (stdout)
#   define DTCONFIG_STDIN  (stdin)
/*#	define DTCONFIG_WANT_STATIC_RCSID */
#	define DTCONFIG_WANT_STATIC_F
#	define DTCONFIG_FOPEN_RBINARY "rb"
#	define DTCONFIG_FOPEN_WBINARY "wb"
#	define DTCONFIG_FOPEN_ABINARY "ab"
#	define DTCONFIG_FOPEN_RWBINARY "r+b"
#	define DTCONFIG_FOPEN_WRBINARY "w+b"
#	define DTCONFIG_FOPEN_RTEXT "rt"
#	define DTCONFIG_FOPEN_WTEXT "wt"
#	define DTCONFIG_FOPEN_ATEXT "at"
#	define DTCONFIG_FOPEN_RWTEXT "r+t"
#	define DTCONFIG_FOPEN_WRTEXT "w+t"
#   define DTCONFIG_OPEN_WTEXT \
      (O_WRONLY | \
       O_TRUNC | \
       O_CREAT | \
       O_TEXT)
                                        // allow all routines to be included in a dll
                                        // except for varargs
                                        // watchfrog #5
#   if defined(DTCONFIG_MICROSOFT) && \
       defined(DTCONFIG_IMPLIED_MSW32) 
#     define DTCONFIG_API1 __declspec( dllexport )
#     define DTCONFIG_API1DEC
#     define DTCONFIG_API2 __declspec( dllexport )
#   else
#     define DTCONFIG_API1    _pascal _export
#     define DTCONFIG_API1DEC _pascal _export
#     define DTCONFIG_API2
#     undef NULL
#     define NULL ((void *)0)
#   endif
#else  									/* not Microsoft Windows			*/
#   define DTCONFIG_API1
#   define DTCONFIG_API1DEC
#   define DTCONFIG_API2 
#endif

/*..........................................................................*/ 
#ifdef DTCONFIG_BORLAND
#	include <memory.h>
#	include <float.h>
#	include <io.h>						/* this has open/read/write in it   */
#endif

/*..........................................................................*/ 
#ifdef DTCONFIG_WATCOM_DOS
#   define DTCONFIG_WATCOM				/* this is a Watcom compiler		*/
  
#   pragma aux 						  	/* specify Microsoft-callable funcs	*/\
      DTCONFIG_WATCOM_DOS_MICROSOFT \
      "_*" \
      parm loadds caller [] \
      value struct float struct routine [ax] \
      modify [ax bx cx dx si di es];

#	include <float.h>					/* floating constants			    */
#	include <io.h>						/* this has read/write in it 		*/
#endif

/*..........................................................................*/ 
#ifdef DTCONFIG_MICROSOFT
#	include <float.h>					/* floating constants			    */
#	include <io.h>						/* this has open/read/write in it   */
#endif

/*..........................................................................*/ 

/*..........................................................................*/ 
#ifdef DTCONFIG_IMPLIED_SUNOS
#	include <malloc.h>
#	include <sys/time.h>
#	include <memory.h>
#	include <floatingpoint.h>			/* this has strtod() in it			*/

#   ifndef __STDC__						/* stdio.h has these already 		*/
    extern int fprintf(FILE *, const char *, ...);
    extern int vfprintf(FILE *, const char *, va_list);
    extern int vsprintf(const char *s, const char *fmt, char *args);
    extern int fclose(FILE *);
    extern int fflush(FILE *);
    extern int fseek(FILE *, long, int);
    extern int printf(const char *, ...);
#   endif

    extern int vprintf(const char *, va_list);

    extern int sscanf(const char *, const char *, ...);
    extern int fscanf(FILE *, const char *, ...);

    extern long strtol(const char *, char **, int);
    extern int system(const char *);
#if 0									/* why was there here anyway?		*/
    extern int mknod(const char *, int, int);
#endif
    extern char *getenv(const char *);
#   define bzero(s, n) memset ((s), 0, (n)) 
    extern int select(int, fd_set *, fd_set *, fd_set *, struct timeval *);

#	ifndef toupper
      extern int toupper(int);
#	endif
#	ifndef tolower
      extern int tolower(int);
#	endif
#endif

/*..........................................................................*/ 
#ifdef DTCONFIG_WATCOM_QNX
#   define DTCONFIG_WATCOM				/* this is a Watcom compiler		*/
#	include <malloc.h>					/* this has _HEAP constants 		*/
#endif

/*..........................................................................*/ 
#ifdef DTCONFIG_IMPLIED_QNX432
#   define DTCONFIG_IMPLIED_QNX4
#	define DTCONFIG_32BIT
#   define DTCONFIG_MALLOC_MAX (32000000L)
#   define DTCONFIG_READ_MAX (65534)	/* no documentation as to why		*/
#   define DTCONFIG_WRITE_MAX (65534)
#endif

/*..........................................................................*/ 
#ifdef DTCONFIG_IMPLIED_QNX416
#   define DTCONFIG_IMPLIED_QNX4
#	define DTCONFIG_16BIT
#   define DTCONFIG_MALLOC_MAX (65504)	/* no documentation as to why		*/
#   define DTCONFIG_READ_MAX (32767)	/* no documentation as to why		*/
#   define DTCONFIG_WRITE_MAX (32767)
#endif

/*..........................................................................*/ 
#ifdef DTCONFIG_IMPLIED_QNX4
#	define DTCONFIG_IMPLIED_UNIXLIKE
#   define DTCONFIG_OSTIME_TIMES		/* use times() in dtos_time() 		*/
#   define DTCONFIG_WANT_STATIC_RCSID
#   define DTCONFIG_WANT_STATIC_F
#endif

/*..........................................................................*/ 
#if defined(DTCONFIG_IMPLIED_DOS16)
#  define DTCONFIG_MEM_TOP (0x000a0000UL)
#else
#if defined(DTCONFIG_32BIT) || defined(DTCONFIG_IMPLIED_MSW16)
#  define DTCONFIG_MEM_TOP (0xffffffffUL)
#else
#if defined(DTCONFIG_64BIT)
#  define DTCONFIG_MEM_TOP (0xffffffffffffffffUL)
#endif
#endif
#endif

/*..........................................................................*/
#ifdef DTCONFIG_IMPLIED_UNIXLIKE
#	include <unistd.h>
#   include <sys/types.h>
#	define DTCONFIG_FOPEN_RBINARY "r"
#	define DTCONFIG_FOPEN_WBINARY "w"
#	define DTCONFIG_FOPEN_ABINARY "a"
#	define DTCONFIG_FOPEN_RWBINARY "r+"
#	define DTCONFIG_FOPEN_WRBINARY "w+"
#	define DTCONFIG_FOPEN_RTEXT "r"
#	define DTCONFIG_FOPEN_WTEXT "w"
#	define DTCONFIG_FOPEN_ATEXT "a"
#	define DTCONFIG_FOPEN_RWTEXT "r+"
#	define DTCONFIG_FOPEN_WRTEXT "w+"
#   define DTCONFIG_STDOUT (stdout)
#   define DTCONFIG_STDERR (stderr)
#   define DTCONFIG_STDIN  (stdin)
#endif

/*..........................................................................*/
#ifdef DTCONFIG_IMPLIED_SEGMENTED
#	define DTCONFIG_SAMESEG(PTR1, PTR2) (FP_SEG((PTR1)) == FP_SEG((PTR2)))
#   define DTCONFIG_FAR far
#else
#	define DTCONFIG_SAMESEG(PTR1, PTR2) (1)
#   define DTCONFIG_FAR
#endif

/*..........................................................................*/
#ifdef DTPRJ_STRATOS_MEMCHECK			/* have StatosWare's MemCheck?		*/
#  if DTPRJ_STRATOS_MEMCHECK == 1
#    define NOMEMCHECK
#  endif
#  include <memcheck.h>
#endif

/*..........................................................................*/

#ifndef  DTCONFIG_OPEN_WTEXT			/* not defined yet? 				*/
# define DTCONFIG_OPEN_WTEXT \
    (O_WRONLY | \
     O_TRUNC | \
     O_CREAT)
#endif

#ifndef  DTCONFIG_OPEN_WPERM			/* not defined yet? 				*/
# define DTCONFIG_OPEN_WPERM \
    (S_IRUSR | S_IWUSR | \
     S_IRGRP | S_IWGRP | \
     S_IROTH | S_IWOTH)
#endif

/*..........................................................................*/
#endif 									/* end ifndef DTDEPEND			    */

/*..........................................................................*/

extern const char *dtconfig;
extern const char *dtconfig_version;
extern const int dtconfig_implied_sunos;
extern const int dtconfig_implied_solaris;
extern const int dtconfig_implied_unixlike;
extern const int dtconfig_implied_linux;
extern const int dtconfig_implied_qnx4;
extern const int dtconfig_implied_qnx416;
extern const int dtconfig_implied_qnx432;
extern const int dtconfig_implied_dos;
extern const int dtconfig_implied_dos16;
extern const int dtconfig_implied_dos32;
extern const int dtconfig_implied_msw;
extern const int dtconfig_implied_msw16;
extern const int dtconfig_implied_msw32;
extern const int dtconfig_watcom;
extern const int dtconfig_borland;
extern const int dtconfig_microsoft;





/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! 
  ! Copyright (C) 1998 Dtack Inc. All Rights Reserved
  ! To use this file, you must have signed a license agreement with Dtack Inc.
  ! Under no circumstances may you redistribute this file.
  ! This software is provided AS IS with no warranty expressed or implied.
  ! Dtack Inc. accepts no liability for use or misuse of this file.
  ! http://www.dtack.com  dtack@dtack.com  telephone +360.417.6700
  ! Dtack Inc, P.O. Box 3061, Port Angeles, WA USA 98362
  !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! */
