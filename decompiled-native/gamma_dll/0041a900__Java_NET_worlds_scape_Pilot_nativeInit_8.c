// 0041a900 _Java_NET_worlds_scape_Pilot_nativeInit@8 [Global]
// programa: gamma.dll

void _Java_NET_worlds_scape_Pilot_nativeInit_8(int *param_1)

{
  undefined4 uVar1;
  
                    /* 0x1a900  257  _Java_NET_worlds_scape_Pilot_nativeInit@8 */
  if (DAT_004895b8 == 0) {
    uVar1 = (**(code **)(*param_1 + 0x18))(param_1,s_NET_worlds_scape_Pilot_004706e0);
    DAT_004895b8 = (**(code **)(*param_1 + 0x54))(param_1,uVar1);
    if (DAT_004895b8 == 0) {
      FUN_00402800(s_nPilot_004706f8,0x17);
    }
    DAT_0049fba4 = (**(code **)(*param_1 + 0x178))
                             (param_1,DAT_004895b8,s_cameraMode_00470704,&DAT_00470700);
    if (DAT_0049fba4 == 0) {
      FUN_00402800(s_nPilot_004706f8,0x1a);
    }
  }
  return;
}


