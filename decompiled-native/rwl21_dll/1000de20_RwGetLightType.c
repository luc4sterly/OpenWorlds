// 1000de20 RwGetLightType [Global]
// programa: RWL21.DLL

undefined4 RwGetLightType(int param_1)

{
                    /* 0xde20  194  RwGetLightType */
  if (param_1 != 0) {
    return *(undefined4 *)(param_1 + 4);
  }
  FUN_1000cba0(1);
  return 0;
}


