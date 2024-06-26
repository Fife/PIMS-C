#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/PIMSC.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/PIMSC.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS
SUB_IMAGE_ADDRESS_COMMAND=--image-address $(SUB_IMAGE_ADDRESS)
else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=PIMSE_INTERFACE/PIMS_E_SHELL.c main.c LED.c buffers.c SYSTEM/interrupts.c SYSTEM/clock.c SYSTEM/uart1.c SYSTEM/uart2.c SYSTEM/setup.c SYSTEM/uart3.c SYSTEM/uart4.c "Unit Tests/SystemTest.c" WIZ_INTERFACE/JSON_CONVERTER.c WIZ_INTERFACE/WIZ_S2E.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/PIMSE_INTERFACE/PIMS_E_SHELL.o ${OBJECTDIR}/main.o ${OBJECTDIR}/LED.o ${OBJECTDIR}/buffers.o ${OBJECTDIR}/SYSTEM/interrupts.o ${OBJECTDIR}/SYSTEM/clock.o ${OBJECTDIR}/SYSTEM/uart1.o ${OBJECTDIR}/SYSTEM/uart2.o ${OBJECTDIR}/SYSTEM/setup.o ${OBJECTDIR}/SYSTEM/uart3.o ${OBJECTDIR}/SYSTEM/uart4.o "${OBJECTDIR}/Unit Tests/SystemTest.o" ${OBJECTDIR}/WIZ_INTERFACE/JSON_CONVERTER.o ${OBJECTDIR}/WIZ_INTERFACE/WIZ_S2E.o
POSSIBLE_DEPFILES=${OBJECTDIR}/PIMSE_INTERFACE/PIMS_E_SHELL.o.d ${OBJECTDIR}/main.o.d ${OBJECTDIR}/LED.o.d ${OBJECTDIR}/buffers.o.d ${OBJECTDIR}/SYSTEM/interrupts.o.d ${OBJECTDIR}/SYSTEM/clock.o.d ${OBJECTDIR}/SYSTEM/uart1.o.d ${OBJECTDIR}/SYSTEM/uart2.o.d ${OBJECTDIR}/SYSTEM/setup.o.d ${OBJECTDIR}/SYSTEM/uart3.o.d ${OBJECTDIR}/SYSTEM/uart4.o.d "${OBJECTDIR}/Unit Tests/SystemTest.o.d" ${OBJECTDIR}/WIZ_INTERFACE/JSON_CONVERTER.o.d ${OBJECTDIR}/WIZ_INTERFACE/WIZ_S2E.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/PIMSE_INTERFACE/PIMS_E_SHELL.o ${OBJECTDIR}/main.o ${OBJECTDIR}/LED.o ${OBJECTDIR}/buffers.o ${OBJECTDIR}/SYSTEM/interrupts.o ${OBJECTDIR}/SYSTEM/clock.o ${OBJECTDIR}/SYSTEM/uart1.o ${OBJECTDIR}/SYSTEM/uart2.o ${OBJECTDIR}/SYSTEM/setup.o ${OBJECTDIR}/SYSTEM/uart3.o ${OBJECTDIR}/SYSTEM/uart4.o ${OBJECTDIR}/Unit\ Tests/SystemTest.o ${OBJECTDIR}/WIZ_INTERFACE/JSON_CONVERTER.o ${OBJECTDIR}/WIZ_INTERFACE/WIZ_S2E.o

