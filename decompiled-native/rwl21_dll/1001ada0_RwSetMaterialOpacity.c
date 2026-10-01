// 1001ada0 RwSetMaterialOpacity [Global]
// program: RWL21.DLL

uint * RwSetMaterialOpacity(uint *param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  longlong lVar3;
  
                    /* 0x1ada0  422  RwSetMaterialOpacity */
  if (param_1 == (uint *)0x0) {
    FUN_1000cba0(1);
    return (uint *)0x0;
  }
  if (0x80000000 < param_2) {
    *(undefined1 *)(param_1 + 1) = 0;
  }
  if ((int)param_2 < 0x3f800000) {
    lVar3 = __ftol();
    *(byte *)(param_1 + 1) = (byte)((ulonglong)lVar3 >> 8) & 0xfc;
  }
  else {
    *(undefined1 *)(param_1 + 1) = 0xff;
  }
  if (param_1 == (uint *)0x0) {
    iVar2 = 1;
  }
  else {
    uVar1 = *param_1;
    if (uVar1 < 0x40) {
      if (uVar1 < 4) {
        iVar2 = 1;
      }
      else if (uVar1 < 8) {
        iVar2 = 2;
      }
      else {
        iVar2 = 4 - (uint)(uVar1 < 0xc);
      }
      goto LAB_1001ae21;
    }
    iVar2 = 0x67;
  }
  FUN_1000cba0(iVar2);
  iVar2 = 0;
LAB_1001ae21:
  RwSetMaterialGeometrySampling(param_1,iVar2);
  return param_1;
}


