// 00413c80 _Java_NET_worlds_scape_Hologram_postrender@12 [Global]
// programa: gamma.dll

void _Java_NET_worlds_scape_Hologram_postrender_12(int *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
                    /* 0x13c80  233  _Java_NET_worlds_scape_Hologram_postrender@12 */
  uVar1 = FUN_00412cf0(param_1,param_2);
  uVar2 = (**(code **)(*param_1 + 400))(param_1,param_2,DAT_00489450);
  (**(code **)(*param_1 + 0x1b4))(param_1,param_2,DAT_00489450,0);
  FUN_00418bc0(uVar1,uVar2);
  FUN_00419130(uVar2);
  return;
}


