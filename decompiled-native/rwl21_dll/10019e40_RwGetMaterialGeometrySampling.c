// 10019e40 RwGetMaterialGeometrySampling [Global]
// programa: RWL21.DLL

int RwGetMaterialGeometrySampling(uint *param_1)

{
  uint uVar1;
  
                    /* 0x19e40  200  RwGetMaterialGeometrySampling */
  if (param_1 == (uint *)0x0) {
    FUN_1000cba0(1);
    return 0;
  }
  uVar1 = *param_1;
  if (0x3f < uVar1) {
    FUN_1000cba0(0x67);
    return 0;
  }
  if (uVar1 < 4) {
    return 1;
  }
  if (uVar1 < 8) {
    return 2;
  }
  return 4 - (uint)(uVar1 < 0xc);
}


