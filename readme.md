# ***Squid List of.***
----------------------------------------

Generic list of implementation in C.

### Projects current status
--------
[![GitHub](https://img.shields.io/github/license/squidfarts/sqdlist.svg?color=blue)](https://github.com/squidfarts/sqdlist)
[![Travis](https://travis-ci.com/squidfarts/sqdlist.svg?branch=master)](https://travis-ci.org/squidfarts/sqdlist)
[![Appveyor](https://ci.appveyor.com/api/projects/status/lh6a93nw50rxq3f7/branch/master?svg=true)](https://ci.appveyor.com/project/squidfarts/sqdlist)
[![Codecov](https://codecov.io/gh/squidfarts/sqdlist/coverage.svg?branch=master)](https://codecov.io/gh/squidfarts/sqdlist/branch/master) 

### Contents
--------
- About this project.
- Features found.
- Required things.
- Downloading this project.
- Setting up Meson build system.
- Building this library.
- Contact the developer.

### About this project.
--------

***Squid List of*** is a generic list implementation that takes
data elements of any data type.


### Features found.
--------

- Meson as the main tool for generating ninja build files.
- Conan as the tool for managing and packaging.
- Setup with Travis-ci Linux and Mac.
- Setup with AppVeyor for Windows.
- Setup with Codecov coverage.
- Simple API structure just for you. 
- Distributed under the Apache 2.0 license.
- Works 99.95% out of the box.

### Required things.
--------
| Tool being used.                               |  Version needed          |
|------------------------------------------------|--------------------------|
| [Meson build system   ](https://mesonbuild.com)| version 0.50.0 or newer. |
| [Conan package manager](https://conan.io)      | version 1.19.x or newer. |
| [Python3 language     ](https://python.org)    | version 3.5.x or newer.  |

### Downloading this project.
--------

To install this project the simplest way is to grab it off github with
this command the Github command looks something like this:

```console
git clone https://github.com/squidfarts/sqdlist.git
```
You can also download it as a zip if you prefer.

### Setting up Meson build system.
--------

Meson is a build system that is designed to be as user-friendly
as possible without sacrificing performance. The main tool for
this is a custom language that the user uses to describe the 
structure of his build. The main design goals of this language 
has been simplicity, clarity and conciseness. Much inspiration
was drawn from the Python programming language, which is
considered very readable, even to people who have not programmed
in Python before.

Another main idea has been to provide first class support for
modern programming tools and best practices. These include
features as varied as unit testing, code coverage reporting,
precompiled headers and the like. All of these features should
be immediately available to any project using Meson. The user
should not need to hunt for third party macros or write shell
scripts to get these features. They should just work out of the
box.

This power should not come at the expense of limited usability. 
Many software builds require unorthodox steps. A common example
is that you first need to build a custom tool and then use that
tool to generate more source code to build. This functionality 
needs to be supported and be as easy to use as other parts of 
the system.

***Meson*** has two main dependencies.

- [Python 3](https://python.org)
- [Ninja](https://github.com/ninja-build/ninja/)

If you will only use the Visual Studio backend (--backend=vs) to
generate Visual Studio solutions on Windows or the XCode backend
(--backend=xcode) to generate XCode projects on macOS, you do not 
need Ninja.

Meson requires that you have a source directory and a build
directory and that these two are different. In your source root
must exist a file called 'meson.build'. To generate the build
system run this command:

```console
meson <source directory> <build directory>
```

Depending on how you obtained Meson the command might also be
called `meson.py` instead of plain `meson`. In the rest of this
document we are going to use the letter form.

### Building this library.
--------

#### Configuring the build directory

Let us assume that we have a source tree that has a Meson build
system. This means that at the topmost directory has a file
called meson.build. We run the following commands to get the
build started.

```console
meson setup <build dir name>
```

The main usability difference between Ninja and Make is that
Ninja will automatically detect the number of CPUs in your
computer and parallelize itself accordingly. You can override the
amount of parallel processes used with the command line argument
-j <num processes>.

#### Building from the source

Meson uses the Ninja build system to actually build the code. To
start the build, simply type the following command.

```console
ninja -C <build dir name>
```

#### Installing

Installing the built software with Meson is just as simple as.

```console
meson install -C <build dir name>
```

This should build the project and install the project.


### Contact the developer.
==========================

#### Developer and maintainer

- gmail : [squidfarts gmail](mailto:michaelbrockus@gmail.com)
- email : [squidfarts email](mailto:michael@squidfarts)

#### Happy planing.  Happy coding...
