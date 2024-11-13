#include "mem.h"
#include "types.h"
#include "macros.h"
#include "hooks.h"
#include "stubs.h"
#include "utils.h"
#include "game_funcs.h"
#include "game_vars.h"

void main()
{
    MAKE_JAL(0x104BFC, (u32)&CGtTimer__Stop_Hook                                            );
    MAKE_JAL(0x10D54C, (u32)&CB4OnePlayerStage__Prepare_Stub                                );
    MAKE_JAL(0x10D67C, (u32)&IsSingleEventMode                                              );
    MAKE_JAL(0x121034, (u32)&IsSingleEventMode                                              );
    MAKE_JAL(0x124204, (u32)&IsSingleEventMode                                              );
    MAKE_JAL(0x126A9C, (u32)&IsSingleEventMode                                              );
    MAKE_JAL(0x16AF8C, (u32)&IsSingleEventMode                                              );
    MAKE_JAL(0x2D63A8, (u32)&IsSingleEventMode                                              );
    MAKE_JAL(0x112C30, (u32)&CGtInputManagerPS2Pad2__Update_Hook                            );
    MAKE_JAL(0x1173E8, (u32)&CB4StageLogic__EventSummaryAptCall_Hook                        );
    MAKE_JAL(0x11740C, (u32)&CB4StageLogic__EventSummaryAptCall_Hook                        );
    MAKE_JAL(0x11A52C, (u32)&CB4SingleRaceLogic__HandleAdjustedAIPositions_Stub2            );
    MAKE_JAL(0x11A61C, (u32)&CB4SingleRaceLogic__HandleAdjustedAIPositions_Stub             );
    MAKE_JAL(0x11A82C, (u32)&CB4SingleRaceLogic__SpawnAICar_Stub                            );
    MAKE_JAL(0x125804, (u32)&CB4GameData__GetGameDataThreshold_f_Hook                       );
    MAKE_JAL(0x163300, (u32)&CB4GameData__GetGameDataThreshold_f_Hook                       );
    MAKE_JAL(0x125CC4, (u32)&CB4EliminatorLogic__Update_Stub2                               );
    MAKE_JAL(0x125CD0, (u32)&CB4EliminatorLogic__Update_Stub                                );
    MAKE_JAL(0x125CF8, (u32)&CB4EliminatorLogic__Update_Stub3                               );
    MAKE_JAL(0x12618C, (u32)&CB4EliminatorLogic__EliminateRaceCar_Stub                      );
    MAKE_JAL(0x126AFC, (u32)&CB4MultiplayerRoadRageLogic__UpdateAIPositions_Hook            );
    MAKE_JAL(0x1630E8, (u32)&strcasecmpBurningLap_Hook                                      );
    MAKE_JAL(0x169DA0, (u32)&CB4HUDHitCount__Update_Stub                                    );
    MAKE_JAL(0x169E9C, (u32)&CB4HUDHitCount__PrepareFixedObjects_Stub                       );
    MAKE_JAL(0x16ADE0, (u32)&CB4HUDLap__Prepare_Hook                                        );
    MAKE_JAL(0x16AED8, (u32)&CB4HUDTrafficAttackScore__Prepare_Hook                         );
    MAKE_JAL(0x16AFBC, (u32)&CB4HUDRoadRageTimer__Prepare_Hook                              );
    MAKE_JAL(0x16B664, (u32)&CB4HUDTrafficAttackBar__Prepare_Hook                           );
    MAKE_JAL(0x17BC50, (u32)&CB4HUDTrafficAttackScore__Prepare_Stub                         );
    MAKE_JAL(0x17BED8, (u32)&CB4HUDTrafficAttackScore__UpdateValueObject_Stub               );
    MAKE_JAL(0x17D7F0, (u32)&AptUpdate_Hook                                                 );
    MAKE_JAL(0x181C2C, (u32)&CB4MenuChoices__RequestOnePlayerGameMode_Hook                  );
    MAKE_JAL(0x19121C, (u32)&CB4PopupManagerService__RequestPopup_Hook                      );
    MAKE_JAL(0x191398, (u32)&CB4StageLogic__MenuExit_Hook                                   );
    MAKE_JAL(0x19B358, (u32)&CB4CarSelectManager__SetNextState_Hook                         );
    MAKE_JAL(0x1A24B8, (u32)&CB4CarSelectService__GetTitles_Hook                            );
    MAKE_JAL(0x1B6780, (u32)&CB4CarSelectService__GetTitles_Hook                            );
    MAKE_JAL(0x1F7208, (u32)&CB4PhysicsManager__BodyBodyResponse_Hook2                      );
    MAKE_JAL(0x1F7908, (u32)&CB4PhysicsManager__VehicleTrafficResponse_Stub                 );
    MAKE_JAL(0x1F792C, (u32)&CB4PhysicsManager__CanCheckTraffic_Hook                        );
    MAKE_JAL(0x1F7CA0, (u32)&CB4PhysicsManager__CalculateAndApplyCheckingImpulse_Stub       );
    MAKE_JAL(0x1F7CE8, (u32)&CB4PhysicsManager__CalculateAndApplyCheckingImpulse_Stub2      );
    MAKE_JAL(0x1F7D58, (u32)&CB4PhysicsManager__CalculateAndApplyCheckingImpulse_Stub3      );
    MAKE_JAL(0x1F7F44, (u32)&CB4PhysicsManager__BodyBodyResponse_DeformVehicle_Hook         );
    MAKE_JAL(0x1F8038, (u32)&CB4PhysicsManager__VehicleTrafficResponseWithoutChecking_Stub  );
    MAKE_JAL(0x1F8118, (u32)&CB4PhysicsManager__VehicleTrafficResponseWithoutChecking_Stub2 );
    MAKE_JAL(0x1F818C, (u32)&CB4PhysicsManager__VehicleTrafficResponseWithoutChecking_Stub3 );
    MAKE_JAL(0x1F8820, (u32)&CB4PhysicsManager__BodyBodyResponse_Hook                       );
    MAKE_JAL(0x1F891C, (u32)&CB4PhysicsManager__BodyBodyResponse_Hook                       );
    MAKE_JAL(0x1FB2D0, (u32)&CB4PhysicsManager__ResolvePenetration_Stub                     );
    MAKE_JAL(0x1FDBF8, (u32)&CB4PhysicsManager__CanCheckTraffic_Stub                        );
    MAKE_JAL(0x1FDED4, (u32)&CB4PhysicsManager__CanCheckTraffic_Stub2                       );
    MAKE_JAL(0x293E14, (u32)&CB4AIAvoidanceMap__CheckTraffic_Hook                           );
    MAKE_JAL(0x2969E8, (u32)&GetAIMode_Hook                                                 );
    MAKE_JAL(0x2C6328, (u32)&CB4GameData__Draw_Stub                                         );
    MAKE_JAL(0x2C7FD8, (u32)&CB4LapManager__IncrementLapCount_Stub                          );
    MAKE_JAL(0x2D34AC, (u32)&CB4LanguageManager__FindString_Hook                            );
    MAKE_JAL(0x2D6E20, (u32)&CB4RevengeScore__UpdateTimeExtensionsAndMedalsStub             );

    // SLUS, SLES, SLKA, SLAJ (currently SLUS)
    PATCH_8(0x1264AE, 0x51);
    PATCH_8(0x16AF97, 0x10);
    PATCH_8(0x19A598, 0x01);
    PATCH_8(0x19B2C4, 0x01);
    PATCH_8(0x45AC40, 0x01);

    PATCH_16(0x169E9A, 0x2448);
    PATCH_16(0x2C633E, 0x8C83);
    PATCH_16(0x2C634A, 0x8CA2);

    // SLPM
    // PATCH_8(0x122F16, 0x51);
    // PATCH_8(0x18B480, 0x01);
    // PATCH_8(0x18C1AC, 0x01);
    // PATCH_8(0x3F0530, 0x01);

    // PATCH_16(0x16545A, 0x2448);
    // PATCH_16(0x16649A, 0x1040);
    // PATCH_16(0x28FEF6, 0x8C83);
    // PATCH_16(0x28FF02, 0x8CA2);

    PATCH_32(0x1108B0, 0x03E00008);
    PATCH_32(0x1108B4, 0x00000000);
    PATCH_32(0x125CFC, 0x00000000);
    PATCH_32(0x1826DC, 0x00000000);
    PATCH_32(0x1827F4, 0x00000000);
    PATCH_32(0x19A5EC, 0x1000002A);
    PATCH_32(0x19A5F0, 0x0220202D);
    PATCH_32(0x19B380, 0x00000000);
    PATCH_32(0x19B81C, 0x08066DD5);
    PATCH_32(0x19B820, 0x27BD0020);
    PATCH_32(0x2AD2C8, 0x10000007);
    PATCH_32(0x451418, 0x00000000);
    PATCH_32(0x45AC74, 0x3E19999A);
    PATCH_32(0x45AC78, 0x3E19999A);
    PATCH_32(0x49ABA4, 0x000B6700); // vtable entry - CB4OnePlayerStage__Prepare_Hook
    PATCH_32(0x49B6BC, 0x000B67F0); // vtable entry - GetRacePositionType_Hook
    PATCH_32(0x49B75C, 0x000B6840); // vtable entry - CB4SingleRaceLogic__GetNumLaps_Hook
    PATCH_32(0x49D8AC, 0x000B6890); // vtable entry - CB4SingleRevengeLogic__OnIntroCameraFinished_Hook
    PATCH_32(0x49DBC4, 0x000B68E0); // vtable entry - CB4BurningLapLogic__OnRaceCarStartNewLap_Hook
    PATCH_32(0x49DD04, 0x000B6990); // vtable entry - CB4BurningLapLogic__GetCheckpointMarkerFlags_Hook
    PATCH_32(0x49DD84, 0x000B69D0); // vtable entry - CB4BurningLapLogic__GetNumLaps_Hook
    PATCH_32(0x49E474, 0x000B67F0); // vtable entry - GetRacePositionType_Hook
    PATCH_32(0x49E7DC, 0x000B6A10); // vtable entry - CB4MultiplayerRoadRageLogic__OnIntroCameraFinished_Hook
    PATCH_32(0x49E894, 0x000B6A80); // vtable entry - CB4MultiplayerRoadRageLogic__GetTimeRemaining_Hook
    PATCH_32(0x49F2EC, 0x000B6AC0); // vtable entry - CB4HUDBurningLap__Update_Hook
    PATCH_32(0x49F314, 0x000B6AF0); // vtable entry - CB4HUDBurningLapTimer__Update_Hook
    PATCH_32(0x49FB9C, 0x000B6B60); // vtable entry - CB4MainMenuState__Action_Hook
    PATCH_32(0x49FDF4, 0x000B6C00); // vtable entry - CB4MPCrashOptionsState__OnActionEnter_Hook
    PATCH_32(0x49FEB4, 0x000B6C80); // vtable entry - CB4MPRaceOptionsState__OnActionEnter_Hook
    PATCH_32(0x49FEC4, 0x000B6D20); // vtable entry - CB4MPRaceOptionsState__OnActionPageSelectEvent_Hook
    PATCH_32(0x49FEF4, 0x000B6F20); // vtable entry - CB4MultiplayerState__OnActionEnter_Hook
    PATCH_32(0x49FF04, 0x000B6FD0); // vtable entry - CB4MultiplayerState__OnActionPageSelectEvent_Hook
    PATCH_32(0x4B8E94, 0x0019B54C);
    PATCH_32(0x4B8E9C, 0x0019B54C);
    PATCH_32(0x4B8EA0, 0x0019B5AC);

    _memset(&gSingleEvent, '\0', sizeof(gSingleEvent));

    FlushCache(0);
    FlushCache(2);
}

static void payload()
{
    char *lacBin;
    CGTFile *lpFile;

    __asm__
    {
        sq a0, 0(sp)
        addiu lacBin, sp, 0x28
    }

    lacBin[0xB] = '\0';
    lpFile = CGTFileSystem__Open(gpFileSystem, lacBin, 0x1);
    lpFile->vtbl->SetPosition(lpFile, 0x3EC000, eGTF_BEGIN);
    lpFile->vtbl->Read(lpFile, (void *)0xB5000, 0x3FB0);
    lpFile->vtbl->Close(lpFile);

    FlushCache(0);
    FlushCache(2);

    main();
}
