 #    Copyright (c) 2010-2014, Delft University of Technology
 #    Copyright (c) 2010-2014, K. Kumar (me@kartikkumar.com)
 #    Copyright (c) 2013-2014, S. Hirsh (sethhirsh@berkeley.edu)
 #    All rights reserved.
 #    See http://bit.ly/12SHPLR for license details.

# Set source files.
set(DATABASE_SOURCES
  # "${SRCROOT}${DATABASEDIR}/caseData.cpp"
)

# Set header files.
set(DATABASE_HEADERS
  # "${SRCROOT}${DATABASEDIR}/caseData.h"
)

# Add static library.
add_library(dustsim_database STATIC ${DATABASE_SOURCES} ${DATABASE_HEADERS})
setup_library_target(dustsim_database)

# Add unit tests.
# add_executable(test_Input "${SRCROOT}${DATABASEDIR}/UnitTests/unitTestInput.cpp")
# setup_unit_test_target(test_Input)
# target_link_libraries(test_Input 
#                       dustsim_database 
#                       assist_basics
#                       tudat_basic_mathematics
#                       ${TUDAT_CORE_LIBRARIES} 
#                       ${Boost_LIBRARIES})
