


SRC = ../..
OUT = ../..

all: 

allsubs:

#----------------------------------------------------------------------------
protos: 

#----------------------------------------------------------------------------

$(DT_YAM)/data/doclist.m4: $(DT_YAM)/data/doclist.dat
	bash dtdocm4.sh $(DT_YAM)

lj4s-: 
lj4s: lj4s-


lj3s-: 
lj3s: lj3s-


ps6s-: 
ps6s: ps6s-


ps3s-: 
ps3s: ps3s-


dvis-: 
dvis: dvis-


dvls-: 
dvls: dvls-


latexs-: 
latexs: latexs-


mans-: 
mans: mans-


infos-: 
infos: infos-


htmls-: 
htmls: htmls-


htm2s-: 
htm2s: htm2s-


texts-: 
texts: texts-


rtfs-: 
rtfs: rtfs-



#-------------------------------------------------------------------------
# docs


docs: latexs dvls ps6s ps3s lj4s mans infos htmls htm2s





#----------------------------------------------------------------------------

examples: 


usages: 


#-------------------------------------------------------------------------
cis:
	find . -type d ! -name . -prune -o \
	  \( -name "*.[chx]" -o -name "dir.yam" \) \
	  -exec ci -l {} </dev/null \;

#-------------------------------------------------------------------------
maks: \
	qw0.maks \
	qw1.maks \
	qw6.maks \
	dw0.maks \
	ww0.maks \
	dw1.maks \
	dt0.maks \
	db0.maks \
	wb0.maks \
	wb3.maks \
	wv0.maks \
	wv4.maks \
	wv5.maks \
	dv0.maks \
	bsd1.maks

#-------------------------------------------------------------------------

makefile: dir.yam \
         $(DT_YAM)/config/def.yam \
         ../../config/prj.yam
	bash yam.sh $(SRC) test/xchg default > $(OUT)/test/xchg/makefile
makefiles: makefile

qw0.mak: dir.yam \
         $(DT_YAM)/config/def.yam \
         ../../config/prj.yam
	bash yam.sh $(SRC) test/xchg qw0 > $(OUT)/test/xchg/qw0.mak
qw0.maks: qw0.mak
	
qw1.mak: dir.yam \
         $(DT_YAM)/config/def.yam \
         ../../config/prj.yam
	bash yam.sh $(SRC) test/xchg qw1 > $(OUT)/test/xchg/qw1.mak
qw1.maks: qw1.mak
	
qw6.mak: dir.yam \
         $(DT_YAM)/config/def.yam \
         ../../config/prj.yam
	bash yam.sh $(SRC) test/xchg qw6 > $(OUT)/test/xchg/qw6.mak
qw6.maks: qw6.mak
	
dw0.mak: dir.yam \
         $(DT_YAM)/config/def.yam \
         ../../config/prj.yam
	bash yam.sh $(SRC) test/xchg dw0 > $(OUT)/test/xchg/dw0.mak
dw0.maks: dw0.mak
	
ww0.mak: dir.yam \
         $(DT_YAM)/config/def.yam \
         ../../config/prj.yam
	bash yam.sh $(SRC) test/xchg ww0 > $(OUT)/test/xchg/ww0.mak
ww0.maks: ww0.mak
	
dw1.mak: dir.yam \
         $(DT_YAM)/config/def.yam \
         ../../config/prj.yam
	bash yam.sh $(SRC) test/xchg dw1 > $(OUT)/test/xchg/dw1.mak
dw1.maks: dw1.mak
	
dt0.mak: dir.yam \
         $(DT_YAM)/config/def.yam \
         ../../config/prj.yam
	bash yam.sh $(SRC) test/xchg dt0 > $(OUT)/test/xchg/dt0.mak
dt0.maks: dt0.mak
	
db0.mak: dir.yam \
         $(DT_YAM)/config/def.yam \
         ../../config/prj.yam
	bash yam.sh $(SRC) test/xchg db0 > $(OUT)/test/xchg/db0.mak
db0.maks: db0.mak
	
wb0.mak: dir.yam \
         $(DT_YAM)/config/def.yam \
         ../../config/prj.yam
	bash yam.sh $(SRC) test/xchg wb0 > $(OUT)/test/xchg/wb0.mak
wb0.maks: wb0.mak
	
wb3.mak: dir.yam \
         $(DT_YAM)/config/def.yam \
         ../../config/prj.yam
	bash yam.sh $(SRC) test/xchg wb3 > $(OUT)/test/xchg/wb3.mak
wb3.maks: wb3.mak
	
wv0.mak: dir.yam \
         $(DT_YAM)/config/def.yam \
         ../../config/prj.yam
	bash yam.sh $(SRC) test/xchg wv0 > $(OUT)/test/xchg/wv0.mak
wv0.maks: wv0.mak
	
wv4.mak: dir.yam \
         $(DT_YAM)/config/def.yam \
         ../../config/prj.yam
	bash yam.sh $(SRC) test/xchg wv4 > $(OUT)/test/xchg/wv4.mak
