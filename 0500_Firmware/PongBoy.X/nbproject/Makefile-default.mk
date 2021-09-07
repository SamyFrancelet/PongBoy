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
MKDIR=mkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/PongBoy.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/PongBoy.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=src/app/pong_ctrl.c src/board/lcd/arialNarrow_12ptBitmaps.c src/board/lcd/lcd_highlevel.c src/board/tsc/tsc.c src/display/display.c src/game_objects/paddle.c src/game_objects/ball.c src/hal/lcd/lcd_lowlevel.c src/pongboy/pongboy.c src/xf/xf.c src/main.c src/configuration_bits.c src/app/menu_ctrl.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/src/app/pong_ctrl.p1 ${OBJECTDIR}/src/board/lcd/arialNarrow_12ptBitmaps.p1 ${OBJECTDIR}/src/board/lcd/lcd_highlevel.p1 ${OBJECTDIR}/src/board/tsc/tsc.p1 ${OBJECTDIR}/src/display/display.p1 ${OBJECTDIR}/src/game_objects/paddle.p1 ${OBJECTDIR}/src/game_objects/ball.p1 ${OBJECTDIR}/src/hal/lcd/lcd_lowlevel.p1 ${OBJECTDIR}/src/pongboy/pongboy.p1 ${OBJECTDIR}/src/xf/xf.p1 ${OBJECTDIR}/src/main.p1 ${OBJECTDIR}/src/configuration_bits.p1 ${OBJECTDIR}/src/app/menu_ctrl.p1
POSSIBLE_DEPFILES=${OBJECTDIR}/src/app/pong_ctrl.p1.d ${OBJECTDIR}/src/board/lcd/arialNarrow_12ptBitmaps.p1.d ${OBJECTDIR}/src/board/lcd/lcd_highlevel.p1.d ${OBJECTDIR}/src/board/tsc/tsc.p1.d ${OBJECTDIR}/src/display/display.p1.d ${OBJECTDIR}/src/game_objects/paddle.p1.d ${OBJECTDIR}/src/game_objects/ball.p1.d ${OBJECTDIR}/src/hal/lcd/lcd_lowlevel.p1.d ${OBJECTDIR}/src/pongboy/pongboy.p1.d ${OBJECTDIR}/src/xf/xf.p1.d ${OBJECTDIR}/src/main.p1.d ${OBJECTDIR}/src/configuration_bits.p1.d ${OBJECTDIR}/src/app/menu_ctrl.p1.d

# Object Files
OBJECTFILES=${OBJECTDIR}/src/app/pong_ctrl.p1 ${OBJECTDIR}/src/board/lcd/arialNarrow_12ptBitmaps.p1 ${OBJECTDIR}/src/board/lcd/lcd_highlevel.p1 ${OBJECTDIR}/src/board/tsc/tsc.p1 ${OBJECTDIR}/src/display/display.p1 ${OBJECTDIR}/src/game_objects/paddle.p1 ${OBJECTDIR}/src/game_objects/ball.p1 ${OBJECTDIR}/src/hal/lcd/lcd_lowlevel.p1 ${OBJECTDIR}/src/pongboy/pongboy.p1 ${OBJECTDIR}/src/xf/xf.p1 ${OBJECTDIR}/src/main.p1 ${OBJECTDIR}/src/configuration_bits.p1 ${OBJECTDIR}/src/app/menu_ctrl.p1

