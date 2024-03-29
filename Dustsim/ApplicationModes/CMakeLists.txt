# Copyright (c) 2010-2014, Delft University of Technology
# Copyright (c) 2010-2014, K. Kumar (me@kartikkumar.com)
# All rights reserved.
# See http://bit.ly/12SHPLR for license details.

# Set source files.
set(APPLICATIONMODES_SOURCES
  "${SOURCE_ROOT}${APPLICATIONMODES_DIR}/singleParticleSimulator.cpp"
)

# Set header files.
set(APPLICATIONMODES_HEADERS
  "${SOURCE_ROOT}${APPLICATIONMODES_DIR}/singleParticleSimulator.h"
)

# Set unit test files.
set(APPLICATIONMODES_UNIT_TESTS
  "${SOURCE_ROOT}${APPLICATIONMODES_DIR}/UnitTests/unitTestApplicationModes.cpp"   
)

# Add static library.
add_library(dustsim_application_modes STATIC 
            ${APPLICATIONMODES_SOURCES} ${APPLICATIONMODES_HEADERS})
setup_library_target(dustsim_application_modes)

# Add unit tests.
# add_executable(stomi_test_ApplicationModes ${APPLICATIONMODES_UNIT_TESTS})
# setup_unit_test_target(stomi_test_ApplicationModes)
# target_link_libraries(stomi_test_ApplicationModes 
#                       ${TUDAT_CORE_LIBRARIES} 
#                       ${SQLITECPP_LIBRARY} 
#                       ${SQLITE3_LIBRARY}  
#                       ${Boost_LIBRARIES})
