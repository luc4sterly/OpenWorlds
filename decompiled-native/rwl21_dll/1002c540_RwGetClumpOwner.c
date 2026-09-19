// 1002c540 RwGetClumpOwner [Global]
// programa: RWL21.DLL

undefined4 RwGetClumpOwner(int param_1)

{
  undefined4 uVar1;
  
                    /* 0x2c540  163  RwGetClumpOwner */
  uVar1 = 0;
  if (param_1 == 0) {
    FUN_1000cba0(1);
  }
  else {
    uVar1 = *(undefined4 *)(*(int *)(param_1 + 0xb8) + 0x18);
  }
  return uVar1;
}