# Source Files
SOURCEFILES=src/app/pong_ctrl.c src/board/lcd/arialNarrow_12ptBitmaps.c src/board/lcd/lcd_highlevel.c src/board/tsc/tsc.c src/display/display.c src/game_objects/paddle.c src/game_objects/ball.c src/hal/lcd/lcd_lowlevel.c src/pongboy/pongboy.c src/xf/xf.c src/main.c src/configuration_bits.c src/app/menu_ctrl.c



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
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/PongBoy.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=18LF25K22
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/src/app/pong_ctrl.p1: src/app/pong_ctrl.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/src/app" 
	@${RM} ${OBJECTDIR}/src/app/pong_ctrl.p1.d 
	@${RM} ${OBJECTDIR}/src/app/pong_ctrl.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -Os -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/src/app/pong_ctrl.p1 src/app/pong_ctrl.c 
	@-${MV} ${OBJECTDIR}/src/app/pong_ctrl.d ${OBJECTDIR}/src/app/pong_ctrl.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/src/app/pong_ctrl.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/src/board/lcd/arialNarrow_12ptBitmaps.p1: src/board/lcd/arialNarrow_12ptBitmaps.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/src/board/lcd" 
	@${RM} ${OBJECTDIR}/src/board/lcd/arialNarrow_12ptBitmaps.p1.d 
	@${RM} ${OBJECTDIR}/src/board/lcd/arialNarrow_12ptBitmaps.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -Os -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/src/board/lcd/arialNarrow_12ptBitmaps.p1 src/board/lcd/arialNarrow_12ptBitmaps.c 
	@-${MV} ${OBJECTDIR}/src/board/lcd/arialNarrow_12ptBitmaps.d ${OBJECTDIR}/src/board/lcd/arialNarrow_12ptBitmaps.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/src/board/lcd/arialNarrow_12ptBitmaps.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/src/board/lcd/lcd_highlevel.p1: src/board/lcd/lcd_highlevel.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/src/board/lcd" 
	@${RM} ${OBJECTDIR}/src/board/lcd/lcd_highlevel.p1.d 
	@${RM} ${OBJECTDIR}/src/board/lcd/lcd_highlevel.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -Os -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/src/board/lcd/lcd_highlevel.p1 src/board/lcd/lcd_highlevel.c 
	@-${MV} ${OBJECTDIR}/src/board/lcd/lcd_highlevel.d ${OBJECTDIR}/src/board/lcd/lcd_highlevel.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/src/board/lcd/lcd_highlevel.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/src/board/tsc/tsc.p1: src/board/tsc/tsc.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/src/board/tsc" 
	@${RM} ${OBJECTDIR}/src/board/tsc/tsc.p1.d 
	@${RM} ${OBJECTDIR}/src/board/tsc/tsc.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -Os -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/src/board/tsc/tsc.p1 src/board/tsc/tsc.c 
	@-${MV} ${OBJECTDIR}/src/board/tsc/tsc.d ${OBJECTDIR}/src/board/tsc/tsc.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/src/board/tsc/tsc.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/src/display/display.p1: src/display/display.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/src/display" 
	@${RM} ${OBJECTDIR}/src/display/display.p1.d 
	@${RM} ${OBJECTDIR}/src/display/display.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -Os -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/src/display/display.p1 src/display/display.c 
	@-${MV} ${OBJECTDIR}/src/display/display.d ${OBJECTDIR}/src/display/display.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/src/display/display.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/src/game_objects/paddle.p1: src/game_objects/paddle.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/src/game_objects" 
	@${RM} ${OBJECTDIR}/src/game_objects/paddle.p1.d 
	@${RM} ${OBJECTDIR}/src/game_objects/paddle.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -Os -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/src/game_objects/paddle.p1 src/game_objects/paddle.c 
	@-${MV} ${OBJECTDIR}/src/game_objects/paddle.d ${OBJECTDIR}/src/game_objects/paddle.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/src/game_objects/paddle.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/src/game_objects/ball.p1: src/game_objects/ball.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/src/game_objects" 
	@${RM} ${OBJECTDIR}/src/game_objects/ball.p1.d 
	@${RM} ${OBJECTDIR}/src/game_objects/ball.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -Os -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/src/game_objects/ball.p1 src/game_objects/ball.c 
	@-${MV} ${OBJECTDIR}/src/game_objects/ball.d ${OBJECTDIR}/src/game_objects/ball.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/src/game_objects/ball.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/src/hal/lcd/lcd_lowlevel.p1: src/hal/lcd/lcd_lowlevel.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/src/hal/lcd" 
	@${RM} ${OBJECTDIR}/src/hal/lcd/lcd_lowlevel.p1.d 
	@${RM} ${OBJECTDIR}/src/hal/lcd/lcd_lowlevel.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -Os -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/src/hal/lcd/lcd_lowlevel.p1 src/hal/lcd/lcd_lowlevel.c 
	@-${MV} ${OBJECTDIR}/src/hal/lcd/lcd_lowlevel.d ${OBJECTDIR}/src/hal/lcd/lcd_lowlevel.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/src/hal/lcd/lcd_lowlevel.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/src/pongboy/pongboy.p1: src/pongboy/pongboy.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/src/pongboy" 
	@${RM} ${OBJECTDIR}/src/pongboy/pongboy.p1.d 
	@${RM} ${OBJECTDIR}/src/pongboy/pongboy.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -Os -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/src/pongboy/pongboy.p1 src/pongboy/pongboy.c 
	@-${MV} ${OBJECTDIR}/src/pongboy/pongboy.d ${OBJECTDIR}/src/pongboy/pongboy.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/src/pongboy/pongboy.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/src/xf/xf.p1: src/xf/xf.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/src/xf" 
	@${RM} ${OBJECTDIR}/src/xf/xf.p1.d 
	@${RM} ${OBJECTDIR}/src/xf/xf.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -Os -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/src/xf/xf.p1 src/xf/xf.c 
	@-${MV} ${OBJECTDIR}/src/xf/xf.d ${OBJECTDIR}/src/xf/xf.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/src/xf/xf.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/src/main.p1: src/main.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/main.p1.d 
	@${RM} ${OBJECTDIR}/src/main.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -Os -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/src/main.p1 src/main.c 
	@-${MV} ${OBJECTDIR}/src/main.d ${OBJECTDIR}/src/main.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/src/main.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/src/configuration_bits.p1: src/configuration_bits.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/configuration_bits.p1.d 
	@${RM} ${OBJECTDIR}/src/configuration_bits.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -Os -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/src/configuration_bits.p1 src/configuration_bits.c 
	@-${MV} ${OBJECTDIR}/src/configuration_bits.d ${OBJECTDIR}/src/configuration_bits.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/src/configuration_bits.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/src/app/menu_ctrl.p1: src/app/menu_ctrl.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/src/app" 
	@${RM} ${OBJECTDIR}/src/app/menu_ctrl.p1.d 
	@${RM} ${OBJECTDIR}/src/app/menu_ctrl.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -Os -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/src/app/menu_ctrl.p1 src/app/menu_ctrl.c 
	@-${MV} ${OBJECTDIR}/src/app/menu_ctrl.d ${OBJECTDIR}/src/app/menu_ctrl.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/src/app/menu_ctrl.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
