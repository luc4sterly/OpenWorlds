// 004171d0 _Java_NET_worlds_scape_Material_closeMaterial@12 [Global]
// programa: gamma.dll

void _Java_NET_worlds_scape_Material_closeMaterial_12(int *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
                    /* 0x171d0  249  _Java_NET_worlds_scape_Material_closeMaterial@12 */
  iVar2 = (**(code **)(*param_1 + 0x17c))(param_1,param_2,DAT_0049fa08);
  if (iVar2 == 0) {
    return;
  }
  iVar3 = (**(code **)(*param_1 + 0x2ec))(param_1,iVar2,0);
  iVar1 = *(int *)(iVar3 + param_3 * 4);
  if (iVar1 != 0) {
    FUN_00419f20(iVar1,0);
    FUN_00419100(iVar1);
    *(undefined4 *)(iVar3 + param_3 * 4) = 0;
  }
  (**(code **)(*param_1 + 0x30c))(param_1,iVar2,iVar3,0);
  return;
}


