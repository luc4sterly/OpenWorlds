// 0041f1d0 _Java_NET_worlds_scape_Shape_nativeSetMaterial@12 [Global]
// program: gamma.dll

void _Java_NET_worlds_scape_Shape_nativeSetMaterial_12(int *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
                    /* 0x1f1d0  295  _Java_NET_worlds_scape_Shape_nativeSetMaterial@12 */
  if (param_3 != 0) {
    iVar2 = (**(code **)(*param_1 + 400))(param_1,param_2,DAT_00489664);
    if (iVar2 != 0) {
      iVar3 = FUN_00412cf0(param_1,param_2);
      if (iVar3 != 0) {
        iVar3 = FUN_00416fd0(param_1,param_3);
        if (iVar3 != 0) {
          piVar4 = (int *)(**(code **)(*param_1 + 0x2ec))(param_1,iVar3,0);
          iVar1 = *piVar4;
          (**(code **)(*param_1 + 0x30c))(param_1,iVar3,piVar4,0);
          if (iVar1 != 0) {
            FUN_00418a20(iVar2,iVar1);
          }
        }
      }
    }
  }
  return;
}