else
${OBJECTDIR}/src/app/pong_ctrl.p1: src/app/pong_ctrl.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/src/app" 
	@${RM} ${OBJECTDIR}/src/app/pong_ctrl.p1.d 
	@${RM} ${OBJECTDIR}/src/app/pong_ctrl.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -Os -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/src/app/pong_ctrl.p1 src/app/pong_ctrl.c 
	@-${MV} ${OBJECTDIR}/src/app/pong_ctrl.d ${OBJECTDIR}/src/app/pong_ctrl.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/src/app/pong_ctrl.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/src/board/lcd/arialNarrow_12ptBitmaps.p1: src/board/lcd/arialNarrow_12ptBitmaps.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/src/board/lcd" 
	@${RM} ${OBJECTDIR}/src/board/lcd/arialNarrow_12ptBitmaps.p1.d 
	@${RM} ${OBJECTDIR}/src/board/lcd/arialNarrow_12ptBitmaps.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -Os -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/src/board/lcd/arialNarrow_12ptBitmaps.p1 src/board/lcd/arialNarrow_12ptBitmaps.c 
	@-${MV} ${OBJECTDIR}/src/board/lcd/arialNarrow_12ptBitmaps.d ${OBJECTDIR}/src/board/lcd/arialNarrow_12ptBitmaps.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/src/board/lcd/arialNarrow_12ptBitmaps.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/src/board/lcd/lcd_highlevel.p1: src/board/lcd/lcd_highlevel.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/src/board/lcd" 
	@${RM} ${OBJECTDIR}/src/board/lcd/lcd_highlevel.p1.d 
	@${RM} ${OBJECTDIR}/src/board/lcd/lcd_highlevel.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -Os -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/src/board/lcd/lcd_highlevel.p1 src/board/lcd/lcd_highlevel.c 
	@-${MV} ${OBJECTDIR}/src/board/lcd/lcd_highlevel.d ${OBJECTDIR}/src/board/lcd/lcd_highlevel.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/src/board/lcd/lcd_highlevel.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/src/board/tsc/tsc.p1: src/board/tsc/tsc.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/src/board/tsc" 
	@${RM} ${OBJECTDIR}/src/board/tsc/tsc.p1.d 
	@${RM} ${OBJECTDIR}/src/board/tsc/tsc.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -Os -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/src/board/tsc/tsc.p1 src/board/tsc/tsc.c 
	@-${MV} ${OBJECTDIR}/src/board/tsc/tsc.d ${OBJECTDIR}/src/board/tsc/tsc.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/src/board/tsc/tsc.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/src/display/display.p1: src/display/display.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/src/display" 
	@${RM} ${OBJECTDIR}/src/display/display.p1.d 
	@${RM} ${OBJECTDIR}/src/display/display.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -Os -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/src/display/display.p1 src/display/display.c 
	@-${MV} ${OBJECTDIR}/src/display/display.d ${OBJECTDIR}/src/display/display.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/src/display/display.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/src/game_objects/paddle.p1: src/game_objects/paddle.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/src/game_objects" 
	@${RM} ${OBJECTDIR}/src/game_objects/paddle.p1.d 
	@${RM} ${OBJECTDIR}/src/game_objects/paddle.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -Os -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/src/game_objects/paddle.p1 src/game_objects/paddle.c 
	@-${MV} ${OBJECTDIR}/src/game_objects/paddle.d ${OBJECTDIR}/src/game_objects/paddle.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/src/game_objects/paddle.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/src/game_objects/ball.p1: src/game_objects/ball.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/src/game_objects" 
	@${RM} ${OBJECTDIR}/src/game_objects/ball.p1.d 
	@${RM} ${OBJECTDIR}/src/game_objects/ball.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -Os -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/src/game_objects/ball.p1 src/game_objects/ball.c 
	@-${MV} ${OBJECTDIR}/src/game_objects/ball.d ${OBJECTDIR}/src/game_objects/ball.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/src/game_objects/ball.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/src/hal/lcd/lcd_lowlevel.p1: src/hal/lcd/lcd_lowlevel.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/src/hal/lcd" 
	@${RM} ${OBJECTDIR}/src/hal/lcd/lcd_lowlevel.p1.d 
	@${RM} ${OBJECTDIR}/src/hal/lcd/lcd_lowlevel.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -Os -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/src/hal/lcd/lcd_lowlevel.p1 src/hal/lcd/lcd_lowlevel.c 
	@-${MV} ${OBJECTDIR}/src/hal/lcd/lcd_lowlevel.d ${OBJECTDIR}/src/hal/lcd/lcd_lowlevel.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/src/hal/lcd/lcd_lowlevel.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/src/pongboy/pongboy.p1: src/pongboy/pongboy.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/src/pongboy" 
	@${RM} ${OBJECTDIR}/src/pongboy/pongboy.p1.d 
	@${RM} ${OBJECTDIR}/src/pongboy/pongboy.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -Os -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/src/pongboy/pongboy.p1 src/pongboy/pongboy.c 
	@-${MV} ${OBJECTDIR}/src/pongboy/pongboy.d ${OBJECTDIR}/src/pongboy/pongboy.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/src/pongboy/pongboy.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/src/xf/xf.p1: src/xf/xf.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/src/xf" 
	@${RM} ${OBJECTDIR}/src/xf/xf.p1.d 
	@${RM} ${OBJECTDIR}/src/xf/xf.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -Os -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/src/xf/xf.p1 src/xf/xf.c 
	@-${MV} ${OBJECTDIR}/src/xf/xf.d ${OBJECTDIR}/src/xf/xf.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/src/xf/xf.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/src/main.p1: src/main.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/main.p1.d 
	@${RM} ${OBJECTDIR}/src/main.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -Os -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/src/main.p1 src/main.c 
	@-${MV} ${OBJECTDIR}/src/main.d ${OBJECTDIR}/src/main.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/src/main.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/src/configuration_bits.p1: src/configuration_bits.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/configuration_bits.p1.d 
	@${RM} ${OBJECTDIR}/src/configuration_bits.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -Os -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/src/configuration_bits.p1 src/configuration_bits.c 
	@-${MV} ${OBJECTDIR}/src/configuration_bits.d ${OBJECTDIR}/src/configuration_bits.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/src/configuration_bits.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/src/app/menu_ctrl.p1: src/app/menu_ctrl.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/src/app" 
	@${RM} ${OBJECTDIR}/src/app/menu_ctrl.p1.d 
	@${RM} ${OBJECTDIR}/src/app/menu_ctrl.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -Os -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/src/app/menu_ctrl.p1 src/app/menu_ctrl.c 
	@-${MV} ${OBJECTDIR}/src/app/menu_ctrl.d ${OBJECTDIR}/src/app/menu_ctrl.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/src/app/menu_ctrl.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/PongBoy.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=dist/${CND_CONF}/${IMAGE_TYPE}/PongBoy.X.${IMAGE_TYPE}.map  -D__DEBUG=1  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -Os -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto        $(COMPARISON_BUILD) -Wl,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -o dist/${CND_CONF}/${IMAGE_TYPE}/PongBoy.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	@${RM} dist/${CND_CONF}/${IMAGE_TYPE}/PongBoy.X.${IMAGE_TYPE}.hex 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/PongBoy.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=dist/${CND_CONF}/${IMAGE_TYPE}/PongBoy.X.${IMAGE_TYPE}.map  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -Os -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     $(COMPARISON_BUILD) -Wl,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -o dist/${CND_CONF}/${IMAGE_TYPE}/PongBoy.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	
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

DEPFILES=$(shell "${PATH_TO_IDE_BIN}"mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
