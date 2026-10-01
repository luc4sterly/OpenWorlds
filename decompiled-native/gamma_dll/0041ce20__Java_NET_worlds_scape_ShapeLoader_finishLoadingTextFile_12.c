// 0041ce20 _Java_NET_worlds_scape_ShapeLoader_finishLoadingTextFile@12 [Global]
// program: gamma.dll

int _Java_NET_worlds_scape_ShapeLoader_finishLoadingTextFile_12
              (int *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  
                    /* 0x1ce20  285  _Java_NET_worlds_scape_ShapeLoader_finishLoadingTextFile@12 */
  uVar1 = (**(code **)(*param_1 + 0x2a4))(param_1,param_3,0);
  iVar2 = FUN_004199c0(uVar1);
  (**(code **)(*param_1 + 0x2a8))(param_1,param_3,uVar1);
  if (iVar2 == 0) {
    return -1;
  }
  uVar1 = (**(code **)(*param_1 + 0x17c))(param_1,param_2,DAT_00489660);
  (**(code **)(*param_1 + 0x1b4))(param_1,uVar1,DAT_00489664,iVar2);
  return iVar2;
}


