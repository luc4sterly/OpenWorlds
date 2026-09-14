// 00412900 _Java_NET_worlds_scape_Room_destroyScene@8 [Global]
// programa: gamma.dll

void _Java_NET_worlds_scape_Room_destroyScene_8(int *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
                    /* 0x12900  274  _Java_NET_worlds_scape_Room_destroyScene@8 */
  uVar1 = (**(code **)(*param_1 + 400))(param_1,param_2,DAT_00489394);
  (**(code **)(*param_1 + 0x1b4))(param_1,param_2,DAT_00489394,0);
  uVar2 = FUN_00419830(uVar1);
  (**(code **)(*param_1 + 0x58))(param_1,uVar2);
  FUN_00419160(uVar1);
  return;
}