wv4.maks: wv4.mak
	
wv5.mak: dir.yam \
         $(DT_YAM)/config/def.yam \
         ../../config/prj.yam
	bash yam.sh $(SRC) test/xchg wv5 > $(OUT)/test/xchg/wv5.mak
wv5.maks: wv5.mak
	
dv0.mak: dir.yam \
         $(DT_YAM)/config/def.yam \
         ../../config/prj.yam
	bash yam.sh $(SRC) test/xchg dv0 > $(OUT)/test/xchg/dv0.mak
dv0.maks: dv0.mak
	
bsd1.mak: dir.yam \
         $(DT_YAM)/config/def.yam \
         ../../config/prj.yam
	bash yam.sh $(SRC) test/xchg bsd1 > $(OUT)/test/xchg/bsd1.mak
bsd1.maks: bsd1.mak

#-------------------------------------------------------------------------

yam:
	bash yam.sh $(SRC) test/xchg default -DDTNODEPEND > $(OUT)/test/xchg/makefile
	make yamsubs

yamsubs:



#--------------------------------------------------------------------------
scratch:
	yam default_host -DDTNODEPEND
	make yam
	make veryclean
	make protos
	make others
	make makefiles
	make
#-------------------------------------------------------------------------

qw0:
	$(MAKE) $(MAKEFLAGS) \
	  -f $(SRC)/test/xchg/qw0.mak  \
	  $(ACT) \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=qw0
qw1:
	$(MAKE) $(MAKEFLAGS) \
	  -f $(SRC)/test/xchg/qw1.mak  \
	  $(ACT) \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=qw1
qw6:
	$(MAKE) -f $(SRC)/test/xchg/qw6.mak SRC=$(SRC) OUT=$(OUT) 
dw0:
	wmake $(__MAKEOPTS__) -h \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  -f $(SRC)/test/xchg/dw0.mak 
ww0:
	wmake $(__MAKEOPTS__) -h -f $(SRC)/test/xchg ww0.mak
dw1:
	wmake $(__MAKEOPTS__) -h \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  -f $(SRC)/test/xchg/dw1.mak 
dt0:
	$(MAKE) -$(MAKEFLAGS) \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  -f $(SRC)/test/xchg/dt0.mak 
db0:
	$(MAKE) -$(MAKEFLAGS) \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  -f $(SRC)/test/xchg/db0.mak 
wb0:
	$(MAKE) -$(MAKEFLAGS) \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  -f $(SRC)/test/xchg/wb0.mak 
wb3:
	$(MAKE) -$(MAKEFLAGS) \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  -f $(SRC)/test/xchg/wb3.mak 
wv0:
	$(MAKE) -$(MAKEFLAGS) \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  -f $(SRC)/test/xchg/wv0.mak 
wv4:
	$(MAKE) -$(MAKEFLAGS) \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  -f $(SRC)/test/xchg/wv4.mak 
wv5:
	$(MAKE) -$(MAKEFLAGS) \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  -f $(SRC)/test/xchg/wv5.mak 
dv0:
	$(MAKE) --$(MAKEFLAGS) --x- \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  --f $(SRC)/test/xchg/dv0.mak 
bsd1:
	$(MAKE) \
	  -f $(DT_SET)/bsd1.set \
	  -f $(DT_SET)/$(MK_TARGET).set \
	  -f $(SRC)/test/xchg/bsd1.mak $(ACT) \
	  SRC=$(SRC) \
	  OUT=$(OUT) \
	  MK_TARGET=$(MK_TARGET)

sg1:
	$(MAKE) -f $(SRC)/test/xchg/sg1.mak SRC=$(SRC) OUT=$(OUT) 
sg1x5:
	$(MAKE) -f $(SRC)/test/xchg/sg1x5.mak SRC=$(SRC) OUT=$(OUT) 
fg1:
	$(MAKE) -f $(SRC)/test/xchg/fg1.mak SRC=$(SRC) OUT=$(OUT) 
lg1:
	$(MAKE) -f $(SRC)/test/xchg/lg1.mak SRC=$(SRC) OUT=$(OUT) 

#-------------------------------------------------------------------------
# protos



#----------------------------------------------------------------------------
deps: 
	bash dtdep.sh $(SRC)/test/xchg \
	  $(SRC)/test/xchg/dttxchg.c \
	  $(SRC)/test/xchg/dttxchg2.c

#----------------------------------------------------------------------------
doctidy:
	rm -f *.rtf *.hh *.hpj *.ref *.dx
	rm -f *.idx *.ind *.log *.dvi *.dvl *.aux *.blg *.bbl *.ltx
docclean: doctidy
	rm -f *.htm *.txi *.txt *.inf
	rm -f *.lj4 *.lj4.gz *.lj3 *.lj3.gz *.ps6 *.ps6.gz*.ps3 *.ps3.gz

#----------------------------------------------------------------------------
veryclean: docclean 
# end of default finish
