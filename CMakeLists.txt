cmake_minimum_required(VERSION 3.0)

project(base)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
include_directories(${PROJECT_SOURCE_DIR})
add_executable( abc                     src/abc.c                   )
add_executable( adder                   src/adder.c                 )
add_executable( args                    src/args.c                  )
add_executable( arrToBin                src/arrToBin.c              )
add_executable( ascii                   src/ascii.c                 )
add_executable( calculator              src/calculator.c            )
add_executable( callreference           src/callreference.c         )
add_executable( circular_shift          src/circular_shift.c        )
add_executable( complex                 src/complex.c               )
add_executable( dividableBy7            src/dividableBy7.c          )
add_executable( structdump              src/structdump.c            )
add_executable( echo                    src/echo.c                  )
add_executable( echochar                src/echochar.c              )
add_executable( euler                   src/euler.c                 )
add_executable( factorial               src/factorial.c             )
add_executable( fail                    src/fail.c                  )
add_executable( fib                    	src/fib.c                  	)
add_executable( fread                   src/fread.c                 )
add_executable( hello-world             src/hello-world.c           )
add_executable( options                 src/options.c               )
add_executable( pointermagic            src/pointermagic.c          )
add_executable( primenumbers            src/primenumbers.c          )
add_executable( print-syste-constants  src/print-system-constants.c )
add_executable( quersumme               src/quersumme.c             )
add_executable( readfile                src/readfile.c              )
add_executable( redefinition            src/redefinition.c          )
add_executable( redefinition-if         src/redefinition-if.c       )
add_executable( return-specified        src/return-specified.c      )
add_executable( scanf-test              src/scanf-test.c            )
add_executable( scnaf-hex-test          src/scnaf-hex-test.c        )
add_executable( signed-to-unsigned      src/signed-to-unsigned.c    )
add_executable( sizeofs                 src/sizeofs.c               )
add_executable( success                 src/success.c               )
add_executable( sum                     src/sum.c                   )
add_executable( tabtest                 src/tabtest.c               )
add_executable( umlaut                  src/umlaut.c                )
add_executable( unary-double-not        src/unary-double-not.c      )
add_executable( warning                 src/warning.c               )
add_executable( pointer-arithmetic      src/pointer-arithmetic.c    )

target_link_libraries(abc m)    # link libm to abc

project(huffman)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
add_executable( huffman                 src/huffman/src/huffman.c       )

execute_process (
	COMMAND bash -c "mkdir -p src/huffman/testfiles"
	COMMAND bash -c "yes 'SAFJALJ AF OIAIFOsdp' | head -c 100KB > src/huffman/testfiles/small.txt"
	COMMAND bash -c "dd if=/dev/urandom of=src/huffman/testfiles/1K-random.img 		count=1 bs=1KiB"
	COMMAND bash -c "dd if=/dev/urandom of=src/huffman/testfiles/10K-random.img 	count=1 bs=10KiB"
	COMMAND bash -c "dd if=/dev/urandom of=src/huffman/testfiles/100K-random.img 	count=1 bs=100KiB"
	COMMAND bash -c "dd if=/dev/urandom of=src/huffman/testfiles/1M-random.img 		count=1 bs=1MiB"
	COMMAND bash -c "dd if=/dev/urandom of=src/huffman/testfiles/10M-random.img 	count=1 bs=10MiB"
	COMMAND bash -c "dd if=/dev/zero of=src/huffman/testfiles/1K-zero.img 				count=1 bs=1KiB"
	COMMAND bash -c "dd if=/dev/zero of=src/huffman/testfiles/10K-zero.img 				count=1 bs=10KiB"
	COMMAND bash -c "dd if=/dev/zero of=src/huffman/testfiles/100K-zero.img 			count=1 bs=100KiB"
	COMMAND bash -c "dd if=/dev/zero of=src/huffman/testfiles/1M-zero.img 				count=1 bs=1MiB"
	COMMAND bash -c "dd if=/dev/zero of=src/huffman/testfiles/10M-zero.img 				count=1 bs=10MiB"
	COMMAND bash -c "echo -e \"Wer\ndas\nliest\nist\ndoof\n\" > src/huffman/testfiles/tiny.txt"
	COMMAND bash -c "yes 'lslfkpoipop iipfiasp' | head -c 1MB > src/huffman/testfiles/mid.txt"
)

# TODO add condition to also generate bigger files
# TODO add targets for these testfiles
