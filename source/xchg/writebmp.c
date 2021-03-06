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
| NAME
| Introduction - intro
| 
| DESCRIPTION
| As yet undocumented.
| 
| RETURN VALUES
| Function return value will be DT_RC_GOOD on success.  
| Any other return value indicates failure or noncompletion.
| When DT_RC_GOOD is not returned, any other return values may not be valid.
| 
| ERRORS
| As yet undocumented.
| 
| END
 *..........................................................................*/

#include <dtack/base.h>
DT_RCSID("source/high $RCSfile: wr_bmp.c,v $ $Revision: 1.3 $");

#include <dtack/mem.h>
#include <dtack/str.h>
#include <dtack/os.h>
#include <dtack/dib.h>
#include <dtack/bmp.h>

/*..........................................................................
 *..........................................................................*/

dt_rc_e
DTCONFIG_API1
dtimage_write_bmp_func(
  dt_ctl_t *ctl,
  void *arg,
  void *data,
  unsigned int size)
{
  DT_F("dtimage_write_bmp_func");
  dtfd_t *fd = (dtfd_t *)arg;
  DT_Q(dtfd_write_all,(ctl, fd,
    data, size));
  return DT_RC_GOOD;
}

/*..........................................................................
 * Microsoft windows metafile
 *..........................................................................*/

dt_rc_e
DTCONFIG_API1
dtimage_write_bmp_fd(					/* put image to opened bmp fd		*/
  dt_ctl_t *ctl,
  dtimage_t *image,
  dtfd_t *fd,
  dtxy_t x,
  dtxy_t y,
  long flags)
{
  DT_F("dtimage_write_bmp_fd");
  dt_rc_e rc;

  DT_C(dtbmp_export,(ctl,				/* export image to file 			*/
    dtimage_write_bmp_func,
    (void *)fd,
    image, 0, 0));

cleanup:

  return rc;
}

/*..........................................................................
 * Microsoft windows metafile
 *..........................................................................*/

dt_rc_e
DTCONFIG_API1
dtimage_write_bmp_file(					/* put image to bmp file			*/
  dt_ctl_t *ctl,
  dtimage_t *image,
  const char *name,
  dtxy_t x,
  dtxy_t y,
  long flags)
{
  DT_F("dtimage_write_bmp_file");
  dtfd_t fd;
  dt_rc_e rc;

  DT_Q(dtfd_open,(ctl,					/* open file for writing			*/
    &fd, name, "w"));

  DT_G(dtimage_write_bmp_fd,(ctl,		/* write image to opened fd	  		*/
    image, &fd, x, y, flags));						

  DT_I(dtfd_close,(ctl, &fd));			/* close opened fd					*/

  return rc;
}





/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! 
  ! Copyright (C) 1998 Dtack Inc. All Rights Reserved
  ! To use this file, you must have signed a license agreement with Dtack Inc.
  ! Under no circumstances may you redistribute this file.
  ! This software is provided AS IS with no warranty expressed or implied.
  ! Dtack Inc. accepts no liability for use or misuse of this file.
  ! http://www.dtack.com  dtack@dtack.com  telephone +360.417.6700
  ! Dtack Inc, P.O. Box 3061, Port Angeles, WA USA 98362
  !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! */
