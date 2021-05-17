libraries := queue

.PHONY: all
all: $(libraries)

.PHONY: $(libraries)
$(libraries):
	$(MAKE) -C $@


test_targets := $(patsubst %,test_%,$(libraries))

.PHONY: test
test: $(test_targets)

.PHONY: $(test_targets)
$(test_targets):
	$(MAKE) -C $(patsubst test_%,%,$@) test


clean_targets := $(patsubst %,clean_%,$(libraries))

.PHONY: clean
clean: $(clean_targets)

.PHONY: $(clean_targets)
$(clean_targets):
	$(MAKE) -C $(patsubst clean_%,%,$@) clean
