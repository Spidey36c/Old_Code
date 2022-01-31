#
# Global makefile for libraries
#
include defines.mk
SHELL=/bin/bash

SUBDIRS	= dsp libc lega-c math proc ieee debugsupport peripheral sol

# We ship with source code for some libraries
SRCINSTALL_SUBDIRS = peripheral

all: $(SUBDIRS)

install: $(SUBDIRS) install-headers

install-src: $(SUBDIRS)
	cp Makefile $(TGTLIBSRC)
	cp defines.mk $(TGTLIBSRC)
	cp HOWTO-build-libraries-from-windows.txt $(TGTLIBSRC)
	$(foreach dir,$(shell find include -type d  | grep -v .svn), \
		mkdir -p $(TGTLIBSRC)/$(dir); \
		cp $(dir)/* ${TGTLIBSRC}/$(dir) 2>>/dev/null; )

install-baseline: $(SUBDIRS) install-headers

install-proc: proc

clean: $(SUBDIRS)

# Each subdirectory is optional, so only build the ones that are present
$(SUBDIRS):
	@if [[ -d $@ ]] ; then $(MAKE) -C $@ $(MAKECMDGOALS) ; fi

install-headers:
	$(foreach dir,$(shell find include -type d  | grep -v .svn), \
		mkdir -p $(TGTDESTDIR)/$(dir); \
		cp $(dir)/* ${TGTDESTDIR}/$(dir) 2>>/dev/null; )

.PHONY: all install clean install-headers install-baseline install-proc
.PHONY: $(SUBDIRS)

