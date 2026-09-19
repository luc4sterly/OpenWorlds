// 1002f150 RwGetLightOwner [Global]
// programa: RWL21.DLL

undefined4 RwGetLightOwner(int param_1)

{
  undefined4 uVar1;
  
                    /* 0x2f150  190  RwGetLightOwner */
  uVar1 = 0;
  if (param_1 == 0) {
    FUN_1000cba0(1);
  }
  else {
    uVar1 = *(undefined4 *)(param_1 + 0x8c);
  }
  return uVar1;
}


