/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! 
  ! Copyright (C) 2000 Dtack Inc. All Rights Reserved
  ! To use this file, you must have signed a license agreement with Dtack Inc.
  ! Under no circumstances may you redistribute this file.
  ! This software is provided AS IS with no warranty expressed or implied.
  ! Dtack Inc. accepts no liability for use or misuse of this file.
  ! http://www.dtack.com  dtack@dtack.com  telephone +360.417.6700
  ! Dtack Inc, P.O. Box 3061, Port Angeles, WA USA 98362
  !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! */

/*
StackWalker thanks to Jochen Kalmbach http://www.codeproject.com/Articles/11132/Walking-the-callstack
is licensed under The BSD License

stackwalker installation for use in this file:
zip is in C:\1\local\StackWalker\StackWalker.2012-01-28.zip
open StackWalker_VC6.dsw with VC6 (not VS2005)
you will know if you are accidentally running VS2005 because it wants to convert the solution
compile normally
output is in C:\1\local\StackWalker\vc6\StackWalker\Debug_VC6\StackWalker.obj for inclusion in the .exe
there is no lib

wv5.mak is edited for the -I header search path and the .obj inclusion in the .lib
the runtime does not see the StackWalker c++ object, just the static routines
the static routines are not compiled ifdef c++ but they possibly could be
*/

#include <dtack/base.h>
DT_RCSID("stack_walker $RCSfile: stack_walker.c,v $ $Revision: 1.8 $");

#include <StackWalker.h>

#include <stackwalker.h>

#define strcpy_s strcpy
#define strcat_s(dst, len, src) strcat(dst, src)
#define _snprintf_s _snprintf
#define _tcscat_s _tcscat

/*..........................................................................
| NAME
| stack walker class override
| 
| END
 *..........................................................................*/
 
class dtack_stackwalker_c: public StackWalker
{
  public:
      	
    dt_ctl_t *ctl;
    const char *output_mode;

  public:
    dtack_stackwalker_c() : StackWalker() 
    {
    	ctl = NULL;
    	output_mode = NULL;
    }

