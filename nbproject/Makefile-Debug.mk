#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/src/AnsiTerm.o \
	${OBJECTDIR}/src/FileLogWriter.o \
	${OBJECTDIR}/src/Format.o \
	${OBJECTDIR}/src/FormatString.o \
	${OBJECTDIR}/src/Log.o \
	${OBJECTDIR}/src/LogFormat.o \
	${OBJECTDIR}/src/LogLevel.o \
	${OBJECTDIR}/src/LogWriter.o \
	${OBJECTDIR}/src/MultiLogWriter.o

# Test Directory
TESTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}/tests

# Test Files
TESTFILES= \
	${TESTDIR}/TestFiles/AnsiTermTest \
	${TESTDIR}/TestFiles/FormatTest \
	${TESTDIR}/TestFiles/LoggerTest \
	${TESTDIR}/TestFiles/LogTest \
	${TESTDIR}/TestFiles/SingletonTest \
	${TESTDIR}/TestFiles/TestApp

# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libsoil.a

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libsoil.a: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libsoil.a
	${AR} -rv ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libsoil.a ${OBJECTFILES} 
	$(RANLIB) ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libsoil.a

${OBJECTDIR}/src/AnsiTerm.o: src/AnsiTerm.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Iinclude -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/AnsiTerm.o src/AnsiTerm.cpp

${OBJECTDIR}/src/FileLogWriter.o: src/FileLogWriter.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Iinclude -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/FileLogWriter.o src/FileLogWriter.cpp

${OBJECTDIR}/src/Format.o: src/Format.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Iinclude -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Format.o src/Format.cpp

${OBJECTDIR}/src/FormatString.o: src/FormatString.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Iinclude -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/FormatString.o src/FormatString.cpp

${OBJECTDIR}/src/Log.o: src/Log.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Iinclude -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Log.o src/Log.cpp

${OBJECTDIR}/src/LogFormat.o: src/LogFormat.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Iinclude -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/LogFormat.o src/LogFormat.cpp

${OBJECTDIR}/src/LogLevel.o: src/LogLevel.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Iinclude -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/LogLevel.o src/LogLevel.cpp

${OBJECTDIR}/src/LogWriter.o: src/LogWriter.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Iinclude -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/LogWriter.o src/LogWriter.cpp

${OBJECTDIR}/src/MultiLogWriter.o: src/MultiLogWriter.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Iinclude -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/MultiLogWriter.o src/MultiLogWriter.cpp

# Subprojects
.build-subprojects:

# Build Test Targets
.build-tests-conf: .build-conf ${TESTFILES}
${TESTDIR}/TestFiles/AnsiTermTest: ${TESTDIR}/tests/AnsiTermTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/AnsiTermTest $^ ${LDLIBSOPTIONS} -lpthread -lgtest_main -lgtest 

${TESTDIR}/TestFiles/FormatTest: ${TESTDIR}/tests/FormatStringTest.o ${TESTDIR}/tests/FormatTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/FormatTest $^ ${LDLIBSOPTIONS} -lpthread -lgtest_main -lgtest 

${TESTDIR}/TestFiles/LoggerTest: ${TESTDIR}/tests/LoggerTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/LoggerTest $^ ${LDLIBSOPTIONS} -lpthread -lgtest_main -lgtest 

${TESTDIR}/TestFiles/LogTest: ${TESTDIR}/tests/LogFormatTest.o ${TESTDIR}/tests/LogTest.o ${TESTDIR}/tests/MultiLogWriter.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/LogTest $^ ${LDLIBSOPTIONS} -lpthread -lgtest_main -lgtest 

${TESTDIR}/TestFiles/SingletonTest: ${TESTDIR}/tests/SingletonTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/SingletonTest $^ ${LDLIBSOPTIONS} -lpthread -lgtest_main -lgtest 

${TESTDIR}/TestFiles/TestApp: ${TESTDIR}/tests/TestApp.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/TestApp $^ ${LDLIBSOPTIONS} -lpthread -lgtest_main -lgtest 


${TESTDIR}/tests/AnsiTermTest.o: tests/AnsiTermTest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Iinclude -I. -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/AnsiTermTest.o tests/AnsiTermTest.cpp


${TESTDIR}/tests/FormatStringTest.o: tests/FormatStringTest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Iinclude -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/FormatStringTest.o tests/FormatStringTest.cpp


${TESTDIR}/tests/FormatTest.o: tests/FormatTest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Iinclude -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/FormatTest.o tests/FormatTest.cpp


${TESTDIR}/tests/LoggerTest.o: tests/LoggerTest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Iinclude -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/LoggerTest.o tests/LoggerTest.cpp


