// 1000ddd0 RwGetLightVector [Global]
// program: RWL21.DLL

undefined4 RwGetLightVector(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
                    /* 0xddd0  195  RwGetLightVector */
  if ((param_1 != 0) && (param_2 != (undefined4 *)0x0)) {
    if (*(int *)(param_1 + 4) == 2) {
      FUN_1000cba0(8);
      return 0;
    }
    uVar1 = FUN_1001ce90(param_1 + 8,param_2);
    return uVar1;
  }
  FUN_1000cba0(1);
  return 0;
}


