AM_CXXFLAGS = -DLIBPATH='"$(pkglibdir)"'
AM_CPPFLAGS = -I.. -I../../libppf -I../../libpdl

EXTRA_DIST = module.ppf patch.pdl

lib_LTLIBRARIES = libnmpatch.la

libnmpatch_la_SOURCES = patchparser.yy patchlexer.ll nmlexer.cc cable.cc ctrlmap.cc knobmap.cc module.cc modulesection.cc morph.cc morphmap.cc note.cc patch.cc moduletype.cc

libnmpatch_la_LIBADD = -L../../libppf/src -lppf
libnmpatch_la_LDFLAGS = -release 1 -no-undefined -static

AM_YFLAGS = -d -pnm
AM_LFLAGS = -+ -olex.yy.c -Pnm

ppffiledir = $(pkglibdir)
ppffile_DATA = module.ppf

clean:
	rm -f patchlexer.cc patchparser.cc patchparser.h