${TESTDIR}/tests/LogFormatTest.o: tests/LogFormatTest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Iinclude -I. -I. -I. -I. -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/LogFormatTest.o tests/LogFormatTest.cpp


${TESTDIR}/tests/LogTest.o: tests/LogTest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Iinclude -I. -I. -I. -I. -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/LogTest.o tests/LogTest.cpp


${TESTDIR}/tests/MultiLogWriter.o: tests/MultiLogWriter.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Iinclude -I. -I. -I. -I. -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/MultiLogWriter.o tests/MultiLogWriter.cpp


${TESTDIR}/tests/SingletonTest.o: tests/SingletonTest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Iinclude -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/SingletonTest.o tests/SingletonTest.cpp


${TESTDIR}/tests/TestApp.o: tests/TestApp.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Iinclude -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/TestApp.o tests/TestApp.cpp


${OBJECTDIR}/src/AnsiTerm_nomain.o: ${OBJECTDIR}/src/AnsiTerm.o src/AnsiTerm.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/AnsiTerm.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Wall -Iinclude -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/AnsiTerm_nomain.o src/AnsiTerm.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/AnsiTerm.o ${OBJECTDIR}/src/AnsiTerm_nomain.o;\
	fi

${OBJECTDIR}/src/FileLogWriter_nomain.o: ${OBJECTDIR}/src/FileLogWriter.o src/FileLogWriter.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/FileLogWriter.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Wall -Iinclude -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/FileLogWriter_nomain.o src/FileLogWriter.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/FileLogWriter.o ${OBJECTDIR}/src/FileLogWriter_nomain.o;\
	fi

${OBJECTDIR}/src/Format_nomain.o: ${OBJECTDIR}/src/Format.o src/Format.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/Format.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Wall -Iinclude -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Format_nomain.o src/Format.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/Format.o ${OBJECTDIR}/src/Format_nomain.o;\
	fi

${OBJECTDIR}/src/FormatString_nomain.o: ${OBJECTDIR}/src/FormatString.o src/FormatString.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/FormatString.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Wall -Iinclude -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/FormatString_nomain.o src/FormatString.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/FormatString.o ${OBJECTDIR}/src/FormatString_nomain.o;\
	fi

${OBJECTDIR}/src/Log_nomain.o: ${OBJECTDIR}/src/Log.o src/Log.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/Log.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Wall -Iinclude -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Log_nomain.o src/Log.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/Log.o ${OBJECTDIR}/src/Log_nomain.o;\
	fi

${OBJECTDIR}/src/LogFormat_nomain.o: ${OBJECTDIR}/src/LogFormat.o src/LogFormat.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/LogFormat.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Wall -Iinclude -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/LogFormat_nomain.o src/LogFormat.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/LogFormat.o ${OBJECTDIR}/src/LogFormat_nomain.o;\
	fi

${OBJECTDIR}/src/LogLevel_nomain.o: ${OBJECTDIR}/src/LogLevel.o src/LogLevel.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/LogLevel.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Wall -Iinclude -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/LogLevel_nomain.o src/LogLevel.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/LogLevel.o ${OBJECTDIR}/src/LogLevel_nomain.o;\
	fi

${OBJECTDIR}/src/LogWriter_nomain.o: ${OBJECTDIR}/src/LogWriter.o src/LogWriter.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/LogWriter.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Wall -Iinclude -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/LogWriter_nomain.o src/LogWriter.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/LogWriter.o ${OBJECTDIR}/src/LogWriter_nomain.o;\
	fi

${OBJECTDIR}/src/MultiLogWriter_nomain.o: ${OBJECTDIR}/src/MultiLogWriter.o src/MultiLogWriter.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/MultiLogWriter.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Wall -Iinclude -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/MultiLogWriter_nomain.o src/MultiLogWriter.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/MultiLogWriter.o ${OBJECTDIR}/src/MultiLogWriter_nomain.o;\
	fi

# Run Test Targets
.test-conf:
	@if [ "${TEST}" = "" ]; \
	then  \
	    ${TESTDIR}/TestFiles/AnsiTermTest || true; \
	    ${TESTDIR}/TestFiles/FormatTest || true; \
	    ${TESTDIR}/TestFiles/LoggerTest || true; \
	    ${TESTDIR}/TestFiles/LogTest || true; \
	    ${TESTDIR}/TestFiles/SingletonTest || true; \
	    ${TESTDIR}/TestFiles/TestApp || true; \
	else  \
	    ./${TEST} || true; \
	fi

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libsoil.a

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
