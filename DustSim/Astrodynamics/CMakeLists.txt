 #    Copyright (c) 2010-2014, Delft University of Technology
 #    Copyright (c) 2010-2014, K. Kumar (me@kartikkumar.com)
 #    Copyright (c) 2013-2014, S. Hirsh (sethhirsh@berkeley.edu)
 #    All rights reserved.
 #    See http://bit.ly/12SHPLR for license details.

# Set source files.
set(ASTRODYNAMICS_SOURCES
  "${SRCROOT}${ASTRODYNAMICSDIR}/void.cpp"
)

# Set header files.
set(ASTRODYNAMICS_HEADERS
    "${SRCROOT}${ASTRODYNAMICSDIR}/executeSimulation.h"
  # "${SRCROOT}${ASTRODYNAMICSDIR}/convertUnitUsingMultiplicativeFactor.h"
)

# Add static library.
add_library(dustsim_astrodynamics STATIC ${ASTRODYNAMICS_SOURCES} ${ASTRODYNAMICS_HEADERS})
setup_library_target(dustsim_astrodynamics)

## Add unit tests.
#add_executable(test_BasicInputOutput 
#               "${SRCROOT}${ASTRODYNAMICSDIR}/UnitTests/unitTestBasicInputOutput.cpp")
#setup_unit_test_target(test_BasicInputOutput "${SRCROOT}${ASTRODYNAMICSDIR}")
#target_link_libraries(test_BasicInputOutput dustsim_input_output 
#                      dustsim_database ${TUDAT_CORE_LIBRARIES} ${Boost_LIBRARIES})
