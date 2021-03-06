Dtack Vpay Rev 1-1 README.TXT 6/22/97

INTRODUCTION
------------
This suite of programs implements a secure means of delivering
pay-per-view live streaming video in a World Wide Web environment.

This   release is a prototype intended to be integrated with a real ASP page.

This release features:
- video capture
- a mini web server to simulate an ASP page
- a drone wrangler for starting a drone on command
- a drone which delivers server push

This release does not have:
- a means of validating ASP requests
- random ports
- support for java
- view timeout


INSTALLATION
------------

changes from previous version installation:
-------------------------------------------
- no fake ASP server is included...use the one with the previous version

full installation instructions:
-------------------------------
1----DOWNLOAD AND EXTRACT
1a   download vpay1-1.exe (about 2MB) from Dtack's web site
     - http://www.dtack.com/secure/xxxxxxxx/vpay1-1.exe 
     - get the password from Dtack to use in place of xxxxxxxx

1b  execute this file on your system
     - you may double-click on it or use the taskbar Start->Run
     - in the "Install to" text field, you may choose any permanent 
       directory, but we suggest c:\vpay\1-1

2----GET VIDEO CAPTURE STARTED
2a  open a DOS box and type:
       c:
       cd \vpay\1-1
       vc -d -1
     - write down the first (unique) part of a capture card's name, such as
       "Winnov" or "Videum" or "Creative"
     - pay attention to upper and lower case

2b   double-click on the "Edit tabgrab.arg" icon in the Vpay1-1 Program group
     - on the line beginning with "-input", replace the "Winnov" with
       the first part of your capture card's name as noted above

2c   double-click on the "Edit tabgrab.conf.arg" icon in the Vpay1-1 Program group
     - make the same change as immediately above

2d   double-click on "Tabgrab start dialog" in the Vpay1-1 Program group
     - in the ensuing dialogs, set your capture card to 24 bit RGB
       (you MUST use this color setting)
     - after finishing with the dialogs, a live Video Monitor
       will appear, updating at least once per second

3----START THE ASP WEB SERVER
3a   double-click on "Asp start" in the Vpay1-0 Program group
     - there is no Asp start included with Vpay1-1
     - a white output box will appear confirming the server's startup

4----START THE WRANGLER
4a   double-click on "Wrangler start" in the Vpay1-1 Program group
     - an black DOS box will appear confirming the wrangler's startup

5----VIEW VIDEO
5a   double-click on "Request video" in the Vpay1-1 Program group
     - your browser will show a sample request form
     - click on SUBMIT REQUEST
     - you must be using Netscape

MANIFEST
--------
capture
-------
vc.exe                     program to list capture cards available
tabgrab.exe                program to capture video
msvcr40d.dll               run-time library for video capture
tabgrab.arg                normal video capture startup arguments
tabgrab.conf.arg           dialog video capture startup arguments

servers
-------
wrangler.exe               the drone wrangler
wrangler.arg               arguments for the wrangler
tableau.exe                the drone
drone.arg                  arguments for the drone

html
----
request.html               simple form to request a video stream
push.template              reply template given by ASP to browser


IMPROVEMENTS TO BE DONE
-----------------------
- wrangler should verify that request is coming from approved ASP IP address
- wrangler should use random ports
- wrangler should pass time limit to drone
- drone should enforce time limit
- drone should support passing messages to Java
- watchdog for unattended tabgrab and server operation
- non-debug build
- tabgrab window movable


CHANGE HISTORY
--------------
vpay1-0 26 Jun 97
  - fixed bug when drone dies, wrangler sometimes dies
  - tableau can now communicate with tabgrab via shared memory
  - reduced debug coming to drone.log
  - fake ASP code and VB5 support removed

vpay1-1 23 Jun 97
  - first release