# Source Files
SOURCEFILES=PIMSE_INTERFACE/PIMS_E_SHELL.c main.c LED.c buffers.c SYSTEM/interrupts.c SYSTEM/clock.c SYSTEM/uart1.c SYSTEM/uart2.c SYSTEM/setup.c SYSTEM/uart3.c SYSTEM/uart4.c Unit Tests/SystemTest.c WIZ_INTERFACE/JSON_CONVERTER.c WIZ_INTERFACE/WIZ_S2E.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/PIMSC.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=24FJ64GL306
MP_LINKER_FILE_OPTION=,--script=p24FJ64GL306.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/PIMSE_INTERFACE/PIMS_E_SHELL.o: PIMSE_INTERFACE/PIMS_E_SHELL.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/PIMSE_INTERFACE" 
	@${RM} ${OBJECTDIR}/PIMSE_INTERFACE/PIMS_E_SHELL.o.d 
	@${RM} ${OBJECTDIR}/PIMSE_INTERFACE/PIMS_E_SHELL.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  PIMSE_INTERFACE/PIMS_E_SHELL.c  -o ${OBJECTDIR}/PIMSE_INTERFACE/PIMS_E_SHELL.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/PIMSE_INTERFACE/PIMS_E_SHELL.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -msmall-code -msmall-data -msmall-scalar -mconst-in-code -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	@${FIXDEPS} "${OBJECTDIR}/PIMSE_INTERFACE/PIMS_E_SHELL.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/main.o: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main.c  -o ${OBJECTDIR}/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/main.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -msmall-code -msmall-data -msmall-scalar -mconst-in-code -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	@${FIXDEPS} "${OBJECTDIR}/main.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/LED.o: LED.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/LED.o.d 
	@${RM} ${OBJECTDIR}/LED.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  LED.c  -o ${OBJECTDIR}/LED.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/LED.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -msmall-code -msmall-data -msmall-scalar -mconst-in-code -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	@${FIXDEPS} "${OBJECTDIR}/LED.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/buffers.o: buffers.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/buffers.o.d 
	@${RM} ${OBJECTDIR}/buffers.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  buffers.c  -o ${OBJECTDIR}/buffers.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/buffers.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -msmall-code -msmall-data -msmall-scalar -mconst-in-code -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	@${FIXDEPS} "${OBJECTDIR}/buffers.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/SYSTEM/interrupts.o: SYSTEM/interrupts.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/SYSTEM" 
	@${RM} ${OBJECTDIR}/SYSTEM/interrupts.o.d 
	@${RM} ${OBJECTDIR}/SYSTEM/interrupts.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  SYSTEM/interrupts.c  -o ${OBJECTDIR}/SYSTEM/interrupts.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/SYSTEM/interrupts.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -msmall-code -msmall-data -msmall-scalar -mconst-in-code -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	@${FIXDEPS} "${OBJECTDIR}/SYSTEM/interrupts.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/SYSTEM/clock.o: SYSTEM/clock.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/SYSTEM" 
	@${RM} ${OBJECTDIR}/SYSTEM/clock.o.d 
	@${RM} ${OBJECTDIR}/SYSTEM/clock.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  SYSTEM/clock.c  -o ${OBJECTDIR}/SYSTEM/clock.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/SYSTEM/clock.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -msmall-code -msmall-data -msmall-scalar -mconst-in-code -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	@${FIXDEPS} "${OBJECTDIR}/SYSTEM/clock.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/SYSTEM/uart1.o: SYSTEM/uart1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/SYSTEM" 
	@${RM} ${OBJECTDIR}/SYSTEM/uart1.o.d 
	@${RM} ${OBJECTDIR}/SYSTEM/uart1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  SYSTEM/uart1.c  -o ${OBJECTDIR}/SYSTEM/uart1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/SYSTEM/uart1.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -msmall-code -msmall-data -msmall-scalar -mconst-in-code -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	@${FIXDEPS} "${OBJECTDIR}/SYSTEM/uart1.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/SYSTEM/uart2.o: SYSTEM/uart2.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/SYSTEM" 
	@${RM} ${OBJECTDIR}/SYSTEM/uart2.o.d 
	@${RM} ${OBJECTDIR}/SYSTEM/uart2.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  SYSTEM/uart2.c  -o ${OBJECTDIR}/SYSTEM/uart2.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/SYSTEM/uart2.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -msmall-code -msmall-data -msmall-scalar -mconst-in-code -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	@${FIXDEPS} "${OBJECTDIR}/SYSTEM/uart2.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/SYSTEM/setup.o: SYSTEM/setup.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/SYSTEM" 
	@${RM} ${OBJECTDIR}/SYSTEM/setup.o.d 
	@${RM} ${OBJECTDIR}/SYSTEM/setup.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  SYSTEM/setup.c  -o ${OBJECTDIR}/SYSTEM/setup.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/SYSTEM/setup.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -msmall-code -msmall-data -msmall-scalar -mconst-in-code -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	@${FIXDEPS} "${OBJECTDIR}/SYSTEM/setup.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/SYSTEM/uart3.o: SYSTEM/uart3.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/SYSTEM" 
	@${RM} ${OBJECTDIR}/SYSTEM/uart3.o.d 
	@${RM} ${OBJECTDIR}/SYSTEM/uart3.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  SYSTEM/uart3.c  -o ${OBJECTDIR}/SYSTEM/uart3.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/SYSTEM/uart3.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -msmall-code -msmall-data -msmall-scalar -mconst-in-code -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	@${FIXDEPS} "${OBJECTDIR}/SYSTEM/uart3.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/SYSTEM/uart4.o: SYSTEM/uart4.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/SYSTEM" 
	@${RM} ${OBJECTDIR}/SYSTEM/uart4.o.d 
	@${RM} ${OBJECTDIR}/SYSTEM/uart4.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  SYSTEM/uart4.c  -o ${OBJECTDIR}/SYSTEM/uart4.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/SYSTEM/uart4.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -msmall-code -msmall-data -msmall-scalar -mconst-in-code -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	@${FIXDEPS} "${OBJECTDIR}/SYSTEM/uart4.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/Unit\ Tests/SystemTest.o: Unit\ Tests/SystemTest.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/Unit Tests" 
	@${RM} "${OBJECTDIR}/Unit Tests/SystemTest.o".d 
	@${RM} "${OBJECTDIR}/Unit Tests/SystemTest.o" 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "Unit Tests/SystemTest.c"  -o "${OBJECTDIR}/Unit Tests/SystemTest.o"  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Unit Tests/SystemTest.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -msmall-code -msmall-data -msmall-scalar -mconst-in-code -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	@${FIXDEPS} "${OBJECTDIR}/Unit Tests/SystemTest.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/WIZ_INTERFACE/JSON_CONVERTER.o: WIZ_INTERFACE/JSON_CONVERTER.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/WIZ_INTERFACE" 
	@${RM} ${OBJECTDIR}/WIZ_INTERFACE/JSON_CONVERTER.o.d 
	@${RM} ${OBJECTDIR}/WIZ_INTERFACE/JSON_CONVERTER.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  WIZ_INTERFACE/JSON_CONVERTER.c  -o ${OBJECTDIR}/WIZ_INTERFACE/JSON_CONVERTER.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/WIZ_INTERFACE/JSON_CONVERTER.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -msmall-code -msmall-data -msmall-scalar -mconst-in-code -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	@${FIXDEPS} "${OBJECTDIR}/WIZ_INTERFACE/JSON_CONVERTER.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/WIZ_INTERFACE/WIZ_S2E.o: WIZ_INTERFACE/WIZ_S2E.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/WIZ_INTERFACE" 
	@${RM} ${OBJECTDIR}/WIZ_INTERFACE/WIZ_S2E.o.d 
	@${RM} ${OBJECTDIR}/WIZ_INTERFACE/WIZ_S2E.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  WIZ_INTERFACE/WIZ_S2E.c  -o ${OBJECTDIR}/WIZ_INTERFACE/WIZ_S2E.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/WIZ_INTERFACE/WIZ_S2E.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -msmall-code -msmall-data -msmall-scalar -mconst-in-code -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	@${FIXDEPS} "${OBJECTDIR}/WIZ_INTERFACE/WIZ_S2E.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
