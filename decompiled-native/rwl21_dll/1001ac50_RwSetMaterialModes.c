// 1001ac50 RwSetMaterialModes [Global]
// programa: RWL21.DLL

int RwSetMaterialModes(int param_1,uint param_2)

{
  byte bVar1;
  
                    /* 0x1ac50  421  RwSetMaterialModes */
  if ((param_2 & 0xffffff3f) != 0) {
    FUN_1000cba0(0x48);
    return 0;
  }
  if (param_1 != 0) {
    bVar1 = *(byte *)(param_1 + 0x30) & 0x3f;
    *(byte *)(param_1 + 0x30) = bVar1;
    *(byte *)(param_1 + 0x30) = (byte)param_2 | bVar1;
    return param_1;
  }
  FUN_1000cba0(1);
  return 0;
}


