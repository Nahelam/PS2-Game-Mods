#include "stubs.h"
#include "types.h"
#include "macros.h"
#include "game_funcs.h"
#include "game_vars.h"
#include "game_enums.h"

/*******************************************************************************
*
* Patch VehicleTrafficResponseWithoutChecking to also set trailer as checked
* by us and avoid ownership related crashes
*
*******************************************************************************/
asm void CB4PhysicsManager__VehicleTrafficResponseWithoutChecking_Stub3()
{
    .set noreorder

    beqzl $s7, @OUT
    addiu $ra, $ra, 0x694
    daddu $s0, $s7, $zero
    daddu $s7, $zero, $zero
    addiu $ra, $ra, -0x3C
@OUT:
    jr    $ra
    nop
}

/*******************************************************************************
*
* Patch VehicleTrafficResponseWithoutChecking to handle our new 0x195 case,
* apply real traffic check values instead of stationary values
*
*******************************************************************************/
asm void CB4PhysicsManager__VehicleTrafficResponseWithoutChecking_Stub2()
{
    .set noreorder

    addiu sp, sp, -0x10
    sd    ra, 0(sp)
    jal   CB4PhysicsManager__CalculateAndApplyCheckingImpulse
    movn  a5, zero, s7
    beqz  s7, @OUT
    nop
    lw    s7, 0x3714(s0)
    beqz  s7, @NOTRAILER
    daddu a0, s6, zero
    daddu a1, s1, zero
    daddu a2, s7, zero
    daddu a3, s2, zero
    daddu a4, s5, zero
    jal   CB4PhysicsManager__CalculateAndApplyCheckingImpulse
    daddu a5, zero, zero
@NOTRAILER:
    lw    v1, 0x118(fp)
    daddu a1, s0, zero
    daddu a2, s4, zero
    lw    a3, 0x1500(s1)
    lb    a3, 0x2CA8(a3)
    lh    a0, 0xD8(v1)
    lw    v0, 0xDC(v1)
    jalr  ra, v0
    addu  a0, fp, a0
@OUT:
    ld    ra, 0(sp)
    jr    ra
    addiu sp, sp, 0x10
}

/*******************************************************************************
*
* Hook at the beginning of HandleAdjustedAIPositions
*
* Part. 2 of handling the special case of the 7th rival
* if we come from CB4EliminatorLogic::Update ($a0 != $s4),
* directly try to respawn the ai car passed in $a3
*
*******************************************************************************/
asm void CB4SingleRaceLogic__HandleAdjustedAIPositions_Stub2()
{
    .set noreorder

    beq   a0, s4, @OUT
    lw    v0, 0x6A0C(a2)
    daddu s2, a0, zero
    sw    a3, 0(sp)
    addiu ra, ra, 0x19C
@OUT:
    jr    ra
    slti  v0, v0, 7
}

/*******************************************************************************
*
* Hook in CB4EliminatorLogic::Update
*
* Part. 1 of handling the special case of the 7th rival
* getting eliminated and not respawning if it was active
* because the loop in HandleAdjustedAIPositions stops at 6
*
* In the loop which checks for active ai cars to be set inactive
* we call HandleAdjustedAIPositions if an AI car is marked for respawn
* and that the remaining cars count is equal to 6
*
*******************************************************************************/
asm void CB4EliminatorLogic__Update_Stub3()
{
    .set noreorder

    daddu s5, v0, zero
    addiu v0, zero, 6
    bne   v0, s2, @OUT
    daddu a0, s1, zero
    beqzl s0, @OUT
    daddu s6, s5, zero
    lbu   v0, 0x2C90(s5)
    bnez  v0, @OUT
    lbu   v1, 0x37AD(s5)
    beqz  v1, @OUT
    daddu a3, s5, zero
    j     CB4SingleRaceLogic__HandleAdjustedAIPositions
    mov.s f21, f20
@OUT:
    daddu a0, s5, zero
    jr    ra
    lw    v0, 0x24E8(a0)
}

/*******************************************************************************
*
* Hook in CB4SingleRaceLogic::SpawnAICar to reset our boolean
* and reset meFinishState, mnLives & meRaceState of AICar to
* avoid undesired behaviors after its reactivation
*
*******************************************************************************/
asm void CB4SingleRaceLogic__SpawnAICar_Stub()
{
    .set noreorder

    lbu   v0, 0x37AD(s0)
    beqz  v0, @OUT
    addiu v1, zero, -1
    sw    zero, 0x24E8(s0)
    sw    v1, 0x29D8(s0)
    sb    zero, 0x37AD(s0)
    addiu v0, zero, 2
    sw    v0, 0x2500(s0)
@OUT:
    jr    ra
    daddu a3, a4, $zero
}