  protected:
    virtual void OnOutput(LPCSTR szText)
    { 
      if (output_mode && !strcmp(output_mode, "err"))
      {
      	dt_err(ctl, "stackwalker", "%s", szText);
      }
      else
      if (output_mode && !strcmp(output_mode, "say"))
      {
      	dt_say_string(ctl, szText, -1);
      }
      else
      {
        fprintf(stderr, szText); 
      }
      		
      StackWalker::OnOutput(szText); 
    };
    
// ----------------------------------------------------------------------------
void OnLoadModule(LPCSTR img, LPCSTR mod, DWORD64 baseAddr, DWORD size, DWORD result, LPCSTR symType, LPCSTR pdbName, ULONGLONG fileVersion)
{
  CHAR buffer[STACKWALK_MAX_NAMELEN];
  if (fileVersion == 0)
    _snprintf_s(buffer, STACKWALK_MAX_NAMELEN, "<load_module><info>%s:%s (%p), size: %d (result: %d), SymType: '%s', PDB: '%s'</info></load_module>\n", img, mod, (LPVOID) baseAddr, size, result, symType, pdbName);
  else
  {
    DWORD v4 = (DWORD) fileVersion & 0xFFFF;
    DWORD v3 = (DWORD) (fileVersion>>16) & 0xFFFF;
    DWORD v2 = (DWORD) (fileVersion>>32) & 0xFFFF;
    DWORD v1 = (DWORD) (fileVersion>>48) & 0xFFFF;
    _snprintf_s(buffer, STACKWALK_MAX_NAMELEN, "<load_module><info>%s:%s (%p), size: %d (result: %d), SymType: '%s', PDB: '%s', fileVersion: %d.%d.%d.%d</info></load_module>\n", img, mod, (LPVOID) baseAddr, size, result, symType, pdbName, v1, v2, v3, v4);
  }
  OnOutput(buffer);
}
// ----------------------------------------------------------------------------
void OnCallstackEntry(
  CallstackEntryType eType, 
  CallstackEntry &entry)
{
  CHAR buffer[STACKWALK_MAX_NAMELEN];
  if ( (eType != lastEntry) && (entry.offset != 0) )
  {
    if (entry.name[0] == 0)
      strcpy_s(entry.name, "(function-name not available)");
    if (entry.undName[0] != 0)
      strcpy_s(entry.name, entry.undName);
    if (entry.undFullName[0] != 0)
      strcpy_s(entry.name, entry.undFullName);
      
    if (entry.lineFileName[0] == 0)
    {
      strcpy_s(entry.lineFileName, "(filename not available)");
      if (entry.moduleName[0] == 0)
        strcpy_s(entry.moduleName, "(module-name not available)");
      _snprintf_s(buffer, STACKWALK_MAX_NAMELEN,
        "<call_stack_entry><info>" 
        "offset %p" 
        " in module \"%s\""
        " %s"
        " %s"
        "</info></call_stack_entry>\n",
        (LPVOID) entry.offset, 
        entry.moduleName, 
        entry.lineFileName, 
        entry.name);
    }
    else
      _snprintf_s(buffer, STACKWALK_MAX_NAMELEN, 
        "<call_stack_entry><info>" 
        "%s"
        "@%d"
        " at function %s"
        "</info></call_stack_entry>\n",
        entry.lineFileName, 
        entry.lineNumber, 
        entry.name);
        
    OnOutput(buffer);
  }
}  // end method

// ----------------------------------------------------------------------------
void OnDbgHelpErr(LPCSTR szFuncName, DWORD gle, DWORD64 addr)
{
  return;
  
  CHAR buffer[STACKWALK_MAX_NAMELEN];
  _snprintf_s(buffer, STACKWALK_MAX_NAMELEN, "<dbghelp_error><info>%s, GetLastError: %d (Address: %p)</info></dbghelp_error>\n", szFuncName, gle, (LPVOID) addr);
  OnOutput(buffer);
}

// ----------------------------------------------------------------------------
void OnSymInit(LPCSTR szSearchPath, DWORD symOptions, LPCSTR szUserName)
{
  return;
  
  CHAR buffer[STACKWALK_MAX_NAMELEN];
  _snprintf_s(buffer, STACKWALK_MAX_NAMELEN, "<sym_init><info>Symbol-SearchPath: '%s', symOptions: %d, UserName: '%s'</info></sym_init>\n", szSearchPath, symOptions, szUserName);
  OnOutput(buffer);
  // Also display the OS-version
#if _MSC_VER <= 1200
  OSVERSIONINFOA ver;
  ZeroMemory(&ver, sizeof(OSVERSIONINFOA));
  ver.dwOSVersionInfoSize = sizeof(ver);
  if (GetVersionExA(&ver) != FALSE)
  {
    _snprintf_s(buffer, STACKWALK_MAX_NAMELEN, "<os_version><info>OS-Version: %d.%d.%d (%s)</info></os_version>\n", 
      ver.dwMajorVersion, ver.dwMinorVersion, ver.dwBuildNumber,
      ver.szCSDVersion);
    OnOutput(buffer);
  }
#else
  OSVERSIONINFOEXA ver;
  ZeroMemory(&ver, sizeof(OSVERSIONINFOEXA));
  ver.dwOSVersionInfoSize = sizeof(ver);
  if (GetVersionExA( (OSVERSIONINFOA*) &ver) != FALSE)
  {
    _snprintf_s(buffer, STACKWALK_MAX_NAMELEN, "<os_version><info>OS-Version: %d.%d.%d (%s) 0x%x-0x%x</info></os_version>\n", 
      ver.dwMajorVersion, ver.dwMinorVersion, ver.dwBuildNumber,
      ver.szCSDVersion, ver.wSuiteMask, ver.wProductType);
    OnOutput(buffer);
  }
#endif
} // end method


};


/*..........................................................................
| NAME
| stack walker show call stack by writing to file
| 
| END
 *..........................................................................*/
 
void
DTCONFIG_API1
dtstackwalker_show_call_stack_fprintf(FILE *file)
{
  dtack_stackwalker_c stackwalker;
  fprintf(file, "<dtstackwalker>\n");
  stackwalker.ShowCallstack();
  fprintf(file, "</dtstackwalker>\n");
 
}


/*..........................................................................
| NAME
| stack walker show call stack by writing to the ctl err
| 
| END
 *..........................................................................*/
 
void
DTCONFIG_API1
dtstackwalker_show_call_stack_err(dt_ctl_t *ctl)
{
  dtack_stackwalker_c stackwalker;
  
  stackwalker.ctl = ctl;
  stackwalker.output_mode = "err";
  
  stackwalker.ShowCallstack();
 
}



/*..........................................................................
| NAME
| stack walker show call stack by writing to the ctl say
| 
| END
 *..........................................................................*/
 
 
void
DTCONFIG_API1
dtstackwalker_show_call_stack_say(
  dt_ctl_t *ctl,
  HANDLE hThread, //= GetCurrentThread() 
  const CONTEXT *context) // = NULL
{
  dtack_stackwalker_c stackwalker;
  
  stackwalker.ctl = ctl;
  stackwalker.output_mode = "say";
  
  stackwalker.ShowCallstack(hThread, context);
 
}



/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! 
  ! Copyright (C) 2000 Dtack Inc. All Rights Reserved
  ! To use this file, you must have signed a license agreement with Dtack Inc.
  ! Under no circumstances may you redistribute this file.
  ! This software is provided AS IS with no warranty expressed or implied.
  ! Dtack Inc. accepts no liability for use or misuse of this file.
  ! http://www.dtack.com  dtack@dtack.com  telephone +360.417.6700
  ! Dtack Inc, P.O. Box 3061, Port Angeles, WA USA 98362
  !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! */

