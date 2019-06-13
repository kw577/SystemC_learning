SOURCES = fir.cc tb.cc

DEPENDENCIES = \
			Makefile \
			$(HEADERS) \
			$(SOURCES)
			
LIBS= -lsystemc -lstdc++ -lm

TESTS= main

all: $(TESTS)
		./$(TESTS)
		@make cmp_result
		
$(TESTS): %: %.cpp $(DEPENDENCIES)
		$(GCC) -g -o $@ $@.cpp $(SOURCES) $(INCLUDE_DIRS) -L$(LIB_DIRS) $(LIBS)
		
clean:
		rm -f $(TESTS) *.0 *.dat
		
# The cmp_result target compares the simultion result with the
# golden results. The testbench writes out the results file (output.dat)
# in the simulation configuration directory. The cmp_result target is
# automatically run at the end of each simulation

GOLD_DIR = ./golden
GOLD_FILE = $(GOLD_DIR)/ref_output.dat

cmp_result:
		@echo "*********************************************"
		@if diff -w $(GOLD_FILE) ./output.dat ; then \
					echo "SIMULATION PASSED"; \
		else \
					echo "SIMULATION failed"; \	
		fi
		
		@echo "*********************************************"