/*******************************************************************************
*
* Hook the condition in CB4SingleRaceLogic::HandleAdjustedAIPositions
* which checks if mbActive is true and always try to respawn in front
* if the car was previously marked by us
*
*******************************************************************************/
asm void CB4SingleRaceLogic__HandleAdjustedAIPositions_Stub()
{
    .set noreorder

    bnezl v0, @OUT
    addiu s1, s1, -1
    lbu   v0, 0x37AD(s0)
    beqzl v0, @OUT
    addiu ra, ra, 0x6C
    sw    s0, 0(sp)
    addiu ra, ra, 0xAC
@OUT:
    jr    ra
    nop
}

/*******************************************************************************
*
* Hook OnRaceCarFinish call in CB4EliminatorLogic::EliminateRaceCar
*
* use the padding in the AICar class to set a boolean which will mark an
* elimited race car to be respawnable if the circular rivals system is still
* active
*
* mnEliminatedCars (0x150($s3)) is always reset to 0 until the race cars
* number is < 7 to display the "6th" eliminated until it really goes under 6
*
*******************************************************************************/
asm void CB4EliminatorLogic__EliminateRaceCar_Stub()
{
    .set noreorder

    slti  v0, s5, 7
    bnez  v0, @OUT
    addiu a3, zero, 1
    sw    zero, 0x150(s3)
    sb    a3, 0x37AD(s2)
@OUT:
    jr    v1
    nop
}

/*******************************************************************************
*
* Another call to apply the -1 also on mnCurrentNumAdjustedAICars
*
*******************************************************************************/
asm void CB4EliminatorLogic__Update_Stub2()
{
    .set noreorder

    slti  v0, s5, 7
    bnez  v0, @OUT
    addiu ra, ra, 0xC
    lw    v0, 0x6A38(s3)
    addiu v0, v0, -1
    sw    v0, 0x6A38(s3)
@OUT:
    jr    ra
    nop
}


/*******************************************************************************
*
* Small stub for fixing CB4EliminatorLogic::Update logic
* to support circular (> 5) rivals elimination when they are
* not "active", also handles hud message display for them
*
*******************************************************************************/
asm void CB4EliminatorLogic__Update_Stub()
{
    .set noreorder

    bnezl  v0, @OUT
    addiu  ra, ra, -0x40
    daddu  s6, ra, zero
    la     a0, gHUDManager
    jal    CB4HUDMessageManager__OnRaceCarElimination
    addiu  a1, zero, 6
    daddiu ra, s6, -0x1C
@OUT:
    jr     ra
    nop
}

void CB4HUDTrafficAttackScore__UpdateValueObject_Stub()
{
    if (gSingleEvent.me8State == eSingleEventState_InGame && gSingleEvent.mn8TATKTimeLimitOn == 0)
    {
        __asm__
        {
            lui at, 0x41A8
        }
    }
    else
    {
        __asm__
        {
            lui at, 0x4254
        }
    }
    __asm__
    {
        mtc1 at, f1
    }
}

void CB4HUDTrafficAttackScore__Prepare_Stub()
{
    if (gSingleEvent.me8State == eSingleEventState_InGame && gSingleEvent.mn8TATKTimeLimitOn == 0)
    {
        __asm__
        {
            daddu at, zero, zero
        }
    }
    else
    {
        __asm__
        {
            lui at, 0x4200
        }
    }
    __asm__
    {
        mtc1 at, f1
    }
}

void CB4GameData__Draw_Stub()
{
    int lnNumFinishLines;

    __asm__
    {
        daddu lnNumFinishLines, v0, zero
    }

    if (lnNumFinishLines == 0)
    {
        __asm__
        {
            // addiu ra, ra, 0x24
            .word 0x27FF0024
        }
        return;
    }

    if (gSingleEvent.me8State == eSingleEventState_InGame && gMenuChoices.meOnePlayerChoice == eB4MenuChoiceOnePlayer_Race)
    {
        __asm__
        {
            addiu a0, s0, 0x38
            addiu a1, s0, 0xB4
        }
    }
    else
    {
        __asm__
        {
            .set noreorder // otherwise second instruction gets ignored, idk why

            daddu a0, s0, zero
            daddu a1, s0, zero
        }
    }
}

void CB4LapManager__IncrementLapCount_Stub()
{
    __asm__
    {
        daddu a4, v0, zero
        daddu a5, v1, zero
    }

    if (gSingleEvent.me8State == eSingleEventState_InGame && gMenuChoices.meOnePlayerChoice == eB4MenuChoiceOnePlayer_Race)
    {
        __asm__
        {
            lw     v0, 0xC8(s1)
            addiu  v0, v0, 1
            sw     v0, 0xC8(s1)
            lw     v1, 0xCC(s1)
        }
    }
    else
    {
        __asm__
        {
            daddu v0, a4, zero
            daddu v1, a5, zero
        }
    }

    __asm__
    {
        .set noreorder

        addiu  a0, ra, 0x18C
        slti   a1, v1, 1

        // movn   ra, a0, a1
        .word 0x0085F80B
    }
}

