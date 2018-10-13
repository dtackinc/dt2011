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

#include <dtack/t.h>
DT_RCSID("test $RCSfile: low.c,v $ $Revision: 1.6 $");

/*..........................................................................*/

DTMAIN1(dttlow)
{
  DT_F("dttlow");
  dt_ctl_t *ctl = &param->ctl;
  dt_rc_e rc;

  if (argc < 2)
    return dt_err(ctl, F,
      "argument required");

  argc--;
  argv++;

  DTT_IFCALL(heap)
  DTT_IFCALL(ipc)
  DTT_IFCALL(list)
  DTT_IFCALL(liner)
  DTT_IFCALL(os)
  DTT_IFCALL(param)
  DTT_IFCALL(str)
  {
    rc = dt_err(ctl, F, 
      "unknown test name \"%s\"",
      argv[0]);
  }
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
