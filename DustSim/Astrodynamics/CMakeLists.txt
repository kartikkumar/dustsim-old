 #    Copyright (c) 2010-2014, Delft University of Technology
 #    Copyright (c) 2010-2014, K. Kumar (me@kartikkumar.com)
 #    Copyright (c) 2013-2014, S. Hirsh (sethhirsh@berkeley.edu)
 #    All rights reserved.
 #    See http://bit.ly/12SHPLR for license details.

# Set source files.
set(ASTRODYNAMICS_SOURCES
    "${SRCROOT}${ASTRODYNAMICSDIR}/executeSimulation.cpp"
)

# Set header files.
set(ASTRODYNAMICS_HEADERS
    "${SRCROOT}${ASTRODYNAMICSDIR}/dataUpdater.h"
    "${SRCROOT}${ASTRODYNAMICSDIR}/executeSimulation.h"
)

# Add static library.
add_library(dustsim_astrodynamics STATIC ${ASTRODYNAMICS_SOURCES} ${ASTRODYNAMICS_HEADERS})
setup_library_target(dustsim_astrodynamics)

# Add unit tests.