void CB4HUDHitCount__Update_Stub()
{
    asm (
        "addiu $a4, $v1, -1    \n "
        "daddu $a5, $v1, $zero \n "
    );

    if (gSingleEvent.me8State == eSingleEventState_InGame && gMenuChoices.meOnePlayerChoice == eB4MenuChoiceOnePlayer_Race)
    {
        if (gaPlayerCars[0].mAICar.mRaceCar.mLapManager.mnLapsCompleted < 0)
        {
            // Store the current race lap limit in CB4HUDHitCount.mnTargetNumHits
            // Load 1 into $v0 which will be later stored in CB4HUDHitCount.mnNumHits
            asm (
                "sw    %0, 0x34($s0)    \n "
                "addiu $v0, $zero, 1    \n "
                :: "r" (gSingleEvent.mn8NumLaps)
            );
        }
        else
        {
            // Load completed laps into $v0 which will be later stored in CB4HUDHitCount.mnNumHits
            asm ("daddu $v0, %0, $zero" :: "r" (gaPlayerCars[0].mAICar.mRaceCar.mLapManager.mnRealLapsCompleted + 1) : "$v0");
        }
        asm ("addiu $v1, $zero, 1");
    }
    else
    {
        asm (
            "daddu $v0, $a4, $zero \n "
            "daddu $v1, $a5, $zero \n "
        );
    }
}

void CB4HUDHitCount__PrepareFixedObjects_Stub()
{
    __asm__
    {
        daddu a3, zero, zero
        daddu a5, a0, zero
    }

    if (gSingleEvent.me8State == eSingleEventState_InGame && gMenuChoices.meOnePlayerChoice == eB4MenuChoiceOnePlayer_Race)
    {
        __asm__
        {
            addiu a4, a4, -0xB0
        }
    }

    __asm__
    {
        lw a4, 0(a4)
        daddu a0, a5, zero
    }
}

void CB4OnePlayerStage__Prepare_Stub()
{
    int lbIsTurnBasedCrash;

    __asm__
    {
        daddu lbIsTurnBasedCrash, v0, zero
        daddu a4, a0, zero
    }

    if (gSingleEvent.me8State == eSingleEventState_InGame)
    {
        if (gMenuChoices.meOnePlayerChoice != eB4MenuChoiceOnePlayer_Crash)
        {
            __asm__
            {
                addiu a1, zero, 0x33
            }
        }
        else
        {
            __asm__
            {
                addiu a1, zero, 0x34
            }
        }
        __asm__
        {
            // addiu ra, ra, 0x4C
            .word 0x27FF004C
        }
    }
    else if (lbIsTurnBasedCrash)
    {
        __asm__
        {
            // addiu ra, ra, 0x60
            .word 0x27FF0060
        }
    }

    __asm__
    {
        daddu a0, a4, zero
    }
}

void CB4RevengeScore__UpdateTimeExtensionsAndMedalsStub(s32 leCurrentMedal)
{
    __asm__
    {
        daddu a4, a0, zero
    }

    if (leCurrentMedal == 2 || gSingleEvent.me8State == eSingleEventState_InGame)
    {
        __asm__
        {
            // addiu ra, ra, 0x68
            .word 0x27FF0068
        }
    }

    __asm__
    {
        daddu a0, a4, zero
    }
}

void CB4PhysicsManager__ResolvePenetration_Stub()
{
    if (gSingleEvent.me8State == eSingleEventState_InGame
        && gSingleEvent.me8TrafficCheckType == eTrafficCheckType_Full)
    {
        __asm__
        {
            mtc1 zero, f0
        }
    }
    else
    {
        __asm__
        {
            lwc1 f0, 0x1E0(a6)
        }
    }
}

void CB4PhysicsManager__CalculateAndApplyCheckingImpulse_Stub3()
{
    if (!(gSingleEvent.me8State == eSingleEventState_InGame
        && gSingleEvent.me8TrafficCheckType == eTrafficCheckType_Full))
    {
        __asm__
        {
            sqc2 vf4, 0xA0(s1)
        }
    }
}

void CB4PhysicsManager__CalculateAndApplyCheckingImpulse_Stub2()
{
    if (!(gSingleEvent.me8State == eSingleEventState_InGame
        && gSingleEvent.me8TrafficCheckType == eTrafficCheckType_Full))
    {
        __asm__
        {
            sqc2 vf1, 0xA0(s1)
        }
    }
}

