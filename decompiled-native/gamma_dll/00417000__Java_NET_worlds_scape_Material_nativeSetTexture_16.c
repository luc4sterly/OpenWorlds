// 00417000 _Java_NET_worlds_scape_Material_nativeSetTexture@16 [Global]
// programa: gamma.dll

void _Java_NET_worlds_scape_Material_nativeSetTexture_16
               (int *param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
                    /* 0x17000  253  _Java_NET_worlds_scape_Material_nativeSetTexture@16 */
  iVar2 = (**(code **)(*param_1 + 0x17c))(param_1,param_2,DAT_0049fa08);
  if (iVar2 == 0) {
    return;
  }
  iVar3 = (**(code **)(*param_1 + 0x2ec))(param_1,iVar2,0);
  iVar1 = *(int *)(iVar3 + param_3 * 4);
  (**(code **)(*param_1 + 0x30c))(param_1,iVar2,iVar3,0);
  if (iVar1 != 0) {
    uVar4 = 0;
    if (param_4 != 0) {
      uVar4 = FUN_00424e00(param_1,param_4);
    }
    FUN_00419f20(iVar1,uVar4);
  }
  return;
}


