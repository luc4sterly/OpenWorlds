// 10002700 RwSetClumpHints [Global]
// program: RWL21.DLL

int RwSetClumpHints(int param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  
                    /* 0x2700  384  RwSetClumpHints */
  if (param_1 == 0) {
    FUN_1000cba0(1);
    return 0;
  }
  if ((param_2 & 0xfffffff8) != 0) {
    FUN_1000cba0(0x30);
    return 0;
  }
  if (((param_2 & 1) == 0) || ((*(uint *)(param_1 + 0x188) & 1) != 0)) {
    if (((param_2 & 1) != 0) || ((*(uint *)(param_1 + 0x188) & 1) == 0)) goto LAB_10002764;
    iVar2 = 0;
  }
  else {
    iVar2 = 1;
  }
  FUN_1002c070(param_1,iVar2);
LAB_10002764:
  uVar1 = FUN_10033600(param_1,param_2);
  *(uint *)(param_1 + 0x188) = uVar1;
  return param_1;
}


