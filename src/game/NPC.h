/*
 * Copyright 2011-2012 Arx Libertatis Team (see the AUTHORS file)
 *
 * This file is part of Arx Libertatis.
 *
 * Arx Libertatis is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Arx Libertatis is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Arx Libertatis.  If not, see <http://www.gnu.org/licenses/>.
 */
/* Based on:
===========================================================================
ARX FATALIS GPL Source Code
Copyright (C) 1999-2010 Arkane Studios SA, a ZeniMax Media company.

This file is part of the Arx Fatalis GPL Source Code ('Arx Fatalis Source Code'). 

Arx Fatalis Source Code is free software: you can redistribute it and/or modify it under the terms of the GNU General Public 
License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

Arx Fatalis Source Code is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied 
warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with Arx Fatalis Source Code.  If not, see 
<http://www.gnu.org/licenses/>.

In addition, the Arx Fatalis Source Code is also subject to certain additional terms. You should have received a copy of these 
additional terms immediately following the terms and conditions of the GNU General Public License which accompanied the Arx 
Fatalis Source Code. If not, please request a copy in writing from Arkane Studios at the address below.

If you have questions concerning this license or the applicable additional terms, you may contact in writing Arkane Studios, c/o 
ZeniMax Media Inc., Suite 120, Rockville, Maryland 20850 USA.
===========================================================================
*/
// Code: Cyril Meynier
//
// Copyright (c) 1999-2001 ARKANE Studios SA. All rights reserved

#ifndef ARX_GAME_NPC_H
#define ARX_GAME_NPC_H

#include <string>

#include "graphics/data/Mesh.h"
#include "math/MathFwd.h"

const float ARX_NPC_AUDIBLE_VOLUME_MIN(0.94F);
const float ARX_NPC_AUDIBLE_VOLUME_MAX(1.0F);
const float ARX_NPC_AUDIBLE_VOLUME_DEFAULT(ARX_NPC_AUDIBLE_VOLUME_MAX);
const float ARX_NPC_AUDIBLE_VOLUME_RANGE(ARX_NPC_AUDIBLE_VOLUME_MAX - ARX_NPC_AUDIBLE_VOLUME_MIN);
const float ARX_NPC_AUDIBLE_FACTOR_MIN(1.0F);
const float ARX_NPC_AUDIBLE_FACTOR_MAX(4.5F);
const float ARX_NPC_AUDIBLE_FACTOR_DEFAULT(ARX_NPC_AUDIBLE_FACTOR_MIN);
const float ARX_NPC_AUDIBLE_FACTOR_RANGE(ARX_NPC_AUDIBLE_FACTOR_MAX - ARX_NPC_AUDIBLE_FACTOR_MIN);
const float ARX_NPC_AUDIBLE_PRESENCE_DEFAULT(1.0F);

void ARX_NPC_Revive(Entity * io, long flag);
bool ARX_NPC_SetStat(Entity & io, const std::string & statname, float value);
void ARX_NPC_TryToCutSomething(Entity * target, Vec3f * pos);
bool ARX_NPC_LaunchPathfind(Entity * io, long target);
bool IsDeadNPC(Entity * io);

void FaceTarget2(Entity * io);
void ARX_TEMPORARY_TrySound(float power);
void ARX_NPC_Behaviour_Stack(Entity * io);
void ARX_NPC_Behaviour_UnStack(Entity * io);
void ARX_NPC_Behaviour_Reset(Entity * io);
void ARX_NPC_Behaviour_ResetAll();
void ARX_NPC_Behaviour_Change(Entity * io, Behaviour behavior, long behavior_param);
void ARX_NPC_ChangeMoveMode(Entity * io, MoveMode MOVEMODE);
void ARX_NPC_SpawnAudibleSound(Vec3f * pos, Entity * source,
                               const float factor = ARX_NPC_AUDIBLE_FACTOR_DEFAULT,
                               const float presence = ARX_NPC_AUDIBLE_PRESENCE_DEFAULT);
void ARX_NPC_NeedStepSound(Entity * io, Vec3f * pos,
                           const float volume = ARX_NPC_AUDIBLE_VOLUME_DEFAULT,
                           const float factor = ARX_NPC_AUDIBLE_FACTOR_DEFAULT);

Entity * ARX_NPC_GetFirstNPCInSight(Entity * ioo);
void CheckNPC(Entity * io);
void ManageIgnition(Entity * io);
void ManageIgnition_2(Entity * io);

void ARX_NPC_Kill_Spell_Launch(Entity * io);

void ARX_PHYSICS_Apply();

void GetTargetPos(Entity * io, unsigned long smoothing = 0);

#endif // ARX_GAME_NPC_H
