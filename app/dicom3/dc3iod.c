/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! 
  ! Copyright (C) 1998 Dtack Inc. All Rights Reserved
  ! To use this file, you must have signed a license agreement with Dtack Inc.
  ! Under no circumstances may you redistribute this file.
  ! This software is provided AS IS with no warranty expressed or implied.
  ! Dtack Inc. accepts no liability for use or misuse of this file.
  ! http://www.dtack.com  dtack@dtack.com  telephone +360.417.6700
  ! Dtack Inc, P.O. Box 3061, Port Angeles, WA USA 98362
  !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! */




static char *CopyrightIdentifier(void) { return "@(#)dc3iod.cc 0.12 95/09/18 Copyright (C) 1993,1994,1995. David A. Clunie. All rights reserved."; }

#include "tattrrd.h"
#include "tlist.h"
#include "tfstream.h"
#include "tiodcmps.h"

#include "GetOpt.h"
#include "MainCmd.h"

int
main(int argc, char *argv[])
{
	CCOMMAND(argc,argv);

	cerr.setf(ios::showbase,ios::showbase);

	char *	inname = 0;
	char *	outname = 0;
	int 	verbose = 0;
	int 	reportlevel = 1;
	int 	stopbad = 1;
	char *	insyntaxUID  = 0;

	GetOpt getopt(argc,argv,"bi:vw");
	int c;
	int err=0;
	while ((c=getopt()) != -1 && !err) {
		switch (c) {
			case 'v':	// Verbose
				verbose=1;
				break;
			case 'w':	// Warnings displayed
				reportlevel=2;
				break;
			case 'b':	// Don't stop on bad attributes
				stopbad=0;
				break;
			case 'i':	// Input transfer syntax
				insyntaxUID=getopt.optarg;
				break;
			case '?':
			default:
				err=1;
		}
	}

	if (getopt.optind+1 == argc) {
		inname=argv[getopt.optind];
	}
	else err=1;

	if (err) {
		cerr << "Usage: " << argv[0] << " -v -w -b -i syntax "
		     << "infile\n"
		     << flush;
		return 1;
	}

	if (insyntaxUID) {
		DC3TransferSyntax intest(insyntaxUID);
		if (!intest.isValid()) {
			cerr << "Input Transfer Syntax UID <"
			     << insyntaxUID << "> is invalid\n";
			return 1;
		}
	}

	DC3ifstream instream(inname,insyntaxUID);
	if (!instream.is_open()) {
		cerr << "Can't open <" << inname << "> for read\n" << flush;
		return 1;
	}

	if (verbose)
		cerr << "**************** Reading **************\n" << flush;

	DC3ListofAttributes list;
	DC3Tag oldtag (0,0);
	while (1) {
		DC3Attribute *attr;
		DC3Tag newtag (0,0);
		int err;
		DC3AttributeRead(instream,reportlevel,
			&newtag,&attr,&err);
		if (!instream.good() || instream.eof()
				     || (stopbad && !attr)) break;
		if (newtag <= oldtag) {
			cerr << "Stop - tags out of order or trailing garbage\n"
			     << flush;
			break;
		}
		if (attr) {
			list.insert(attr);
		}
		oldtag=newtag;
	}

	if (verbose)
		cerr << "************** Parsing IOD ************\n" << flush;

	DC3CompositeIOD *iod;
	if (iod=DC3SelectCompositeIOD(&list)) {
		cerr << "Found an IOD <" << iod->Identify() << ">\n" << flush;
	}
	else {
		cerr << "Error - No IOD found\n" << flush;
		return 1;
	}

	if (verbose) {
		cerr << "************ Describing IOD ***********\n" << flush;
		iod->Put(cerr);
	}

	return 0;
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
