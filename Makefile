
#Get OS version
OS=`lsb_release -si`
ARCH=`uname -m | sed 's/x86_//;s/i[3-6]86/32/'`
VER=`lsb_release -sr`
REL=OpenCVR-$(OS)-$(VER)-$(ARCH)bit

subdirs=3rdparty xcmnlib velib veuilib veapp

all:
	chmod +x ./linux/*.sh
	for d in $(subdirs); do (cd $$d; (if  test -e "Makefile"; then $(MAKE) $(MFLAGS); fi;) ); done
	strip ./output/$(VE_INSTALL_DIR)/lib/*.so
	cp -r ./linux/env.sh ./output/$(VE_INSTALL_DIR)/
	cp -r ./linux/start* ./output/$(VE_INSTALL_DIR)/
clean:
	for d in $(subdirs); do (cd $$d; (if  test -e "Makefile"; then $(MAKE) clean; fi;) ); done
	rm -rf ./linux/*.so ./linux/bin ./linux/lib/ ./linux/share ./linux/ssl ./linux/include 

install:
	for d in $(subdirs); do (cd $$d; (if  test -e "Makefile"; then $(MAKE) install; fi;) ); done

distclean: clean
	for d in $(subdirs); do (cd $$d; (if  test -e "Makefile"; then $(MAKE) distclean; fi;) ); done

rel:
	echo $(REL)
	rm -rf ./$(REL)
	cp -r ./output/$(VE_INSTALL_DIR) $(REL)
	rm -rf ./$(REL)/bin/c*
	rm -rf ./$(REL)/bin/f*
	rm -rf ./$(REL)/bin/o*
	rm -rf ./$(REL)/bin/s*
	rm -rf ./$(REL)/include
	rm -rf ./$(REL)/share
	rm -rf ./$(REL)/ssl
	rm -rf ./$(REL)/.svn
	rm -rf ./$(REL)/lib/*.a
	rm -rf ./$(REL)/lib/pkgconfig
	rm -rf ./$(REL)/lib/*.dbg
	rm -rf ./$(REL)/lib/libSDL*
	strip ./$(REL)/bin/OpenCVR
	strip ./$(REL)/lib/*.so
	strip ./$(REL)/lib/*.so.*
	
