# cggml

Rhymes with *signal*. A general algorithms library for the purpose of me practicing C. If you aren't Phil or 
someone who knows Phil, use at your own risk.

Goals
- Small and simple
- C90 compliant
- MISRA-C friendly (not necessarily compliant)
- Usable in applications targeting Game Boys, Super Nintendos, toasters, 
refrigerators, and modern PCs

## How to build
The unit testing portion of this project has a dependency on *libcheck*.
See https://libcheck.github.io/check/

`mkdir build` \
`cd build` \
`cmake ..` \
`make` 

If you don't want to build tests, build the modules separately.

`mkdir build` \
`cd build` \
`cmake ..` \
`make geometry` \
`make sort` \
`make search` 
