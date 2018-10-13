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
| Time-getting function.
| Various operating system flavors are in this file.
| 
| RETURN VALUES
| All functions Return DTOS_RANWELL on success.  
| Any other return value indicates failure.
| 
| ERRORS
| As yet undocumented.
| 
| END
 *..........................................................................*/

#include <dtack/base.h>
#include <dtack/os.h>

#include <dtack/errno.h>
#include <dtack/msw.h>
#include <dtack/str.h>

DT_RCSID("source/low $RCSfile: os_env.c,v $ $Revision: 1.1 $");

/*..........................................................................*/

dt_rc_e
DTCONFIG_API1
dtos_getpid(
  dt_ctl_t *ctl,
  int *pid)
{
#   ifdef DTCONFIG_IMPLIED_MSW
      DT_F("dtos_getpid");
      DT_Q(dtmsw_pidwin,(ctl, pid));
#   else
      *pid = getpid();
#   endif
  return DT_RC_GOOD;
}

/*..........................................................................*/

dt_rc_e
DTCONFIG_API1
dtos_getenv(
  dt_ctl_t *ctl,
  const char *var,
  char *val,
  int max,
  int *len)
{
#   ifdef DTCONFIG_IMPLIED_MSWXXX
      *len = (int)GetEnvironmentVariable(var, val, max);
      if (*len >= max)
	  {
        *len -= 1;
        val[max-1] = '\0';
	  }
#   else
      const char *env = getenv(var);
      if (env != NULL)
	  {
		*len = strlen(env);
        dtstr_printf(ctl, val, max, "%s", env);
	  }
      else
        *len = 0;
#   endif
#ifdef NONO
  DT_F("dtos_getenv");
  dt_dbg(ctl, F, DT_DBG_MASK_ANY,
    "%s: \"%s\" %02x %02x %02x %02x %02x %02x len=%d", var, val,
    val[0], val[1], val[2], val[3], val[4], val[5], *len);
#endif
  return DT_RC_GOOD;
}


/*..........................................................................
 * set priority using system-specific value
 * return previous system-specific value if NULL
 *..........................................................................*/

dt_rc_e
DTCONFIG_API1
dtos_priority_system(
  dt_ctl_t *ctl,
  double newpriority,
  double *oldpriority)
{
  DT_F("dtos_priority_system");
  HANDLE process;
  DWORD process_priority;
  BOOL winrc;
  dt_rc_e rc = DT_RC_GOOD;

  process = GetCurrentProcess();
  process_priority = GetPriorityClass(process);

  winrc = SetPriorityClass(process, (DWORD)(newpriority));
  if (!winrc)
  {
	char s[4096];
    DWORD e = GetLastError();
    DTERRNO_LASTS(e, s, sizeof(s));
	DT_CLEANUP((ctl, F,
      "SetProcessPriority("
	  "0x%08lx, %ld)"
      DTERRNO_LASTFS,
      process,
      (DWORD)newpriority,
      DTERRNO_LASTES(e, s)));
  }

  if (*oldpriority)							/* caller wants old value back? 	*/
    *oldpriority = process_priority;

  dt_dbg(ctl, F, DT_DBG_MASK_CONFIG,
    "priority changed from %g to %g",
    *oldpriority, newpriority);

cleanup:
  return rc;
}
/*..........................................................................
 * set priority using generic symbol string value
 * return previous system-specific value if NULL
 *..........................................................................*/

#ifndef ABOVE_NORMAL_PRIORITY_CLASS
#define ABOVE_NORMAL_PRIORITY_CLASS (0x00008000)
#endif

#ifndef BELOW_NORMAL_PRIORITY_CLASS
#define BELOW_NORMAL_PRIORITY_CLASS (0x00004000)
#endif

dt_rc_e
DTCONFIG_API1
dtos_priority_symbol(
  dt_ctl_t *ctl,
  const char *symbol,
  double *oldpriority)
{
  DT_F("dtos_priority_symbol");
  double newpriority;
  dt_rc_e rc = DT_RC_GOOD;

  if (!strcmp(symbol, "realtime"))
    newpriority = REALTIME_PRIORITY_CLASS;
  else
  if (!strcmp(symbol, "high"))
    newpriority = HIGH_PRIORITY_CLASS;
  else
  if (!strcmp(symbol, "above"))
    newpriority = ABOVE_NORMAL_PRIORITY_CLASS;
  else
  if (!strcmp(symbol, "normal"))
    newpriority = NORMAL_PRIORITY_CLASS;
  else
  if (!strcmp(symbol, "below"))
    newpriority = BELOW_NORMAL_PRIORITY_CLASS;
  else
  if (!strcmp(symbol, "idle"))
    newpriority = IDLE_PRIORITY_CLASS;
  else
    DT_CLEANUP
	  ((ctl, F,
		"invalid priority \"%s\"", symbol)); 

  DT_C(dtos_priority_system,
	   (ctl, newpriority, oldpriority));

cleanup:
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
