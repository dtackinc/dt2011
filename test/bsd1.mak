
SRC = ./..
OUT = ./..



default: $(MK_DEFAULT)


all: allsubs statics shareds others


static: statics
statics: 
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/lib/bsd1.mak static \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/1d/bsd1.mak static \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/low/bsd1.mak static \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/bigmem/bsd1.mak static \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/screen/bsd1.mak static \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/win/bsd1.mak static \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/ftp/bsd1.mak static \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/high/bsd1.mak static \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/xchg/bsd1.mak static \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/view/bsd1.mak static \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
shared: shareds
shareds: 
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/lib/bsd1.mak shared \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/1d/bsd1.mak shared \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/low/bsd1.mak shared \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/bigmem/bsd1.mak shared \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/screen/bsd1.mak shared \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/win/bsd1.mak shared \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/ftp/bsd1.mak shared \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/high/bsd1.mak shared \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/xchg/bsd1.mak shared \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/view/bsd1.mak shared \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
allsubs:
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/lib/bsd1.mak all \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/1d/bsd1.mak all \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/low/bsd1.mak all \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/bigmem/bsd1.mak all \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/screen/bsd1.mak all \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/win/bsd1.mak all \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/ftp/bsd1.mak all \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/high/bsd1.mak all \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/xchg/bsd1.mak all \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/view/bsd1.mak all \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
exes: 
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/lib/bsd1.mak exes \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/1d/bsd1.mak exes \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/low/bsd1.mak exes \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/bigmem/bsd1.mak exes \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/screen/bsd1.mak exes \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/win/bsd1.mak exes \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/ftp/bsd1.mak exes \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/high/bsd1.mak exes \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/xchg/bsd1.mak exes \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/view/bsd1.mak exes \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
shexes: 
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/lib/bsd1.mak shexes \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/1d/bsd1.mak shexes \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/low/bsd1.mak shexes \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/bigmem/bsd1.mak shexes \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/screen/bsd1.mak shexes \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/win/bsd1.mak shexes \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/ftp/bsd1.mak shexes \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/high/bsd1.mak shexes \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/xchg/bsd1.mak shexes \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/view/bsd1.mak shexes \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
scripts: 
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/lib/bsd1.mak scripts \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/1d/bsd1.mak scripts \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/low/bsd1.mak scripts \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/bigmem/bsd1.mak scripts \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/screen/bsd1.mak scripts \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/win/bsd1.mak scripts \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/ftp/bsd1.mak scripts \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/high/bsd1.mak scripts \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/xchg/bsd1.mak scripts \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/view/bsd1.mak scripts \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
libs: 
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/lib/bsd1.mak libs \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/1d/bsd1.mak libs \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/low/bsd1.mak libs \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/bigmem/bsd1.mak libs \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/screen/bsd1.mak libs \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/win/bsd1.mak libs \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/ftp/bsd1.mak libs \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/high/bsd1.mak libs \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/xchg/bsd1.mak libs \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/view/bsd1.mak libs \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
shlibs: 
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/lib/bsd1.mak shlibs \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/1d/bsd1.mak shlibs \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/low/bsd1.mak shlibs \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/bigmem/bsd1.mak shlibs \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/screen/bsd1.mak shlibs \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/win/bsd1.mak shlibs \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/ftp/bsd1.mak shlibs \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/high/bsd1.mak shlibs \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/xchg/bsd1.mak shlibs \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/view/bsd1.mak shlibs \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
others: 
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/lib/bsd1.mak others \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/1d/bsd1.mak others \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/low/bsd1.mak others \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/bigmem/bsd1.mak others \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/screen/bsd1.mak others \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/win/bsd1.mak others \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/ftp/bsd1.mak others \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/high/bsd1.mak others \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/xchg/bsd1.mak others \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/view/bsd1.mak others \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)

#----------------------------------------------------------------------------
strip:
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/lib/bsd1.mak strip \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/1d/bsd1.mak strip \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/low/bsd1.mak strip \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/bigmem/bsd1.mak strip \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/screen/bsd1.mak strip \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/win/bsd1.mak strip \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/ftp/bsd1.mak strip \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/high/bsd1.mak strip \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/xchg/bsd1.mak strip \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/view/bsd1.mak strip \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)


#----------------------------------------------------------------------------
clean:
	$(MK_RM) $(OUT)/test/*.o
	$(MK_RM) $(MK_JUNK)
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/lib/bsd1.mak clean \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/1d/bsd1.mak clean \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/low/bsd1.mak clean \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/bigmem/bsd1.mak clean \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/screen/bsd1.mak clean \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/win/bsd1.mak clean \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/ftp/bsd1.mak clean \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/high/bsd1.mak clean \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/xchg/bsd1.mak clean \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/view/bsd1.mak clean \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
#----------------------------------------------------------------------------
veryclean: clean rpcclean
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/lib/bsd1.mak veryclean \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/1d/bsd1.mak veryclean \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/low/bsd1.mak veryclean \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/bigmem/bsd1.mak veryclean \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/screen/bsd1.mak veryclean \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/win/bsd1.mak veryclean \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/ftp/bsd1.mak veryclean \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/high/bsd1.mak veryclean \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/xchg/bsd1.mak veryclean \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/view/bsd1.mak veryclean \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)#----------------------------------------------------------------------------
rpcclean:
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/lib/bsd1.mak rpcclean \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/1d/bsd1.mak rpcclean \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/low/bsd1.mak rpcclean \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/bigmem/bsd1.mak rpcclean \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/screen/bsd1.mak rpcclean \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/win/bsd1.mak rpcclean \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/ftp/bsd1.mak rpcclean \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/high/bsd1.mak rpcclean \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/xchg/bsd1.mak rpcclean \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/view/bsd1.mak rpcclean \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)



#-------------------------------------------------------------------------
# subs



subdir_lib: 
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/lib/bsd1.mak $(ACT) \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
subdir_1d: 
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/1d/bsd1.mak $(ACT) \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
subdir_low: 
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/low/bsd1.mak $(ACT) \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
subdir_bigmem: 
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/bigmem/bsd1.mak $(ACT) \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)



subdir_screen: 
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/screen/bsd1.mak $(ACT) \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)

subdir_win: 
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/win/bsd1.mak $(ACT) \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)

subdir_ftp: 
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/ftp/bsd1.mak $(ACT) \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)

subdir_high: 
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/high/bsd1.mak $(ACT) \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)
subdir_xchg: 
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/xchg/bsd1.mak $(ACT) \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)

subdir_view: 
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/view/bsd1.mak $(ACT) \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)


#-------------------------------------------------------------------------
# exes




#-------------------------------------------------------------------------
# libs




#-------------------------------------------------------------------------
# others



#-------------------------------------------------------------------------
# srcs





