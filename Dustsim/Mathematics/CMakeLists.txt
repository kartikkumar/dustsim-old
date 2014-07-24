 #    Copyright (c) 2010-2014, Delft University of Technology
 #    Copyright (c) 2010-2014, K. Kumar (me@kartikkumar.com)
 #    Copyright (c) 2013-2014, S. Hirsh (sethhirsh@berkeley.edu)
 #    All rights reserved.
 #    See http://bit.ly/12SHPLR for license details.

# Set source files.
set(MATHEMATICS_SOURCES
  "${SOURCE_ROOT}${MATHEMATICS_DIR}/basicMathematics.cpp"
)

# Set header files.
set(MATHEMATICS_HEADERS
  "${SOURCE_ROOT}${MATHEMATICS_DIR}/basicMathematics.h"
)

# Add static library.
add_library(dustsim_mathematics STATIC ${MATHEMATICS_SOURCES} ${MATHEMATICS_HEADERS})
setup_library_target(dustsim_mathematics)

## Add unit tests.
#add_executable(test_BasicInputOutput 
#               "${SOURCE_ROOT}${MATHEMATICS_DIR}/UnitTests/unitTestBasicInputOutput.cpp")
#setup_unit_test_target(test_BasicInputOutput "${SOURCE_ROOT}${MATHEMATICS_DIR}")
#target_link_libraries(test_BasicInputOutput dustsim_input_output 
#                      dustsim_database ${TUDAT_CORE_LIBRARIES} ${Boost_LIBRARIES})
