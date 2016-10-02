SUBDIRS := $(wildcard */)

all clean:
	$(foreach i,$(SUBDIRS),$(MAKE) -C $i $@ &&) true

verify:
	for i in $(SUBDIRS); do $(MAKE) -C "$$i" $@; done

.PHONY: all veirfy clean
