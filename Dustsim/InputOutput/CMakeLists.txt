 #    Copyright (c) 2010-2014, Delft University of Technology
 #    Copyright (c) 2010-2014, K. Kumar (me@kartikkumar.com)
 #    Copyright (c) 2013-2014, S. Hirsh (sethhirsh@berkeley.edu)
 #    All rights reserved.
 #    See http://bit.ly/12SHPLR for license details.

# Set source files.
set(INPUTOUTPUT_SOURCES
  "${SOURCE_ROOT}${INPUTOUTPUT_DIR}/caseData.cpp"
  "${SOURCE_ROOT}${INPUTOUTPUT_DIR}/dictionaries.cpp"
)

# Set header files.
set(INPUTOUTPUT_HEADERS
  "${SOURCE_ROOT}${INPUTOUTPUT_DIR}/caseData.h"
  "${SOURCE_ROOT}${INPUTOUTPUT_DIR}/dictionaries.h"
  "${SOURCE_ROOT}${INPUTOUTPUT_DIR}/outputData.h"
)

# Add static library.
add_library(dustsim_input_output STATIC ${INPUTOUTPUT_SOURCES} ${INPUTOUTPUT_HEADERS})
setup_library_target(dustsim_input_output)

## Add unit tests.
#add_executable(test_BasicInputOutput 
#               "${SOURCE_ROOT}${INPUTOUTPUT_DIR}/UnitTests/unitTestBasicInputOutput.cpp")
#setup_unit_test_target(test_BasicInputOutput "${SOURCE_ROOT}${INPUTOUTPUT_DIR}")
#target_link_libraries(test_BasicInputOutput dustsim_input_output 
#                      dustsim_database ${TUDAT_CORE_LIBRARIES} ${Boost_LIBRARIES})
