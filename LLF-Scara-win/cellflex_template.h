/* ----------------------------------------------------------------------------
 |	Nom :			cellflex_template.h
 |	Projet :		Cellflex - LLF Scara
 |	Sujet :     	LLF Scara configuration file template
 |  Auteur :		Alain Menu
 |	Version :		1.0
 |	Création :		mars 2014
 |	Mise à jour :	01/04/2014
 |	Fabrication :	Qt4 / Qt5 OpenSource (Desktop)
 + ------------------------------------------------------------------------- */
/*
 |	Copyright (c) 2014 by Alain Menu <alain.menu@ac-creteil.fr>
 |
 |  This file is part of "Qam LLF Scara project"
 |
 |  This program is free software ;  you can  redistribute it and/or  modify it
 |  under the terms of the  GNU General Public License as published by the Free
 |  Software Foundation ; either version 2 of the License, or  (at your option)
 |  any later version.
 |
 |  This program is distributed in the hope that it will be useful, but WITHOUT
 |  ANY WARRANTY ; without even the  implied  warranty  of  MERCHANTABILITY  or
 |  FITNESS FOR  A PARTICULAR PURPOSE. See the  GNU General Public License  for
 |  more details < http://www.gnu.org/licenses/gpl.txt >.
 + ------------------------------------------------------------------------- */

#ifndef CELLFLEX_TEMPLATE_H
#define CELLFLEX_TEMPLATE_H

#define CELLFLEX_SCARA_CONF \
    "##FileName## - ##Dating##\n" \
    "# --------------------------------------------------------\n" \
    "# LLF CELLFLEX Project - Scara spatial configuration file \n" \
    "# (c)2014 by A. Menu                                      \n" \
    "# --------------------------------------------------------\n" \
    "\n" \
    "# puzzle center gap (mm)\n" \
    "##PuzzleGap##\n" \
    "##PuzzleCols##\n" \
    "##PuzzleRows##\n" \
    "\n" \
    "# TCP's relative escape (mm)\n" \
    "##ZEscape##\n" \
    "\n" \
    "# gap between fingers interior spacing and axis value (mm)\n" \
    "##GripperOffs##\n" \
    "\n" \
    "# fingers open/close spacing (mm)\n" \
    "##GripperOpen##\n" \
    "##GripperClose##\n" \
    "\n" \
    "# --------------------------------------------------------\n" \
    "# Kinematic properties                                    \n" \
    "# for axis: Tcp; ZAxis; Shoulder; Elbow; Wrist; Gripper   \n" \
    "# --------------------------------------------------------\n" \
    "\n" \
    "# Velocity in m/s or rad/s\n" \
    "##Velocity##\n" \
    "\n" \
    "# Acceleration in m/s2 or rad/s2\n" \
    "##Acceleration##\n" \
    "\n" \
    "# --------------------------------------------------------\n" \
    "# TCP Waypoints:      format = pointName; X; Y; Z; RZ     \n" \
    "# (XYZ = TCP absolute coordinates in millimeters)         \n" \
    "# (RZ  = TCP rotation corrector in deg., relative to Ox+) \n" \
    "# --------------------------------------------------------\n" \
    "\n" \
    "# palette point for assembly mode\n" \
    "##Pa_Mon##\n" \
    "\n" \
    "# palette point for disassembly mode\n" \
    "##Pa_Dem##\n" \
    "\n" \
    "# puzzle top-left piece\n" \
    "##Pu_00##\n" \
    "\n" \
    "# puzzle piece number 1 to 18 points\n" \
    "##Pu_01##\n" \
    "##Pu_02##\n" \
    "##Pu_03##\n" \
    "##Pu_04##\n" \
    "##Pu_05##\n" \
    "##Pu_06##\n" \
    "##Pu_07##\n" \
    "##Pu_08##\n" \
    "##Pu_09##\n" \
    "##Pu_10##\n" \
    "##Pu_11##\n" \
    "##Pu_12##\n" \
    "##Pu_13##\n" \
    "##Pu_14##\n" \
    "##Pu_15##\n" \
    "##Pu_16##\n" \
    "##Pu_17##\n" \
    "##Pu_18##\n" \
    "\n" \
    "# puzzle bottom-right piece\n" \
    "##Pu_19##\n" \
    "\n" \
    "# waiting point\n" \
    "##PWait##\n" \
    "\n" \
    "# trash point\n" \
    "##PTrash##\n" \
    "\n" \
    "# --------------------------------------------------------\n" \
    "# TCP Orientation:  format = turnName; RZ_begin; RZ_end   \n" \
    "# (TCP rotations in degrees, relative to Ox+)             \n" \
    "# --------------------------------------------------------\n" \
    "\n" \
    "# assembly mode (from palette to puzzle)\n" \
    "##Pa_to_Pu_0##\n" \
    "##Pa_to_Pu_1##\n" \
    "##Pa_to_Pu_2##\n" \
    "##Pa_to_Pu_3##\n" \
    "\n" \
    "# for disassembly mode (from puzzle to palette)\n" \
    "# just exchange RZ_begin and RZ_end...\n"


#endif // CELLFLEX_TEMPLATE_H
