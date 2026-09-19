// 1000daf0 RwGetLightData [Global]
// programa: RWL21.DLL

undefined4 RwGetLightData(int param_1)

{
                    /* 0xdaf0  188  RwGetLightData */
  if (param_1 != 0) {
    return *(undefined4 *)(param_1 + 0x88);
  }
  FUN_1000cba0(1);
  return 0;
}


