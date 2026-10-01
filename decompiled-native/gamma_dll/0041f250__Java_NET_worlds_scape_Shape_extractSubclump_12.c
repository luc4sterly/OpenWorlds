// 0041f250 _Java_NET_worlds_scape_Shape_extractSubclump@12 [Global]
// program: gamma.dll

int _Java_NET_worlds_scape_Shape_extractSubclump_12(int *param_1,int param_2,int param_3)

{
  int iVar1;
  
                    /* 0x1f250  292  _Java_NET_worlds_scape_Shape_extractSubclump@12 */
  if (param_2 != 0) {
    iVar1 = FUN_00412cf0(param_1,param_2);
    if (iVar1 != 0) {
      iVar1 = FUN_004196d0(iVar1);
      while ((iVar1 != 0 && (param_3 = param_3 + -1, -1 < param_3))) {
        iVar1 = FUN_00419770(iVar1);
      }
      if (iVar1 != 0) {
        FUN_00417ac0(iVar1);
      }
      return iVar1;
    }
  }
  return 0;
}


