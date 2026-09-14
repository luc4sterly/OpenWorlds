// 00426220 _Java_NET_worlds_scape_Transform_nativeFinalize@8 [Global]
// programa: gamma.dll

void _Java_NET_worlds_scape_Transform_nativeFinalize_8(int *param_1,undefined4 param_2)

{
  int iVar1;
  
                    /* 0x26220  328  _Java_NET_worlds_scape_Transform_nativeFinalize@8 */
  iVar1 = (**(code **)(*param_1 + 400))(param_1,param_2,DAT_0049d24c);
  if (iVar1 != 0) {
    (**(code **)(*param_1 + 0x1b4))(param_1,param_2,DAT_0049d24c,0);
    FUN_00419130(iVar1);
  }
  return;
}


