DustSim
===================

DustSim is a tool that can be used to study the dynamics of dust particles in planetary environments.

For an example use of this toolbox, take a look at Kumar et al. (2014) and Hirsh & Kumar (2014).

Requirements
------

`DustSim` requires the following libraries/tools. The listed versions are not necessarily essential, however `DustSim` is known to build succesfully when these are used.

| Name                                                                     | Version       |
| -------------                                                            |:-------------:|
| [GCC](http://gcc.gnu.org "GCC homepage")                                 | 4.8           |
| [CMake](http://www.cmake.org/ "CMake homepage")                          | 2.8.12        |
| [Eigen](http://eigen.tuxfamily.org "Eigen's homepage")                   | 3.2.1         |
| [Boost](http://www.boost.org "Boost's homepage")                         | 1.55.0        |
| [SQLite](https://sqlite.org/ "SQLite homepage")                          | 3.7.11        |
| [SQLiteCpp](http://srombauts.github.com/SQLiteCpp "SQLite project")      | [d42964](https://github.com/kartikkumar/SQLiteCpp/tree/60b6593998e396f14010e8c82618a7196fd42964)    |
| [Tudat & Tudat Core](http://tudat.tudelft.nl "Tudat project homepage")   | [2a2720](https://github.com/kartikkumar/tudat-svn-mirror/tree/54dc69cd91e84c2a9cddc4caf9f0e86aba2a2720) & [bec885](https://github.com/kartikkumar/tudatCore-svn-mirror/tree/184a180d7213aeb021d672b7b92b0733a4bec885)                                    |
| [Assist](https://github.com/kartikkumar/assist "Assist project")         | [f9c915](https://github.com/kartikkumar/assist/tree/c3f8281dc21d0d7364aecd63c8ea68e929f9c915)       |

Alternative C++ compilers may be used, however they haven't been tested to date.

Installation
------

The easiest way to install `DustSim` is to simply clone the repository and run `CMake`. This assumes that the above mentioned libraries/tools have been installed and can either be found through the system path or through relative paths (see `CMakeModules` directory included in the `DustSim` project).

In addition, you must have a C++ compiler and the [CMake](http://www.cmake.org/ "CMake homepage") tool needs to be installed on the system path. 

To clone the `DustSim` toolbox, simply execute the following from your terminal:

```
> git clone https://github.com/kartikkumar/DustSim.git
```

Move into the `DustSim` directory and create a `build` directory:

```
> mkdir build
> cd build
```

From within the `build` directory, run the following command:

```
build> cmake ../DustSim
```

Once `CMake` has been run succesfully, run `make` from within the `build` directory to build the library. 

```
build> make
```

You can optionally also run the test suite at this stage to make sure that everything has been built correctly.

```
build> make test
```

This should not result in any failures.

The applications reside in `bin/applications` directory, relative to the project root.

Documentation
-------------

You can pass the `-DBUILD_DOCUMENTATION=on` option to `CMake` to build the [Doxygen](http://www.doxygen.org "Doxygen homepage") documentation locally.

Contributing
------------

Once you've made your great commits:

1. [Fork](https://github.com/kartikkumar/DustSim/fork) DustSim
2. Create a topic branch - `git checkout -b my_branch`
3. Push to your branch - `git push origin my_branch`
4. Create a [Pull Request](http://help.github.com/pull-requests/) from your branch
5. That's it!

License
------

See [COPYING](https://github.com/kartikkumar/DustSim/blob/master/COPYING).

Disclaimer
------

I am not liable for silly use of the DustSim project.

Contact
------

You can reach me at [me@kartikkumar.com](me@kartikkumar.com).