else
${OBJECTDIR}/PIMSE_INTERFACE/PIMS_E_SHELL.o: PIMSE_INTERFACE/PIMS_E_SHELL.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/PIMSE_INTERFACE" 
	@${RM} ${OBJECTDIR}/PIMSE_INTERFACE/PIMS_E_SHELL.o.d 
	@${RM} ${OBJECTDIR}/PIMSE_INTERFACE/PIMS_E_SHELL.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  PIMSE_INTERFACE/PIMS_E_SHELL.c  -o ${OBJECTDIR}/PIMSE_INTERFACE/PIMS_E_SHELL.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/PIMSE_INTERFACE/PIMS_E_SHELL.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -msmall-code -msmall-data -msmall-scalar -mconst-in-code -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	@${FIXDEPS} "${OBJECTDIR}/PIMSE_INTERFACE/PIMS_E_SHELL.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/main.o: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main.c  -o ${OBJECTDIR}/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/main.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -msmall-code -msmall-data -msmall-scalar -mconst-in-code -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	@${FIXDEPS} "${OBJECTDIR}/main.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/LED.o: LED.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/LED.o.d 
	@${RM} ${OBJECTDIR}/LED.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  LED.c  -o ${OBJECTDIR}/LED.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/LED.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -msmall-code -msmall-data -msmall-scalar -mconst-in-code -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	@${FIXDEPS} "${OBJECTDIR}/LED.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/buffers.o: buffers.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/buffers.o.d 
	@${RM} ${OBJECTDIR}/buffers.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  buffers.c  -o ${OBJECTDIR}/buffers.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/buffers.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -msmall-code -msmall-data -msmall-scalar -mconst-in-code -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	@${FIXDEPS} "${OBJECTDIR}/buffers.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/SYSTEM/interrupts.o: SYSTEM/interrupts.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/SYSTEM" 
	@${RM} ${OBJECTDIR}/SYSTEM/interrupts.o.d 
	@${RM} ${OBJECTDIR}/SYSTEM/interrupts.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  SYSTEM/interrupts.c  -o ${OBJECTDIR}/SYSTEM/interrupts.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/SYSTEM/interrupts.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -msmall-code -msmall-data -msmall-scalar -mconst-in-code -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	@${FIXDEPS} "${OBJECTDIR}/SYSTEM/interrupts.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/SYSTEM/clock.o: SYSTEM/clock.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/SYSTEM" 
	@${RM} ${OBJECTDIR}/SYSTEM/clock.o.d 
	@${RM} ${OBJECTDIR}/SYSTEM/clock.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  SYSTEM/clock.c  -o ${OBJECTDIR}/SYSTEM/clock.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/SYSTEM/clock.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -msmall-code -msmall-data -msmall-scalar -mconst-in-code -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	@${FIXDEPS} "${OBJECTDIR}/SYSTEM/clock.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/SYSTEM/uart1.o: SYSTEM/uart1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/SYSTEM" 
	@${RM} ${OBJECTDIR}/SYSTEM/uart1.o.d 
	@${RM} ${OBJECTDIR}/SYSTEM/uart1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  SYSTEM/uart1.c  -o ${OBJECTDIR}/SYSTEM/uart1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/SYSTEM/uart1.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -msmall-code -msmall-data -msmall-scalar -mconst-in-code -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	@${FIXDEPS} "${OBJECTDIR}/SYSTEM/uart1.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/SYSTEM/uart2.o: SYSTEM/uart2.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/SYSTEM" 
	@${RM} ${OBJECTDIR}/SYSTEM/uart2.o.d 
	@${RM} ${OBJECTDIR}/SYSTEM/uart2.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  SYSTEM/uart2.c  -o ${OBJECTDIR}/SYSTEM/uart2.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/SYSTEM/uart2.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -msmall-code -msmall-data -msmall-scalar -mconst-in-code -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	@${FIXDEPS} "${OBJECTDIR}/SYSTEM/uart2.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/SYSTEM/setup.o: SYSTEM/setup.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/SYSTEM" 
	@${RM} ${OBJECTDIR}/SYSTEM/setup.o.d 
	@${RM} ${OBJECTDIR}/SYSTEM/setup.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  SYSTEM/setup.c  -o ${OBJECTDIR}/SYSTEM/setup.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/SYSTEM/setup.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -msmall-code -msmall-data -msmall-scalar -mconst-in-code -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	@${FIXDEPS} "${OBJECTDIR}/SYSTEM/setup.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/SYSTEM/uart3.o: SYSTEM/uart3.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/SYSTEM" 
	@${RM} ${OBJECTDIR}/SYSTEM/uart3.o.d 
	@${RM} ${OBJECTDIR}/SYSTEM/uart3.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  SYSTEM/uart3.c  -o ${OBJECTDIR}/SYSTEM/uart3.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/SYSTEM/uart3.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -msmall-code -msmall-data -msmall-scalar -mconst-in-code -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	@${FIXDEPS} "${OBJECTDIR}/SYSTEM/uart3.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/SYSTEM/uart4.o: SYSTEM/uart4.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/SYSTEM" 
	@${RM} ${OBJECTDIR}/SYSTEM/uart4.o.d 
	@${RM} ${OBJECTDIR}/SYSTEM/uart4.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  SYSTEM/uart4.c  -o ${OBJECTDIR}/SYSTEM/uart4.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/SYSTEM/uart4.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -msmall-code -msmall-data -msmall-scalar -mconst-in-code -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	@${FIXDEPS} "${OBJECTDIR}/SYSTEM/uart4.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/Unit\ Tests/SystemTest.o: Unit\ Tests/SystemTest.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/Unit Tests" 
	@${RM} "${OBJECTDIR}/Unit Tests/SystemTest.o".d 
	@${RM} "${OBJECTDIR}/Unit Tests/SystemTest.o" 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "Unit Tests/SystemTest.c"  -o "${OBJECTDIR}/Unit Tests/SystemTest.o"  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Unit Tests/SystemTest.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -msmall-code -msmall-data -msmall-scalar -mconst-in-code -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	@${FIXDEPS} "${OBJECTDIR}/Unit Tests/SystemTest.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/WIZ_INTERFACE/JSON_CONVERTER.o: WIZ_INTERFACE/JSON_CONVERTER.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/WIZ_INTERFACE" 
	@${RM} ${OBJECTDIR}/WIZ_INTERFACE/JSON_CONVERTER.o.d 
	@${RM} ${OBJECTDIR}/WIZ_INTERFACE/JSON_CONVERTER.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  WIZ_INTERFACE/JSON_CONVERTER.c  -o ${OBJECTDIR}/WIZ_INTERFACE/JSON_CONVERTER.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/WIZ_INTERFACE/JSON_CONVERTER.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -msmall-code -msmall-data -msmall-scalar -mconst-in-code -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	@${FIXDEPS} "${OBJECTDIR}/WIZ_INTERFACE/JSON_CONVERTER.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/WIZ_INTERFACE/WIZ_S2E.o: WIZ_INTERFACE/WIZ_S2E.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/WIZ_INTERFACE" 
	@${RM} ${OBJECTDIR}/WIZ_INTERFACE/WIZ_S2E.o.d 
	@${RM} ${OBJECTDIR}/WIZ_INTERFACE/WIZ_S2E.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  WIZ_INTERFACE/WIZ_S2E.c  -o ${OBJECTDIR}/WIZ_INTERFACE/WIZ_S2E.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/WIZ_INTERFACE/WIZ_S2E.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -msmall-code -msmall-data -msmall-scalar -mconst-in-code -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	@${FIXDEPS} "${OBJECTDIR}/WIZ_INTERFACE/WIZ_S2E.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemblePreproc
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/PIMSC.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/PIMSC.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG=__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -mreserve=data@0x800:0x81B -mreserve=data@0x81C:0x81D -mreserve=data@0x81E:0x81F -mreserve=data@0x820:0x821 -mreserve=data@0x822:0x823 -mreserve=data@0x824:0x827 -mreserve=data@0x82A:0x84F   -Wl,--local-stack,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D__DEBUG=__DEBUG,--defsym=__MPLAB_DEBUGGER_PK3=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/PIMSC.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/PIMSC.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -Wl,--local-stack,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	${MP_CC_DIR}\\xc16-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/PIMSC.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf   -mdfp="${DFP_DIR}/xc16" 
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
