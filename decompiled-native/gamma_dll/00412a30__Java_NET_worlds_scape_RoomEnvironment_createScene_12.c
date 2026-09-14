// 00412a30 _Java_NET_worlds_scape_RoomEnvironment_createScene@12 [Global]
// programa: gamma.dll

void _Java_NET_worlds_scape_RoomEnvironment_createScene_12
               (int *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
                    /* 0x12a30  269  _Java_NET_worlds_scape_RoomEnvironment_createScene@12 */
  uVar1 = FUN_00419070();
  uVar2 = (**(code **)(*param_1 + 0x54))(param_1,param_3);
  FUN_00419ff0(uVar1,uVar2);
  (**(code **)(*param_1 + 0x1b4))(param_1,param_2,DAT_00489398,uVar1);
  uVar2 = FUN_00412cf0(param_1,param_2);
  FUN_00418dd0(uVar1,uVar2);
  return;
}


