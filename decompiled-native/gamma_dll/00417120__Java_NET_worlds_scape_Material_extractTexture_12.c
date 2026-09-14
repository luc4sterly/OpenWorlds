// 00417120 _Java_NET_worlds_scape_Material_extractTexture@12 [Global]
// programa: gamma.dll

int _Java_NET_worlds_scape_Material_extractTexture_12(int *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
                    /* 0x17120  250  _Java_NET_worlds_scape_Material_extractTexture@12 */
  iVar2 = (**(code **)(*param_1 + 0x17c))(param_1,param_2,DAT_004a031c);
  if (iVar2 == 0) {
    return 0;
  }
  iVar3 = (**(code **)(*param_1 + 0x2b4))(param_1,iVar2,param_3);
  if (iVar3 != 0) {
    iVar4 = (**(code **)(*param_1 + 0x17c))(param_1,param_2,DAT_0049fa08);
    if (iVar4 != 0) {
      iVar5 = (**(code **)(*param_1 + 0x2ec))(param_1,iVar4,0);
      iVar1 = *(int *)(iVar5 + param_3 * 4);
      (**(code **)(*param_1 + 0x30c))(param_1,iVar4,iVar5,0);
      if (iVar1 != 0) {
        FUN_00419f20(iVar1,0);
      }
    }
    (**(code **)(*param_1 + 0x2b8))(param_1,iVar2,param_3,0);
  }
  return iVar3;
}