void CB4PhysicsManager__CalculateAndApplyCheckingImpulse_Stub()
{
    if (!(gSingleEvent.me8State == eSingleEventState_InGame
        && gSingleEvent.me8TrafficCheckType == eTrafficCheckType_Full))
    {
        __asm__
        {
            sqc2 vf5, 0xA0(s1)
        }
    }
}

// ShouldWeReCheck
void CB4PhysicsManager__VehicleTrafficResponse_Stub(EB4ActiveBodyType leType, CB4ActiveBody *lpActiveBody)
{
    __asm__
    {
        daddu a4, a2, zero
    }
    if (leType == eABT_CrashingTraffic
        && gSingleEvent.me8State == eSingleEventState_InGame
        && gSingleEvent.me8TrafficCheckType == eTrafficCheckType_Full
        && ((CB4TrafficPhysics *)lpActiveBody->mpBodyData)->mn8ImmediateChecking == 2)
    {
        goto OUT;
    }
    else if (leType != eABT_Traffic)
    {
        __asm__
        {
            // addiu ra, ra, 0x88
            .word 0x27FF0088
        }
    }
OUT:;
    __asm__
    {
        daddu a2, a4, zero
    }
}

// HandleImmediateChecking
void CB4PhysicsManager__VehicleTrafficResponseWithoutChecking_Stub()
{
    CB4ActiveBody *lpActiveBody;
    int lbStationary;
    int ln8ImmediateChecking;

    __asm__
    {
        daddu a4, a2, zero
        daddu lbStationary, v0, zero
        daddu lpActiveBody, s3, zero

        // daddu s7, zero, zero
        .word 0x0000B82D
    }

    if (lpActiveBody->meType == eABT_Traffic)
    {
        __asm__
        {
            lb ln8ImmediateChecking, 0x195(s4)
            sb zero, 0x195(s4)
        }
    }
    else if (lpActiveBody->meType == eABT_CrashingTraffic)
    {
        __asm__
        {
            lw v0, 0x28(s3)
            lb ln8ImmediateChecking, 0x3738(v0)
            sb zero, 0x3738(v0)
        }
    }

    // ln8ImmediateChecking should be in a1

    if (ln8ImmediateChecking == 1)
    {
        __asm__
        {
            // addiu ra, ra, 0x84
            .word 0x27FF0084

            // daddu s7, a1, zero
            .word 0x00A0B82D
        }
    }
    else if (ln8ImmediateChecking == 2)
    {
        __asm__
        {
            // addiu ra, ra, 0xBC
            .word 0x27FF00BC

            // daddu s7, a1, zero
            .word 0x00A0B82D
        }
    }
    else
    {
        __asm__
        {
            daddu a2, a4, zero
        }

        if (!lbStationary)
        {
            __asm__
            {
                // addiu ra, ra, 0x154
                .word 0x27FF0154
            }
        }
    }
}

void CB4PhysicsManager__CanCheckTraffic_Stub2()
{
    int lnControlWord;
    CB4TrafficVehicle *lpTrafficVehicle;

    __asm__
    {
        cfc1 lnControlWord, $31
        daddu lpTrafficVehicle, s1, zero
    }

    if (!((lnControlWord >> 23) & 1))
    {
        if (gSingleEvent.me8State == eSingleEventState_InGame
            && gSingleEvent.me8TrafficCheckType == eTrafficCheckType_Full)
        {
            lpTrafficVehicle->mn8ImmediateChecking = 1;
        }
        __asm__
        {
            // addiu ra, ra, 0x2C
            .word 0x27FF002C
        }
    }
    __asm__
    {
        daddu $v0, $s3, $zero
    }
}

void CB4PhysicsManager__CanCheckTraffic_Stub()
{
    int lnIsBusOrCab;
    CB4TrafficVehicle *lpTrafficVehicle;

    __asm__
    {
        daddu lnIsBusOrCab, v0, zero
        daddu lpTrafficVehicle, s1, zero
    }

    if (gSingleEvent.me8State == eSingleEventState_InGame
        && gSingleEvent.me8TrafficCheckType == eTrafficCheckType_Full
        && (lnIsBusOrCab
            || lpTrafficVehicle->meClass == eVehicleCategoryArticulatedTrailer
            || (lpTrafficVehicle->mx8OtherFlags & 4) != 0))
    {
        lpTrafficVehicle->mn8ImmediateChecking = 1;
    }
    if (lnIsBusOrCab)
    {
        __asm__
        {
            // addiu ra, ra, 0x38
            .word 0x27FF0038
        }
    }
    else
    {
        __asm__
        {
            daddu a0, zero, zero
            lbu   v1, 0x187(s1)
        }
    }
}
